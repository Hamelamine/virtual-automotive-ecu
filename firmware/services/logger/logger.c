#include "logger.h"

#include <stdio.h>

void Logger_Init(void)
{
    printf("[LOGGER] Logger initialized\n");
}

void Logger_LogInfo(const char* message)
{
    printf("[INFO] %s\n", message);
}

void Logger_LogWarning(const char* message)
{
    printf("[WARNING] %s\n", message);
}

void Logger_LogError(const char* message)
{
    printf("[ERROR] %s\n", message);
}