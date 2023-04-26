/*
 * timers.h
 *
 * Created: 2023-04-12 11:58:03 AM
 *  Author: khale
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

#include "../../Utilities/std_types.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/common_macros.h"
#include "../../Interrupts_Library/interrupts_library.h"


void (*p_IntCallbackFunc)(void);

/**
 * @enum TIMER0_WaveFormGeneration
 * @brief Specifies the PWM mode of operation for the timer.
 */
typedef enum {
	NORMAL_WG, PWM_WG, CTC_WG, FAST_PWM_WG	
}TIMER0_WaveFormGeneration;

/**
 * @enum TIMER0_ClockSelect
 * @brief Specifies the clock source to feed the timer.
 */
typedef enum {
	NO_CLK, F_CPU_CLK, F_CPU_8, F_CPU_64, F_CPU_256, F_CPU_1024	
}TIMER0_ClockSelect;

/**
 * @enum TIMER0_InterruptMode
 * @brief Specifies the interrupt mode for the timer.
 */
typedef enum {
	INTERRUPT_DISABLED, INTERRUPT_OVERFLOW_ENABLED, INTERRUPT_COMPARE_MATCH_ENABLED, INTERRUPT_ENABLED
}TIMER0_InterruptMode;

/**
 * @enum TIMER0_Mode
 * @brief Specifies the mode of operation for Timer_0.
 */
typedef enum {
	TIMER0_OVERFLOW, TIMER0_COMPARE_TOGGLE, TIMER0_COMPARE_CLEAR, TIMER0_COMPARE_SET
}TIMER0_Mode;

/**
 * @enum TIMER0_Status
 * @brief Specifies the state of the timer.
 */
typedef enum {
    TIMER0_STATUS_OVERFLOW, TIMER0_STATUS_COMPARE_MATCH, TIMER0_ERROR
}TIMER0_Status;

/**
 * @struct TIMER0_Config
 * @brief Holds the user's configuration for Timer_0.
 * @var TIMER0_Config::timerMode
 * Member 'timerMode' specifies the mode of operation for the timer.
 * @var TIMER0_Config::timerClock
 * Member 'timerClcok' specifies the clock source of the timer.
 * @var TIMER0_Config::timerWaveGeneration
 * Member 'timerWaveGeneration' specifies the
 * @var TIMER0_Config::TIMER0_InitValue
 * Member 'TIMER0_InitValue' specifies the initial loaded value of the timer.
 * @var TIMER0_Config::TIMER0_CompareValue
 * Member 'TIMER0_CompareValue' specifies the compare value which the timer will compare to.
 * @var TIMER0_Config::InterruptMode
 * Member 'InterruptMode' specifies the interrupt mode of the timer.
 */
typedef struct {
	TIMER0_Mode timerMode;
	TIMER0_ClockSelect timerClock;
	TIMER0_WaveFormGeneration timerWaveGeneration;
	uint8 TIMER0_InitValue;
	uint8 TIMER0_CompareValue;
	TIMER0_InterruptMode InterruptMode;
}TIMER0_Config;

/**
 * @brief Initialize Timer0 with the user configuration and starts the timer.
 * @param TIMER0_UserConfig
 */
void Timer0_Init(TIMER0_Config *TIMER0_UserConfig);

/**
 * @brief Disables Timer0 by disengage of the clock source.
 */
void Timer0_DeInit(void);

/**
 * @brief Sets an initial value for Timer0 to start counting from.
 * @param Timer0_InitValue The value to be loaded to Timer0.
 */
void Timer0_SetValue(uint8 Timer0_InitValue);

/**
 * @brief Gets the overflow and compare status of Timer0.
 * @return TIMER0_STATUS_OVERFLOW
 * @return TIMER0_STATUS_COMPARE_MATCH
 */
TIMER0_Status Timer0_GetStatus(void);

/**
 * @brief Sets a delay assuming that the prescaler value is 1024.
 * @param delay_ms The amount of time is mSec.
 */
void Timer0_SetDelay(uint32 delay_ms);

/**
 * @brief Sets the call-back function when Timer0 triggers an interrupt.
 * @param p_func Address of the function to be executed when an interrupt is triggered.
 */
void Timer0_Int_Callback(void(*p_func)(void));

#endif /* TIMERS_H_ */