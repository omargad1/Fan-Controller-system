 /******************************************************************************
 *
 * Module: DC MOTOR
 *
 * File Name: dc_motor.h
 *
 * Description: header file for dc motor driver
 *
 * Author: Omar Mohamed
 *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
# include "std_types.h"

/**************************************************************
 *               Types Declaration
 ***************************************************************/
/* Declare new types for the motor states stop=0,cw=1,a_cw=2*/
typedef enum{
	STOP,CW,A_CW

}DcMotor_State;

/**************************************************************
 *       Function prototypes
 ***********************************************************/


/*
 * description:
 * The Function responsible for setup the direction for the two
motor pins through the GPIO driver.
 *
 */
void DcMotor_Init(void);



/*
 * description:
 * the function responsible for rotate the DC Motor CW/ or A-CW or
stop the motor based on the state input state value.
 *
 */

void DcMotor_Rotate(DcMotor_State state,uint8 speed);

/*
 * description:
 * Generate a PWM signal with frequency 500Hz
 * The function responsible for trigger the Timer0 with the PWM Mode
 */

void PWM_Timer0_Start(uint8 duty_cycle);



#endif /* DC_MOTOR_H_ */
