 /******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: dc_motor.c
 *
 * Description: source file for dc motor driver
 *
 * Author: Omar Mohamed
 *
 *******************************************************************************/

# include"dc_motor.h"
# include "gpio.h"
# include <avr/io.h>
# include "common_macros.h"

/*******************************************************************************
 *                          Functions Definitions                              *
 *******************************************************************************/


void DcMotor_Init(void){
	GPIO_setupPinDirection(PORTB_ID , PIN0_ID, PIN_OUTPUT);  /* setup pin0 in portB as output pin*/
	GPIO_setupPinDirection(PORTB_ID , PIN1_ID, PIN_OUTPUT);  /* setup pin1 in portB as output pin*/


	/* Stop at the DC-Motor at the beginning */

	GPIO_writePin(PORTB_ID , PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID , PIN1_ID,LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed){


	/*Send the required duty cycle to the PWM driver based on the
	required speed value.
	*/
	PWM_Timer0_Start(speed);


	/* for rotate the DC Motor CW/ or A-CW or
	stop the motor based on the state input state value.
	*/
	switch(state){
	/* STOP the motor*/

	case(STOP):
			GPIO_writePin(PORTB_ID , PIN0_ID,LOGIC_LOW);
			GPIO_writePin(PORTB_ID , PIN1_ID,LOGIC_LOW);
			break;

	/* rotate clock-wise*/
	case(CW):
			GPIO_writePin(PORTB_ID , PIN0_ID,LOGIC_HIGH);
			GPIO_writePin(PORTB_ID , PIN1_ID,LOGIC_LOW);
			break;

	/* rotate anti clock-wise*/
	case(A_CW):
			GPIO_writePin(PORTB_ID , PIN0_ID,LOGIC_LOW);
			GPIO_writePin(PORTB_ID , PIN1_ID,LOGIC_HIGH);
			break;
	}

}
void PWM_Timer0_Start(uint8 duty_cycle){

     uint8 duty=duty_cycle*2.55;

	TCNT0 = 0;                                               /*Set Timer Initial Value to 0*/
	OCR0=duty;                                               /*Set Compare value*/

	GPIO_setupPinDirection(PORTB_ID , PIN3_ID, PIN_OUTPUT);  /* set PB3/OC0 as output pin WHERE pwm signal is generated*/

	/* Configure timer control register
			 * 1. Fast PWM mode FOC0=0
			 * 2. Fast PWM Mode WGM01=1 & WGM00=1
			 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	         * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
			 */
TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);

}

