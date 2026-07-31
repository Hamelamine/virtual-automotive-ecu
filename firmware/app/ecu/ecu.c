#include "ecu.h"
#include "logger.h"
#include "fault_manager.h"
#include "cooling.h"

void ECU_Init(void)
{
    Logger_Init();
    Logger_LogInfo("ECU Initialization");
    FaultManager_Init();
    Logger_LogInfo("Configuration Loaded");
    Cooling_Init();

}

void ECU_Start(void)
{
    Logger_LogInfo("ECU Started");
    int temperatures[] = {60, 68, 71, 75, 69, 64, 112}; 
    for (int i = 0; i < 7; i++) { 
        Cooling_Update(temperatures[i]); }

}

void ECU_Run(void)
{
    Logger_LogInfo("ECU Running");
}