/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Dio_Regs.h
 *  Module:  	  Dio_Regs
 *
 *  Description:  Header file for Dio Registers
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  27/9/2022
 *********************************************************************************************************************/

#ifndef DIO_REGS_H_
#define DIO_REGS_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_types.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define MGPIOA ((volatile GPIO *)0x40010800)
#define MGPIOB ((volatile GPIO *)0x40010C00)
#define MGPIOC ((volatile GPIO *)0x40011000)
#define AFIO   ((volatile AFIO_t *)0x40010000)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* Implementation of CRL bit field*/
typedef struct
{
	uint32 MODE0 : 2;
	uint32 CNF0 : 2;
	uint32 MODE1 : 2;
	uint32 CNF1 : 2;
	uint32 MODE2 : 2;
	uint32 CNF2 : 2;
	uint32 MODE3 : 2;
	uint32 CNF3 : 2;
	uint32 MODE4 : 2;
	uint32 CNF4 : 2;
	uint32 MODE5 : 2;
	uint32 CNF5 : 2;
	uint32 MODE6 : 2;
	uint32 CNF6 : 2;
	uint32 MODE7 : 2;
	uint32 CNF7 : 2;
} GPIO_CRL_BF;

typedef union
{
	uint32 REG;
	GPIO_CRL_BF BF;
} CRL_Type;

/* Implementation of CRH bit field*/
typedef struct
{
	uint32 MODE8 : 2;
	uint32 CNF8 : 2;
	uint32 MODE9 : 2;
	uint32 CNF9 : 2;
	uint32 MODE10 : 2;
	uint32 CNF10 : 2;
	uint32 MODE11 : 2;
	uint32 CNF11 : 2;
	uint32 MODE12 : 2;
	uint32 CNF12 : 2;
	uint32 MODE13 : 2;
	uint32 CNF13 : 2;
	uint32 MODE14 : 2;
	uint32 CNF14 : 2;
	uint32 MODE15 : 2;
	uint32 CNF15 : 2;
} GPIO_CRH_BF;

typedef union
{
	uint32 REG;
	GPIO_CRH_BF BF;
} CRH_Type;

/* Implementation of IDR bit field*/
typedef struct
{
	uint32 IDR0 : 1;
	uint32 IDR1 : 1;
	uint32 IDR2 : 1;
	uint32 IDR3 : 1;
	uint32 IDR4 : 1;
	uint32 IDR5 : 1;
	uint32 IDR6 : 1;
	uint32 IDR7 : 1;
	uint32 IDR8 : 1;
	uint32 IDR9 : 1;
	uint32 IDR10 : 1;
	uint32 IDR11 : 1;
	uint32 IDR12 : 1;
	uint32 IDR13 : 1;
	uint32 IDR14 : 1;
	uint32 IDR15 : 1;
	uint32 : 0;
} GPIO_IDR_BF;

typedef union
{
	uint32 REG;
	GPIO_IDR_BF BF;
} IDR_Type;

/* Implementation of ODR bit field*/
typedef struct
{
	uint32 ODR0 : 1;
	uint32 ODR1 : 1;
	uint32 ODR2 : 1;
	uint32 ODR3 : 1;
	uint32 ODR4 : 1;
	uint32 ODR5 : 1;
	uint32 ODR6 : 1;
	uint32 ODR7 : 1;
	uint32 ODR8 : 1;
	uint32 ODR9 : 1;
	uint32 ODR10 : 1;
	uint32 ODR11 : 1;
	uint32 ODR12 : 1;
	uint32 ODR13 : 1;
	uint32 ODR14 : 1;
	uint32 ODR15 : 1;
	uint32 : 0;
} GPIO_ODR_BF;

typedef union
{
	uint32 REG;
	GPIO_ODR_BF BF;
} ODR_Type;

/* Implementation of BSRR bit field*/
typedef struct
{
	uint32 BSR : 16;
	uint32 BR : 16;
} GPIO_BSRR_BF;

typedef union
{
	uint32 REG;
	GPIO_BSRR_BF BF;
} BSRR_Type;

/* Implementation of BRR bit field*/
typedef struct
{
	uint32 BR : 16;
	uint32 : 0;
} GPIO_BRR_BF;

typedef union
{
	uint32 REG;
	GPIO_BRR_BF BF;
} BRR_Type;

