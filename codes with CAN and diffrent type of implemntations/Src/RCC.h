/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  RCC.h
 *  Module:  	  RCC
 *  Description:  This file contains all the functions prototypes for the
 *                RCC firmware library.
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Mohamed Emad
 *	Date:		  27/09/2022
 *********************************************************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef RCC_H
#define RCC_H
#include "RCC_Types.h"
#include "RCC_Regs.h"
#include"Std_Types.h"

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
void RCC_MCOConfig(RCC_ClkConfig RCC_MCO);
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
void RCC_DeInit(void);
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
void RCC_Init(void);
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
void RCC_AHBPeripheralEnable(RCC_AHBperipherals peripheral);
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
void RCC_APB1PeripheralEnable(RCC_ABP1peripherals peripheral);
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
void RCC_APB2PeripheralEnable(RCC_ABP2peripherals peripheral);
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
void RCC_AHBPeripheralDisable(RCC_AHBperipherals peripheral);
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
void RCC_APB1PeripheralDisable(RCC_ABP1peripherals peripheral);
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
void RCC_APB2PeripheralDisable(RCC_ABP2peripherals peripheral);
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
void RCC_SetClkSource(uint8 sys_clk_source);
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
void RCC_SetClkStatus(uint8 sys_clk_source, RCC_ClkStat clk_status);
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
void RCC_SetBusesPrescaler(uint8 AHB_Pre, uint8 APB1_Pre, uint8 APB2_Pre);

#endif /* RCC_H */