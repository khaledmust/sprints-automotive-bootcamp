#include "push_button.h"

/**
 * @brief Initializes the state of the pin connected to the push button.
 * - The function declares a DIO_Init_t variable and extract the port and the pin from the p_pb_config_struct,
 * with a constant value for the 'direction' member as DIO_INPUT.
 * - Then it calls DIO_Init function.
 * @param[in] p_config_struct Address of the configuration structure.
 * @return PB_SUCCESS
 */
EN_PB_API_STATE PB_Init(PB_Init_t *p_pb_config_struct) {
    DIO_Init_t pb_config = {p_pb_config_struct -> port,
                             p_pb_config_struct -> pin,
                             DIO_INPUT};
    DIO_Init(&pb_config);
    return PB_SUCCESS;
}

/**
 * @brief Reads the current state of the push button.
 * The function works by reading the value of the specified bit from the PIN port
 * and then writes the state of that bit to the 'pb_status' member of the PB_Init_t.
 * @param[in/out] p_config_struct Address of the configuration structure.
 * @return PB_PORT_INVALID The selected port doesn't corresponds to the MCU ports.
 * @return PB_SUCCESS
 */
EN_PB_API_STATE PB_ReadState(PB_Init_t *p_pb_config_struct) {
    uint8 port_num = p_pb_config_struct -> port;
    switch (port_num) {
        case PORT_A:
            if (BIT_IS_SET(PINA, p_pb_config_struct -> pin)) {
                p_pb_config_struct -> pb_status = PB_HIGH;
            } else if (BIT_IS_CLEAR(PINA, p_pb_config_struct -> pin)) {
                p_pb_config_struct->pb_status = PB_LOW;
            }
            break;
        case PORT_B:
            if (BIT_IS_SET(PINB, p_pb_config_struct -> pin)) {
                p_pb_config_struct -> pb_status = PB_HIGH;
            } else if (BIT_IS_CLEAR(PINA, p_pb_config_struct -> pin)) {
                p_pb_config_struct->pb_status = PB_LOW;
            }
            break;
        case PORT_C:
            if (BIT_IS_SET(PINC, p_pb_config_struct -> pin)) {
                p_pb_config_struct -> pb_status = PB_HIGH;
            } else if (BIT_IS_CLEAR(PINA, p_pb_config_struct -> pin)) {
                p_pb_config_struct->pb_status = PB_LOW;
            }
            break;
        case PORT_D:
            if (BIT_IS_SET(PIND, p_pb_config_struct -> pin)) {
                p_pb_config_struct -> pb_status = PB_HIGH;
            } else if (BIT_IS_CLEAR(PINA, p_pb_config_struct -> pin)) {
                p_pb_config_struct->pb_status = PB_LOW;
            }
            break;
        default:
            return PB_PORT_INVALID;
    }
    return PB_SUCCESS;
}