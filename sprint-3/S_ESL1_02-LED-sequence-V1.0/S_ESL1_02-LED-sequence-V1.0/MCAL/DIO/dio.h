
#ifndef MOVING_CAR_SYSTEM_DIO_H
#define MOVING_CAR_SYSTEM_DIO_H

#include "../../Utilities/registers.h"
#include "../../Utilities/std_types.h"
#include "../../Utilities/common_macros.h"

/**
 * @enum EN_DIO_ERROR_STATE
 * @brief Defines the state of DIO functions.
 */
typedef enum EN_DIO_ERROR_STATE {
    DIO_SUCCESS = 0, DIO_PORT_INVALID, DIO_DIRECTION_INVALID, DIO_PIN_INVALID
}EN_DIO_ERROR_STATE;

/**
 * @enum EN_DIO_DIRECTION
 * @brief Specifies the state of the pin.
 */
typedef enum EN_DIO_DIRECTION {
    DIO_INPUT = 0, DIO_OUTPUT
}EN_DIO_DIRECTION;

/**
 * @enum EN_DIO_PIN
 * @brief Specifies the number of pin.
 */
typedef enum EN_DIO_PIN {
   PIN0 = 0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7, PIN8
}EN_DIO_PIN;

/**
 * @enum EN_DIO_PORT
 * @brief Specifies the port number.
 * the port number and returns the address of the corresponding port.
 */
typedef enum EN_DIO_PORT {
    PORT_A = 0, PORT_B, PORT_C, PORT_D
}EN_DIO_PORT;

/**
 * @enum EN_DIO_LEVEL
 * @brief Specifies the level of the pin.
 */
typedef enum EN_DIO_LEVEL {
    DIO_LOW = 0, DIO_HIGH
}EN_DIO_LEVEL;

/**
 * @struct DIO_Init_t
 * @brief Holds the configuration of a specific pin of a port.
 * @var DIO_Init_t::port
 * Member 'port' sets the port to be configured.
 * @var DIO_Init_t::pin
 * Member 'pin' sets the pin to be configured.
 * @var DIO_Init_t::direction
 * Member 'direction' sets the direction of the pin.
 * @var DIO_Init_t::pin_value
 * Member 'pin_value; contains the value of the pin when it's configured as input mode.
 * @var DIO_Init_t::port_value
 * Member 'port_value' contains the value to be written to the port register if the pin is configured as output.
 */
typedef struct DIO_Init_t {
    EN_DIO_PORT port;
    EN_DIO_PIN pin;
    EN_DIO_DIRECTION direction;
    union {
        uint8 pin_value;
        uint8 port_value;
    };
}DIO_Init_t;

/**
 * @brief Initializes the direction of the specified pin.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return DIO_PORT_INVALID Port in invalid.
 * @return DIO_SUCCESS The pin initialization is a success.
 */
EN_DIO_ERROR_STATE DIO_Init(DIO_Init_t *p_config_struct);

/**
 * @brief Reads the state of a specific pin.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return DIO_PORT_INVALID Port is invalid.
 * @return DIO_DIRECTION_INVALID Reading from a pin that is configured as output.
 * @return DIO_SUCCESS The read operation is a success.
 */
EN_DIO_ERROR_STATE DIO_ReadPin(DIO_Init_t *p_config_struct);

/**
 * @brief Write a specific level to a specified pin.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return DIO_PORT_INVALID Port is invalid.
 * @return DIO_DIRECTION_INVALID Writing to a pin that is configured as input.
 * @return DIO_SUCCESS The write operation is a success.
 */
EN_DIO_ERROR_STATE DIO_WritePin(DIO_Init_t *p_config_struct);

/**
 * @brief Toggles the current level of a pin.
 * @param[in] p_config_struct Address of the configuration structure.
 *  @return DIO_PORT_INVALID Port is invalid.
 * @return DIO_DIRECTION_INVALID Toggle a pin that is configured as input.
 * @return DIO_SUCCESS The toggle operation is a success.
 */
EN_DIO_ERROR_STATE DIO_TogglePin(DIO_Init_t *p_config_struct);

#endif //MOVING_CAR_SYSTEM_DIO_H
