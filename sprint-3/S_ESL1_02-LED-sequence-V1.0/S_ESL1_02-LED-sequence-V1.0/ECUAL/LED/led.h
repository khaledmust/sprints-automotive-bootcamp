#ifndef MOVING_CAR_SYSTEM_LED_H
#define MOVING_CAR_SYSTEM_LED_H

#include "../../MCAL/DIO/dio.h"

/**
 * @enum EN_LED_API_STATE
 * @brief Defines the state of LED functions.
 */
typedef enum EN_LED_API_STATE {
    LED_SUCCESS = 0, LED_PORT_INVALID, LED_STATUS_INVALID
}EN_LED_API_STATE;

/**
 * @enum EN_LED_STATUS
 * @brief Defines the LED status.
 */
typedef enum EN_LED_STATUS {
    LED_OFF = 0, LED_ON
}EN_LED_STATUS;

/**
 * @struct LED_Init_t
 * @brief Holds the port number and the pin number of the LED.
 * @var LED_Init_t::port
 * Member 'port' specifies the port number.
 * @var LED_Init_t::pin
 * Member 'pin' specifies the pin number.
 * @var LED_INIT_t::led_status
 * Member 'led_status' specifies the status of the LED.
 */
typedef struct LED_Init_t {
    EN_DIO_PORT port;
    EN_DIO_PIN pin;
    EN_LED_STATUS led_status;
}LED_Init_t;

/**
 * @brief Initializes the pin attached to the LED.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return LED_SUCCESS Initialization is done successfully.
 */
EN_LED_API_STATE LED_Init(LED_Init_t *p_led_config_struct);

/**
 * @brief Turns the LED on.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return LED_PORT_INVALID
 * @return LED_STATUS_INVALID
 * @return LED_SUCCESS
 */
EN_LED_API_STATE LED_On(LED_Init_t *p_led_config_struct);

/**
 * @brief Turns the LED off.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return LED_PORT_INVALID
 * @return LED_STATUS_INVALID
 * @return LED_SUCCESS
 */
EN_LED_API_STATE LED_Off(LED_Init_t *p_led_config_struct);

#endif //MOVING_CAR_SYSTEM_LED_H
