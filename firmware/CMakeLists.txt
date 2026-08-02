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
    hal/temperature_sensor/temperature_sensor.c
    hal/fan/fan.c
    drivers/can/can.c
    hal/system/system.c
    communication/socket_server.c
)

target_include_directories(
    virtual_ecu
    PRIVATE
        services/logger
        app/ecu
        services/config
        services/fault_manager
        app/cooling
        hal/temperature_sensor
        hal/fan
        drivers/can
        hal/system
        communication
        
)
if(WIN32)
    target_link_libraries(virtual_ecu ws2_32)
endif()