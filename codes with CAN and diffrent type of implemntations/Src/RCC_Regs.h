/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  RCC_Regs.h
 *  Module:  	  RCC
 *  Description:  This file contains the definition of registers of RCC
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Mohamed Emad
 *	Date:		  27/09/2022
 *********************************************************************************************************************/
#ifndef RCC_REGS_H
#define RCC_REGS_H
#include "Std_Types.h"
#define RCC ((volatile RCC_t *)0x40021000)
/**************************************************************************
*                       Registers_bit_field                               *
***************************************************************************/
typedef struct 
{
    uint32 HSION  : 1 ;
    uint32 HSIRDY : 1 ;
    uint32        : 1 ;
    uint32 HSITRIM: 5 ;
    uint32 HSICAL : 8 ;
    uint32 HSEON  : 1 ;
    uint32 HSERD  : 1 ;
    uint32 HSEBYP : 1 ;
    uint32 CSSON  : 1 ;
    uint32        : 4 ;
    uint32 PLL_ON : 1 ;
    uint32 PLL_RDY: 1 ;
    uint32        : 6 ;
}RCC_CR_BF;
typedef struct
{
    uint32 SW      : 2 ;
    uint32 SWS     : 2 ;
    uint32 HPRE    : 4 ;
    uint32 PPRE1   : 3 ;
    uint32 PPRE2   : 3 ;
    uint32 ADC_PRE : 2 ;
    uint32 PLLSRC  : 1 ;
    uint32 PLLXTPRE: 1 ;
    uint32 PLLMUL  : 4 ;
    uint32 USBPRE  : 1 ;
    uint32         : 1 ;
    uint32 MCO     : 3 ;
    uint32         : 5 ;
}RCC_CFGR_BF;
typedef struct
{
    uint32 LSIRDYF : 1 ;
    uint32 LSERDYF : 1 ;
    uint32 HSIRDYF : 1 ;
    uint32 HSERDYF : 1 ;
    uint32 PLLRDYF : 1 ;
    uint32         : 2 ;
    uint32 CSSF    : 1 ;
    uint32 LSIRDYIE: 1 ;
    uint32 LSERDYIE: 1 ;
    uint32 HSIRDYIE: 1 ;
    uint32 HSERDYIE: 1 ;
    uint32 PLLRDYIE: 1 ;
    uint32         : 3 ;
    uint32 LSIRDYC : 1 ;
    uint32 LSERDYC : 1 ;
    uint32 HSIRDYC : 1 ;
    uint32 HSERDYC : 1 ;
    uint32 PLLRDYC : 1 ;
    uint32         : 2 ;
    uint32 CSSC    : 1 ;
    uint32         : 8 ;
}RCC_CIR_BF;
typedef struct{
    uint32 AFIORST  : 1 ;
    uint32          : 1 ;
    uint32 IOPARST  : 1 ;
    uint32 IOPBRST  : 1 ;
    uint32 IOPCRST  : 1 ;
    uint32 IOPDRST  : 1 ;
    uint32 IOPERST  : 1 ;
    uint32 IOPFRST  : 1 ;
    uint32 IOPGRST  : 1 ;
    uint32 ADC1RST  : 1 ;
    uint32 ADC2RST  : 1 ;
    uint32 TIM1RST  : 1 ;
    uint32 SPI1RST  : 1 ;
    uint32 TIM8RST  : 1 ;
    uint32 USART1RST: 1 ;
    uint32 ADC3RST  : 1 ;
    uint32          : 3 ;
    uint32 TIM9RST  : 1 ;
    uint32 TIM10RST : 1 ;
    uint32 TIM11RST : 1 ;
    uint32          : 10 ;
}RCC_APB2RSTR_BF;
typedef struct{
    uint32 TIM2RST  : 1 ;
    uint32 TIM3RST  : 1 ;
    uint32 TIM4RST  : 1 ;
    uint32 TIM5RST  : 1 ;
    uint32 TIM6RST  : 1 ;
    uint32 TIM7RST  : 1 ;
    uint32 TIM12RST : 1 ;
    uint32 TIM13RST : 1 ;
    uint32 TIM14RST : 1 ;
    uint32          : 2 ;
    uint32 WWDGRST  : 1 ;
    uint32          : 2 ;
    uint32 SPI2RST  : 1 ;
    uint32 SPI3RST  : 1 ;
    uint32          : 1 ;
    uint32 USART2RST: 1 ;
    uint32 USART3RST: 1 ;
    uint32 USART4RST: 1 ;
    uint32 USART5RST: 1 ;
    uint32 I2C1RST  : 1 ;
    uint32 I2C2RST  : 1 ;
    uint32 USBRST   : 1 ;
    uint32          : 1 ;
    uint32 CANRST   : 1 ;
    uint32          : 1 ;
    uint32 BKPRST   : 1 ;
    uint32 PWRRST   : 1 ;
    uint32 DACRST   : 1 ;
    uint32          : 2 ;
}RCC_APB1RSTR_BF;
typedef struct
{
    uint32 DMA1EN : 1 ;
    uint32 DMA2EN : 1 ;
    uint32 SRAMEN : 1 ;
    uint32        : 1 ;
    uint32 FLITFEN: 1 ;
    uint32        : 1 ;
    uint32 CRCEN  : 1 ;
    uint32 DACRST : 1 ;
    uint32 FSMCEN : 1 ;
    uint32        : 1 ;
    uint32 SDIOEN : 1 ;
    uint32        : 21 ;
}RCC_AHBENR_BF;
typedef struct
{
    uint32 AFIOEN  : 1 ;
    uint32         : 1 ;
    uint32 IOPAEN  : 1 ;
    uint32 IOPBEN  : 1 ;
    uint32 IOPCEN  : 1 ;
    uint32 IOPDEN  : 1 ;
    uint32 IOPEEN  : 1 ;
    uint32 IOPFEN  : 1 ;
    uint32 IOPGEN  : 1 ;
    uint32 ADC1EN  : 1 ;
    uint32 ADC2EN  : 1 ;
    uint32 TIM1EN  : 1 ;
    uint32 SPI1EN  : 1 ;
    uint32 TIM8EN  : 1 ;
    uint32 USART1EN: 1 ;
    uint32 ADC3EN  : 1 ;
    uint32         : 3 ;
    uint32 TIM9EN  : 1 ;
    uint32 TIM10EN : 1 ;
    uint32 TIM11EN : 1 ;
    uint32         : 10 ;
}RCC_APB2ENR_BF;
typedef struct
{
    uint32 TIM2EN  : 1 ;
    uint32 TIM3EN  : 1 ;
    uint32 TIM4EN  : 1 ;
    uint32 TIM5EN  : 1 ;
    uint32 TIM6EN  : 1 ;
    uint32 TIM7EN  : 1 ;
    uint32 TIM12EN : 1 ;
    uint32 TIM13EN : 1 ;
    uint32 TIM14EN : 1 ;
    uint32         : 2 ;
    uint32 WWDGEN  : 1 ;
    uint32         : 2 ;
    uint32 SPI2EN  : 1 ;
    uint32 SPI3EN  : 1 ;
    uint32         : 1 ;
    uint32 USART2EN: 1 ;
    uint32 USART3EN: 1 ;
    uint32 USART4EN: 1 ;
    uint32 USART5EN: 1 ;
    uint32 I2C1EN  : 1 ;
    uint32 I2C2EN  : 1 ;
    uint32 USBEN   : 1 ;
    uint32         : 1 ;
    uint32 CANEN   : 1 ;
    uint32         : 1 ;
    uint32 BKPEN   : 1 ;
    uint32 PWREN   : 1 ;
    uint32 DACEN   : 1 ;
    uint32         : 2 ;
}RCC_APB1ENR_BF;
typedef struct
{
    uint32 LSEON : 1 ;
    uint32 LSERDY: 1 ;
    uint32 LSEBYP: 1 ;
    uint32       : 5 ;
    uint32 RTCSEL: 2 ;
    uint32       : 5 ;
    uint32 RTCEN : 1 ;
    uint32 BDRST : 1 ;
    uint32       : 15 ;
}RCC_BDCR_BF;
typedef struct
{
    uint32 LSION   : 1 ;
    uint32 LSIRDY  : 1 ;
    uint32         : 22 ;
    uint32 RMVF    : 1 ;
    uint32         : 1 ;
    uint32 PINRSTF : 1 ;
    uint32 PORRSTF : 1 ;
    uint32 SFTRSTF : 1 ;
    uint32 IWDGRSTF: 1 ;
    uint32 WWDGRSTF: 1 ;
    uint32 LPWRSTF : 1 ;
}RCC_CSR_BF;
/**************************************************************************
*                       Registers_Unions                                  *
***************************************************************************/
typedef union
{
    RCC_CR_BF BF;
    uint32 R ;
}RCC_CR_union;
typedef union
{
    RCC_CFGR_BF BF;
    uint32 R ;
}RCC_CFGR_union;
typedef union
{
    RCC_CIR_BF BF;
    uint32 R ;
}RCC_CIR_union;
typedef union
{
    RCC_APB2RSTR_BF BF;
    uint32 R ;
}RCC_APB2RSTR_union;
typedef union
{
    RCC_APB1RSTR_BF BF;
    uint32 R ;
}RCC_APB1RSTR_union;
typedef union
{
    RCC_AHBENR_BF BF;
    uint32 R ;
}RCC_AHBENR_union;
typedef union
{
    RCC_APB2ENR_BF BF;
    uint32 R ;
}RCC_APB2ENR_union;
typedef union
{
    RCC_APB1ENR_BF BF;
    uint32 R ;
}RCC_APB1ENR_uinon;
typedef union
{
    RCC_BDCR_BF BF;
    uint32 R ;
}RCC_BDCR_union;
typedef union
{
    RCC_CSR_BF BF;
    uint32 R ;
}RCC_CSR_union;
/**************************************************************************
*                           RCC_Registers                                 *
***************************************************************************/
typedef struct
{
    volatile RCC_CR_union CR;
    volatile RCC_CFGR_union CFGR;
    volatile RCC_CIR_union CIR;
    volatile RCC_APB2RSTR_union APB2RSTR;
    volatile RCC_APB1RSTR_union APB1RSTR;
    volatile RCC_AHBENR_union AHBENR;
    volatile RCC_APB2ENR_union APB2ENR;
    volatile RCC_APB1ENR_uinon APB1ENR;
    volatile RCC_BDCR_union BDCR;
    volatile RCC_CSR_union CSR;

} RCC_t;
#endif