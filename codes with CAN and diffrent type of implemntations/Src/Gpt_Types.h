/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Gpt_Types.h
 *  Module:  	  Gpt_Types
 *
 *  Description:  Header file for TM4C123GH6PM MCU - Gpt Module's Types
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Salma Hisham & Mohamed Emad & Mohamed Hesham
 *	Date:		  29/10/2023
 *********************************************************************************************************************/
#ifndef GPT_TYPES_H
#define GPT_TYPES_H

#include "Platform_Types.h"

#define SYS_CLK 8000000
typedef uint32 GPT_prescaler_val;
typedef uint32 GPT_init_val;
typedef uint32 GPT_compare_val;
typedef uint32 GPT_duty_cycle_val;

#define RISING_EDGE 0
#define FALLING_EDGE 1

/* enum for all the timers */
typedef enum
{
    TIMER2_DEF = 0,
    TIMER3_DEF = 1,
    TIMER4_DEF = 2

} GPT_G1timers;
typedef enum
{
    Direction_Down = 0,
    Direction_Up = 1

} GPT_directions;
typedef enum
{
    TIMER_CHANNEL1=1,
    TIMER_CHANNEL2=2,
    TIMER_CHANNEL3=3,
    TIMER_CHANNEL4=4,


} GPT_CHANNELS;

typedef enum
{
    GPT_OverFlow_Mode = 0,
    GPT_Input_Capture_Mode = 1,
    GPT_Encoder_Interface_Mode = 2,
    GPT_PWM_Mode = 3

} GPT_MODS;

typedef enum
{
    Mode_1 = 001,
    Mode_2 = 010,
    Mode_3 = 011
} GPT_Encoder_MODS;

typedef struct
{
    GPT_G1timers GPT_Timers_timer_ID;
    GPT_CHANNELS GPT_CHANNELS_ID;
    GPT_directions GPT_Timer_direction;
    GPT_MODS GPT_Timers_mode;
    GPT_prescaler_val GPT_Timers_prescalar;
    GPT_init_val GPT_Timers_initialvalue;
    GPT_compare_val GPT_Timers_comparevalue;
    GPT_duty_cycle_val GPT_Timers_dutycycle;

} Configtype_timer;

extern Configtype_timer GPT_config2;
extern Configtype_timer GPT_config3;


#endif
