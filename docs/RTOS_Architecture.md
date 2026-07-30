# RTOS Architecture

## 1. Overview

The Virtual Automotive Cooling Control Unit uses a Real-Time Operating System (RTOS) architecture to manage multiple concurrent software functions.

The system is divided into independent tasks. Each task has a dedicated responsibility and communicates with other tasks using RTOS synchronization mechanisms.

The final implementation will be compatible with a FreeRTOS-based embedded system.
