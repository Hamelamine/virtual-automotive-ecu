#ifndef FAULT_MANAGER_H
#define FAULT_MANAGER_H

typedef enum
{
    FAULT_NONE = 0,
    FAULT_OVERTEMPERATURE,
    FAULT_SENSOR_FAILURE,
    FAULT_CAN_TIMEOUT,
    FAULT_FAN_FAILURE

} FaultCode_t;

void FaultManager_Init(void);

void FaultManager_Report(FaultCode_t fault);

void FaultManager_Clear(void);

FaultCode_t FaultManager_GetCurrentFault(void);

#endif /* FAULT_MANAGER_H */