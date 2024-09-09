/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  DcMotor.c
 *  Module:  	  DC Motor
 *
 *  Description:  Source file for DC Motor Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Salma Hisham
 *	Date:		  12/11/2023
 *********************************************************************************************************************/

#include "dc_motor.h"
#include "FreeRTOS.h"

extern uint8 MOTOR_STATE_R;
extern uint8 MOTOR_STATE_spare;
#define TIMER_USED_MOTOR TIMER2_DEF

float DISTANCEREAD1 = 0;
float DISTANCEREAD2 = 0;
float DISTANCEREAD3 = 0;
/*********************************[1]********************************************
 * Service Name: DcMotor_Rotate
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Non-Reentrant
 * Parameters (in): direction
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to rotate motor according to direction
 *******************************************************************************/
void DcMotor_Rotate(Motor_StateType state) {
	switch (state) {
	case Stop: {
		GPT_PWMInit(TIMER_USED_MOTOR, CompareVal, 0);
		GPT_StartG1Timer(TIMER_USED_MOTOR);
		Dio_WriteChannel(port1, pin1, DIO_LEVEL_LOW);
		Dio_WriteChannel(port1, pin2, DIO_LEVEL_LOW);
		Dio_WriteChannel(port2, pin3, DIO_LEVEL_LOW);
		Dio_WriteChannel(port2, pin4, DIO_LEVEL_LOW);
		break;
	}
	case FORWARD: {
		GPT_PWMInit(TIMER_USED_MOTOR, CompareVal, 65);
		GPT_StartG1Timer(TIMER_USED_MOTOR);
		Dio_WriteChannel(port1, pin1, DIO_LEVEL_HIGH);
		Dio_WriteChannel(port1, pin2, DIO_LEVEL_LOW);
		Dio_WriteChannel(port2, pin3, DIO_LEVEL_HIGH);
		Dio_WriteChannel(port2, pin4, DIO_LEVEL_LOW);

		break;
	}
	case BACKWARD: {
		GPT_PWMInit(TIMER_USED_MOTOR, CompareVal, 65);
		GPT_StartG1Timer(TIMER_USED_MOTOR);
		Dio_WriteChannel(port1, pin1, DIO_LEVEL_LOW);
		Dio_WriteChannel(port1, pin2, DIO_LEVEL_HIGH);
		Dio_WriteChannel(port2, pin3, DIO_LEVEL_LOW);
		Dio_WriteChannel(port2, pin4, DIO_LEVEL_HIGH);

		break;
	}
	case LEFT: {
		GPT_PWMInit(TIMER_USED_MOTOR, CompareVal, 80);
		GPT_StartG1Timer(TIMER_USED_MOTOR);
		Dio_WriteChannel(port1, pin1, DIO_LEVEL_LOW);
		Dio_WriteChannel(port1, pin2, DIO_LEVEL_LOW);
		Dio_WriteChannel(port2, pin3, DIO_LEVEL_HIGH);
		Dio_WriteChannel(port2, pin4, DIO_LEVEL_LOW);
//	delaySeconds(TIMER3_DEF,0.4);
		//vTaskDelay(pdMS_TO_TICKS(500));
//stop
//	GPT_PWMInit(TIMER_USED_MOTOR,CompareVal,0);
//	GPT_StartG1Timer(TIMER_USED_MOTOR);
//  Dio_WriteChannel(port1,pin1,DIO_LEVEL_LOW);
//	Dio_WriteChannel(port1,pin2,DIO_LEVEL_LOW);
//	Dio_WriteChannel(port2,pin3,DIO_LEVEL_LOW);
//	Dio_WriteChannel(port2,pin4,DIO_LEVEL_LOW);
//to make sure that you will start from first speed

		break;
	}
	case RIGHT: {
		GPT_PWMInit(TIMER_USED_MOTOR, CompareVal, 80);
		GPT_StartG1Timer(TIMER_USED_MOTOR);
		Dio_WriteChannel(port1, pin1, DIO_LEVEL_HIGH);
		Dio_WriteChannel(port1, pin2, DIO_LEVEL_LOW);
		Dio_WriteChannel(port2, pin3, DIO_LEVEL_LOW);
		Dio_WriteChannel(port2, pin4, DIO_LEVEL_LOW);

//	delaySeconds(TIMER3_DEF,0.4);
////vTaskDelay(pdMS_TO_TICKS(500));
////stop
//	GPT_PWMInit(TIMER_USED_MOTOR,CompareVal,0);
//	GPT_StartG1Timer(TIMER_USED_MOTOR);
//  Dio_WriteChannel(port1,pin1,DIO_LEVEL_LOW);
//	Dio_WriteChannel(port1,pin2,DIO_LEVEL_LOW);
//	Dio_WriteChannel(port2,pin3,DIO_LEVEL_LOW);
//	Dio_WriteChannel(port2,pin4,DIO_LEVEL_LOW);
		break;
	}
	default:
		break;
	}

	MOTOR_STATE_R=50;
	MOTOR_STATE_spare=50;
}
void DCMOTOR_voidsetspeed(uint8 speed) {
	GPT_PWMInit(TIMER_USED_MOTOR, CompareVal, speed);
	GPT_StartG1Timer(TIMER_USED_MOTOR);
}
/*********************************[2]********************************************
 * Service Name: DCMOTOR_voidULTRAstop
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Non-Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to stop car
 *******************************************************************************/
void DCMOTOR_voidULTRAstop() {
	GPT_PWMInit(TIMER_USED_MOTOR, CompareVal, 0);
	GPT_StartG1Timer(TIMER_USED_MOTOR);
	Dio_WriteChannel(port1, pin1, DIO_LEVEL_LOW);
	Dio_WriteChannel(port1, pin2, DIO_LEVEL_LOW);
	Dio_WriteChannel(port2, pin3, DIO_LEVEL_LOW);
	Dio_WriteChannel(port2, pin4, DIO_LEVEL_LOW);
	MOTOR_STATE_R=50;
	MOTOR_STATE_spare=50;
}
