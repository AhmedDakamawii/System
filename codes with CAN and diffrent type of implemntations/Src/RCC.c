/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  RCC.c
 *  Module:  	  RCC
 *  Description:  This file contains the functions of RCC driver
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Mohamed Emad
 *	Date:		  20/07/2022
 *********************************************************************************************************************/
#include "RCC.h"
#include "RCC_Regs.h"
#include "RCC_Types.h"
#include "Macros.h"
#include "RCC_Cfg.h"
#include "Std_Types.h"
/*******************************************************************************
 * Service Name: RCC_MCOConfig
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): - RCC_MCO: specifies the clock source to output.
 *                    This parameter can be one of the following values:
 *                      - NO_CLK: No clock selected
 *                      - SYSCLK: System clock selected
 *                      - HSI_CLK: HSI oscillator clock selected
 *                      - HSE_CLK: HSE oscillator clock selected
 *                      - PLL_DEVIDED_BY_TWO: PLL clock divided by 2 selected
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Selects the clock source to output on MCO pin.
 *******************************************************************************/
void RCC_MCOConfig(RCC_ClkConfig RCC_MCO)
{
    /* Perform Byte access to MCO[26:24] bits to select the MCO source */
    (RCC->CFGR).BF.MCO = RCC_MCO;
}
/*******************************************************************************
 * Service Name: RCC_DeInit
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Deinitializes the RCC peripheral registers to their default
 *              reset values.
 *******************************************************************************/
void RCC_DeInit(void)
{
    RCC->AHBENR.R = RESET_VALUE_AHBENR;
    RCC->APB1ENR.R = RESET_VALUE_APB1ENR;
    RCC->APB1RSTR.R = RESET_VALUE_APB1RSTR;
    RCC->APB2ENR.R = RESET_VALUE_APB2ENR;
    RCC->APB2RSTR.R = RESET_VALUE_APB2RSTR;
    RCC->BDCR.R = RESET_VALUE_BDCR;
    RCC->CFGR.R = RESET_VALUE_CFGR;
    RCC->CIR.R = RESET_VALUE_CIR;
    RCC->CR.R = RESET_VALUE_CR;
    RCC->CSR.R = RESET_VALUE_CSR;
}
/*******************************************************************************
 * Service Name: RCC_Init
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description:  Init the RCC peripheral registers according to the defined
 *               clock source.
 *******************************************************************************/
