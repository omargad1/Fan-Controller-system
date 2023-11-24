/*
 *
 * Module: Temperature Sensor
 *
 * File Name: temp_sensor.h
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Omar Mohamed
 */

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_
# include "std_types.h"
/*********************************************************
 *                   DEFINITONS
 ***********************************************************/
# define SENSOR_MAX_VOLT              1.5
# define SENSOR_MAX_TEMP              150
# define SENSOR_CHANNEL_ID            2
/*********************************************************
 *                  FUNCTION PROTOTYPE
 *******************************************************/
/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_GetTemprature(void);


#endif /* LM35_SENSOR_H_ */
