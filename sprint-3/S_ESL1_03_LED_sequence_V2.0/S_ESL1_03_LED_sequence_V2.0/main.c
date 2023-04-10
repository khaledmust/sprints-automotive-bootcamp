/**
* @file main.c
* @brief This application turns on and then turns off LED sequentially.
* @author Khaled Mustafa
* @version 1.0
* @date 2023/04/08
*
*/

#include "Utilities/common_macros.h"
#include "Application/led_sequence.h"
#include "Interrupts_Library/external_interrupts.h"


int main(void) {
	
	//INT_UnitTest();
	
	APP_Init();
	
	while (1)
	{
		APP_Start();
	}
}