void RCC_Init(void)
{
#if CLK_SOURCE == HSI
    /*
     * 1- Turn on HSI Clock
     * 2- Check HSI is Ready
     * 3- Switch to HSI
     * 4- Turn off PLL
     * 5- Turn off HSE
     */
    /*Turn on HSI Clock*/
    (RCC->CR).BF.HSION = 1;
    // 2- Check HSI is Ready
    while ((RCC->CR).BF.HSIRDY == 0)
        ;
    // 3- Switch to HSI
    (RCC->CFGR).BF.SW = 0b00;
    // 4- Turn off PLL
    (RCC->CR).BF.PLL_ON = 0;
    // 5- Turn off HSE
    (RCC->CR).BF.HSEON = 0;
    // Set the prescalers of the buses
    (RCC->CFGR).BF.HPRE = AHB_PRESCALER;
    (RCC->CFGR).BF.PPRE1 = APB1_PRESCALER;
    (RCC->CFGR).BF.PPRE2 = APB2_PRESCALER;
#elif CLK_SOURCE == HSE
    /*
     * 1- Turn on HSE Clock
     * 2- Check HSe is Ready
     * 3- Switch to HSE
     * 4- Turn off PLL
     * 5- Turn off HSI
     */

    // 1- Turn on HSE Clock
    (RCC->CR).BF.HSEON = 1;
    // 2- Check HSI is Ready
    while ((RCC->CR).BF.HSERD == 0)
        ;
    // 3- Switch to HSE
    (RCC->CFGR).BF.SW = 0b01;
    // 4- Turn off PLL
    (RCC->CR).BF.PLL_ON = 0;
    // 5- Turn off HSI
    (RCC->CR).BF.HSION = 0;
    // Set the prescalers of the buses
    (RCC->CFGR).BF.HPRE = AHB_PRESCALER;
    (RCC->CFGR).BF.PPRE1 = APB1_PRESCALER;
    (RCC->CFGR).BF.PPRE2 = APB2_PRESCALER;
#elif CLK_SOURCE == PLL
#if PLL_SOURCE == HSI
    // 1- Turn on HSI Clock
    SET_BIT(RCC->CR, CR_HSI_ON_BIT);
    (RCC->CR).BF.HSION = 1;
    // 2- Check HSI is Ready
    while ((RCC->CR).BF.HSIRDY == 0)
        ;
    // 3- Set PLL Source to HSI
    (RCC->CFGR).BF.PLLSRC = 0;
    // 4- Set PLLM Values
    (RCC->CFGR).BF.PLLMUL = PLLM_VALUE;
    // 5-Set the prescalers of the buses
    (RCC->CFGR).BF.HPRE = AHB_PRESCALER;
    (RCC->CFGR).BF.PPRE1 = APB1_PRESCALER;
    (RCC->CFGR).BF.PPRE2 = APB2_PRESCALER;
    // 6- Turn on PLL Clock
    (RCC->CR).BF.PLL_ON = 1;
    // 7- Check HSI is Ready
    while ((RCC->CR).BF.PLL_RDY == 0)
        ;
    // 8- Switch to PLL
    (RCC->CFGR).BF.SW = 0b10;
#elif PLL_SOURCE == HSE
    // 1- Turn on HSE Clock
    (RCC->CR).BF.HSEON = 1;
    // 2- Check HSE is Ready
    while ((RCC->CR).BF.HSERD == 0)
        ;
    // 3- Set PLL Source to HSE
    (RCC->CFGR).BF.PLLSRC = 1;
    // 4- Set PLLM Values
    (RCC->CFGR).BF.PLLMUL = PLLM_VALUE;
    // 5-Set the prescalers of the buses
    (RCC->CFGR).BF.HPRE = AHB_PRESCALER;
    (RCC->CFGR).BF.PPRE1 = APB1_PRESCALER;
    (RCC->CFGR).BF.PPRE2 = APB2_PRESCALER;
    // 6- Turn on PLL Clock
    (RCC->CR).BF.PLL_ON = 1;
    // 7- Check HSI is Ready
    while ((RCC->CR).BF.PLL_RDY == 0)
        ;
    // 8- Switch to PLL
    (RCC->CFGR).BF.SW = 0b10;
#else
#error "Wrong Clock Configuration"
#endif
#else
#error "Wrong Clock Configuration"
#endif
}
/*******************************************************************************
 * Service Name: RCC_AHBPeripheralEnable
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): peripheral (The one you want to enable)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description:  Enable the specified peripheral in AHB bus
 *******************************************************************************/
void RCC_AHBPeripheralEnable(RCC_AHBperipherals peripheral)
{
    if (peripheral > 31)
    {
        return;
    }
    else
    {
        switch (peripheral)
        {
        case DMA1EN:
            (RCC->AHBENR).BF.DMA1EN = 1;
            break;
        case DMA2EN:
            (RCC->AHBENR).BF.DMA2EN = 1;
            break;
        case SRAMEN:
            (RCC->AHBENR).BF.SRAMEN = 1;
            break;
        case FLITFEN:
            (RCC->AHBENR).BF.FLITFEN = 1;
            break;
        case CRCEN:
            (RCC->AHBENR).BF.CRCEN = 1;
            break;
        case DACRST:
            (RCC->AHBENR).BF.DACRST = 1;
            break;
        case FSMCEN:
            (RCC->AHBENR).BF.FSMCEN = 1;
            break;
        case SDIOEN:
            (RCC->AHBENR).BF.SDIOEN = 1;
            break;
        default:
            /*[TO DO]: Error handling*/
            break;
        }
    }
}
/*******************************************************************************
 * Service Name: RCC_APB1PeripheralEnable
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): peripheral (The one you want to enable)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description:  Enable the specified peripheral in APB1 bus
 *******************************************************************************/
