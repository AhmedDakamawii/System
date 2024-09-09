/*
 * dc_motor.h
 *
 *  Created on: 5 Oct 2022
 *      Author: Salma H
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "Std_types.h"
#include "Macros.h"
#include "Platform_Types.h"
#include "Dio.h"
#include "Gpt.h"
#include "dc_motor_Types.h"

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/


void DcMotor_Rotate(Motor_StateType state);
void DCMOTOR_voidULTRAstop();
void DCMOTOR_voidsetspeed(uint8 speed);

#endif /* DC_MOTOR_H_ */
