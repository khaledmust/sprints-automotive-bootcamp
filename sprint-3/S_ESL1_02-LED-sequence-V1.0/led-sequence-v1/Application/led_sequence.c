#include "led_sequence.h"

LED_Init_t LED0 = {PORT_A, PIN0, LED_OFF};
LED_Init_t LED1 = {PORT_A, PIN1, LED_OFF};
LED_Init_t LED2 = {PORT_A, PIN2, LED_OFF};
LED_Init_t LED3 = {PORT_A, PIN3, LED_OFF};

PB_Init_t PB0 = {PORT_A, PIN4, PB_HIGH};

uint8 counter = 0;

void APP_Init() {

	LED_Init(&LED0);
	LED_Init(&LED1);
	LED_Init(&LED2);
	LED_Init(&LED3);

	PB_Init(&PB0);
}

void APP_Start() {
    PB_ReadState(&PB0);
    if (PB0.pb_status == PB_HIGH) {
        if (counter <= 3) {
            switch (counter) {
                case 0:
					LED0.led_status = LED_ON;
                    LED_On(&LED0);
					while (PB0.pb_status == PB_HIGH) {
						PB_ReadState(&PB0);
					}
                    break;
                case 1:
					LED1.led_status = LED_ON;
                    LED_On(&LED1);
					while (PB0.pb_status == PB_HIGH) {
						PB_ReadState(&PB0);
					}
                    break;
                case 2:
					LED2.led_status = LED_ON;
                    LED_On(&LED2);
					while (PB0.pb_status == PB_HIGH) {
						PB_ReadState(&PB0);
					}
                    break;
                case 3:
					LED3.led_status = LED_ON;
                    LED_On(&LED3);
					while (PB0.pb_status == PB_HIGH) {
						PB_ReadState(&PB0);
					}
                    break;
            }
            counter++;
        } else if (counter > 3 && counter < 8) {
            uint8 led_num = counter - 4;
            switch (led_num) {
                case 0:
					LED0.led_status = LED_OFF;
                    LED_Off(&LED0);
					while (PB0.pb_status == PB_HIGH) {
						PB_ReadState(&PB0);
					}
                    break;
                case 1:
					LED1.led_status = LED_OFF;
                    LED_Off(&LED1);
					while (PB0.pb_status == PB_HIGH) {
						PB_ReadState(&PB0);
					}
                    break;
                case 2:
					LED2.led_status = LED_OFF;
                    LED_Off(&LED2);
					while (PB0.pb_status == PB_HIGH) {
						PB_ReadState(&PB0);
					}
                    break;
                case 3:
					LED3.led_status = LED_OFF;
                    LED_Off(&LED3);
					while (PB0.pb_status == PB_HIGH) {
						PB_ReadState(&PB0);
					}
                    break;
            }
            counter++;
        } else {
            counter = 0;
        }
    } else {
        while (PB0.pb_status == PB_LOW) {
            PB_ReadState(&PB0);
        }
    }
}