void RCC_APB1PeripheralEnable(RCC_ABP1peripherals peripheral)
{
    if (peripheral > 31)
    {
        return;
    }
    else
    {
        switch (peripheral)
        {
        case TIM2EN:
            (RCC->APB1ENR).BF.TIM2EN = 1;
            break;
        case TIM3EN:
            (RCC->APB1ENR).BF.TIM3EN = 1;
            break;
        case TIM4EN:
            (RCC->APB1ENR).BF.TIM4EN = 1;
            break;
        case TIM5EN:
            (RCC->APB1ENR).BF.TIM5EN = 1;
            break;
        case TIM6EN:
            (RCC->APB1ENR).BF.TIM6EN = 1;
            break;
        case TIM7EN:
            (RCC->APB1ENR).BF.TIM7EN = 1;
            break;
        case TIM12EN:
            (RCC->APB1ENR).BF.TIM12EN = 1;
            break;
        case TIM13EN:
            (RCC->APB1ENR).BF.TIM13EN = 1;
            break;
        case TIM14EN:
            (RCC->APB1ENR).BF.TIM14EN = 1;
            break;
        case WWDGEN:
            (RCC->APB1ENR).BF.WWDGEN = 1;
            break;
        case SPI2EN:
            (RCC->APB1ENR).BF.SPI2EN = 1;
            break;
        case SPI3EN:
            (RCC->APB1ENR).BF.SPI3EN = 1;
            break;
        case USART2EN:
            (RCC->APB1ENR).BF.USART2EN = 1;
            break;
        case USART3EN:
            (RCC->APB1ENR).BF.USART3EN = 1;
            break;
        case UART4EN:
            (RCC->APB1ENR).BF.USART4EN = 1;
            break;
        case UART5EN:
            (RCC->APB1ENR).BF.USART5EN = 1;
            break;
        case I2C1EN:
            (RCC->APB1ENR).BF.I2C1EN = 1;
            break;
        case I2C2EN:
            (RCC->APB1ENR).BF.I2C2EN = 1;
            break;
        case USBEN:
            (RCC->APB1ENR).BF.USBEN = 1;
            break;
        case CANEN:
            (RCC->APB1ENR).BF.CANEN = 1;
            break;
        case BKPEN:
            (RCC->APB1ENR).BF.BKPEN = 1;
            break;
        case PWREN:
            (RCC->APB1ENR).BF.PWREN = 1;
            break;
        case DACEN:
            (RCC->APB1ENR).BF.DACEN = 1;
            break;
        default:
            /*[TO DO]: Error handling*/
            break;
        }
    }
}
/*******************************************************************************
 * Service Name: RCC_APB2PeripheralEnable
 * Service ID[hex]: 0x05
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): peripheral (The one you want to enable)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description:  Enable the specified peripheral in APB2 bus
 *******************************************************************************/
void RCC_APB2PeripheralEnable(RCC_ABP2peripherals peripheral)
{
    if (peripheral > 31)
    {
        return;
    }
    else
    {
       switch (peripheral)
        {
        case AFIOEN:
            (RCC->APB2ENR).BF.AFIOEN = 1;
            break;
        case IOPAEN:
            (RCC->APB2ENR).BF.IOPAEN = 1;
            break;
        case IOPBEN:
            (RCC->APB2ENR).BF.IOPBEN = 1;
            break;
        case IOPCEN:
            (RCC->APB2ENR).BF.IOPCEN = 1;
            break;
        case IOPDEN:
            (RCC->APB2ENR).BF.IOPDEN = 1;
            break;
        case IOPEEN:
            (RCC->APB2ENR).BF.IOPEEN = 1;
            break;
        case IOPFEN:
            (RCC->APB2ENR).BF.IOPFEN = 1;
            break;
        case IOPGEN:
            (RCC->APB2ENR).BF.IOPGEN = 1;
            break;
        case ADC1EN:
            (RCC->APB2ENR).BF.ADC1EN = 1;
            break;
        case ADC2EN:
            (RCC->APB2ENR).BF.ADC2EN = 1;
            break;
        case TIM1EN:
            (RCC->APB2ENR).BF.TIM1EN = 1;
            break;
        case SPI1EN:
            (RCC->APB2ENR).BF.SPI1EN = 1;
            break;
        case TIM8EN:
            (RCC->APB2ENR).BF.TIM8EN = 1;
            break;
        case USART1EN:
            (RCC->APB2ENR).BF.USART1EN = 1;
            break;
        case ADC3EN:
            (RCC->APB2ENR).BF.ADC3EN = 1;
            break;
        case TIM9EN:
            (RCC->APB2ENR).BF.TIM9EN = 1;
            break;
        case TIM10EN:
            (RCC->APB2ENR).BF.TIM10EN = 1;
            break;
        case TIM11EN:
            (RCC->APB2ENR).BF.TIM11EN = 1;
            break;
        default:
            /*[TO DO]: Error handling*/
            break;
        }
    }
}
/*******************************************************************************
 * Service Name: RCC_AHBPeripheralDisable
 * Service ID[hex]: 0x06
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): peripheral (The one you want to disable)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description:  Disable the specified peripheral in AHB bus
 *******************************************************************************/
