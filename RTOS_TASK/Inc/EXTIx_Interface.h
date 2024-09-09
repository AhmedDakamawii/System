/**
*@file       EXTIx_Interface.h
*@version    1.0.0
*@brief      MCAL ................
*@details    ...........................
*@author     Shehab aldeen mohammed abdalah
*/

#ifndef EXTIX_INTERFACE_H_
#define EXTIX_INTERFACE_H_

#include "Std_Types.h"
#include "Det.h"
#include "Bit_Math.h"

typedef enum {
	PINAx,
	PINBx,
	PINCx
}PIN_Enum;

typedef enum {
	EXTI0,
	EXTI1,
	EXTI2,
	EXTI3,
	EXTI4,
	EXTI5,
	EXTI6,
	EXTI7,
	EXTI8,
	EXTI9,
	EXTI10,
	EXTI11,
	EXTI12,
	EXTI13,
	EXTI14,
	EXTI15
}EXTI_Enum;

typedef enum {
	EXTI0_Flag  = 0x00000001 ,
	EXTI1_Flag  = 0x00000002 ,
	EXTI2_Flag  = 0x00000004 ,
	EXTI3_Flag  = 0x00000008 ,
	EXTI4_Flag  = 0x00000010 ,
	EXTI5_Flag  = 0x00000020 ,
	EXTI6_Flag  = 0x00000040 ,
	EXTI7_Flag  = 0x00000080 ,
	EXTI8_Flag  = 0x00000100 ,
	EXTI9_Flag  = 0x00000200 ,
	EXTI10_Flag  = 0x00000400 ,
	EXTI11_Flag  = 0x00000800 ,
	EXTI12_Flag  = 0x00001000 ,
	EXTI13_Flag  = 0x00002000 ,
	EXTI14_Flag  = 0x00004000 ,
	EXTI15_Flag  = 0x00008000
}Flag_Enum;

typedef enum {
	EXTI0_INT_Active  = 0x00000001 ,
	EXTI1_INT_Active  = 0x00000002 ,
	EXTI2_INT_Active  = 0x00000004 ,
	EXTI3_INT_Active  = 0x00000008 ,
	EXTI4_INT_Active  = 0x00000010 ,
	EXTI5_INT_Active  = 0x00000020 ,
	EXTI6_INT_Active  = 0x00000040 ,
	EXTI7_INT_Active  = 0x00000080 ,
	EXTI8_INT_Active  = 0x00000100 ,
	EXTI9_INT_Active  = 0x00000200 ,
	EXTI10_INT_Active  = 0x00000400 ,
	EXTI11_INT_Active  = 0x00000800 ,
	EXTI12_INT_Active  = 0x00001000 ,
	EXTI13_INT_Active  = 0x00002000 ,
	EXTI14_INT_Active  = 0x00004000 ,
	EXTI15_INT_Active  = 0x00008000 ,

	EXTI0_Event_Active  = 0x00010001 ,
	EXTI1_Event_Active  = 0x00010002 ,
	EXTI2_Event_Active  = 0x00010004 ,
	EXTI3_Event_Active  = 0x00010008 ,
	EXTI4_Event_Active  = 0x00010010 ,
	EXTI5_Event_Active  = 0x00010020 ,
	EXTI6_Event_Active  = 0x00010040 ,
	EXTI7_Event_Active  = 0x00010080 ,
	EXTI8_Event_Active  = 0x00010100 ,
	EXTI9_Event_Active  = 0x00010200 ,
	EXTI10_Event_Active  = 0x00010400 ,
	EXTI11_Event_Active  = 0x00010800 ,
	EXTI12_Event_Active  = 0x00011000 ,
	EXTI13_Event_Active  = 0x00012000 ,
	EXTI14_Event_Active  = 0x00014000 ,
	EXTI15_Event_Active  = 0x00018000
}IntOrEventActive_Enum;

#define FALLING_EDGE         0
#define RISING_EDGE          1
#define BOTH_EDGES           2

void EXTI_ConfigLine             (EXTI_Enum EXTI_Line , PIN_Enum PIN ,IntOrEventActive_Enum IntOrEveActive,uint8 edge);
void EXTI_SW_InterruptEnable     (Flag_Enum Copy_uint8Flag);
void EXTI_ClearPending           (Flag_Enum Copy_uint8Flag);

#endif /* EXTIX_INTERFACE_H_ */
