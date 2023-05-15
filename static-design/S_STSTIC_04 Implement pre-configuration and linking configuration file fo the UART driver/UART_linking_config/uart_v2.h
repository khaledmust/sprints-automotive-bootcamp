#ifndef UART_H_
#define UART_H_

/* Specifies the order of the devices that are using the USART. */
typedef enum {
	DEVICE_0,
	DEVICE_1,	   
	DEVICE_2,
    TOTAL_DEVICES
} en_UART_DEVICES_t;

/* Specifies the speed in which the frame to be sent with. */
typedef enum {
	NORMAL_SPEED,
	DOUBLE_SPEED
} en_UART_SPEED_MODE_t;

/* Specifies the frequency of the MCU. */
typedef enum {
	_4_MHZ,
	_8_MHZ,
	_16_MHZ
} en_UART_CPU_F_t;

/* Specifies the baud rate that is to be agreed upon the TX and the RX. */
typedef enum {
	BAUD_2400,
	BAUD_4800,
	BAUD_9600,
	BAUD_14400,
	BAUD_19200,
	BAUD_28800
} en_UART_BUAD_RATE_t;

/* Specifies the type of parity bit used for error recovery. */
typedef enum {
	NO_PARITY,
	EVEN_PARITY,
	ODD_PARITY
} en_UART_PARITY_MODE_t;

/* Specifies the mode of operation. */
typedef enum {
	ASYNC,
	SYNC
} en_UART_SYNCH_MODE_t;

/* Specifies the number of data bits to be sent in the frame. */
typedef enum {
	_5_DATA_BITS,
	_6_DATA_BITS,
	_7_DATA_BITS,
	_8_DATA_BITS,
	_9_DATA_BITS
} en_UART_N_DATA_BITS_t;

/* Specifies the number of stop bits in the frame. */
typedef enum {
	ONE_STOP_BIT,
	TWO_STOP_BIT
} en_UART_N_STOP_BITS_t;

/* Specifies the role of the device using the USART communication protocol. */
typedef enum {
	TRANSMITTER,
	RECEIVER,
	TRANSCEIVER
}en_UART_DEVICE_ROLE_t;

/* This sturcture holds the configuration of the USART device. */
typedef struct {
	en_UART_DEVICE_ROLE_t DEVICE_ROLE;
	en_UART_SPEED_MODE_t SPEED_MODE;
	en_UART_CPU_F_t CPU_F;
	en_UART_BUAD_RATE_t BUAD_RATE;
	en_UART_PARITY_MODE_t SYNCH_MODE;
	en_UART_SYNCH_MODE_t PARITY_MODE;
	en_UART_N_DATA_BITS_t N_DATA_BITS;
	en_UART_N_STOP_BITS_t N_STOP_BITS;	
} ST_UART_config;



#endif /* UART_H_ */