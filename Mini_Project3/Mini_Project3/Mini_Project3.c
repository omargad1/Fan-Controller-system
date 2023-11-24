/*
 ======================================================================================
 Name        : Mini Project3.c
 Author      : Omar Mohamed
 Description : design a temperature-controlled fan using ATmega32 microcontroller
 ======================================================================================
 */


# include "adc.h"
# include "gpio.h"
# include "lcd.h"
# include "dc_motor.h"
# include "lm35_sensor.h"

int main(void){

	uint8 temp;

	/* GIVE configuration structure values */
ADC_ConfigType configure_ptr={VREF_INTERNAL,F_CPU_8};

	/*initialize the ADC driver*/
	ADC_init(&configure_ptr);

	/*initialize the LCD driver*/
	LCD_init();

	/*initialize the DC MOTOR driver*/
	DcMotor_Init();

	/* move cursor to middle */
	LCD_moveCursor(0, 4);


	/* display fan status*/
	LCD_displayString("Fan is ");

	/* move the cursor down */
	LCD_moveCursor(1, 4);

	/* display the temperature */
	LCD_displayString("Temp =   C");


	while(1){
    temp=LM35_GetTemprature();

    if(temp<30){
    	DcMotor_Rotate(STOP, 0);
    }
    else if((temp>=30)&&(temp<60)){

    	        DcMotor_Rotate(CW, 25);
    }

    else if((temp>=60)&&(temp<90)){

        	        DcMotor_Rotate(CW, 50);
        }
    else if((temp>=90)&&(temp<120)){

        	        DcMotor_Rotate(CW, 75);
        }


    else if(temp>=120){

        	        DcMotor_Rotate(CW, 100);
        }

    LCD_moveCursor(1, 10);
     if(temp >= 100)
     		{
     			LCD_intgerToString(temp);
     		}
     		else
     		{
     			LCD_intgerToString(temp);
     			/* In case the digital value is three or two or one digits print space in the next digit place */
     			LCD_displayCharacter(' ');
     		}


 LCD_moveCursor(0, 11);
if(temp>=30){
	LCD_displayString("ON");
	LCD_displayCharacter(' ');
}
else{

	  LCD_displayString("OFF");
}





	}






}


