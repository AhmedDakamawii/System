/***************************************************************************/
/*  Author     :   Ahmed Atef                                              */
/*  Date       :   16/8/2023                                               */
/*  Version    :   V01                                                     */
/***************************************************************************/

#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

/* TIM(2->5) : APB1 Bus */


/* Define Timer Registers*/
typedef struct{
	volatile u32 CR1         ;
	volatile u32 CR2         ;
	volatile u32 SMCR        ;
	volatile u32 DIER        ;
	volatile u32 SR          ;
	volatile u32 EGR         ;
	volatile u32 CCMR1       ;
	volatile u32 CCMR2       ;
	volatile u32 CCER        ;
	volatile u32 CNT         ;
	volatile u32 PSC         ;
	volatile u32 ARR         ;
	volatile u32 RESERVED    ;
	volatile u32 CCR[4]      ;
	volatile u32 RESERVED2   ;
	volatile u32 DCR         ;
	volatile u32 DMAR        ;
}Timer_t;


/* Define Timer Addresses */
#define MTIM2                      ((volatile Timer_t*)0x40000000)
#define MTIM3                      ((volatile Timer_t*)0x40000400)
#define MTIM4                      ((volatile Timer_t*)0x40000800)

#define F_CPU                      8000000  /* Working Frequency on MCU */

#define REG_MAX                    65535    /* Max Value in Registers of 16 Bits only */

/* Options For Timer Status */
#define ON                         1
#define OFF                        0


/* Options For Interval */
#define MTIM_Single_Interval       1
#define MTIM_Periodic_Interval     2

/* Options For Timer Modes */
#define PWM_MODE                   0
#define OUTPUT_CAPTURE_MODE        1

/*
 * 3 Timer CallBacks( Pointer To Function ) :
 * TIM_CALLBACK[0] for Timer 2
 * TIM_CALLBACK[1] for Timer 3
 * TIM_CALLBACK[2] for Timer 4
*/
void (* TIM_CALLBACK[3])(void);

/* TIMER ISR Functions */
void TIM2_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);

#endif
