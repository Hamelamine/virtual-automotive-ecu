#include "temperature_sensor.h"
#include "logger.h"

static int currentTemperature = 25;
static int sensorFailure = 0;


void TemperatureSensor_Init(void)
{
    currentTemperature = 25;
    sensorFailure = 0;

    Logger_LogInfo("Temperature Sensor Initialized");
}


int TemperatureSensor_Read(void)
{
    if(sensorFailure)
    {
        return -1;
    }

    currentTemperature += 5;

    Logger_LogInfo("Temperature reading updated");

    return currentTemperature;
}


void TemperatureSensor_SetFailure(int state)
{
    sensorFailure = state;
}