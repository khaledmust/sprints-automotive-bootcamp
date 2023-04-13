#include "external_interrupts.h"

#include "interrupts_library.h"
#include "../Utilities/common_macros.h"
#include "../Utilities/registers.h"

/**
 * @brief Enables and sets the sense control of the external interrupt.
 * This is achieved by calling both INT_EnableINTx and INT_ExtIntSenseControl.
 * @param ext_int_config_struct
 * @return INT_INVALID_EXTERNAL_SRC
 * @return INT_SUCCESS
 */
EN_INT_ERROR_STATE INT_ExtInterruptInit(INT_ExtInit_t *ext_int_config_struct) {
	EN_EXT_INTERRUPT_SRC src = ext_int_config_struct -> src;
    EN_EXT_INT_SENSE_CONTROL control = ext_int_config_struct -> control;
	EN_INT_ERROR_STATE external_interrupt_state = -1;
    sei();
    switch (src) {
        case INT0:
            INT_ExtIntSenseControl(src, control);
			external_interrupt_state = INT_EnableINT0();
			if (external_interrupt_state == INT_GLOBAL_INT_NOT_SET) {
				return INT_GLOBAL_INT_NOT_SET;
			}
            break;
        case INT1:
            INT_ExtIntSenseControl(src, control);
			external_interrupt_state = INT_EnableINT1();
			if (external_interrupt_state == INT_GLOBAL_INT_NOT_SET) {
				return INT_GLOBAL_INT_NOT_SET;
			}
            break;
        case INT2:
            INT_ExtIntSenseControl(src, control);
			external_interrupt_state = INT_EnableINT2();
			if (external_interrupt_state == INT_GLOBAL_INT_NOT_SET) {
				return INT_GLOBAL_INT_NOT_SET;
			}
            break;
        default:
            return INT_INVALID_EXTERNAL_SRC;
    }
    return INT_SUCCESS;
}

/**
 * @brief Enables external interrupt 0.
 * This is achieved by setting bit 6 of GICR.
 * @return INT_GLOBAL_INT_NOT_SET
 * @return INT_SUCCESS
 */
EN_INT_ERROR_STATE INT_EnableINT0() {
    if (BIT_IS_SET(SREG,7)) {
		SET_BIT(GICR,6);
		return INT_SUCCESS;
    } else {
		return INT_GLOBAL_INT_NOT_SET;
    }
}

/**
 * @brief Enables external interrupt 1.
 * This is achieved by setting bit 7 of GICR.
 * @return INT_GLOBAL_INT_NOT_SET
 * @return INT_SUCCESS
 */
EN_INT_ERROR_STATE INT_EnableINT1() {
    if (BIT_IS_CLEAR(SREG,7)) {
        return INT_GLOBAL_INT_NOT_SET;
    } else {
        SET_BIT(GICR,7);
        return INT_SUCCESS;
    }
}

/**
 * @brief Enables external interrupt 2.
 * This is achieved by setting bit 5 of GICR.
 * @return INT_GLOBAL_INT_NOT_SET
 * @return INT_SUCCESS
 */
EN_INT_ERROR_STATE INT_EnableINT2() {
    if (BIT_IS_CLEAR(SREG,7)) {
        return INT_GLOBAL_INT_NOT_SET;
    } else {
        SET_BIT(GICR,5);
        return INT_SUCCESS;
    }
}

/**
 * @brief Controls the triggering mechanism of INT1 and INT0.
 * Interrupt 0 sense control.
 * | ISC01 Bit 3 | ISC00 Bit 2 | Description                       |
 * |-------------|-------------|-----------------------------------|
 * | 0           | 0           | INT0 triggered on low level.      |
 * | 0           | 1           | Any logic change triggers.        |
 * | 1           | 0           | Falling edge generates interrupt. |
 * | 1           | 1           | Rising edge generates interrupt.  |
 * Interrupt 1 sense control
 * | ISC11 Bit 3 | ISC10 Bit 2 | Description                       |
 * |-------------|-------------|-----------------------------------|
 * | 0           | 0           | INT1 triggered on low level.      |
 * | 0           | 1           | Any logic change triggers.        |
 * | 1           | 0           | Falling edge generates interrupt. |
 * | 1           | 1           | Rising edge generates interrupt.  |
 * Interrupt 2 sense control
 * 0 - Falling edge activates the interrupt.
 * 1 - Rising edge activates the interrupt.
*/
EN_INT_ERROR_STATE INT_ExtIntSenseControl(EN_EXT_INTERRUPT_SRC src, EN_EXT_INT_SENSE_CONTROL control) {
    switch (src) {
        case INT0:
            switch (control) {
                case LOW_LEVEL:
                    CLEAR_BIT(MCUCR,ISC00);
                    CLEAR_BIT(MCUCR,ISC01);
                    break;
                case ANY_LOGIC_CHANGE:
                    SET_BIT(MCUCR,ISC00);
                    CLEAR_BIT(MCUCR,ISC01);
                    break;
                case FALLING_EDGE:
                    CLEAR_BIT(MCUCR,ISC00);
                    SET_BIT(MCUCR,ISC01);
                    break;
                case RISING_EDGE:
                    SET_BIT(MCUCR,ISC00);
                    SET_BIT(MCUCR,ISC01);
                    break;
            }
            break;
        case INT1:
            switch (control) {
                case LOW_LEVEL:
                    CLEAR_BIT(MCUCR,ISC10);
                    CLEAR_BIT(MCUCR,ISC11);
                    break;
                case ANY_LOGIC_CHANGE:
                    SET_BIT(MCUCR,ISC10);
                    CLEAR_BIT(MCUCR,ISC11);
                    break;
                case FALLING_EDGE:
                    CLEAR_BIT(MCUCR,ISC10);
                    SET_BIT(MCUCR,ISC11);
                    break;
                case RISING_EDGE:
                    SET_BIT(MCUCR,ISC10);
                    SET_BIT(MCUCR,ISC11);
                    break;
            }
            break;
        case INT2:
            if (control == FALLING_EDGE) {
                CLEAR_BIT(MCUCSR,ISC2);
            } else if (control == RISING_EDGE) {
                SET_BIT(MCUCSR, ISC2);
            } else {
                return INT_INVALID_CONTROL;
            }
            break;
        default:
            return INT_INVALID_EXTERNAL_SRC;
    }
    return INT_SUCCESS;
}

void INT_UnitTest(void) {
	INT_ExtInit_t INT_UnitTest_config_struct;
	volatile EN_INT_ERROR_STATE INT_UnitTestError = -1;
	
	// Test case #1.
	/* Configure and enable external interrupt without first enabling the global interrupt.
	 * Expected EN_INT_ERROR_STATE is INT_GLOBAL_INT_NOT_SET which evaluates to 1.*/
	INT_UnitTest_config_struct.src = INT0;
	INT_UnitTest_config_struct.control = RISING_EDGE;
	INT_UnitTestError = INT_ExtInterruptInit(&INT_UnitTest_config_struct);
}