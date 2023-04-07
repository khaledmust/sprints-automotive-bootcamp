cmake_minimum_required(VERSION 3.25)
project(LED_sequence_v1_0 C)

set(CMAKE_C_STANDARD 99)

add_executable(LED_sequence_v1_0 main.c ECUAL/LED/led.c ECUAL/Push_Button/push_button.c MCAL/DIO/dio.c Application/led_sequence.c)
