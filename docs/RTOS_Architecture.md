# RTOS Architecture

## 1. Overview

The Virtual Automotive Cooling Control Unit uses a Real-Time Operating System (RTOS) architecture to manage multiple concurrent software functions.

The system is divided into independent tasks. Each task has a dedicated responsibility and communicates with other tasks using RTOS synchronization mechanisms.

The final implementation will be compatible with a FreeRTOS-based embedded system.

## 2. Task Table

| Task | Period | Priority | Responsibility |
|------|--------|----------|----------------|
| Watchdog Task | 1000 ms | Highest | System monitoring |
| CAN Task | 50 ms | High | Communication |
| Cooling Task | 100 ms | High | Fan control |
| Sensor Task | 100 ms | Medium | Sensor acquisition |
| Diagnostic Task | 100 ms | Medium | Diagnostics |
| Logger Task | 500 ms | Low | Event logging |

## 3. Inter-task Communication

Tasks shall communicate using RTOS mechanisms:

- Queues for data exchange.
- Mutexes for shared resources.
- Event groups for system states.