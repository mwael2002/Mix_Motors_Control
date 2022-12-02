/*
 * Stepper_program.c
 *
 *  Created on: Sep 25, 2021
 *      Author: mwael
 */
#include"avr/delay.h"
#include"STD_Types.h"
#include"DIO_interface.h"
#include "Stepper_config.h"
#include "Stepper_interface.h"

void Stepper_rotate_CW_full_step(void){
	DIO_set_pin_value(Stepper_port,coil_blue,LOW);
	DIO_set_pin_value(Stepper_port,coil_pink,LOW);
	DIO_set_pin_value(Stepper_port,coil_yellow,LOW);
	DIO_set_pin_value(Stepper_port,coil_orange,HIGH);
    _delay_ms(10);
	DIO_set_pin_value(Stepper_port,coil_blue,LOW);
    DIO_set_pin_value(Stepper_port,coil_pink,LOW);
    DIO_set_pin_value(Stepper_port,coil_yellow,HIGH);
	DIO_set_pin_value(Stepper_port,coil_orange,LOW);
	_delay_ms(10);
	DIO_set_pin_value(Stepper_port,coil_blue,LOW);
	DIO_set_pin_value(Stepper_port,coil_pink,HIGH);
	DIO_set_pin_value(Stepper_port,coil_yellow,LOW);
	DIO_set_pin_value(Stepper_port,coil_orange,LOW);
	_delay_ms(10);
	DIO_set_pin_value(Stepper_port,coil_blue,HIGH);
	DIO_set_pin_value(Stepper_port,coil_pink,LOW);
	DIO_set_pin_value(Stepper_port,coil_yellow,LOW);
	DIO_set_pin_value(Stepper_port,coil_orange,LOW);
	_delay_ms(10);
}

void Stepper_rotate_ACW_full_step(void){
	DIO_set_pin_value(Stepper_port,coil_blue,HIGH);
	DIO_set_pin_value(Stepper_port,coil_pink,LOW);
	DIO_set_pin_value(Stepper_port,coil_yellow,LOW);
	DIO_set_pin_value(Stepper_port,coil_orange,LOW);
	_delay_ms(10);
	DIO_set_pin_value(Stepper_port,coil_blue,LOW);
	DIO_set_pin_value(Stepper_port,coil_pink,HIGH);
	DIO_set_pin_value(Stepper_port,coil_yellow,LOW);
	DIO_set_pin_value(Stepper_port,coil_orange,LOW);
	_delay_ms(10);
	DIO_set_pin_value(Stepper_port,coil_blue,LOW);
    DIO_set_pin_value(Stepper_port,coil_pink,LOW);
    DIO_set_pin_value(Stepper_port,coil_yellow,HIGH);
	DIO_set_pin_value(Stepper_port,coil_orange,LOW);
	_delay_ms(10);
	DIO_set_pin_value(Stepper_port,coil_blue,LOW);
	DIO_set_pin_value(Stepper_port,coil_pink,LOW);
	DIO_set_pin_value(Stepper_port,coil_yellow,LOW);
	DIO_set_pin_value(Stepper_port,coil_orange,HIGH);
    _delay_ms(10);
}



void Stepper_rotate_CW_half_step(void){
	DIO_set_pin_value(Stepper_port,coil_blue,HIGH);
	DIO_set_pin_value(Stepper_port,coil_pink,LOW);
    DIO_set_pin_value(Stepper_port,coil_yellow,LOW);
    DIO_set_pin_value(Stepper_port,coil_orange,HIGH);
	_delay_ms(10);
    DIO_set_pin_value(Stepper_port,coil_blue,LOW);
	DIO_set_pin_value(Stepper_port,coil_pink,LOW);
	DIO_set_pin_value(Stepper_port,coil_yellow,LOW);
	DIO_set_pin_value(Stepper_port,coil_orange,HIGH);
	_delay_ms(10);
	DIO_set_pin_value(Stepper_port,coil_blue,LOW);
	DIO_set_pin_value(Stepper_port,coil_pink,LOW);
	DIO_set_pin_value(Stepper_port,coil_yellow,HIGH);
	DIO_set_pin_value(Stepper_port,coil_orange,HIGH);
	_delay_ms(10);
	DIO_set_pin_value(Stepper_port,coil_blue,LOW);
	DIO_set_pin_value(Stepper_port,coil_pink,LOW);
	DIO_set_pin_value(Stepper_port,coil_yellow,HIGH);
	DIO_set_pin_value(Stepper_port,coil_orange,LOW);
	_delay_ms(10);
	DIO_set_pin_value(Stepper_port,coil_blue,LOW);
	DIO_set_pin_value(Stepper_port,coil_pink,HIGH);
	DIO_set_pin_value(Stepper_port,coil_yellow,HIGH);
	DIO_set_pin_value(Stepper_port,coil_orange,LOW);
	_delay_ms(10);
	DIO_set_pin_value(Stepper_port,coil_blue,LOW);
	DIO_set_pin_value(Stepper_port,coil_pink,HIGH);
	DIO_set_pin_value(Stepper_port,coil_yellow,LOW);
	DIO_set_pin_value(Stepper_port,coil_orange,LOW);
	_delay_ms(10);
	DIO_set_pin_value(Stepper_port,coil_blue,HIGH);
	DIO_set_pin_value(Stepper_port,coil_pink,HIGH);
	DIO_set_pin_value(Stepper_port,coil_yellow,LOW);
	DIO_set_pin_value(Stepper_port,coil_orange,LOW);
	_delay_ms(10);
    DIO_set_pin_value(Stepper_port,coil_blue,HIGH);
	DIO_set_pin_value(Stepper_port,coil_pink,LOW);
    DIO_set_pin_value(Stepper_port,coil_yellow,LOW);
	DIO_set_pin_value(Stepper_port,coil_orange,LOW);
	_delay_ms(10);
}

