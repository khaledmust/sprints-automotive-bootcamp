#ifndef S_ESL1_03_LED_SEQUENCE_V2_0_EXTERNAL_INTERRUPTS_H
#define S_ESL1_03_LED_SEQUENCE_V2_0_EXTERNAL_INTERRUPTS_H

/**
 * @enum EN_INT_ERROR_STATE
 * @brief Specifies the state of DIO functions.
 */
typedef enum EN_INT_ERROR_STATE {
    INT_SUCCESS = 0, INT_GLOBAL_INT_NOT_SET, INT_INVALID_CONTROL, INT_INVALID_EXTERNAL_SRC
}EN_INT_ERROR_STATE;

/**
 * @enum EN_EXT_INT_SENSE_CONTROL
 * @brief Specifies the triggering mechanism for the external interrupts.
 */
typedef enum EN_EXT_INT_SENSE_CONTROL {
    LOW_LEVEL = 0, ANY_LOGIC_CHANGE, FALLING_EDGE, RISING_EDGE
}EN_EXT_INT_SENSE_CONTROL;

/**
 * @enum EN_EXT_INTERRUPT_SRC
 * @brief Specifies the external interrupts source.
 */
typedef enum EN_EXT_INTERRUPT_SRC {
    INT0 = 0, INT1, INT2
}EN_EXT_INTERRUPT_SRC;

/**
 * @enum EN_EXT_INTERRUPT_BITS
 * @brief Control sense configuration bits.
 */
typedef enum EN_EXT_INTERRUPT_BITS {
    ISC00 = 0, ISC01, ISC10, ISC11, ISC2 = 6
}EN_EXT_INTERRUPT_BITS;

/**
 * @struct INT_ExtInit_t
 * @brief Holds the configuration of external interrupts.
 * @var INT_ExtInit_t::src
 * Member 'src' specifies the external source of the interrupt.
 * @var INT_ExtInit_t::control
 * Member 'control' specifies how the external pin gets triggered.
 */
typedef struct INT_ExtInit_t {
    EN_EXT_INTERRUPT_SRC src;
    EN_EXT_INT_SENSE_CONTROL control;
}INT_ExtInit_t;

/**
 * @brief Enables and sets the sense control of the external interrupt.
 * @param ext_int_config_struct
 * @return INT_INVALID_EXTERNAL_SRC
 * @return INT_SUCCESS
 */
EN_INT_ERROR_STATE INT_ExtInterruptInit(INT_ExtInit_t *ext_int_config_struct);

/**
 * @brief Enables external interrupt 0.
 * @return INT_GLOBAL_INT_NOT_SET
 * @return INT_SUCCESS
 */
EN_INT_ERROR_STATE INT_EnableINT0();

/**
 * @brief Enables external interrupt 1.
 * @return INT_GLOBAL_INT_NOT_SET
 * @return INT_SUCCESS
 */
EN_INT_ERROR_STATE INT_EnableINT1();

/**
 * @brief Enables external interrupt 2.
 * @return INT_GLOBAL_INT_NOT_SET
 * @return INT_SUCCESS
 */
EN_INT_ERROR_STATE INT_EnableINT2();

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
EN_INT_ERROR_STATE INT_ExtIntSenseControl(EN_EXT_INTERRUPT_SRC src, EN_EXT_INT_SENSE_CONTROL control);

void INT_UnitTest(void);

#endif //S_ESL1_03_LED_SEQUENCE_V2_0_EXTERNAL_INTERRUPTS_H
