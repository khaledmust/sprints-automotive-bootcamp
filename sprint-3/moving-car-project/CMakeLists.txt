cmake_minimum_required(VERSION 3.25)
project(moving_car_project C)

set(CMAKE_C_STANDARD 11)

include_directories(moving-car-project/ECUAL/LED)
include_directories(moving-car-project/ECUAL/Motor)
include_directories(moving-car-project/ECUAL/Push_Button)
include_directories(moving-car-project/MCAL/DIO)
include_directories(moving-car-project/MCAL/Timer)
include_directories(moving-car-project/Utilities)

add_executable(moving_car_project
        moving-car-project/ECUAL/LED/led.c
        moving-car-project/ECUAL/LED/led.h
        moving-car-project/ECUAL/Motor/motor.c
        moving-car-project/ECUAL/Motor/motor.h
        moving-car-project/ECUAL/Push_Button/push_button.c
        moving-car-project/ECUAL/Push_Button/push_button.h
        moving-car-project/MCAL/DIO/dio.c
        moving-car-project/MCAL/DIO/dio.h
        moving-car-project/MCAL/Timer/timer.c
        moving-car-project/MCAL/Timer/timer.h
        moving-car-project/Utilities/common_macros.h
        moving-car-project/Utilities/registers.h
        moving-car-project/Utilities/std_types.h
        moving-car-project/main.c moving-car-project/Application/led_sequence.c)
