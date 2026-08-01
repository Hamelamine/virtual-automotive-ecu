#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

/**
 * @brief Initialize temperature sensor.
 */
void TemperatureSensor_Init(void);


/**
 * @brief Read current temperature.
 *
 * @return Temperature in Celsius.
 */
int TemperatureSensor_Read(void);


/**
 * @brief Simulate sensor failure.
 */
void TemperatureSensor_SetFailure(int state);


#endif /* TEMPERATURE_SENSOR_H */