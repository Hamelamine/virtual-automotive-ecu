#ifndef LOGGER_H
#define LOGGER_H

/**
 * @brief Initializes the logger module.
 */
void Logger_Init(void);

/**
 * @brief Logs an informational message.
 *
 * @param message Message to log.
 */
void Logger_LogInfo(const char* message);

/**
 * @brief Logs a warning message.
 *
 * @param message Message to log.
 */
void Logger_LogWarning(const char* message);

/**
 * @brief Logs an error message.
 *
 * @param message Message to log.
 */
void Logger_LogError(const char* message);

#endif /* LOGGER_H */