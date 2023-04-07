#include "push_button.h"


EN_PB_API_STATE PB_Init(PB_Init_t *p_pb_config_struct) {
    DIO_Init_t pb_config = {p_pb_config_struct -> port,
                             p_pb_config_struct -> pin,
                             DIO_INPUT};
    DIO_Init(&pb_config);
    return PB_SUCCESS;
}

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