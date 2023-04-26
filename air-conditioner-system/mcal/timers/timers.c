#include "timers.h"

/**
 * @brief This function initializes the timer with the specified configuration.
 * @param TIMER0_UserConfig
 */
void Timer0_Init(TIMER0_Config *TIMER0_UserConfig) {
    switch (TIMER0_UserConfig -> timerWaveGeneration) {
        case NORMAL_WG:
            CLEAR_BIT(TCCR0, WGM00);
            CLEAR_BIT(TCCR0, WGM01);
            break;
        case PWM_WG:
            SET_BIT(TCCR0, WGM00);
            CLEAR_BIT(TCCR0, WGM01);
            break;
        case CTC_WG:
            CLEAR_BIT(TCCR0, WGM00);
            SET_BIT(TCCR0, WGM01);
            break;
        case FAST_PWM_WG:
            SET_BIT(TCCR0, WGM00);
            SET_BIT(TCCR0, WGM01);
            break;
        default:
		;
            // Do nothing.
    }
    switch (TIMER0_UserConfig -> timerMode) {
        case TIMER0_OVERFLOW:
            CLEAR_BIT(TCCR0, COM00);
            CLEAR_BIT(TCCR0, COM01);
            break;
        case TIMER0_COMPARE_TOGGLE:
            SET_BIT(TCCR0, COM00);
            CLEAR_BIT(TCCR0, COM01);
            break;
        case TIMER0_COMPARE_CLEAR:
            CLEAR_BIT(TCCR0, COM00);
            SET_BIT(TCCR0, COM01);
            break;
        case TIMER0_COMPARE_SET:
            SET_BIT(TCCR0, COM00);
            SET_BIT(TCCR0, COM01);
            break;
    }
    /* Set the value of the output compare register. */
    OCR0 = TIMER0_UserConfig -> TIMER0_CompareValue;

    /* Set the initial count value of the timer. */
    TCNT0 = TIMER0_UserConfig -> TIMER0_InitValue;

    switch (TIMER0_UserConfig -> InterruptMode) {
        case INTERRUPT_DISABLED:
            CLEAR_BIT(TIMSK, TOIE0);
            CLEAR_BIT(TIMSK, OCIE0);
            break;
        case INTERRUPT_OVERFLOW_ENABLED:
            SET_BIT(TIMSK, TOIE0);
            CLEAR_BIT(TIMSK, OCIE0);
            break;
        case INTERRUPT_COMPARE_MATCH_ENABLED:
            CLEAR_BIT(TIMSK ,TOIE0);
            SET_BIT(TIMSK, OCIE0);
            break;
        case INTERRUPT_ENABLED:
            SET_BIT(TIMSK, TOIE0);
            SET_BIT(TIMSK, OCIE0);
            break;
    }

    /* Set the clock source and start the timer. */
    switch (TIMER0_UserConfig -> timerClock) {
        case NO_CLK:
            CLEAR_BIT(TCCR0, CS00);
            CLEAR_BIT(TCCR0, CS01);
            CLEAR_BIT(TCCR0, CS02);
            break;
        case F_CPU_CLK:
            SET_BIT(TCCR0, CS00);
            CLEAR_BIT(TCCR0, CS01);
            CLEAR_BIT(TCCR0, CS02);
            break;
        case F_CPU_8:
            CLEAR_BIT(TCCR0, CS00);
            SET_BIT(TCCR0, CS01);
            CLEAR_BIT(TCCR0, CS02);
            break;
        case F_CPU_64:
            SET_BIT(TCCR0, CS00);
            SET_BIT(TCCR0, CS01);
            CLEAR_BIT(TCCR0, CS02);
            break;
        case F_CPU_256:
            CLEAR_BIT(TCCR0, CS00);
            CLEAR_BIT(TCCR0, CS01);
            SET_BIT(TCCR0, CS02);
            break;
        case F_CPU_1024:
            SET_BIT(TCCR0, CS00);
            CLEAR_BIT(TCCR0, CS01);
            SET_BIT(TCCR0, CS02);
            break;

    }
}

void Timer0_DeInit(void) {
    CLEAR_BIT(TCCR0, CS00);
    CLEAR_BIT(TCCR0, CS01);
    CLEAR_BIT(TCCR0, CS02);
}

void Timer0_SetValue(uint8 Timer0_InitValue) {
    TCNT0 = Timer0_InitValue;
}

TIMER0_Status Timer0_GetStatus(void) {
    if (BIT_IS_SET(TIFR, TOV0)) {
        return TIMER0_STATUS_OVERFLOW;
    } else if (BIT_IS_SET(TIFR, OCF0)) {
        return TIMER0_STATUS_COMPARE_MATCH;
    }
	return TIMER0_ERROR;
}

void Timer0_SetDelay(uint32 delay_ms) {
    // Assuming a prescaler value of 1024.
    uint8 overflow_counter = 0;
	uint16 num_of_overflows = 0;
    double timer_period = 0.001024;
    uint32 total_ticks = delay_ms / (timer_period * 1000);
    if (delay_ms < 256) {
        uint32 timer0_init_value = 256 - (total_ticks % 256);
        TCNT0 = timer0_init_value;
        while (BIT_IS_CLEAR(TIFR, TOV0)) {
            // Wait.
        }
        SET_BIT(TIFR, TOV0);
    } else if (delay_ms > 256) {
        num_of_overflows = total_ticks / 256;
        while (overflow_counter < num_of_overflows) {
            while (BIT_IS_CLEAR(TIFR, TOV0)) {
                // Wait.
            }
            SET_BIT(TIFR, TOV0);
            overflow_counter++;
        }
    }
}

void Timer0_Int_Callback(void(*p_func)(void)) {
    p_IntCallbackFunc = p_func;
}

ISR(TIMER0_OVF_INT) {
    p_IntCallbackFunc();
}