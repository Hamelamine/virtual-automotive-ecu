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

## 2. Functional Requirements

## 2. Functional Requirements

### 2.1 Temperature Monitoring

**REQ_TEMP_001**  
The system shall simulate engine temperature measurements within a range of -20°C to 150°C.

**REQ_TEMP_002**  
The system shall acquire temperature data periodically every 100 ms.

**REQ_TEMP_003**  
The system shall detect an overheating condition when engine temperature exceeds 105°C.

---

### 2.2 Cooling Fan Control

**REQ_FAN_001**  
The system shall control a virtual cooling fan based on engine temperature.

**REQ_FAN_002**  
The cooling fan shall be activated when engine temperature exceeds 95°C.

**REQ_FAN_003**  
The cooling fan shall be deactivated when engine temperature falls below 85°C.

**REQ_FAN_004**  
The fan speed shall be represented using a PWM value ranging from 0% to 100%.

---

### 2.3 Battery Monitoring

**REQ_BAT_001**  
The system shall simulate battery voltage measurements within a range of 10V to 15V.

**REQ_BAT_002**  
The system shall monitor battery voltage periodically.

**REQ_BAT_003**  
The system shall detect abnormal battery conditions.

---

### 2.4 CAN Communication

**REQ_CAN_001**  
The system shall communicate through a simulated CAN network.

**REQ_CAN_002**  
The CAN communication bitrate shall be configured to 500 kbps.

**REQ_CAN_003**  
The ECU shall periodically transmit status information through CAN messages.

**REQ_CAN_004**  
The ECU shall detect CAN communication failures using timeout monitoring.

---

### 2.5 Fault Detection and Management

**REQ_FAULT_001**  
The system shall detect engine overheating conditions.

**REQ_FAULT_002**  
The system shall detect CAN communication failures.

**REQ_FAULT_003**  
The system shall detect cooling fan failures.

**REQ_FAULT_004**  
Detected faults shall be stored as Diagnostic Trouble Codes (DTCs).
