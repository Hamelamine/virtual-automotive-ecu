#include "logger.h"

int main(void)
{
    Logger_Init();

    Logger_LogInfo("Virtual Automotive ECU Starting...");
    Logger_LogInfo("Initializing modules...");
    Logger_LogInfo("System ready.");

    return 0;
}