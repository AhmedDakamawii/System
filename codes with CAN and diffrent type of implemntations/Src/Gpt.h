/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  GPT.h
 *  Module:  	  GPT
 *  Description:  This file contains the functions  prototype of GPT driver
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Salma Hisham & Mohamed Emad & Mohamed Hesham
 *	Date:		  29/10/2023
 *********************************************************************************************************************/

#ifndef GPT_H_
#define GPT_H_
#include "Gpt_Regs.h"
#include "Gpt_Types.h"
#include "Platform_Types.h"



/*******************************************************************************
 * Service Name      : TIMER0_init
 * Service ID[hex]   : 0x00
 * Sync/Async        : Synchronous
 * Reentrancy        : Reentrant
 * Parameters (in)   : timer: the timer to start
 * Parameters (inout): None
 * Parameters (out)  : None
 * Return value      : None
 * Description       : Starts the timer.
 *******************************************************************************/
void TIMER_init(Configtype_timer *Config);
/*******************************************************************************
 * Service Name      : GPT_PWMInit
 * Service ID[hex]   : 0x01
 * Sync/Async        : Synchronous
 * Reentrancy        : Reentrant
 * Parameters (in)   : timer: timer to be initialized with PWM, Compare Value, Duty Cycle
 * Parameters (inout): None
 * Parameters (out)  : None
 * Return value      : None
 * Description       : Intialize PWM
 *******************************************************************************/
void GPT_PWMInit(GPT_G1timers Timer, GPT_compare_val CompareValue, GPT_duty_cycle_val DutyCycle);
/*******************************************************************************
 * Service Name      : GPT_StartG1Timer
 * Service ID[hex]   : 0x02
 * Sync/Async        : Synchronous
 * Reentrancy        : Reentrant
 * Parameters (in)   : timer: the timer to start
 * Parameters (inout): None
 * Parameters (out)  : None
 * Return value      : None
 * Description       : Starts the timer.
 *******************************************************************************/
void GPT_StartG1Timer(GPT_G1timers timer);
/*******************************************************************************
 * Service Name      : GPT_StopG1Timer
 * Service ID[hex]   : 0x03
 * Sync/Async        : Synchronous
 * Reentrancy        : Reentrant
 * Parameters (in)   : timer: the timer to stop
 * Parameters (inout): None
 * Parameters (out)  : None
 * Return value      : None
 * Description       : Stops the timer.
 *******************************************************************************/
void GPT_StopG1Timer(GPT_G1timers timer);
/*******************************************************************************
 * Service Name      : GPT_EnableInterrupts
 * Service ID[hex]   : 0x04
 * Sync/Async        : Synchronous
 * Reentrancy        : Reentrant
 * Parameters (in)   : timer: the timer to enable its interrupts
 * Parameters (inout): None
 * Parameters (out)  : None
 * Return value      : None
 * Description       : Enables the timers to sent interrupt event.
 *******************************************************************************/
void GPT_EnableInterrupts(Configtype_timer *Config);
/*******************************************************************************
 * Service Name      : GPT_DisableInterrupts
 * Service ID[hex]   : 0x05
 * Sync/Async        : Synchronous
 * Reentrancy        : Reentrant
 * Parameters (in)   : timer: the timer to enable its interrupts
 * Parameters (inout): None
 * Parameters (out)  : None
 * Return value      : None
 * Description       : Disables the timers to sent interrupt event.
 *******************************************************************************/
void GPT_DisableInterrupts(GPT_G1timers timer);
/*******************************************************************************
 * Service Name      : Gpt_GetCountsElapsed
 * Service ID[hex]   : 0x06
 * Sync/Async        : Synchronous
 * Reentrancy        : Reentrant
 * Parameters (in)   : timer: the timer which we will do our calculations on.
 * Parameters (inout): None
 * Parameters (out)  : None
 * Return value      : Elapsed counts.
 * Description       : Get the elapsed counts since the timer has been started.
 *******************************************************************************/
uint32 Gpt_GetCountsElapsed(GPT_G1timers timer);
/*******************************************************************************
 * Service Name      : Gpt_GetCountsRemaining
 * Service ID[hex]   : 0x07
 * Sync/Async        : Synchronous
 * Reentrancy        : Reentrant
 * Parameters (in)   : timer: the timer which we will do our calculations on.
 * Parameters (inout): None
 * Parameters (out)  : None
 * Return value      : Elapsed counts.
 * Description       : Get the remaining counts since the timer has been started.
 *******************************************************************************/
uint32 Gpt_GetCountsRemaining(GPT_G1timers timer);
/************************************************************************************
 * Service Name: GPT_SetCallBack
 * Service ID[hex]   : 0x08
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): Ptr2Func - Call Back function address
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Setup the GPT Timer call back
 ************************************************************************************/
void GPT_SetCallBack(void (*Ptr2Func)(uint8 Edge), GPT_G1timers ID);
/************************************************************************************
 * Service Name: MTIM4_voidICUInit
 * Service ID[hex]   : 0x09
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): void
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to intialize ICU
 ************************************************************************************/
void MTIM4_voidICUInit(void);
/************************************************************************************
 * Service Name: MTIM4_GetDistance
 * Service ID[hex]   : 0x10
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): void
 * Parameters (inout): None
 * Parameters (out): uint16
 * Return value: None
 * Description: get distance
 ************************************************************************************/
uint16 MTIM4_GetDistance(void);
/************************************************************************************
 * Service Name: MTIM4_GetCapture
 * Service ID[hex]   : 0x11
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): void
 * Parameters (inout): None
 * Parameters (out): uint16
 * Return value: None
 * Description: get capture
 ************************************************************************************/
uint16 MTIM4_GetCapture(void);
/************************************************************************************
 * Service Name: MTIM4_voidSetEdgeDetectionType
 * Service ID[hex]   : 0x12
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): edge type
 * Parameters (inout): None
 * Parameters (out): uint16
 * Return value: None
 * Description: get distance
 ************************************************************************************/
void MTIM4_voidSetEdgeDetectionType(uint8 EDGE_TYPE);
/************************************************************************************
 * Service Name: delaySeconds
 * Service ID[hex]   : 0x13
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Parameters (in): timer , seconds to be delayed
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Delay using specific timer for specific time in seconds
 ************************************************************************************/
void delaySeconds(GPT_G1timers timer, float32 seconds);
void delaymilliSeconds(GPT_G1timers timer, uint32 milliseconds);
void delaymicroSeconds(GPT_G1timers timer, uint32 microseconds);

#endif
