/*
 * main.c
 *
 *  Created on: Oct 15, 2021
 *      Author: mwael
 */
#include<util/delay.h>
#include "STD_Types.h"
#include "DIO_interface.h"
#include "Timer_interface.h"
#include "LCD_interface.h"
#include "Keypad_interface.h"
#include "DC_Motor_interface.h"
#include "Stepper_interface.h"
#include "Servo_interface.h"
#include "Buzzer_interface.h"

U16 Correct_ID;
U16 Correct_password;
U8 Wrong_user_flag;

void log_in(void);
void Reconfigure(void);

void DC_Motor_task(void);
void Stepper_task(void);
void Servo_task(void);
void DC_Motor_task(void);
void Buzzer_task(void);


void main(void){

	Correct_ID=1111;
    Correct_password=4567;

	KPD_init();
	LCD_init();

    log_in();

while(1){

	if(Wrong_user_flag==0){
    Reconfigure();
    }
}
}

void log_in(void){
	U16 Entered_ID;
	U16 Entered_password;
	U8  Entered_no;
	U8 incorrect_count=0;

	while(1){

    if(incorrect_count==3){

    	LCD_write_string_pos("Wrong inputs",0,0);
    	LCD_write_string_pos("3 times, ALARM",1,0);
    	Buzzer_task();
    	Wrong_user_flag=1;
    	return;
    }

	Entered_no=0;
	Entered_ID=0;
	Entered_password=0;

	LCD_clear();

	LCD_write_string_pos("Enter ID",0,0);

	while(Entered_no!=16){
	do{
	   Entered_no=KPD_status();
	   }while(Entered_no==No_pressed_key);

	if(Entered_no<10){
    Entered_ID=Entered_ID*10+Entered_no;
    LCD_write_no_pos(Entered_ID,1,0);
	}
  }

	Entered_no=0;
	Entered_password=0;

    LCD_clear();
	LCD_write_string_pos("Enter password",0,0);

	while(Entered_no!=16){
	do{
	   Entered_no=KPD_status();
	   }while(Entered_no==No_pressed_key);

	if(Entered_no<10){
	Entered_password=Entered_password*10+Entered_no;
    LCD_write_no_pos(Entered_password,1,0);
	Entered_no=0;

  }

	}


	if((Entered_ID==Correct_ID)&&(Entered_password==Correct_password)){

		incorrect_count=0;

		LCD_clear();

        Entered_no=0;
		break;
	}


	else if(Entered_ID!=Correct_ID){
		incorrect_count++;
		LCD_clear();
		LCD_write_string_pos("wrong ID",0,0);
		_delay_ms(2000);
		continue;
	}

	else if(Entered_password!=Correct_password){
		incorrect_count++;
		LCD_clear();
		LCD_write_string_pos("wrong password",0,0);
		_delay_ms(2000);
	}

	}

		LCD_write_string_pos("Welcome to",0,0);
		LCD_write_string_pos("motor dashboard",1,0);

		_delay_ms(2000);

		LCD_write_string_pos("Motor:1-Servo",0,0);
		LCD_write_string_pos("2-DC  3-Stepper",1,0);

	do{
	   Entered_no=KPD_status();

	   }while(Entered_no==No_pressed_key);


	 if(Entered_no==1){

		 Servo_task();

	 }
	 else if(Entered_no==2){

		 DC_Motor_task();

	 }
	 else if(Entered_no==3){

		Stepper_task();

	 }

}

void Reconfigure(void){

	U8 Entered_no;

	LCD_write_string_pos("Press Enter to",0,0);
	LCD_write_string_pos("reconfigure:",1,0);

	do{
		   Entered_no=KPD_status();

		   }while(Entered_no==No_pressed_key);

	if(Entered_no==16){
		LCD_clear();
		LCD_write_string_pos("Motor:1-Servo",0,0);
		LCD_write_string_pos("2-DC  3-Stepper",1,0);

		do{
		   Entered_no=KPD_status();

		   }while(Entered_no==No_pressed_key);


		 if(Entered_no==1){

			 Servo_task();

		 }
		 else if(Entered_no==2){

			 DC_Motor_task();

		 }
		 else if(Entered_no==3){

			Stepper_task();

		 }
	}

}



