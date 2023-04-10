#include "led.h"

/**
 * @brief Initializes the pin attached to the LED.
 * - The function declares a DIO_Init_t variable and extract the port and the pin from the p_led_config_struct,
 * with a constant value for the 'direction' member as DIO_OUTPUT.
 * - Then it calls DIO_Init function.
 * - The initial status of the LED is then checked and accordingly it's set.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return LED_SUCCESS Initialization is done successfully.
 */
EN_LED_API_STATE LED_Init(LED_Init_t *p_led_config_struct) {
    DIO_Init_t led_config = {p_led_config_struct -> port,
                      p_led_config_struct -> pin,
                      DIO_OUTPUT};
    DIO_Init(&led_config);
	
	if (p_led_config_struct ->led_status == LED_ON) {
		LED_On(p_led_config_struct);
	} else if (p_led_config_struct -> led_status == LED_OFF) {
		LED_Off(p_led_config_struct);
	}
    return LED_SUCCESS;
}

/**
 *
 * @param p_led_config_struct
 * The function first checks if the status of the led, an accordingly turns on the LED.
 * @return LED_PORT_INVALID
 * @return LED_STATUS_INVALID
 * @return LED_SUCCESS
 */
EN_LED_API_STATE LED_On(LED_Init_t *p_led_config_struct) {
    uint8 port_num = p_led_config_struct -> port;
    if (p_led_config_struct -> led_status == LED_ON) {
        switch (port_num) {
            case PORT_A:
                SET_BIT(PORTA, p_led_config_struct -> pin);
                break;
            case PORT_B:
                SET_BIT(PORTB, p_led_config_struct -> pin);
                break;
            case PORT_C:
                SET_BIT(PORTC, p_led_config_struct -> pin);
                break;
            case PORT_D:
                SET_BIT(PORTD, p_led_config_struct -> pin);
                break;
            default:
                return LED_PORT_INVALID;
        }
    } else {
        return LED_STATUS_INVALID;
    }
    return LED_SUCCESS;
}

/**
 *
 * @param p_led_config_struct
 * The function first checks if the status of the led, an accordingly turns on the LED.
 * @return LED_PORT_INVALID
 * @return LED_STATUS_INVALID
 * @return LED_SUCCESS
 */
EN_LED_API_STATE LED_Off(LED_Init_t *p_led_config_struct) {
    uint8 port_num = p_led_config_struct -> port;
    if (p_led_config_struct -> led_status == LED_OFF) {
        switch (port_num) {
            case PORT_A:
                CLEAR_BIT(PORTA, p_led_config_struct -> pin);
                break;
            case PORT_B:
                CLEAR_BIT(PORTB, p_led_config_struct -> pin);
                break;
            case PORT_C:
                CLEAR_BIT(PORTC, p_led_config_struct -> pin);
                break;
            case PORT_D:
                CLEAR_BIT(PORTD, p_led_config_struct -> pin);
                break;
            default:
                return LED_PORT_INVALID;
        }
    } else {
        return LED_STATUS_INVALID;
    }
    return LED_SUCCESS;
}
