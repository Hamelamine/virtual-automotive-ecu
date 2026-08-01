#include "ecu.h"
#include "logger.h"
#include "fault_manager.h"
#include "temperature_sensor.h"
#include "cooling.h"

void ECU_Init(void)
{
    Logger_Init();
    Logger_LogInfo("ECU Initialization");
    FaultManager_Init();
    Logger_LogInfo("Configuration Loaded");
    Cooling_Init();
    TemperatureSensor_Init();

}

void ECU_Start(void)
{
    Logger_LogInfo("ECU Started");
    for(int i = 0; i < 20; i++)
    {
    int temperature = TemperatureSensor_Read();

    Cooling_Update(temperature);
    }

}

void ECU_Run(void)
{
    Logger_LogInfo("ECU Running");
}