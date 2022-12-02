/*
 * Servo_interface.h
 *
 *  Created on: Sep 9, 2022
 *      Author: mwael
 */

#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

#define Servo_Pin_1          4
#define Servo_Pin_2          5


void Servo_init(U8 Pin_no);
void Servo_set_angle(U8 Pin_no,U8 angle);

#endif /* SERVO_INTERFACE_H_ */
