# Software Requirements Specification (SRS)

## 1. Introduction

### 1.1 Purpose

The purpose of the Virtual Automotive Cooling Control Unit (VCCU) is to simulate the behavior of an automotive Electronic Control Unit responsible for monitoring engine cooling conditions and controlling the cooling system.

The project demonstrates embedded software development concepts including Embedded C, RTOS-based task management, CAN communication, diagnostics, fault handling, and modular software architecture.

### 1.2 Scope

The VCCU system shall:

- Monitor simulated engine temperature.
- Monitor simulated battery voltage.
- Control a virtual cooling fan.
- Communicate with external systems through a simulated CAN network.
- Detect and store system faults.
- Provide diagnostic services.
- Log important system events.

### 1.3 Development Constraints

The system will be developed as a software simulation without physical hardware.

The architecture shall remain compatible with a future STM32-based implementation by separating application logic from hardware-dependent drivers.