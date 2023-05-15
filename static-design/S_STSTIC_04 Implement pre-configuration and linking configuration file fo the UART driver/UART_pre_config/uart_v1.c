#include "./uart_v1.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*
 * This is done by:
 * 1. Set the baud rate.
 * 2. Enable receiver and transmitter.
 * 3. Set frame format.
 */
void UART_init() {
	/* Calculate the UBRR register value */
	uint16 baud_rate;
#if (UART_BAUD_RATE == BAUD_2400)
	baud_rate = 2400;
#elif (UART_BAUD_RATE == BAUD_4800)
	baud_rate = 4800;
#elif (UART_BAUD_RATE == BAUD_9600)
	baud_rate = 9600;
#elif (UART_BAUD_RATE == BAUD_14400)
	baud_rate = 14400;
#elif (UART_BAUD_RATE == BAUD_19200)
	baud_rate = 19200;
#elif (UART_BAUD_RATE == BAUD_28800)
	baud_rate = 28800;
#endif

	uint16 ubrr_value = (uint16)(((F_CPU / (baud_rate * 8UL))) - 1);

	UBRRH = (uint8) (ubrr_value >> 8);
	UBRRL = (uint8) ubrr_value;
	
#if (DEVICE_ROLE == TRANSMITTER)
	SET_BIT(UCSRB, TXEN);
#elif (DEVICE_ROLE == RECEIVER)
	SET_BIT(UCSRB, RXEN);
#elif (DEVICE_ROLE == TRANCEIVER)
	SET_BIT(UCSRB, RXEN);
	SET_BIT(UCSRB, TXEN);
#endif

	
	/* Acessing UCSRC. */
	SET_BIT(UCSRC, URSEL);

#if (SYNC_MODE == ASYNC)
	CLEAR_BIT(UCSRC, UMSEL);
#elif (SYNC_MODE == SYNC)
	SET_BIT(UCSRC, UMSEL);
#endif
	
#if (PARITY_MODE == NO_PARITY) 
	CLEAR_BIT(UCSRC, UPM0);
	CLEAR_BIT(UCSRC, UPM1);
#elif (PARITY_MODE == EVEN_PARITY)
	CLEAR_BIT(UCSRC, UPM0);
	SET_BIT(UCSRC, UPM1);
#elif (PARITY_MODE == ODD_PARITY)
	SET_BIT(UCSRC, UPM0);
	SET_BIT(UCSRC, UPM1);
#endif

#if (N_STOP_BITS == ONE_STOP_BIT)
	SET_BIT(UCSRC, USBS);
#elif (N_STOP_BITS == TWO_STOP_BIT)
	CLEAR_BIT(UCSRC, USBS);
#endif
	

#if (N_DATA_BITS == _5_DATA_BITS)
	CLEAR_BIT(UCSRC, UCSZ0);
	CLEAR_BIT(UCSRC, UCSZ1);
	CLEAR_BIT(UCSRB, UCSZ2);
#elif (N_DATA_BITS == _6_DATA_BITS)
	SET_BIT(UCSRC, UCSZ0);
	CLEAR_BIT(UCSRC, UCSZ1);
	CLEAR_BIT(UCSRB, UCSZ2);
#elif (N_DATA_BITS == _7_DATA_BITS)
	CLEAR_BIT(UCSRC, UCSZ0);
	SET_BIT(UCSRC, UCSZ1);
	CLEAR_BIT(UCSRB, UCSZ2);
#elif (N_DATA_BITS == _8_DATA_BITS)
	SET_BIT(UCSRC, UCSZ0);
	SET_BIT(UCSRC, UCSZ1);
	CLEAR_BIT(UCSRB, UCSZ2);
#elif (N_DATA_BITS == _9_DATA_BITS)
	SET_BIT(UCSRC, UCSZ0);
	SET_BIT(UCSRC, UCSZ1);
	SET_BIT(UCSRB, UCSZ2);
#endif	
}