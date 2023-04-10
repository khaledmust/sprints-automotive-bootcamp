#include "led_sequence.h"

LED_Init_t LED0 = {PORT_A, PIN0, LED_OFF};
LED_Init_t LED1 = {PORT_A, PIN1, LED_OFF};
LED_Init_t LED2 = {PORT_A, PIN2, LED_OFF};
LED_Init_t LED3 = {PORT_A, PIN3, LED_OFF};

PB_Init_t PB0 = {PORT_D, PIN2, PB_LOW};

INT_ExtInit_t PushButton_Int = {INT0, RISING_EDGE};

uint8 counter = 0;

ISR(EXT_INT0) {
    if (counter < 8) {
        counter++;
    } else {
        counter = 1;
    }
}

void APP_Init() {

	LED_Init(&LED0);
	LED_Init(&LED1);
	LED_Init(&LED2);
	LED_Init(&LED3);

	PB_Init(&PB0);
	
	INT_ExtInterruptInit(&PushButton_Int);
}

void APP_Start() {
    switch (counter) {
        case 1:
            LED0.led_status = LED_ON;
            LED_On(&LED0);
            while (PB0.pb_status == PB_HIGH) {
                PB_ReadState(&PB0);
            }
            break;
        case 2:
            LED1.led_status = LED_ON;
            LED_On(&LED1);
            while (PB0.pb_status == PB_HIGH) {
                PB_ReadState(&PB0);
            }
            break;
        case 3:
            LED2.led_status = LED_ON;
            LED_On(&LED2);
            while (PB0.pb_status == PB_HIGH) {
                PB_ReadState(&PB0);
            }
            break;
        case 4:
            LED3.led_status = LED_ON;
            LED_On(&LED3);
            while (PB0.pb_status == PB_HIGH) {
                PB_ReadState(&PB0);
            }
            break;
        case 5:
            LED0.led_status = LED_OFF;
            LED_Off(&LED0);
            while (PB0.pb_status == PB_HIGH) {
                PB_ReadState(&PB0);
            }
            break;
        case 6:
            LED1.led_status = LED_OFF;
            LED_Off(&LED1);
            while (PB0.pb_status == PB_HIGH) {
                PB_ReadState(&PB0);
            }
            break;
        case 7:
            LED2.led_status = LED_OFF;
            LED_Off(&LED2);
            while (PB0.pb_status == PB_HIGH) {
                PB_ReadState(&PB0);
            }
            break;
        case 8:
            LED3.led_status = LED_OFF;
            LED_Off(&LED3);
            while (PB0.pb_status == PB_HIGH) {
                PB_ReadState(&PB0);
            }
            break;
        default:
		;
            /* Do nothing. */
    }
}