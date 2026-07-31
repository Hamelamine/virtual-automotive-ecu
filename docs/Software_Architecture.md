# Software Architecture

## Overview

The Virtual Automotive Cooling Control Unit (VCCU) follows a layered software architecture.

Each layer has a well-defined responsibility and communicates only with adjacent layers.

This design improves modularity, maintainability, portability, and testability.

---

## Architecture Layers

Application
│
├── Cooling Control
├── Diagnostics
├── Fault Manager
└── Logger

↓

Services

├── Configuration Manager
├── EEPROM Manager
└── CAN Service

↓

Drivers

├── CAN Driver
├── GPIO Driver
├── ADC Driver
├── PWM Driver
└── UART Driver

↓

Hardware Abstraction Layer (HAL)

↓

Simulation Layer


## Design Rules

The application layer shall never directly access hardware.

All hardware interactions shall be performed through driver interfaces.

Each software module shall have its own source and header file.

Each module shall expose only its public API.

Global variables shall be avoided whenever possible.

Modules shall communicate through clearly defined interfaces.
