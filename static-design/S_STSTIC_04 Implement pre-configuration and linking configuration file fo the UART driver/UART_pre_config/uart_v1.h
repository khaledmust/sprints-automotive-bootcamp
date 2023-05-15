#ifndef UART_H_
#define UART_H_

#include "std_types.h"


 /* Select device role:
  * Option 1: TRANSMITTER
  * Option 2: RECEIVER
  * Option 3: TRANCEIVER
  */
#define  DEVICE_ROLE TRANSMITTER

 /* Select speed mode:
  * Option 1: NORMAL_SPEED
  * Option 2: DOUBLE_SPEED
  */
#define UART_TRANSMISSION_SPEED	NORMAL_SPEED


/* Select CPU frequency: 
 * Option 1: _4_MHZ
 * Option 2: _8_MHZ
 * Option 3: _16_MHZ
 */
#define F_CPU _16_MHZ

/* Select the baud rate: 
 * Option 1: BAUD_2400
 * Option 2: BAUD_4800
 * Option 3: BAUD_9600
 * Option 4: BAUD_14400
 * Option 5: BAUD_19200
 * Option 6: BAUD_28800
 */
#define UART_BAUD_RATE BAUD_9600

/* Select USAT operation mode:
 * Option 1: ASYNC
 * Option 2: SYNC
 */
#define SYNC_MODE ASYNC

 /* Select parity mode:
 * Option 1: NO_PARITY
 * Option 2: EVEN_PARITY
 * Option 3: ODD_PARITY
 */
#define PARITY_MODE NO_PARITY

 /* Select character size:
  * Option 1: _5_DATA_BITS
  * Option 2: _6_DATA_BITS
  * Option 3: _7_DATA_BITS
  * Option 4: _8_DATA_BITS
  * Option 5: _9_DATA_BITS
  */
#define  N_DATA_BITS _8_DATA_BITS

 /* Selcet number of stop bits:
  * Option 1: ONE_STOP_BIT
  * Option 2: TWO_STOP_BIT
  */
#define   N_STOP_BITS ONE_STOP_BIT

/*----------------------------------------------------------------------*/

#endif /* UART_H_ */