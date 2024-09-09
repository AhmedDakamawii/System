/*
 * Systick_Interface.h
 *
 *  Created on: Jul 26, 2023
 *      Author: HP
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_

#include "Det.h"
#include "Std_Types.h"
#include "Bit_Math.h"

void    MSTK_voidInit();
void    MSTK_voidSetBusyWait( uint32 Copy_u32Ticks );
void    MSTK_voidSetSingleInterval  ( uint32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void    MSTK_voidSetPeriodicInterval( uint32 Copy_u32Ticks, void (*Copy_ptr)(void) );
void    MSTK_voidStopInterval(void);
uint32  MSTK_u32GetElapsedTime(void);

#endif /* SYSTICK_INTERFACE_H_ */
