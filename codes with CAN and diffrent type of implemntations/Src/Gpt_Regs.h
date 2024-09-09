/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Gpt_Regs.h
 *  Module:  	  GPT
 *  Description:  This file contains the definition of registers of GPT
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Salma Hisham & Mohamed Emad & Mohamed Hesham
 *	Date:		  29/10/2023
 *********************************************************************************************************************/
#ifndef GPT_REGS_H
#define GPT_REGS_H
#include "Std_Types.h"

#define TIMER2 ((volatile GPT_G1_t *)0x40000000)
#define TIMER3 ((volatile GPT_G1_t *)0x40000400)
#define TIMER4 ((volatile GPT_G1_t *)0x40000800)
#define TIMER5 ((volatile GPT_G1_t *)0x40000C00)
#define TIMER9 ((volatile GPT_G2_t *)0x40014C00)
#define TIMER10 ((volatile GPT_G3_t *)0x40015000)
#define TIMER11 ((volatile GPT_G3_t *)0x40015400)
#define TIMER12 ((volatile GPT_G2_t *)0x40001800)
#define TIMER13 ((volatile GPT_G3_t *)0x40001C00)
#define TIMER14 ((volatile GPT_G3_t *)0x40002000)
/**********************************************************************************************************************
 *                                      Bit_fields                                                                    *
 *********************************************************************************************************************/
typedef struct
{
    uint32 CEN : 1;
    uint32 UDIS : 1;
    uint32 URS : 1;
    uint32 OPM : 1;
    uint32 DIR : 1;
    uint32 CMS : 2;
    uint32 ARPE : 1;
    uint32 CKD : 2;
    uint32 : 22;
} GPT_G1_CR1_BF;

typedef struct
{
    uint32 : 3;
    uint32 CCDS : 1;
    uint32 MMS : 3;
    uint32 TI1S : 1;
    uint32 : 24;
} GPT_G1_CR2_BF;

typedef struct
{
    uint32 SMS : 3;
    uint32 : 1;
    uint32 TS : 3;
    uint32 MSM : 1;
    uint32 ETF : 4;
    uint32 ETPS : 2;
    uint32 ECE : 1;
    uint32 ETP : 1;
    uint32 : 16;
} GPT_G1_SMCR_BF;

typedef struct
{
    uint32 UIE : 1;
    uint32 CC1IE : 1;
    uint32 CC2IE : 1;
    uint32 CC3IE : 1;
    uint32 CC4IE : 1;
    uint32 : 1;
    uint32 TIE : 1;
    uint32 : 1;
    uint32 UDE : 1;
    uint32 CC1DE : 1;
    uint32 CC2DE : 1;
    uint32 CC3DE : 1;
    uint32 CC4DE : 1;
    uint32 COMDE : 1;
    uint32 TDE : 1;
    uint32 : 17;
} GPT_G1_DIER_BF;

typedef struct
{
    uint32 UIF : 1;
    uint32 CC1IF : 1;
    uint32 CC2IF : 1;
    uint32 CC3IF : 1;
    uint32 CC4IF : 1;
    uint32 : 1;
    uint32 TIF : 1;
    uint32 : 2;
    uint32 CC1OF : 1;
    uint32 CC2OF : 1;
    uint32 CC3OF : 1;
    uint32 CC4OF : 1;
    uint32 : 19;
} GPT_G1_SR_BF;

typedef struct
{
    uint32 UG : 1;
    uint32 CC1G : 1;
    uint32 CC2G : 1;
    uint32 CC3G : 1;
    uint32 CC4G : 1;
    uint32 : 1;
    uint32 TG : 1;
    uint32 : 25;
} GPT_G1_EGR_BF;

typedef struct
{
    uint32 CC1S : 2;
    uint32 OC1FE : 1;
    uint32 OC1PE : 1;
    uint32 OC1M : 3;
    uint32 OC1CE : 1;
    uint32 CC2S : 2;
    uint32 OC2FE : 1;
    uint32 OC2PE : 1;
    uint32 OC2M : 3;
    uint32 OC2CE : 1;
    uint32 : 16;
} GPT_G1_CCMR1_OC_BF;

