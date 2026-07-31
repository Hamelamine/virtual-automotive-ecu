cmake_minimum_required(VERSION 3.20)

project(VirtualECU
        VERSION 1.0
        LANGUAGES C)

set(CMAKE_C_STANDARD 11)

add_executable(
    virtual_ecu

    src/main.c
    services/logger/logger.c
    app/ecu/ecu.c
    services/config/config.c
    services/fault_manager/fault_manager.c
    app/cooling/cooling.c
)

target_include_directories(
    virtual_ecu
    PRIVATE
        services/logger
        app/ecu
        services/config
        services/fault_manager
        app/cooling
        
)