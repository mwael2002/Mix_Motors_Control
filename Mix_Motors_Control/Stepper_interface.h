/*
 * Stepper_interface.h
 *
 *  Created on: Sep 25, 2021
 *      Author: mwael
 */

#ifndef Stepper_INTERFACE_H_
#define Stepper_INTERFACE_H_

#define CW 0
#define ACW 1

#define FULL_STEP 1
#define HALF_STEP 0

void Stepper_init(void);

void Stepper_rotate_CW_full_step(void);
void Stepper_rotate_ACW_full_step(void);
void Stepper_rotate_CW_half_step(void);
void Stepper_rotate_ACW_half_step(void);

void Stepper_set_angle(U32 angle,U8 direction,U8 mode);
void Stepper_set_zero_angle(void);

#endif /* Stepper_INTERFACE_H_ */