/* Implementation of LCKR bit field*/
typedef struct
{
	uint32 LCK : 16;
	uint32 LCKK : 1;
	uint32 : 0;
} GPIO_LCKR_BF;

typedef struct
{
	uint32 PIN : 4;
	uint32 PORT : 3;
	uint32 EVOE: 1;
	uint32 RESERVED0: 24;
} AFIO_EVCR_BF;

typedef struct
{
	uint32 SPI1_REMAP : 1;
	uint32 I2C1_REMAP : 1;
	uint32 USART1_REMAP: 1;
	uint32 USART2_REMAP: 1;
	uint32 USART3_REMAP : 2;
	uint32 TIM1_REMAP : 2;
	uint32 TIM2_REMAP: 2;
	uint32 TIM3_REMAP: 2;
	uint32 TIM4_REMAP : 1;
	uint32 CAN_REMAP : 2;
	uint32 PD01_REMAP: 1;
	uint32 TIM5CH4_IREMAP: 1;
	uint32 ADC1_ETRGINJ_REMAP: 1;
	uint32 ADC1_ETRGREG_REMAP : 1;
	uint32 ADC2_ETRGINJ_REMAP: 1;
	uint32 ADC2_ETRGREG_REMAP : 1;
	uint32 RESERVED1 : 3;
	uint32 SWJ_CFG : 3;
	uint32 RESERVED2: 5;
} AFIO_MAPR_BF;

typedef struct
{
	uint32 EXTI0 : 4;
	uint32 EXTI1 : 4;
	uint32 EXTI2: 4;
	uint32 EXTI3: 4;
	uint32 RESERVED3: 16;
} AFIO_EXTICR1_BF;
typedef struct
{
	uint32 EXTI4 : 4;
	uint32 EXTI5 : 4;
	uint32 EXTI6: 4;
	uint32 EXTI7: 4;
	uint32 RESERVED4: 16;
} AFIO_EXTICR2_BF;

typedef struct
{
	uint32 EXTI8 : 4;
	uint32 EXTI9 : 4;
	uint32 EXTI10: 4;
	uint32 EXTI11: 4;
	uint32 RESERVED5: 16;
} AFIO_EXTICR3_BF;

typedef struct
{
	uint32 EXTI12 : 4;
	uint32 EXTI13 : 4;
	uint32 EXTI14 : 4;
	uint32 EXTI15 : 4;
	uint32 RESERVED6: 16;
} AFIO_EXTICR4_BF;

typedef struct
{
	uint32 RESERVED7: 5;
	uint32 TIM9_REMAP : 1;
	uint32 TIM10_REMAP : 1;
	uint32 TIM11_REMAP : 1;
	uint32 TIM13_REMAP : 1;
	uint32 TIM14_REMAP : 1;
    uint32 FSMC_NADV : 1;
	uint32 RESERVED8: 21;
} AFIO_MAPR2_BF;


typedef union
{
	uint32 REG;
	GPIO_LCKR_BF BF;
} LCKR_Type;

typedef union
{
	uint32 REG;
	AFIO_EVCR_BF BF;
} EVCR_Type;
typedef union
{
	uint32 REG;
	AFIO_MAPR_BF BF;
} MAPR_Type;
typedef union
{
	uint32 REG;
	AFIO_EXTICR1_BF BF;
} EXTICR1_Type;
typedef union
{
	uint32 REG;
	AFIO_EXTICR2_BF BF;
} EXTICR2_Type;
typedef union
{
	uint32 REG;
	AFIO_EXTICR3_BF BF;
} EXTICR3_Type;
typedef union
{
	uint32 REG;
	AFIO_EXTICR4_BF BF;
} EXTICR4_Type;
typedef union
{
	uint32 REG;
	AFIO_MAPR2_BF BF;
} MAPR2_Type;

typedef struct
{
	CRL_Type CRL;
	CRH_Type CRH;
	IDR_Type IDR;
	ODR_Type ODR;
	BSRR_Type BSRR;
	BRR_Type BRR;
	LCKR_Type LCKR;
} GPIO;

typedef struct 
{
	EVCR_Type EVCR;
	MAPR_Type MAPR;
	EXTICR1_Type EXTICR1;
	EXTICR2_Type EXTICR2;
	EXTICR3_Type EXTICR3;
	EXTICR4_Type EXTICR4;
	MAPR2_Type MAPR2;
}AFIO_t;


#endif /* DIO_REGS_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Dio_Regs.h
 *********************************************************************************************************************/
