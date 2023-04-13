cmake_minimum_required(VERSION 3.25)
project(S_ESL1_04_LED_sequence_V3_0 C)

set(CMAKE_C_STANDARD 11)

include_directories(Application)
include_directories(ECUAL/LED)
include_directories(ECUAL/Push_Button)
include_directories(Interrupts_Library)
include_directories(MCAL/DIO)
include_directories(MCAL/Timers)
include_directories(Utilities)

add_executable(S_ESL1_04_LED_sequence_V3_0
        Application/led_sequence.c
        Application/led_sequence.h
        ECUAL/LED/led.c
        ECUAL/LED/led.h
        ECUAL/Push_Button/push_button.c
        ECUAL/Push_Button/push_button.h
        Interrupts_Library/external_interrupts.c
        Interrupts_Library/external_interrupts.h
        Interrupts_Library/interrupts_library.h
        MCAL/DIO/dio.c
        MCAL/DIO/dio.h
        MCAL/Timers/timers.c
        MCAL/Timers/timers.h
        Utilities/common_macros.h
        Utilities/registers.h
        Utilities/std_types.h
        main.c)
