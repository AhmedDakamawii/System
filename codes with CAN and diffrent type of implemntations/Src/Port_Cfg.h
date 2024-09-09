/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Port_Cfg.h
 *  Module:  	  Port_Cfg
 *
 *  Description:  Header file for Port Module configurations
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Salma Hisham
 *	Date:		  24/10/2023
 *********************************************************************************************************************/

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"
#include "Port_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
extern const Port_configType Port_ConfigType;

#define SPI1_cfg Spi1_no_remap
#define I2C1_cfg I2C1_REMAP_no_remap
#define USART1_cfg USART1_REMAP_no_remap
#define USART2_cfg USART2_REMAP_no_remap
#define USART3_cfg USART3_REMAP_no_remap
#define CAN_cfg CAN_REMAP_PB
#define PD01_cfg PDO1_REMAP_no_remap
#define TIM1_cfg TIM1_REMAP_no_remap
#define TIM2_cfg TIM2_REMAP_no_remap
#define TIM3_cfg TIM3_REMAP_no_remap
#define TIM4_cfg TIM4_REMAP_no_remap
#define TIM9_cfg TIM9_REMAP_no_remap
#define TIM10_cfg TIM10_REMAP_no_remap
#define TIM11_cfg TIM11_REMAP_no_remap
#define TIM13_cfg TIM13_REMAP_no_remap
#define TIM14_cfg TIM14_REMAP_no_remap
#define FSMC_NADV_cfg TIM9_REMAP_no_remap

#endif /* PORT_CFG_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Port_Cfg.h
 *********************************************************************************************************************/