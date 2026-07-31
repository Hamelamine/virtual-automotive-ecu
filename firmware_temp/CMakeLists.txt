cmake_minimum_required(VERSION 3.20)

project(VirtualECU
        VERSION 1.0
        LANGUAGES C)

set(CMAKE_C_STANDARD 11)

add_executable(
    virtual_ecu
    src/main.c
)