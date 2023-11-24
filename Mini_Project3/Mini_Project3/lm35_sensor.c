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
#include "lm35_sensor.h"

# include "adc.h"
/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_GetTemprature(void){
	uint8 temp_value=0;
    uint16 adc_value=0;
    adc_value=ADC_readchannel(SENSOR_CHANNEL_ID);

   temp_value=(uint8)(((uint32) adc_value*ADC_VOLT_REF*SENSOR_MAX_TEMP) / (SENSOR_MAX_VOLT*ADC_BITS) );

    return temp_value;
}
