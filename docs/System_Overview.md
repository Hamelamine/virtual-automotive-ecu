# Virtual Automotive Cooling Control Unit (VCCU)

## Overview

The Virtual Automotive Cooling Control Unit (VCCU) is a simulated embedded system inspired by automotive Electronic Control Units (ECUs).

The objective of the project is to demonstrate professional embedded software development practices using Embedded C, FreeRTOS, CAN communication, modular software architecture, diagnostics, and a virtual hardware abstraction layer.

Although no physical hardware is used, the software architecture is designed so that the simulated drivers could later be replaced by real STM32 drivers with minimal changes to the application layer.

## Main Features

- Simulated engine temperature monitoring
- Simulated battery voltage monitoring
- Cooling fan control
- CAN communication
- Diagnostic services
- Fault detection and DTC management
- Event logging
- Modular layered architecture