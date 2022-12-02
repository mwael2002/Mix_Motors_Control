/*
 * Servo_program.c
 *
 *  Created on: Sep 9, 2022
 *      Author: mwael
 */
#include "STD_Types.h"
#include "Map_interface.h"
#include "DIO_interface.h"
#include "Timer_interface.h"
#include "Servo_interface.h"


void Servo_init(U8 Pin_no){
DIO_set_pin_direction(Group_D,Pin_no,OUTPUT);

Timer1_init();
Set_ICR1(20000);
}

void Servo_set_angle(U8 Pin_no,U8 angle){
	if(Pin_no==Servo_Pin_1){
	Timer1_set_comparematch_value(CMPB,(U16)MAP_Get_Input_Value(0,180,500,2500,angle));
	}
	else if(Pin_no==Servo_Pin_2){
    Timer1_set_comparematch_value(CMPA,(U16)MAP_Get_Input_Value(0,180,500,2500,angle));
	}
}


