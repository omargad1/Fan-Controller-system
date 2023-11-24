 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: source file for the ATmega32 ADC driver
 *
 * Author: Omar Mohamed
 *
 *******************************************************************************/
# include "adc.h"
# include "common_macros.h"
# include <avr/io.h>
# include "gpio.h"


/*******************************************************************************
 *                          Global Variables                                   *
 *******************************************************************************/

volatile uint16 g_adcResult = 0;

/*******************************************************************************
 *                          ISR's Definitions                                  *
 *******************************************************************************/

ISR(ADC_vect)
{
	/* Read ADC Data after conversion complete */
	g_adcResult = ADC;
}



/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/
void ADC_init(const ADC_ConfigType *  Config_Ptr){
	ADMUX|=(ADMUX&0X3F)|((Config_Ptr->ref_volt)<<6);
	SET_BIT(ADCSRA,ADEN);
	ADCSRA=(ADCSRA & 0XF8)|(Config_Ptr->prescaler);

	/* choose interrupt mode of operation for ADC*/

  #ifndef ADC_OPERTION_POOLING
	SET_BIT(ADSCRA,ADIE);
    #endif

}


uint16 ADC_readchannel(uint8 channel){
	/* clear the last 5bits of register ADMUX & Input channel number must be from 0 -->7 **/
	ADMUX=(channel&0x07)|(ADMUX&0XE0);

	/*SET BIT ADSC TO ONE START CONVERSION FOR ANALOG TO DIGIAL*/
	SET_BIT(ADCSRA,ADSC);

	/* CHOOSE POOLING MODE OF OPERATION*/
#ifdef ADC_OPERTION_POOLING
	while(bit_is_clear(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	return ADC;
#endif
}

