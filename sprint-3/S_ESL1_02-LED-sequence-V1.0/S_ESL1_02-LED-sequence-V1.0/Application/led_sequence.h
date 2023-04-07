#ifndef LED_SEQUENCE_H_
#define LED_SEQUENCE_H_

#include "../Utilities/std_types.h"
#include "../ECUAL/LED/led.h"
#include "../ECUAL/Push_Button/push_button.h"


/**
 * @brief Initialize the push button and the 4 LEDs.
 */
void APP_Init();

/**
 * @brief Start the LED sequence application.
 */
void APP_Start();

#endif /* LED_SEQUENCE_H_ */