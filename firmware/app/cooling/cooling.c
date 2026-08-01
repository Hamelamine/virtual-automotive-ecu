#include "cooling.h" 
#include "config.h" 
#include "logger.h" 
#include "fault_manager.h" 
static int fanOn = 0; 
void Cooling_Init(void) { fanOn = 0; 
    Logger_LogInfo("Cooling Module Initialized"); } 
void Cooling_Update(int temperature) { 
    if(temperature < 0)
{
    FaultManager_Report(FAULT_SENSOR_FAILURE);
    return;
}
    if (temperature >= CRITICAL_TEMPERATURE) { 
        FaultManager_Report(FAULT_OVERTEMPERATURE); 
        fanOn = 1; return; } 
    if (temperature >= FAN_ON_TEMPERATURE) { 
        if (!fanOn) { 
            fanOn = 1; 
            Logger_LogInfo("Fan Turned ON"); } 
        } 
        else if (temperature <= FAN_OFF_TEMPERATURE) { 
            if (fanOn) { 
                fanOn = 0; 
                Logger_LogInfo("Fan Turned OFF"); } 
            } 
        } 
int Cooling_IsFanOn(void) { return fanOn; }