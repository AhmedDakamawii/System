/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  GPT.c
 *  Module:  	  GPT
 *  Description:  This file contains the functions of GPT driver
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Salma Hisham & Mohamed Emad & Mohamed Hesham
 *	Date:		  29/10/2023
 *********************************************************************************************************************/
#include "Gpt.h"
#include "Macros.h"
#include "Std_Types.h"

static void (*g_GPT_Timer2_Call_Back_Ptr)(uint8 Edge) = NULL_PTR;
static void (*g_GPT_Timer3_Call_Back_Ptr)(uint8 Edge) = NULL_PTR;
static void (*g_GPT_Timer4_Call_Back_Ptr)(uint8 Edge) = NULL_PTR;

uint8 Edge_Type;
volatile uint32 start_time = 0;
volatile uint32 end_time = 0;
volatile uint32 pulse_duration = 0;
volatile uint32 distance = 0;

Configtype_timer GPT_config2 = {
    TIMER2_DEF, TIMER_CHANNEL2, Direction_Up, GPT_PWM_Mode, 1, 0, 65535, 50};
Configtype_timer GPT_config3 = {
    TIMER3_DEF, TIMER_CHANNEL2, Direction_Up, GPT_OverFlow_Mode, 1, 0, 65535, 50};
/************************************************************************************
 * Service Name: TIM2_IRQHandler
 * Description: GPT Timer2 ISR
 ************************************************************************************/
void TIM2_IRQHandler(void)
{
    /* Check if the Timer0_setCallBack is already called */
    if (g_GPT_Timer2_Call_Back_Ptr != NULL_PTR)
    {
        switch (GPT_config2.GPT_CHANNELS_ID)
        {
        case TIMER_CHANNEL1:
            if ((TIMER2->SR).BF.UIF == 1)
            {
                Edge_Type = 1; // Rising  Edge
            }
            else if ((TIMER2->SR).BF.CC1IF == 0)
            {
                Edge_Type = 0; // falling  Edge
            }

            (*g_GPT_Timer2_Call_Back_Ptr)(Edge_Type); /* call the function in the scheduler using call-back concept */
            (TIMER2->SR).BF.UIF = 0;
            (TIMER2->SR).BF.CC1IF = 0;
            break;
        case TIMER_CHANNEL2:
            if ((TIMER2->SR).BF.UIF == 1)
            {
                Edge_Type = 1; // Rising  Edge
            }
            else if ((TIMER2->SR).BF.CC2IF == 0)
            {
                Edge_Type = 0; // falling  Edge
            }

            (*g_GPT_Timer2_Call_Back_Ptr)(Edge_Type); /* call the function in the scheduler using call-back concept */
            (TIMER2->SR).BF.UIF = 0;
            (TIMER2->SR).BF.CC2IF = 0;
            break;

        case TIMER_CHANNEL3:
            if ((TIMER2->SR).BF.UIF == 1)
            {
                Edge_Type = 1; // Rising  Edge
            }
            else if ((TIMER2->SR).BF.CC3IF == 0)
            {
                Edge_Type = 0; // falling  Edge
            }

            (*g_GPT_Timer2_Call_Back_Ptr)(Edge_Type); /* call the function in the scheduler using call-back concept */
            (TIMER2->SR).BF.UIF = 0;
            (TIMER2->SR).BF.CC3IF = 0;
            break;

        case TIMER_CHANNEL4:
            if ((TIMER2->SR).BF.UIF == 1)
            {
                Edge_Type = 1; // Rising  Edge
            }
            else if ((TIMER2->SR).BF.CC4IF == 0)
            {
                Edge_Type = 0; // falling  Edge
            }

            (*g_GPT_Timer2_Call_Back_Ptr)(Edge_Type); /* call the function in the scheduler using call-back concept */
            (TIMER2->SR).BF.UIF = 0;
            (TIMER2->SR).BF.CC4IF = 0;
            break;
        }
    }
}

/************************************************************************************
 * Service Name: TIM3_IRQHandler
 * Description: GPT Timer3 ISR
 ************************************************************************************/