void Servo_task(void){

	U16 angle=0;
	U8 Entered_no=0;

	LCD_clear();
	LCD_write_string_pos("Angle(0->180):",0,0);

	while(Entered_no!=16){
		do{
		   Entered_no=KPD_status();
		   }while(Entered_no==No_pressed_key);

		if(Entered_no<10){
		angle=angle*10+Entered_no;
	    LCD_write_no_pos(angle,1,0);
	  }
	}

	if((angle>=0)&&(angle<180)){
    Servo_init(Servo_Pin_1);
    Servo_set_angle(Servo_Pin_1,angle);
	}

	else{
	LCD_clear();
	LCD_write_string_pos("Angle out of",0,0);
	LCD_write_string_pos("Range",1,0);
	}

	LCD_clear();
}

void DC_Motor_task(void){
    U8 mode;
    U8 Entered_no;
    U8 speed_percentage=0;

	LCD_clear();
	LCD_write_string_pos("1-Full Speed:",0,0);
	LCD_write_string_pos("2-Choose speed",1,0);

	do{
	   mode=KPD_status();
	   }while(mode==No_pressed_key);

	if(mode==1){
		DC_Motor_init();
		DC_Motor_Rotate_No_Direction();
	}

	else if(mode==2){

		LCD_clear();
		LCD_write_string_pos("Enter speed:",0,0);
		LCD_write_string_pos("%",1,2);

		while(Entered_no!=16){
			do{
			   Entered_no=KPD_status();
			   }while(Entered_no==No_pressed_key);

			if(Entered_no<10){
              speed_percentage=speed_percentage*10+Entered_no;
              LCD_write_no_pos(speed_percentage,1,0);
		  }
		}

        DC_Motor_init();
		set_comparematch_value(TIMER2_ID,(speed_percentage/100.0)*255);
		Timer2_init();
	}

	LCD_clear();
}

void Stepper_task(void){
	U8 direction;
	U8 step;
	U8 Entered_no=0;
	U16 angle=0;


	LCD_clear();
	LCD_write_string_pos("Direction:",0,0);
	LCD_write_string_pos("1-CW 2-ACW",1,0);

	do{
	   direction=KPD_status();
	   }while(direction==No_pressed_key);


	LCD_clear();
	LCD_write_string_pos("Step:",0,0);
	LCD_write_string_pos("1-Full 2-Half",1,0);

	do{
	   step=KPD_status();
	   }while(step==255);

	LCD_clear();
	LCD_write_string_pos("Angle:",0,0);

	while(Entered_no!=16){
		do{
		   Entered_no=KPD_status();
		   }while(Entered_no==No_pressed_key);

		if(Entered_no<10){
		angle=angle*10+Entered_no;
	    LCD_write_no_pos(angle,1,0);
	   }

	}

	Stepper_init();

	LCD_clear();
	LCD_write_string_pos("Angle:",0,0);
	LCD_write_no_pos(angle,0,6);


	if(direction==1){
	LCD_write_string_pos("CW",1,0);

	   if(step==1){
		   LCD_write_string_pos("Full Step",1,4);
			Stepper_set_angle(angle,CW,FULL_STEP);
		}
		else if(step==2){
			LCD_write_string_pos("Half Step",1,4);
			Stepper_set_angle(angle,CW,HALF_STEP);

		}
	}

	else if(direction==2){

		LCD_write_string_pos("ACW",1,0);

		if(step==1){
			LCD_write_string_pos("Full Step",1,4);
			Stepper_set_angle(angle,ACW,FULL_STEP);

		}
		else if(step==2){
			LCD_write_string_pos("Half Step",1,4);
			Stepper_set_angle(angle,ACW,HALF_STEP);

		}
	}

            LCD_clear();

}

void Buzzer_task(void){
Buzzer_init();
Buzzer_On();
}

