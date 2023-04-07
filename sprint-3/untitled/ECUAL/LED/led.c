#include "led.h"

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
        return LED_DIRECTION_INVALID;
    }
    return LED_SUCCESS;
}

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
        return LED_DIRECTION_INVALID;
    }
    return LED_SUCCESS;
}