void TIM3_IRQHandler(void)
{
    /* Check if the Timer0_setCallBack is already called */
    if (g_GPT_Timer3_Call_Back_Ptr != NULL_PTR)
    {
        switch (GPT_config2.GPT_CHANNELS_ID)
        {
        case TIMER_CHANNEL1:
            if ((TIMER3->SR).BF.UIF == 1)
            {
                Edge_Type = 1; // Raising  Edge
            }
            else if ((TIMER3->SR).BF.CC1IF == 1)
            {
                Edge_Type = 0; // falling  Edge
            }

            (*g_GPT_Timer3_Call_Back_Ptr)(Edge_Type); /* call the function in the scheduler using call-back concept */

            (TIMER3->SR).BF.UIF = 0;
            (TIMER3->SR).BF.CC1IF = 0;
            break;

        case TIMER_CHANNEL2:
            if ((TIMER3->SR).BF.UIF == 1)
            {
                Edge_Type = 1; // Raising  Edge
            }
            else if ((TIMER3->SR).BF.CC2IF == 1)
            {
                Edge_Type = 0; // falling  Edge
            }

            (*g_GPT_Timer3_Call_Back_Ptr)(Edge_Type); /* call the function in the scheduler using call-back concept */

            (TIMER3->SR).BF.UIF = 0;
            (TIMER3->SR).BF.CC2IF = 0;
            break;
        case TIMER_CHANNEL3:
            if ((TIMER3->SR).BF.UIF == 1)
            {
                Edge_Type = 1; // Raising  Edge
            }
            else if ((TIMER3->SR).BF.CC3IF == 1)
            {
                Edge_Type = 0; // falling  Edge
            }

            (*g_GPT_Timer3_Call_Back_Ptr)(Edge_Type); /* call the function in the scheduler using call-back concept */

            (TIMER3->SR).BF.UIF = 0;
            (TIMER3->SR).BF.CC3IF = 0;
            break;
        case TIMER_CHANNEL4:
            if ((TIMER3->SR).BF.UIF == 1)
            {
                Edge_Type = 1; // Raising  Edge
            }
            else if ((TIMER3->SR).BF.CC4IF == 1)
            {
                Edge_Type = 0; // falling  Edge
            }

            (*g_GPT_Timer3_Call_Back_Ptr)(Edge_Type); /* call the function in the scheduler using call-back concept */

            (TIMER3->SR).BF.UIF = 0;
            (TIMER3->SR).BF.CC4IF = 0;
            break;
        }
    }
}

/************************************************************************************
 * Service Name: TIM4_IRQHandler
 * Description: GPT Timer4 ISR
 ************************************************************************************/
