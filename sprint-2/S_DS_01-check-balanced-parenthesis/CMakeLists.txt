cmake_minimum_required(VERSION 3.24)
project(S_DS_01_check_balanced_parenthesis C)

set(CMAKE_C_STANDARD 99)

add_executable(S_DS_01_check_balanced_parenthesis main.c stack.h stack.c balanced.c balanced.h)
