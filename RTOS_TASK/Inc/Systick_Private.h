/*
 * Systick_Private.h
 *
 *  Created on: Jul 26, 2023
 *      Author: HP
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

#include "Std_Types.h"

typedef struct {
	    volatile uint32 CTRL    ;
	    volatile uint32 LOAD    ;
	    volatile uint32 VAL     ;
	    volatile uint32 CALIB   ;
} SYSTICK_TypeDef;

#define SysTick (( SYSTICK_TypeDef *)0xE000E010 )


#define PRESCALAR_CLOCK   0x0
#define PROCESSOR_CLOCK   0x4

#define TICKINT_ENABLE            0x2
#define TICKINT_DISABLE           0x0

#define COUNTER_ENABLE            0x1
#define COUNTER_DISABLE           0x0


// SYSTICK_CTRL Register
#define SYSTICK_CTRL_ENABLE         0
#define SYSTICK_CTRL_TICKINT        1 // generates interrupt request
#define SYSTICK_CTRL_CLKSOURCE      2
#define SYSTICK_CTRL_COUNTFLAG      16 // interrupt flag

// SYSTICK_LOAD Register
#define SYSTICK_LOAD_RELOAD         0

// SYSTICK_VAL Register
#define SYSTICK_VAL_CURRENT         0

// SYSTICK_CALIB Register
#define SYSTICK_CALIB_TENMS         0
#define SYSTICK_CALIB_SKEW          30
#define SYSTICK_CALIB_NOREF         31

//CallBack pointer
void (*SysTickCallback) (void);

#endif /* SYSTICK_PRIVATE_H_ */
