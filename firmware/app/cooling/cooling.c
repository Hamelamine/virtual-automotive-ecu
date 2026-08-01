#include "cooling.h"
#include "config.h"
#include "logger.h"
#include "fault_manager.h"
#include "fan.h"

void Cooling_Init(void)
{
    Logger_LogInfo("Cooling Module Initialized");
}

void Cooling_Update(int temperature)
{
    if (temperature < 0)
    {
        FaultManager_Report(FAULT_SENSOR_FAILURE);
        return;
    }

    if (temperature >= CRITICAL_TEMPERATURE)
    {
        FaultManager_Report(FAULT_OVERTEMPERATURE);
        Fan_SetSpeed(100);
        return;
    }

    if (temperature >= FAN_ON_TEMPERATURE)
    {
        if (Fan_GetSpeed() == 0)
        {
            Fan_SetSpeed(100);
            Logger_LogInfo("Fan Turned ON");
        }
    }
    else if (temperature <= FAN_OFF_TEMPERATURE)
    {
        if (Fan_GetSpeed() != 0)
        {
            Fan_SetSpeed(0);
            Logger_LogInfo("Fan Turned OFF");
        }
    }
}

int Cooling_GetFanSpeed(void)
{
    return Fan_GetSpeed();
}