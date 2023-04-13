#include "led_sequence.h"

LED_Init_t LED0 = {PORT_A, PIN0, LED_OFF};
LED_Init_t LED1 = {PORT_A, PIN1, LED_OFF};
LED_Init_t LED2 = {PORT_A, PIN2, LED_OFF};
LED_Init_t LED3 = {PORT_A, PIN3, LED_OFF};

PB_Init_t PB0 = {PORT_D, PIN2, PB_LOW};
PB_Init_t PB1 = {PORT_D, PIN3, PB_LOW};

INT_ExtInit_t PushButton_Int = {INT0, RISING_EDGE};
INT_ExtInit_t PushButton_Int1 = {INT1, RISING_EDGE};

TIMER0_Config Timer = {TIMER0_OVERFLOW, F_CPU_1024, NORMAL_WG, 0, 0, INTERRUPT_DISABLED};

uint8 counter = 0;
uint8 blink_counter = 1;
uint16 led_on_time = 0;
uint16 led_off_time = 0;

ISR(EXT_INT0) {
    if (counter < 8) {
        counter++;
    } else {
        counter = 1;
    }
}

ISR(EXT_INT1) {
    if (blink_counter < 5) {
        blink_counter++;
    } else {
        blink_counter = 1;
    }
}

void APP_Init() {

	LED_Init(&LED0);
	LED_Init(&LED1);
	LED_Init(&LED2);
	LED_Init(&LED3);

	PB_Init(&PB0);
    PB_Init(&PB1);
	
	INT_ExtInterruptInit(&PushButton_Int);
    INT_ExtInterruptInit(&PushButton_Int1);

    Timer0_Init(&Timer);
}
uint8 flag = 0;
void Blink(uint16 ON, uint16 OFF) {
    if (flag == 0) {
        Timer0_SetDelay(ON);
        flag = 1;
    } else {
        Timer0_SetDelay(OFF);
        flag = 0;
    }
}

void __LED_Blink(LED_Init_t *p_led_num, uint16 on_time, uint16 off_time) {
    p_led_num -> led_status = LED_ON;
    LED_On(p_led_num);
    Blink(on_time, off_time);
    p_led_num -> led_status = LED_OFF;
    LED_Off(p_led_num);
    Blink(on_time, off_time);
    while (PB0.pb_status == PB_HIGH) {
        PB_ReadState(&PB0);
    }
}

void APP_Start() {
    switch (counter) {
        case 1:
            __LED_Blink(&LED0, led_on_time, led_off_time);
            break;
        case 2:
            __LED_Blink(&LED0, led_on_time, led_off_time);
            __LED_Blink(&LED1, led_on_time, led_off_time);
            break;
        case 3:
            __LED_Blink(&LED0, led_on_time, led_off_time);
            __LED_Blink(&LED1, led_on_time, led_off_time);
            __LED_Blink(&LED2, led_on_time, led_off_time);
            break;
        case 4:
            __LED_Blink(&LED0, led_on_time, led_off_time);
            __LED_Blink(&LED1, led_on_time, led_off_time);
            __LED_Blink(&LED2, led_on_time, led_off_time);
            __LED_Blink(&LED3, led_on_time, led_off_time);
            break;
        case 5:
            LED0.led_status = LED_OFF;
            LED_Off(&LED0);
            __LED_Blink(&LED1, led_on_time, led_off_time);
            __LED_Blink(&LED2, led_on_time, led_off_time);
            __LED_Blink(&LED3, led_on_time, led_off_time);
            break;
        case 6:
            LED0.led_status = LED_OFF;
            LED_Off(&LED0);
            LED1.led_status = LED_OFF;
            LED_Off(&LED1);
            __LED_Blink(&LED2, led_on_time, led_off_time);
            __LED_Blink(&LED3, led_on_time, led_off_time);
            break;
        case 7:
            LED0.led_status = LED_OFF;
            LED_Off(&LED0);
            LED1.led_status = LED_OFF;
            LED_Off(&LED1);
            LED2.led_status = LED_OFF;
            LED_Off(&LED2);
            __LED_Blink(&LED3, led_on_time, led_off_time);
            break;
        case 8:
            LED0.led_status = LED_OFF;
            LED_Off(&LED0);
            LED1.led_status = LED_OFF;
            LED_Off(&LED1);
            LED2.led_status = LED_OFF;
            LED_Off(&LED2);
            LED3.led_status = LED_OFF;
            LED_Off(&LED3);
        default:
		;
            /* Do nothing. */
    }

    switch (blink_counter) {
        case 1:
            led_on_time = 100;
            led_off_time = 900;
            while (PB1.pb_status == PB_HIGH) {
                PB_ReadState(&PB1);
            }
            break;
        case 2:
            led_on_time = 200;
            led_off_time = 800;
            while (PB1.pb_status == PB_HIGH) {
                PB_ReadState(&PB1);
            }
            break;
        case 3:
            led_on_time = 300;
            led_off_time = 700;
            while (PB1.pb_status == PB_HIGH) {
                PB_ReadState(&PB1);
            }
            break;
        case 4:
            led_on_time = 500;
            led_off_time = 500;
            while (PB1.pb_status == PB_HIGH) {
                PB_ReadState(&PB1);
            }
            break;
        case 5:
            led_on_time = 800;
            led_off_time = 200;
            while (PB1.pb_status == PB_HIGH) {
                PB_ReadState(&PB1);
            }
            break;
        default:
            // Do nothing.
            ;
    }
}