void RCC_AHBPeripheralDisable(RCC_AHBperipherals peripheral)
{
     if (peripheral > 31)
    {
        return;
    }
    else
    {
        switch (peripheral)
        {
        case DMA1EN:
            (RCC->AHBENR).BF.DMA1EN = 0;
            break;
        case DMA2EN:
            (RCC->AHBENR).BF.DMA2EN = 0;
            break;
        case SRAMEN:
            (RCC->AHBENR).BF.SRAMEN = 0;
            break;
        case FLITFEN:
            (RCC->AHBENR).BF.FLITFEN = 0;
            break;
        case CRCEN:
            (RCC->AHBENR).BF.CRCEN = 0;
            break;
        case DACRST:
            (RCC->AHBENR).BF.DACRST = 0;
            break;
        case FSMCEN:
            (RCC->AHBENR).BF.FSMCEN = 0;
            break;
        case SDIOEN:
            (RCC->AHBENR).BF.SDIOEN = 0;
            break;
        default:
            /*[TO DO]: Error handling*/
            break;
        }
    }
}
/*******************************************************************************
 * Service Name: RCC_APB1PeripheralDisable
 * Service ID[hex]: 0x07
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): peripheral (The one you want to disable)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description:  Disable the specified peripheral in APB1 bus
 *******************************************************************************/
void RCC_APB1PeripheralDisable(RCC_ABP1peripherals peripheral)
{
    if (peripheral > 31)
    {
        return;
    }
    else
    {
        switch (peripheral)
        {
        case TIM2EN:
            (RCC->APB1ENR).BF.TIM2EN = 0;
            break;
        case TIM3EN:
            (RCC->APB1ENR).BF.TIM3EN = 0;
            break;
        case TIM4EN:
            (RCC->APB1ENR).BF.TIM4EN = 0;
            break;
        case TIM5EN:
            (RCC->APB1ENR).BF.TIM5EN = 0;
            break;
        case TIM6EN:
            (RCC->APB1ENR).BF.TIM6EN = 0;
            break;
        case TIM7EN:
            (RCC->APB1ENR).BF.TIM7EN = 0;
            break;
        case TIM12EN:
            (RCC->APB1ENR).BF.TIM12EN = 0;
            break;
        case TIM13EN:
            (RCC->APB1ENR).BF.TIM13EN = 0;
            break;
        case TIM14EN:
            (RCC->APB1ENR).BF.TIM14EN = 0;
            break;
        case WWDGEN:
            (RCC->APB1ENR).BF.WWDGEN = 0;
            break;
        case SPI2EN:
            (RCC->APB1ENR).BF.SPI2EN = 0;
            break;
        case SPI3EN:
            (RCC->APB1ENR).BF.SPI3EN = 0;
            break;
        case USART2EN:
            (RCC->APB1ENR).BF.USART2EN = 0;
            break;
        case USART3EN:
            (RCC->APB1ENR).BF.USART3EN = 0;
            break;
        case UART4EN:
            (RCC->APB1ENR).BF.USART4EN = 0;
            break;
        case UART5EN:
            (RCC->APB1ENR).BF.USART5EN = 0;
            break;
        case I2C1EN:
            (RCC->APB1ENR).BF.I2C1EN = 0;
            break;
        case I2C2EN:
            (RCC->APB1ENR).BF.I2C2EN = 0;
            break;
        case USBEN:
            (RCC->APB1ENR).BF.USBEN = 0;
            break;
        case CANEN:
            (RCC->APB1ENR).BF.CANEN = 0;
            break;
        case BKPEN:
            (RCC->APB1ENR).BF.BKPEN = 0;
            break;
        case PWREN:
            (RCC->APB1ENR).BF.PWREN = 0;
            break;
        case DACEN:
            (RCC->APB1ENR).BF.DACEN = 0;
            break;
        default:
            /*[TO DO]: Error handling*/
            break;
        }
    }
}
/*******************************************************************************
 * Service Name: RCC_APB2PeripheralDisable
 * Service ID[hex]: 0x08
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): peripheral (The one you want to disable)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description:  Disable the specified peripheral in APB2 bus
 *******************************************************************************/