void Stepper_rotate_ACW_half_step(void){
    DIO_set_pin_value(Stepper_port,coil_blue,HIGH);
	DIO_set_pin_value(Stepper_port,coil_pink,LOW);
    DIO_set_pin_value(Stepper_port,coil_yellow,LOW);
	DIO_set_pin_value(Stepper_port,coil_orange,LOW);
	_delay_ms(10);
	DIO_set_pin_value(Stepper_port,coil_blue,HIGH);
	DIO_set_pin_value(Stepper_port,coil_pink,HIGH);
	DIO_set_pin_value(Stepper_port,coil_yellow,LOW);
	DIO_set_pin_value(Stepper_port,coil_orange,LOW);
	_delay_ms(10);
	DIO_set_pin_value(Stepper_port,coil_blue,LOW);
	DIO_set_pin_value(Stepper_port,coil_pink,HIGH);
	DIO_set_pin_value(Stepper_port,coil_yellow,LOW);
	DIO_set_pin_value(Stepper_port,coil_orange,LOW);
	_delay_ms(10);
	DIO_set_pin_value(Stepper_port,coil_blue,LOW);
	DIO_set_pin_value(Stepper_port,coil_pink,HIGH);
	DIO_set_pin_value(Stepper_port,coil_yellow,HIGH);
	DIO_set_pin_value(Stepper_port,coil_orange,LOW);
	_delay_ms(10);
	DIO_set_pin_value(Stepper_port,coil_blue,LOW);
	DIO_set_pin_value(Stepper_port,coil_pink,LOW);
	DIO_set_pin_value(Stepper_port,coil_yellow,HIGH);
	DIO_set_pin_value(Stepper_port,coil_orange,LOW);
	_delay_ms(10);
	DIO_set_pin_value(Stepper_port,coil_blue,LOW);
	DIO_set_pin_value(Stepper_port,coil_pink,LOW);
	DIO_set_pin_value(Stepper_port,coil_yellow,HIGH);
	DIO_set_pin_value(Stepper_port,coil_orange,HIGH);
	_delay_ms(10);
    DIO_set_pin_value(Stepper_port,coil_blue,LOW);
	DIO_set_pin_value(Stepper_port,coil_pink,LOW);
	DIO_set_pin_value(Stepper_port,coil_yellow,LOW);
	DIO_set_pin_value(Stepper_port,coil_orange,HIGH);
	_delay_ms(10);
	DIO_set_pin_value(Stepper_port,coil_blue,HIGH);
	DIO_set_pin_value(Stepper_port,coil_pink,LOW);
    DIO_set_pin_value(Stepper_port,coil_yellow,LOW);
    DIO_set_pin_value(Stepper_port,coil_orange,HIGH);
	_delay_ms(10);
}



void Stepper_set_zero_angle(void){
	DIO_set_pin_value(Stepper_port,coil_blue,LOW);
    DIO_set_pin_value(Stepper_port,coil_pink,LOW);
    DIO_set_pin_value(Stepper_port,coil_yellow,LOW);
	DIO_set_pin_value(Stepper_port,coil_orange,LOW);
}


void Stepper_set_angle(U32 angle,U8 direction,U8 mode){

	U32 steps=angle*2048/360/4;

	if(mode==FULL_STEP){

	if(direction==CW){
		for(U32 i =0; i<steps;i++)
		{
			Stepper_rotate_CW_full_step();
		}
	}
	else if(direction==ACW){
		for(U32 i =0; i<steps;i++)
		{
			Stepper_rotate_ACW_full_step();
		}
	}
  }


	else if(mode==HALF_STEP){

		if(direction==CW){
			for(U32 i =0; i<steps;i++)
			{
				Stepper_rotate_CW_half_step();
			}
		}
		else if(direction==ACW){
			for(U32 i =0; i<steps;i++)
			{
				Stepper_rotate_ACW_half_step();
			}
		}
	}


}


void Stepper_init(void){
	DIO_set_pin_direction(Stepper_port,coil_blue,OUTPUT);
	DIO_set_pin_direction(Stepper_port,coil_pink,OUTPUT);
	DIO_set_pin_direction(Stepper_port,coil_yellow,OUTPUT);
	DIO_set_pin_direction(Stepper_port,coil_orange,OUTPUT);


}



