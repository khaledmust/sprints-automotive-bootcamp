
#ifndef MOVING_CAR_SYSTEM_REGISTERS_H
#define MOVING_CAR_SYSTEM_REGISTERS_H

#include <stdint.h>

/**
 * @defgroup AVR-Ports Port addresses
 * De-referenced addresses of ports.
 * @{
 */
#define PORTA *((uint8_t *)0x3B)
#define PORTB *((uint8_t *)0x38)
#define PORTC *((uint8_t *)0x35)
#define PORTD *((uint8_t *)0x32)
/**@}*/

/**
 * @defgroup AVR-Pins Pin addresses
 * De-referenced addresses of pins.
 * @{
 */
#define PINA *((uint8_t *)0x39)
#define PINB *((uint8_t *)0x36)
#define PINC *((uint8_t *)0x33)
#define PIND *((uint8_t *)0x30)
/**@}*/

/**
 * @defgroup AVR-DDR DDR addresses
 * De-referenced addresses of DDR.
 * @{
 */
#define DDRA *((uint8_t *)0x3A)
#define DDRB *((uint8_t *)0x37)
#define DDRC *((uint8_t *)0x34)
#define DDRD *((uint8_t *)0x31)
/**@}*/

#endif //MOVING_CAR_SYSTEM_REGISTERS_H