typedef struct
{
    uint32 CC1S : 2;
    uint32 IC1PSC : 2;
    uint32 IC1F : 4;
    uint32 CC2S : 2;
    uint32 IC2PSC : 2;
    uint32 IC2F : 4;
    uint32 : 16;
} GPT_G1_CCMR1_IC_BF;

typedef struct
{
    uint32 CC3S : 2;
    uint32 OC3FE : 1;
    uint32 OC3PE : 1;
    uint32 OC3M : 3;
    uint32 OC3CE : 1;
    uint32 CC4S : 2;
    uint32 OC4FE : 1;
    uint32 OC4PE : 1;
    uint32 OC4M : 3;
    uint32 OC4CE : 1;
    uint32 : 16;
} GPT_G1_CCMR2_OC_BF;

typedef struct
{
    uint32 CC3S : 2;
    uint32 IC3PSC : 2;
    uint32 IC3F : 4;
    uint32 CC4S : 2;
    uint32 IC4PSC : 2;
    uint32 IC4F : 4;
    uint32 : 16;
} GPT_G1_CCMR2_IC_BF;

typedef struct
{
    uint32 CC1E : 1;
    uint32 CC1P : 1;
    uint32 : 2;
    uint32 CC2E : 1;
    uint32 CC2P : 1;
    uint32 : 2;
    uint32 CC3E : 1;
    uint32 CC3P : 1;
    uint32 : 2;
    uint32 CC4E : 1;
    uint32 CC4P : 1;
    uint32 : 18;
} GPT_G1_CCER_BF;

typedef struct
{
    uint32 DBA : 5;
    uint32 : 3;
    uint32 DBL : 5;
    uint32 : 19;
} GPT_G1_DCR_BF;
/**********************************************************************************************************************
 *                                         Unions                                                                     *
 **********************************************************************************************************************/
typedef union
{
    GPT_G1_CR1_BF BF;
    uint32 R;
} GPT_G1_CR1_union;

typedef union
{
    GPT_G1_CR2_BF BF;
    uint32 R;
} GPT_G1_CR2_union;

typedef union
{
    GPT_G1_SMCR_BF BF;
    uint32 R;
} GPT_G1_SMCR_union;

typedef union
{
    GPT_G1_DIER_BF BF;
    uint32 R;
} GPT_G1_DIER_union;
typedef union
{
    GPT_G1_SR_BF BF;
    uint32 R;
} GPT_G1_SR_union;
typedef union
{
    GPT_G1_EGR_BF BF;
    uint32 R;
} GPT_G1_EGR_union;
typedef union
{
    GPT_G1_CCMR1_OC_BF OBF;
    GPT_G1_CCMR1_IC_BF IBF;
    uint32 R;
} GPT_G1_CCMR1_union;
typedef union
{
    GPT_G1_CCMR2_OC_BF OBF;
    GPT_G1_CCMR2_IC_BF IBF;
    uint32 R;
} GPT_G1_CCMR2_union;
typedef union
{
    GPT_G1_CCER_BF BF;
    uint32 R;
} GPT_G1_CCER_union;

typedef union
{
    GPT_G1_DCR_BF BF;
    uint32 R;
} GPT_G1_DCR_union;
/**********************************************************************************************************************
 *                                      Registers                                                                     *
 **********************************************************************************************************************/
/*Registers and bits of G1 : timers 2 -> 5 */
typedef struct
{
    volatile GPT_G1_CR1_union CR1;
    volatile GPT_G1_CR2_union CR2;
    volatile GPT_G1_SMCR_union SMCR;
    volatile GPT_G1_DIER_union DIER;
    volatile GPT_G1_SR_union SR;
    volatile GPT_G1_EGR_union EGR;
    volatile GPT_G1_CCMR1_union CCMR1;
    volatile GPT_G1_CCMR2_union CCMR2;
    volatile GPT_G1_CCER_union CCER;
    volatile uint32 CNT;
    volatile uint32 PSC;
    volatile uint32 ARR;
    volatile uint32 RESERVED;
    volatile uint32 CCR1;
    volatile uint32 CCR2;
    volatile uint32 CCR3;
    volatile uint32 CCR4;
    volatile uint32 RESERVED2;
    volatile GPT_G1_DCR_union DCR;
    volatile uint32 DMAR;
} GPT_G1_t;

#endif