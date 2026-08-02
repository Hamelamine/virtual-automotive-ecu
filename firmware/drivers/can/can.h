#ifndef CAN_H
#define CAN_H

#include <stdint.h>

typedef struct
{
    uint32_t id;
    uint8_t dlc;
    uint8_t data[8];

} CAN_Frame_t;

void CAN_Init(void);

void CAN_Send(const CAN_Frame_t *frame);

#endif /* CAN_H */