void RCC_APB2PeripheralDisable(RCC_ABP2peripherals peripheral)
{
    if (peripheral > 31)
    {
        return;
    }
    else
    {
       switch (peripheral)
        {
        case AFIOEN:
            (RCC->APB2ENR).BF.AFIOEN = 0;
            break;
        case IOPAEN:
            (RCC->APB2ENR).BF.IOPAEN = 0;
            break;
        case IOPBEN:
            (RCC->APB2ENR).BF.IOPBEN = 0;
            break;
        case IOPCEN:
            (RCC->APB2ENR).BF.IOPCEN = 0;
            break;
        case IOPDEN:
            (RCC->APB2ENR).BF.IOPDEN = 0;
            break;
        case IOPEEN:
            (RCC->APB2ENR).BF.IOPEEN = 0;
            break;
        case IOPFEN:
            (RCC->APB2ENR).BF.IOPFEN = 0;
            break;
        case IOPGEN:
            (RCC->APB2ENR).BF.IOPGEN = 0;
            break;
        case ADC1EN:
            (RCC->APB2ENR).BF.ADC1EN = 0;
            break;
        case ADC2EN:
            (RCC->APB2ENR).BF.ADC2EN = 0;
            break;
        case TIM1EN:
            (RCC->APB2ENR).BF.TIM1EN = 0;
            break;
        case SPI1EN:
            (RCC->APB2ENR).BF.SPI1EN = 0;
            break;
        case TIM8EN:
            (RCC->APB2ENR).BF.TIM8EN = 0;
            break;
        case USART1EN:
            (RCC->APB2ENR).BF.USART1EN = 0;
            break;
        case ADC3EN:
            (RCC->APB2ENR).BF.ADC3EN = 0;
            break;
        case TIM9EN:
            (RCC->APB2ENR).BF.TIM9EN = 0;
            break;
        case TIM10EN:
            (RCC->APB2ENR).BF.TIM10EN = 0;
            break;
        case TIM11EN:
            (RCC->APB2ENR).BF.TIM11EN = 0;
            break;
        default:
            /*[TO DO]: Error handling*/
            break;
        }
    }
}
/*******************************************************************************
 * Service Name: RCC_SetClkSource
 * Service ID[hex]: 0x09
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): sys_clk_source
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description:  Set the clock source for the system
 *******************************************************************************/
void RCC_SetClkSource(uint8 sys_clk_source)
{
    switch (sys_clk_source)
    {
    case HSI:
        (RCC->CFGR).BF.SW = 0b00;
        break;
    case HSE:
        (RCC->CFGR).BF.SW = 0b01;
        break;
    case PLL:
        (RCC->CFGR).BF.SW = 0b10;
        break;
    default:
        break;
    }
}
/*******************************************************************************
 * Service Name: RCC_SetClkStatus
 * Service ID[hex]: 0x10
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): sys_clk_source : The clock source of the system
 *                  clk_status : The status of the clock source (ON , OFF)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description:  Turn on or off the clock source
 *******************************************************************************/
void RCC_SetClkStatus(uint8 sys_clk_source, RCC_ClkStat clk_status)
{
    switch (sys_clk_source)
    {
    case HSI:
        switch (clk_status)
        {
        case ON:
            (RCC->CR).BF.HSION = 1;
            break;
        case OFF:
            (RCC->CR).BF.HSION = 0;
            break;
        }
        break;
    case HSE:
        switch (clk_status)
        {
        case ON:
            (RCC->CR).BF.HSEON = 1;
            break;
        case OFF:
            (RCC->CR).BF.HSEON = 0;
            break;
        }
        break;
    case PLL:
        switch (clk_status)
        {
        case ON:
            (RCC->CR).BF.PLL_ON = 1;
            break;
        case OFF:
            (RCC->CR).BF.PLL_ON = 0;
            break;
        }
        break;
    default:
        break;
    }
}

/*******************************************************************************
 * Service Name: RCC_SetBusesPrescaler
 * Service ID[hex]: 0x11
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): AHB_Pre : The prescaler of AHB
 *                  APB1_Pre : The prescaler of APB1
 *                  APB2_Pre : The prescaler of APB2
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description:  Set the prescalers of the buses (AHB , APB1 , APB2)
 *******************************************************************************/
void RCC_SetBusesPrescaler(uint8 AHB_Pre, uint8 APB1_Pre, uint8 APB2_Pre)
{
    // 1- Set AHB Prescaler
    (RCC->CFGR).BF.HPRE = AHB_PRESCALER;
    // 2- Set APB1 Prescaler
    (RCC->CFGR).BF.PPRE1 = APB1_PRESCALER;
    // 3- Set APB2 Prescaler
    (RCC->CFGR).BF.PPRE2 = APB2_PRESCALER;
}
/* Set PLL Factors */
void RCC_SetPLLFactor(uint8 pllm_val)
{
    // Set PLLM Values
    (RCC->CFGR).BF.PLLMUL = pllm_val;
}