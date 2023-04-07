/**
* @file main.c
* @brief This application turns on and then turns off LED sequentially.
* @author Khaled Mustafa
* @version 1.0
* @date 2023/04/08
*
*/



#include "Application/led_sequence.h"

int main(void) {
	APP_Init();
	
	while (1)
	{
		APP_Start();
	}
}


