#ifndef MOVING_CAR_SYSTEM_MOTOR_H
#define MOVING_CAR_SYSTEM_MOTOR_H

#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/Timer/timer.h"
#include "../../Utilities/std_types.h"


/**
 * @struct MOTOR_Init_t
 * @var MOTOR_Init_t::port
 * Member 'port' specifies the port number that the motor is attached to.
 * @var MOTOR_Init_t::pin
 * Member 'pin' specifies the pin number that the motor is attached to.
 */
typedef struct MOTOR_Init_t {
    EN_DIO_PORT port;
    EN_DIO_PIN pin;
}MOTOR_Init_t;

/**
 * @enum EN_MOTOR_Direction
 * @brief Specifies the direction of rotation of the motor.
 */
typedef enum EN_MOTOR_Direction {
    CW = 0, CCW
}EN_MOTOR_Direction;

/**
 * @brief Initializes the state of the pin the motor is attached to.
 * @param p_config_struct[in] Address of the configuration structure.
 */
void MOTOR_Init(MOTOR_Init_t *p_config_struct);

/**
 * @brief Moves the motor in the forward direction.
 * @param p_config_struct[in] Address of the configuration structure.
 */
void MOTOR_Forward(MOTOR_Init_t *p_config_struct);

/**
 * @brief Stops the movement of the motors.
 * @param p_config_struct[in] Address of the configuration structure.
 */
void MOTOR_Stop(MOTOR_Init_t *p_config_struct);

/**
 * @brief Rotates the motor is the specified direction.
 * @param motor_direction Direction of the rotation.
 */
void MOTOR_Rotation(EN_MOTOR_Direction motor_direction);

/**
 * @brief Specifies the speed of the motor.
 * @param speed[in] The speed of the motor.
 */
void MOTOR_Speed(uint8 speed);

#endif //MOVING_CAR_SYSTEM_MOTOR_H