void TIM4_IRQHandler(void)
{

    if (start_time == 0)
    {
        // Save the start time of the pulse
        start_time = MTIM4_GetCapture();
        /* Detect falling edge */
        MTIM4_voidSetEdgeDetectionType(FALLING_EDGE);
    }
    else
    {
        // Save the end time of the pulse
        end_time = MTIM4_GetCapture();

        if (end_time > start_time)
        {
            // Calculate the pulse duration
            pulse_duration = end_time - start_time;
        }
        else
        {
            pulse_duration = (0xFFFF - start_time) + end_time;
        }
        /* Detect rising edge */
        MTIM4_voidSetEdgeDetectionType(RISING_EDGE);

        /* Clear the timer counter register to start measurements again */
        TIMER4->CNT = 0;
        // Reset the start time
        start_time = 0;
        // Reset the end time
        end_time = 0;
    }
    TIMER4->SR.BF.UIF = 0;
    TIMER4->SR.BF.CC1IF = 0;
    TIMER4->SR.BF.CC2IF = 0;
    TIMER4->SR.BF.CC3IF = 0;
    TIMER4->SR.BF.CC4IF = 0;
}

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
void TIMER_init(Configtype_timer *Config)
{

    // upcounting overflow mode:
    switch (Config->GPT_Timers_mode)
    {
    case GPT_OverFlow_Mode:
        if ((Config->GPT_Timers_timer_ID) == (TIMER2_DEF))
        {

            (TIMER2->CR1).BF.ARPE = 0;
            (TIMER2->CR1).BF.URS = 1;
            (TIMER2->ARR) = (Config->GPT_Timers_comparevalue);
            (TIMER2->CR1).BF.DIR = 0;
            (TIMER2->EGR).BF.UG = 0;
            (TIMER2->PSC) = (Config->GPT_Timers_prescalar);
        }
        else if ((Config->GPT_Timers_timer_ID) == (TIMER3_DEF))
        {
            (TIMER3->CR1).BF.ARPE = 0;
            (TIMER3->CR1).BF.URS = 1;
            (TIMER3->ARR) = (Config->GPT_Timers_comparevalue);
            (TIMER3->CR1).BF.DIR = 0;
            (TIMER3->EGR).BF.UG = 0;
            (TIMER3->PSC) = (Config->GPT_Timers_prescalar);
        }
        else if ((Config->GPT_Timers_timer_ID) == (TIMER4_DEF))
        {
            (TIMER4->CR1).BF.ARPE = 0;
            (TIMER4->CR1).BF.URS = 1;
            (TIMER4->ARR) = (Config->GPT_Timers_comparevalue);
            (TIMER4->CR1).BF.DIR = 0;
            (TIMER4->EGR).BF.UG = 0;
            (TIMER4->PSC) = (Config->GPT_Timers_prescalar);
        }
        break;
    case GPT_Encoder_Interface_Mode:
        (TIMER2->PSC) = (Config->GPT_Timers_prescalar);
        (TIMER2->CR1).BF.DIR = 0;
        (TIMER2->ARR) = (Config->GPT_Timers_comparevalue);
        (TIMER2->CR1).BF.CKD = 0b00;
        (TIMER2->CR1).BF.ARPE = 0;
        (TIMER2->SMCR).BF.SMS = 0b011;
        (TIMER2->CCER).BF.CC1P = 1;
        (TIMER2->CCMR1).IBF.CC1S = 0b01;
        (TIMER2->CCMR1).IBF.IC1PSC = 0b00;
        (TIMER2->CCMR1).IBF.IC1F = 0;
        (TIMER2->CCER).BF.CC2P = 0;
        (TIMER2->CCMR1).IBF.CC2S = 0b01;
        (TIMER2->CCMR1).IBF.IC2PSC = 0b00;
        (TIMER2->CCMR1).IBF.IC2F = 0;
        (TIMER2->CCER).BF.CC1E = 1;
        (TIMER2->CCER).BF.CC2E = 1;

        break;
    case GPT_PWM_Mode:
        if ((Config->GPT_Timers_timer_ID) == (TIMER2_DEF) && (Config->GPT_CHANNELS_ID) == (TIMER_CHANNEL1))
        {
            (TIMER2->ARR) = (Config->GPT_Timers_comparevalue);                                       // frequency
            (TIMER2->CCR1) = (Config->GPT_Timers_comparevalue * Config->GPT_Timers_dutycycle) / 100; // Duty Cycle
            (TIMER2->CCMR1).OBF.OC1M = 0b110;                                                        // pwm mode 1
            (TIMER2->CCMR1).OBF.OC1PE = 1;                                                           // pre_load enable
            (TIMER2->CR1).BF.ARPE = 1;
            (TIMER2->EGR).BF.UG = 1;
            (TIMER2->CCER).BF.CC1P = 0; // clock polarity
            (TIMER2->CCER).BF.CC1E = 1;
            (TIMER2->CR1).BF.DIR = 0;
        }
        else if ((Config->GPT_Timers_timer_ID) == (TIMER2_DEF) && (Config->GPT_CHANNELS_ID) == (TIMER_CHANNEL2))
        {
            (TIMER2->ARR) = (Config->GPT_Timers_comparevalue);                                       // frequency
            (TIMER2->CCR2) = (Config->GPT_Timers_comparevalue * Config->GPT_Timers_dutycycle) / 100; // Duty Cycle
            (TIMER2->CCMR1).OBF.OC2M = 0b110;                                                        // pwm mode 1
            (TIMER2->CCMR1).OBF.OC2PE = 1;                                                           // pre_load enable
            (TIMER2->CR1).BF.ARPE = 1;
            (TIMER2->EGR).BF.UG = 1;
            (TIMER2->CCER).BF.CC2P = 0; // clock polarity
            (TIMER2->CCER).BF.CC2E = 1;
            (TIMER2->CR1).BF.DIR = 0;
        }
        else if ((Config->GPT_Timers_timer_ID) == (TIMER2_DEF) && (Config->GPT_CHANNELS_ID) == (TIMER_CHANNEL3))
        {
            (TIMER2->ARR) = (Config->GPT_Timers_comparevalue);                                       // frequency
            (TIMER2->CCR3) = (Config->GPT_Timers_comparevalue * Config->GPT_Timers_dutycycle) / 100; // Duty Cycle
            (TIMER2->CCMR2).OBF.OC3M = 0b110;                                                        // pwm mode 1
            (TIMER2->CCMR2).OBF.OC3PE = 1;                                                           // pre_load enable
            (TIMER2->CR1).BF.ARPE = 1;
            (TIMER2->EGR).BF.UG = 1;
            (TIMER2->CCER).BF.CC3P = 0; // clock polarity
            (TIMER2->CCER).BF.CC3E = 1;
            (TIMER2->CR1).BF.DIR = 0;
        }
        else if ((Config->GPT_Timers_timer_ID) == (TIMER2_DEF) && (Config->GPT_CHANNELS_ID) == (TIMER_CHANNEL4))
        {
            (TIMER2->ARR) = (Config->GPT_Timers_comparevalue);                                       // frequency
            (TIMER2->CCR4) = (Config->GPT_Timers_comparevalue * Config->GPT_Timers_dutycycle) / 100; // Duty Cycle
            (TIMER2->CCMR2).OBF.OC4M = 0b110;                                                        // pwm mode 1
            (TIMER2->CCMR2).OBF.OC4PE = 1;                                                           // pre_load enable
            (TIMER2->CR1).BF.ARPE = 1;
            (TIMER2->EGR).BF.UG = 1;
            (TIMER2->CCER).BF.CC4P = 0; // clock polarity
            (TIMER2->CCER).BF.CC4E = 1;
            (TIMER2->CR1).BF.DIR = 0;
        }

        else if ((Config->GPT_Timers_timer_ID) == (TIMER3_DEF) && (Config->GPT_CHANNELS_ID) == (TIMER_CHANNEL1))
        {

            (TIMER3->ARR) = (Config->GPT_Timers_comparevalue);                                       // frequency
            (TIMER3->CCR1) = (Config->GPT_Timers_comparevalue * Config->GPT_Timers_dutycycle) / 100; // Duty Cycle
            (TIMER3->CCMR1).OBF.OC1M = 0b110;                                                        // pwm mode 1
            (TIMER3->CCMR1).OBF.OC1PE = 1;                                                           // pre_load enable
            (TIMER3->CR1).BF.ARPE = 1;
            (TIMER3->EGR).BF.UG = 1;
            (TIMER3->CCER).BF.CC1P = 0; // clock polarity
            (TIMER3->CCER).BF.CC1E = 1;
            (TIMER3->CR1).BF.DIR = 0;
        }
        else if ((Config->GPT_Timers_timer_ID) == (TIMER3_DEF) && (Config->GPT_CHANNELS_ID) == (TIMER_CHANNEL2))
        {

            (TIMER3->ARR) = (Config->GPT_Timers_comparevalue);                                       // frequency
            (TIMER3->CCR2) = (Config->GPT_Timers_comparevalue * Config->GPT_Timers_dutycycle) / 100; // Duty Cycle
            (TIMER3->CCMR1).OBF.OC2M = 0b110;                                                        // pwm mode 1
            (TIMER3->CCMR1).OBF.OC2PE = 1;                                                           // pre_load enable
            (TIMER3->CR1).BF.ARPE = 1;
            (TIMER3->EGR).BF.UG = 1;
            (TIMER3->CCER).BF.CC2P = 0; // clock polarity
            (TIMER3->CCER).BF.CC2E = 1;
            (TIMER3->CR1).BF.DIR = 0;
        }
        else if ((Config->GPT_Timers_timer_ID) == (TIMER3_DEF) && (Config->GPT_CHANNELS_ID) == (TIMER_CHANNEL3))
        {

            (TIMER3->ARR) = (Config->GPT_Timers_comparevalue);                                       // frequency
            (TIMER3->CCR3) = (Config->GPT_Timers_comparevalue * Config->GPT_Timers_dutycycle) / 100; // Duty Cycle
            (TIMER3->CCMR2).OBF.OC3M = 0b110;                                                        // pwm mode 1
            (TIMER3->CCMR2).OBF.OC3PE = 1;                                                           // pre_load enable
            (TIMER3->CR1).BF.ARPE = 1;
            (TIMER3->EGR).BF.UG = 1;
            (TIMER3->CCER).BF.CC3P = 0; // clock polarity
            (TIMER3->CCER).BF.CC3E = 1;
            (TIMER3->CR1).BF.DIR = 0;
        }
        else if ((Config->GPT_Timers_timer_ID) == (TIMER3_DEF) && (Config->GPT_CHANNELS_ID) == (TIMER_CHANNEL4))
        {

            (TIMER3->ARR) = (Config->GPT_Timers_comparevalue);                                       // frequency
            (TIMER3->CCR4) = (Config->GPT_Timers_comparevalue * Config->GPT_Timers_dutycycle) / 100; // Duty Cycle
            (TIMER3->CCMR2).OBF.OC4M = 0b110;                                                        // pwm mode 1
            (TIMER3->CCMR2).OBF.OC4PE = 1;                                                           // pre_load enable
            (TIMER3->CR1).BF.ARPE = 1;
            (TIMER3->EGR).BF.UG = 1;
            (TIMER3->CCER).BF.CC4P = 0; // clock polarity
            (TIMER3->CCER).BF.CC4E = 1;
            (TIMER3->CR1).BF.DIR = 0;
        }
        else if ((Config->GPT_Timers_timer_ID) == (TIMER4_DEF))
        {
            (TIMER4->ARR) = (Config->GPT_Timers_comparevalue);                                       // frequancy
            (TIMER4->CCR1) = (Config->GPT_Timers_comparevalue * Config->GPT_Timers_dutycycle) / 100; // Duty Cycle
            (TIMER4->CCMR1).OBF.OC1M = 0b110;                                                        // pwm mode 1
            (TIMER4->CCMR1).OBF.OC1PE = 1;                                                           // pre_load enable
            (TIMER4->CR1).BF.ARPE = 1;
            (TIMER4->EGR).BF.UG = 1;
            (TIMER4->CCER).BF.CC1P = 0; // clock polarity
            (TIMER4->CCER).BF.CC1E = 1;
            (TIMER4->CR1).BF.DIR = 0;
        }

        break;

        // default
    }
}

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
void GPT_PWMInit(GPT_G1timers Timer, GPT_compare_val CompareValue, GPT_duty_cycle_val DutyCycle)
{
    if (Timer == TIMER2_DEF)
    {
          switch (GPT_config2.GPT_CHANNELS_ID)
        {
            case TIMER_CHANNEL1:
        if ((TIMER2->CCMR1).OBF.OC1M == 0b110)
        {
            (TIMER2->ARR) = (CompareValue);                    // frequency
            (TIMER2->CCR1) = (CompareValue * DutyCycle) / 100; // Duty Cycle
        }
        break;
        case TIMER_CHANNEL2:
        if ((TIMER2->CCMR1).OBF.OC2M == 0b110)
        {
            (TIMER2->ARR) = (CompareValue);                    // frequency
            (TIMER2->CCR2) = (CompareValue * DutyCycle) / 100; // Duty Cycle
        }
        break;
        case TIMER_CHANNEL3:
        if ((TIMER2->CCMR2).OBF.OC3M == 0b110)
        {
            (TIMER2->ARR) = (CompareValue);                    // frequency
            (TIMER2->CCR3) = (CompareValue * DutyCycle) / 100; // Duty Cycle
        }
        break;
        case TIMER_CHANNEL4:
        if ((TIMER2->CCMR2).OBF.OC4M == 0b110)
        {
            (TIMER2->ARR) = (CompareValue);                    // frequency
            (TIMER2->CCR4) = (CompareValue * DutyCycle) / 100; // Duty Cycle
        }
        break;
        }
    }

    if (Timer == TIMER3_DEF)
    {
          switch (GPT_config2.GPT_CHANNELS_ID)
        {
            case TIMER_CHANNEL1:
        if ((TIMER3->CCMR1).OBF.OC1M = 0b110)
        {
            (TIMER3->ARR) = (CompareValue);                    // frequency
            (TIMER3->CCR1) = (CompareValue * DutyCycle) / 100; // Duty Cycle
        }
        break;
         case TIMER_CHANNEL2:
        if ((TIMER3->CCMR1).OBF.OC2M = 0b110)
        {
            (TIMER3->ARR) = (CompareValue);                    // frequency
            (TIMER3->CCR2) = (CompareValue * DutyCycle) / 100; // Duty Cycle
        }
        break;
         case TIMER_CHANNEL3:
        if ((TIMER3->CCMR2).OBF.OC3M = 0b110)
        {
            (TIMER3->ARR) = (CompareValue);                    // frequency
            (TIMER3->CCR3) = (CompareValue * DutyCycle) / 100; // Duty Cycle
        }
        break;
         case TIMER_CHANNEL4:
        if ((TIMER3->CCMR2).OBF.OC4M = 0b110)
        {
            (TIMER3->ARR) = (CompareValue);                    // frequency
            (TIMER3->CCR4) = (CompareValue * DutyCycle) / 100; // Duty Cycle
        }
        break;
        }
    }

    if (Timer == TIMER4_DEF)
    {
        if ((TIMER4->CCMR1).OBF.OC1M = 0b110)
        {
            (TIMER4->ARR) = (CompareValue);                    // frequency
            (TIMER4->CCR1) = (CompareValue * DutyCycle) / 100; // Duty Cycle
        }
    }
}

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
void GPT_StartG1Timer(GPT_G1timers timer)
{
    switch (timer)
    {
    case TIMER2_DEF:
        (TIMER2->CR1).BF.CEN = 1;
        break;
    case TIMER3_DEF:
        (TIMER3->CR1).BF.CEN = 1;
        break;
    case TIMER4_DEF:
        (TIMER4->CR1).BF.CEN = 1;
        break;
    default:
        /*[TO DO] error handling*/
        break;
    }
}

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
void GPT_StopG1Timer(GPT_G1timers timer)
{
    switch (timer)
    {
    case TIMER2_DEF:
        (TIMER2->CR1).BF.CEN = 0;
        break;
    case TIMER3_DEF:
        (TIMER3->CR1).BF.CEN = 0;
        break;
    case TIMER4_DEF:
        (TIMER4->CR1).BF.CEN = 0;
        break;
    default:
        /*[TO DO] error handling*/
        break;
    }
}
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
void GPT_EnableInterrupts(Configtype_timer *Config)
{
    /*UIE-->*/
    switch (Config->GPT_Timers_timer_ID)
    {
    case TIMER2_DEF:
        (TIMER2->CR1).BF.UDIS = 0;
        switch (Config->GPT_CHANNELS_ID)
        {
        case TIMER_CHANNEL1:
            (TIMER2->DIER).BF.CC1IE = 1;
            break;
        case TIMER_CHANNEL2:
            (TIMER2->DIER).BF.CC2IE = 1;
            break;
        case TIMER_CHANNEL3:
            (TIMER2->DIER).BF.CC3IE = 1;
            break;
        case TIMER_CHANNEL4:
            (TIMER2->DIER).BF.CC4IE = 1;
            break;
        }
        (TIMER2->DIER).BF.UIE = 1;
        break;
    case TIMER3_DEF:
        (TIMER3->CR1).BF.UDIS = 0;

        switch (Config->GPT_CHANNELS_ID)
        {
        case TIMER_CHANNEL1:
            (TIMER3->DIER).BF.CC1IE = 1;
            break;
        case TIMER_CHANNEL2:
            (TIMER3->DIER).BF.CC2IE = 1;
            break;
        case TIMER_CHANNEL3:
            (TIMER3->DIER).BF.CC3IE = 1;
            break;
        case TIMER_CHANNEL4:
            (TIMER3->DIER).BF.CC4IE = 1;
            break;
        }
        (TIMER3->DIER).BF.UIE = 1;

        break;
    case TIMER4_DEF:
        (TIMER4->CR1).BF.UDIS = 0;

        (TIMER4->DIER).BF.CC1IE = 1;

        (TIMER4->DIER).BF.UIE = 1;

        break;
    default:
        /*[TO DO] error handling*/
        break;
    }
}
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
void GPT_DisableInterrupts(GPT_G1timers timer)
{
    switch (timer)
    {
    case TIMER2_DEF:
        (TIMER2->CR1).BF.UDIS = 1;
        (TIMER2->DIER).BF.CC1IE = 0;
        (TIMER2->DIER).BF.UIE = 0;

        break;
    case TIMER3_DEF:
        (TIMER3->CR1).BF.UDIS = 1;
        (TIMER3->DIER).BF.CC1IE = 0;
        (TIMER3->DIER).BF.UIE = 0;

        break;
    case TIMER4_DEF:
        (TIMER4->CR1).BF.UDIS = 1;
        (TIMER4->DIER).BF.CC1IE = 0;
        (TIMER4->DIER).BF.UIE = 0;

        break;
    default:
        /*[TO DO] error handling*/
        break;
    }
}
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
uint32 Gpt_GetCountsElapsed(GPT_G1timers timer)
{
    switch (timer)
    {
        uint32 elpased_time;
    case TIMER2_DEF:
        elpased_time = (TIMER2->CNT);
        return elpased_time;
        break;
    case TIMER3_DEF:
        elpased_time = (uint32) (TIMER3->CNT);
        return elpased_time;
        break;
    case TIMER4_DEF:
        elpased_time = (TIMER4->CNT);
        return elpased_time;
        break;
    default:
        /*[TO DO] error handling*/
        break;
    }
}
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
uint32 Gpt_GetCountsRemaining(GPT_G1timers timer)
{
    switch (timer)
    {
        uint32 no_of_counts_remaining;
    case TIMER2_DEF:
        no_of_counts_remaining = (TIMER2->ARR) - (TIMER2->CNT);
        return no_of_counts_remaining;
        break;
    case TIMER3_DEF:
        no_of_counts_remaining = (TIMER3->ARR) - (TIMER3->CNT);
        return no_of_counts_remaining;
        break;
    case TIMER4_DEF:
        no_of_counts_remaining = (TIMER4->ARR) - (TIMER4->CNT);
        return no_of_counts_remaining;
        break;
    default:
        /*[TO DO] error handling*/
        break;
    }
}

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
void GPT_SetCallBack(void (*Ptr2Func)(uint8 Edge_Type), GPT_G1timers ID)
{
    switch (ID)
    {
    case TIMER2_DEF:
        g_GPT_Timer2_Call_Back_Ptr = Ptr2Func;
        break;

    case TIMER3_DEF:
        g_GPT_Timer3_Call_Back_Ptr = Ptr2Func;
        break;

    case TIMER4_DEF:
        g_GPT_Timer4_Call_Back_Ptr = Ptr2Func;
        break;
    }
}

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

