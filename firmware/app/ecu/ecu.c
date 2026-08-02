#include "ecu.h"
#include "logger.h"
#include "fault_manager.h"
#include "temperature_sensor.h"
#include "cooling.h"
#include "fan.h"
#include "can.h"
#include "system.h"
#include "socket_server.h"
#include <stdio.h>

void ECU_Init(void)
{
    Logger_Init();
    Logger_LogInfo("ECU Initialization");
    FaultManager_Init();
    Logger_LogInfo("Configuration Loaded");
    Cooling_Init();
    TemperatureSensor_Init();
    Fan_Init();
    CAN_Init();
    SocketServer_Init();

}

void ECU_Start(void)
{
    Logger_LogInfo("ECU Started");
    int temperature;

while(1)
{
    temperature = TemperatureSensor_Read();

    Cooling_Update(temperature);

    CAN_Frame_t frame;

    frame.id = 0x100;
    frame.dlc = 3;
    frame.data[0] = temperature;
    frame.data[1] = Fan_GetSpeed();
    frame.data[2] = FaultManager_GetCurrentFault();

    CAN_Send(&frame);

    // Send data to Python Dashboard
    char message[64];

    sprintf(
        message,
        "%d,%d,%d\n",
        temperature,
        Fan_GetSpeed(),
        FaultManager_GetCurrentFault()
    );

    SocketServer_Send(message);

    System_DelayMs(100);
}

}

void ECU_Run(void)
{
    Logger_LogInfo("ECU Running");
}
