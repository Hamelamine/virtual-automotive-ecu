#ifndef ECU_H
#define ECU_H

/**
 * @brief Initializes the ECU.
 */
void ECU_Init(void);

/**
 * @brief Starts the ECU.
 */
void ECU_Start(void);

/**
 * @brief Executes one ECU cycle.
 *
 * In the future, this function will:
 * - Read sensors
 * - Update the control algorithm
 * - Handle diagnostics
 * - Communicate over CAN
 */
void ECU_Run(void);

#endif /* ECU_H */