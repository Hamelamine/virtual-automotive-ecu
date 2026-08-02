#include "system.h"

#ifdef _WIN32
#include <windows.h>

void System_DelayMs(unsigned int ms)
{
    Sleep(ms);
}

#else

#include <unistd.h>

void System_DelayMs(unsigned int ms)
{
    usleep(ms * 1000);
}

#endif