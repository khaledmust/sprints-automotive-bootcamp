#ifndef MOVING_CAR_SYSTEM_PUSH_BUTTON_H
#define MOVING_CAR_SYSTEM_PUSH_BUTTON_H

#include "../../MCAL/DIO/dio.h"
#include "../../Utilities/common_macros.h"

typedef enum EN_PB_API_STATE {
    PB_SUCCESS = 0, PB_PORT_INVALID, PB_DIRECTION_INVALID
}EN_PB_API_STATE;

/**
 * @struct PB_Init_t
 * @var PB_Init_t::port
 * Member 'port' specifies the port which the push button is connected to.
 * @var PB_Init::pin
 * Member 'pin' specifies the pin number which the push button is connected to.
 */
typedef struct PB_Init_t {
    EN_DIO_PORT port;
    EN_DIO_PIN pin;
    uint8 pb_status;
}PB_Init_t;

/**
 * @enum EN_PB_LEVEL
 * @brief Specifies the state of push button.
 */
typedef enum EN_PB_LEVEL {
    PB_LOW = 0, PB_HIGH
}EN_PB_LEVEL;

/**
 * @brief Initializes the state of the pin connected to the push button.
 * @param[in] p_config_struct Address of the configuration structure.
 */
EN_PB_API_STATE PB_Init(PB_Init_t *p_pb_config_struct);

/**
 * @brief Reads the current state of the push button.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return The current state of the push button.
 */
EN_PB_API_STATE PB_ReadState(PB_Init_t *p_pb_config_struct);

#endif //MOVING_CAR_SYSTEM_PUSH_BUTTON_H
