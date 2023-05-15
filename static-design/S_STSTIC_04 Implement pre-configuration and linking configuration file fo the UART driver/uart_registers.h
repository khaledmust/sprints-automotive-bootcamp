#define UDR *((volatile uint8 *)0x2C) ///<
#define UCSRA *((volatile uint8 *)0x2B) ///<
#define UCSRB *((volatile uint8 *)0x2A) ///<
#define UCSRC *((volatile uint8 *)0x40) ///<
#define UBRRH *((volatile uint8 *)0x40) ///<
#define UBRRL *((volatile uint8 *)0x29) ///<

/**
 * @defgroup UCSRA USART contorl and status register A
 * @{
 */
#define MPCM 0 ///< (R/W) Multi-processor communication mode. (All incoming frames received by the RX that don't contain address information will be ignored).
#define U2X 1 ///< (R/W) Double transmission speed.
#define PE 2 ///< (R) Parity error.
#define DOR 3 ///< (R) Data over run error.
#define FE 4 ///< (R) Frame error.
#define UDRE 5 ///< (R) USART data registry error.
#define TXC 6 ///< (R) USART transmit complete flag.
#define RXC 7 ///< (R) USART receive complete flag.
/**@}*/

/**
 * @defgroup UCSRB USART control and status register B
 * @{
 */
#define TXB8 0 ///< (R/W) The ninth bit to be transmitted.
#define RXB8 1 ///< (R) The ninth bit to be received.
#define UCSZ2 2 ///< (R/W) Character size.
#define TXEN 3 ///< (R/W) Transmitter enable.
#define RXEN 4 ///< (R/W) Receiver enable.
#define UDRIE 5 ///< (R/W) Empty interrupt enable.
#define TXCIE 6 ///< (R/W) TX complete interrupt enable.
#define RXCIE 7 ///< (R/W) RX complete interrupt enable.
/**@}*/

/**
 * @defgroup UCSRC USART control and status register C
 * @{
 */
#define UCPOL 0 ///< (R/W) Clock polarity.
#define UCSZ0 1 ///< (R/W) Character size.
#define UCSZ1 2 ///< (R/W) Character size.
#define USBS 3 ///< (R/W) Stop bit size.
#define UPM0 4 ///< (R/W) Parity mode.
#define UMP1 5 ///< (R/W) Parity mode.
#define UMSEL 6 ///< (R/W) USART mode select.
#define URSEL 7 ///< (R/W) USART register select.
/**@}*/