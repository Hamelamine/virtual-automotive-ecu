#include "fan.h"
#include "logger.h"

static int fanSpeed = 0;


void Fan_Init(void)
{
    fanSpeed = 0;

    Logger_LogInfo("Fan Driver Initialized");
}


void Fan_SetSpeed(int speed)
{
    if(speed < 0)
        speed = 0;

    if(speed > 100)
        speed = 100;


    if(fanSpeed == speed)
    {
        return;
    }

    fanSpeed = speed;

    Logger_LogInfo("Fan speed updated");
}


int Fan_GetSpeed(void)
{
    return fanSpeed;
}