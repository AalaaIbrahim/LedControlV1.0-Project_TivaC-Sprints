cmake_minimum_required(VERSION 3.25)
project(shared C)

set(CMAKE_C_STANDARD 11)

include_directories(LED-V1.0)
include_directories(LED-V1.0/APP)
include_directories(LED-V1.0/LIB)
include_directories(LED-V1.0/RTE/_Target_1)
include_directories(LED-V1.0/RTE/Device)
include_directories(LED-V1.0/RTE/Device/TM4C123GH6PM)

add_executable(shared
        LED-V1.0/APP/app.c
        LED-V1.0/APP/app.h
        LED-V1.0/LIB/bit_math.h
        LED-V1.0/LIB/std.h
        LED-V1.0/RTE/_Target_1/RTE_Components.h
        LED-V1.0/RTE/Device/TM4C123GH6PM/system_TM4C123.c
        LED-V1.0/main.c)
