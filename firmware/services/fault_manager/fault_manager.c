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
            Logger_LogInfo("No Active Fault");
            break;
    }
}

FaultCode_t FaultManager_GetCurrentFault(void)
{
    return currentFault;
}