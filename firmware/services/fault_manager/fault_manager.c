#include "fault_manager.h"
#include "logger.h"

static FaultCode_t currentFault = FAULT_NONE;

void FaultManager_Init(void)
{
    currentFault = FAULT_NONE;
    Logger_LogInfo("Fault Manager Initialized");
}

void FaultManager_Report(FaultCode_t fault)
{
    if(currentFault == fault)
    {
        return;
    }

    currentFault = fault;

    switch (fault)
    {
        case FAULT_OVERTEMPERATURE:
            Logger_LogError("Fault: Overtemperature");
            break;

        case FAULT_SENSOR_FAILURE:
            Logger_LogError("Fault: Sensor Failure");
            break;

        case FAULT_CAN_TIMEOUT:
            Logger_LogError("Fault: CAN Timeout");
            break;

        case FAULT_FAN_FAILURE:
            Logger_LogError("Fault: Fan Failure");
            break;

        default:
            break;
    }
}
void FaultManager_Clear(void)
{
    currentFault = FAULT_NONE;

    Logger_LogInfo("Faults Cleared");
}

FaultCode_t FaultManager_GetCurrentFault(void)
{
    return currentFault;
}