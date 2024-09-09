/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  RCC_Types.h
 *  Module:  	  RCC
 *  Description:  This file contains all the types used in the RCC driver
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Mohamed Emad
 *	Date:		  27/09/2022
 *********************************************************************************************************************/
#ifndef RCC_TYPES_H_
#define RCC_TYPES_H_
/********************************************************************************
 *                          Type_definitions                                    *
 ********************************************************************************/
/*Type definition used for clk congifuration for the microcontroller -MC OUTPUT-*/
typedef enum
{
    NO_CLK = 0b000,
    SYSCLK = 0b100,
    HSI_CLK = 0b101,
    HSE_CLK = 0b110,
    PLL_DEVIDED_BY_TWO = 0b111
} RCC_ClkConfig;
/* AHB Peripherals */
typedef enum
{
    DMA1EN = 0,
    DMA2EN = 1,
    SRAMEN = 2,
    FLITFEN = 4,
    CRCEN = 6,
    DACRST =7,
    FSMCEN = 8,
    SDIOEN = 10
} RCC_AHBperipherals;
/* APB2 Peripherals */
typedef enum
{
    AFIOEN = 0,
    IOPAEN = 2,
    IOPBEN = 3,
    IOPCEN = 4,
    IOPDEN = 5,
    IOPEEN = 6,
    IOPFEN = 7,
    IOPGEN = 8,
    ADC1EN = 9,
    ADC2EN = 10,
    TIM1EN = 11,
    SPI1EN = 12,
    TIM8EN = 13,
    USART1EN = 14,
    ADC3EN = 15,
    TIM9EN = 19,
    TIM10EN = 20,
    TIM11EN = 21
} RCC_ABP2peripherals;
/* APB1 Peripherals */
typedef enum
{
    TIM2EN = 0,
    TIM3EN = 1,
    TIM4EN = 2,
    TIM5EN = 3,
    TIM6EN = 4,
    TIM7EN = 5,
    TIM12EN = 6,
    TIM13EN = 7,
    TIM14EN = 8,
    WWDGEN = 11,
    SPI2EN = 14,
    SPI3EN = 15,
    USART2EN = 17,
    USART3EN = 18,
    UART4EN = 19,
    UART5EN = 20,
    I2C1EN = 21,
    I2C2EN = 22,
    USBEN = 23,
    CANEN = 25,
    BKPEN = 27,
    PWREN = 28,
    DACEN = 29
} RCC_ABP1peripherals;
typedef enum
{
    OFF = 0,
    ON = 1
} RCC_ClkStat;

#endif