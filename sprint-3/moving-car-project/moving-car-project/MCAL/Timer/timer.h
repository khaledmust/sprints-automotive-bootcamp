//
// Created by khale on 2023-04-05.
//

#ifndef MOVING_CAR_SYSTEM_TIMER_H
#define MOVING_CAR_SYSTEM_TIMER_H

#include "../../Utilities/registers.h"
#include "../../Utilities/std_types.h"
#include "../../Utilities/common_macros.h"

typedef enum
{
    NORMAL_WG, PWM_WG, CTC_WG, FAST_PWM_WG
}TIMER0_WaveFormGeneration;

/* Clock Selection. */
typedef enum
{
    NO_CLOCK, F_CPU_CLOCK, F_CPU_8, F_CPU_64, F_CPU_256, F_CPU_1024
}TIMER0_ClockSelect;

typedef enum
{
    INTERRUPT_DISABLED, INTERRUPT_ENABLED
}TIMER0_InterruptMode;

typedef enum
{
    TIMER0_OVERFLOW, TIMER0_COMPARE
}TIMER0_MODE;

/* Timer configuration structure. */
typedef struct
{
    TIMER0_MODE timerMode;
    TIMER0_ClockSelect timerClock;
    TIMER0_WaveFormGeneration timerWaveGeneration;
    uint8 TIMER0_Reg;
    uint8 TIMER0_CompareValue;
    TIMER0_InterruptMode InterruptMode;
}TIMER0_Config;

/* Initialize and start Timer0.
 * Global interrupt is enabled when interrupt mode is chosen.
 */
void Timer0_Init(TIMER0_Config *UserConfig);

/* De-initialize Timer0 registers and turn off the timer. */
void Timer0_DeInit(void);


void Timer0_setCallBack(void (*a_ptr) (void));

#endif //MOVING_CAR_SYSTEM_TIMER_H
