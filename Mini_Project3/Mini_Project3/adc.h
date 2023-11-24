 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega32 ADC driver
 *
 * Author: Omar Mohamed
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_
# include "std_types.h"

/**************************************************************
 *               Types Declaration
 ***************************************************************/
typedef enum{
	AREF,AVCC,VREF_INTERNAL=3

}ADC_ReferenceVolatge;


typedef enum{

	F_CPU_1,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128,

}ADC_Prescaler;

typedef struct{
 ADC_ReferenceVolatge ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;




/**************************************************************
 *                Definitions
 ***************************************************************/
/* CHOOSE between pooling and interrupt*/
# define ADC_OPERTION_POOLING

# define ADC_VOLT_REF                               2.56
# define ADC_BITS                                   1023

/*******************************************************************************
 *                       External Variables                                    *
 *******************************************************************************/
extern volatile uint16 g_adcResult;

/**************************************************************
 *       Function prototypes
 ***********************************************************/

/*
 * Description :
 * Function responsible for initialize of configurable ADC driver.
 */
void ADC_init(const ADC_ConfigType *  Config_Ptr);


/*
 * description: read the analog to digital value form the channel
 */
uint16 ADC_readchannel(uint8 channel);


#endif /* ADC_H_ */
