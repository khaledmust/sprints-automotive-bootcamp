
/* Array of configuration structure fot the devices that uses UART Communication protocol. */
const ST_UART_config UART_config[TOTAL_DEVICES];


UART_config[DEVICE_0] = { 
 /* Select device role:
  * Option 1: TRANSMITTER
  * Option 2: RECEIVER
  * Option 3: TRANCEIVER
  */
	.Device_role = TRANSMITTER,

 /* Select speed mode:
  * Option 1: NORMAL_SPEED
  * Option 2: DOUBLE_SPEED
  */
	.SPEED_MODE = NORMAL_SPEED,

/* Select CPU frequency: 
 * Option 1: _4_MHZ
 * Option 2: _8_MHZ
 * Option 3: _16_MHZ
 */
    .CPU_F = _16_MHZ,	
	
/* Select the baud rate: 
 * Option 1: BAUD_2400
 * Option 2: BAUD_4800
 * Option 3: BAUD_9600
 * Option 4: BAUD_14400
 * Option 5: BAUD_19200
 * Option 6: BAUD_28800
 */
    .BUAD_RATE = BAUD_9600,
	 
/* Select USAT operation mode:
 * Option 1: ASYNC
 * Option 2: SYNC
 */
    .SYNCH_MODE = ASYNC,

 /* Select parity mode:
 * Option 1: NO_PARITY
 * Option 2: EVEN_PARITY
 * Option 3: ODD_PARITY
 */
    .PARITY_MODE = NO_PARITY, 

 /* Select character size:
  * Option 1: _5_DATA_BITS
  * Option 2: _6_DATA_BITS
  * Option 3: _7_DATA_BITS
  * Option 4: _8_DATA_BITS
  * Option 5: _9_DATA_BITS
  */
    .N_DATA_BITS = _8_DATA_BITS,

 /* Selcet number of stop bits:
  * Option 1: ONE_STOP_BIT
  * Option 2: TWO_STOP_BIT
  */
    .N_STOP_BITS = ONE_STOP_BIT
}