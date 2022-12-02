/*
 * DC_Motor_program.c
 *
 *  Created on: Sep 9, 2022
 *      Author: mwael
 */
#include "STD_Types.h"
#include "DIO_interface.h"
#include "DC_Motor_config.h"
#include "DC_Motor_interface.h"


void DC_Motor_init(void){
	DIO_set_pin_direction(MOTOR_PORT,MOTOR_PINA,OUTPUT);
    #if USE_DIRECTION==1
	DIO_set_pin_direction(MOTOR_PORT,MOTOR_PINB,OUTPUT);
    #endif
}

void DC_Motor_Rotate_No_Direction(void){
	DIO_set_pin_value(MOTOR_PORT,MOTOR_PINA,HIGH);
}

void DC_Motor_Rotate_CW(void){
	DIO_set_pin_value(MOTOR_PORT,MOTOR_PINA,HIGH);
	DIO_set_pin_value(MOTOR_PORT,MOTOR_PINB,LOW);
}

void DC_Motor_Rotate_ACW(void){
	DIO_set_pin_value(MOTOR_PORT,MOTOR_PINA,LOW);
	DIO_set_pin_value(MOTOR_PORT,MOTOR_PINB,HIGH);
}

void DC_Motor_Stop(void){
	DIO_set_pin_value(MOTOR_PORT,MOTOR_PINA,LOW);
    #if USE_DIRECTION==1
	DIO_set_pin_value(MOTOR_PORT,MOTOR_PINB,LOW);
    #endif

}

