#include "can.h"
#include "logger.h"

#include <stdio.h>

void CAN_Init(void)
{
    Logger_LogInfo("CAN Driver Initialized");
}

void CAN_Send(const CAN_Frame_t *frame)
{
    printf("\n========== CAN FRAME ==========\n");
    printf("ID  : 0x%03X\n", frame->id);
    printf("DLC : %d\n", frame->dlc);

    printf("DATA: ");

    for(int i = 0; i < frame->dlc; i++)
    {
        printf("%02X ", frame->data[i]);
    }

    printf("\n===============================\n");
}