void MTIM4_voidICUInit()
{
    /*set the prescaler*/
    TIMER4->PSC = 7;

    /* Reset Counter */
    TIMER4->CNT = 0;

    /*set the maximum value of the count*/
    TIMER4->ARR = 0xFFFF;

    /* Select the active input: TIMx_CCR1 must be linked to the TI1 input */
    TIMER4->CCMR2.IBF.CC4S = 0X01;

    /* selects the trigger input to be used to synchronize the counter , 101:Filtered Timer Input 1 (TI1FP1)*/
    TIMER4->SMCR.BF.TS = 5;

    /* Enable capture from the counter into the capture register by setting the CC1E bit in the TIMx_CCER register */
    /* 0: Capture disabled.
       1: Capture enabled. */
    TIMER4->CCER.BF.CC4E = 1;

    /* Enable the related interrupt request by setting the CC1IE bit in the TIMx_DIER register, */
    /* Bit 1 CC1IE: Capture/Compare 1 interrupt enable
    0: CC1 interrupt disabled.
    1: CC1 interrupt enabled. */
    TIMER4->DIER.BF.CC4IE = 1;

    /*enable timer to start count*/
    TIMER4->CR1.BF.CEN = 1;
}

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

uint16 MTIM4_GetDistance()
{
    distance = pulse_duration / 59;
    return distance;
}

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
uint16 MTIM4_GetCapture(void)
{
    /* If channel CC1is configured as input:
        CCR1 is the counter value transferred by the last input capture 1 event (IC1). The
        TIMx_CCR1 register is read-only and cannot be programmed */
    return TIMER4->CCR4;
}

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
void MTIM4_voidSetEdgeDetectionType(uint8 EDGE_TYPE)
{
    if (EDGE_TYPE == RISING_EDGE)
    {
        TIMER4->CCER.BF.CC4P = 0;
    }
    else if (EDGE_TYPE == FALLING_EDGE)
    {
        TIMER4->CCER.BF.CC4P = 1;
    }
}

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
void delaySeconds(GPT_G1timers timer, float32 seconds)
{
    Configtype_timer GPT_config_overflow = {
        timer, TIMER_CHANNEL2, Direction_Up, GPT_OverFlow_Mode, 1, 0, 65535, 0};
    uint32 counts_elapsed = 0;

    // Calculate the number of timer ticks needed for the delay
    uint32 ticks = seconds * (SYS_CLK)/2;
    uint32 num_overflows = ticks / 65535;
    uint32 remaining_ticks = (uint32)ticks % 65535;
    TIMER_init(&GPT_config_overflow);
    GPT_StartG1Timer(timer);
uint32 i = 0;

    for ( i = 0; i < num_overflows; i++)
    {
        while(!(TIMER3->SR.BF.UIF));
        TIMER3->SR.BF.UIF = 0;
    }
    // Wait for the required number of ticks
    while (Gpt_GetCountsElapsed(timer) < remaining_ticks);
}
void delaymilliSeconds(GPT_G1timers timer, uint32 milliseconds)
{
       Configtype_timer GPT_config_overflow = {
        timer, TIMER_CHANNEL2, Direction_Up, GPT_OverFlow_Mode, 1, 0, 65535, 0};
    uint32 counts_elapsed = 0;
    uint32 i = 0;
    // Calculate the number of timer ticks needed for the delay
    uint32 ticks = milliseconds * (SYS_CLK)/1000;
    uint32 num_overflows = ticks / 65535;
    uint32 remaining_ticks = (uint32)ticks % 65535;
    TIMER_init(&GPT_config_overflow);
    GPT_StartG1Timer(timer);

   for ( i = 0; i < num_overflows; i++)
    {
        while(!(TIMER3->SR.BF.UIF));
        TIMER3->SR.BF.UIF = 0;
    }
    // Wait for the required number of ticks
    while (Gpt_GetCountsElapsed(timer) < remaining_ticks);
}
void delaymicroSeconds(GPT_G1timers timer, uint32 microseconds)
{
     Configtype_timer GPT_config_overflow = {
        timer, TIMER_CHANNEL2, Direction_Up, GPT_OverFlow_Mode, 1, 0, 65535, 0};
    uint32 counts_elapsed = 0;
uint32 i = 0;

    // Calculate the number of timer ticks needed for the delay
    uint32 ticks = microseconds * (SYS_CLK)/2000000;
    uint32 num_overflows = ticks / 65535;
    uint32 remaining_ticks = (uint32)ticks % 65535;
    TIMER_init(&GPT_config_overflow);
    GPT_StartG1Timer(timer);
     for ( i = 0; i < num_overflows; i++)
    {
        while(!(TIMER3->SR.BF.UIF));
        TIMER3->SR.BF.UIF = 0;
    }
    // Wait for the required number of ticks
    while ((TIMER3->CNT) < remaining_ticks);
}


