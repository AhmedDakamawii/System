/**
*@file       NVIC_Interface.h
*@version    1.0.0
*@brief      MCAL Nested vectored interrupt controller .
*@details    It contains all prototypes of used functions and states
*@author     Shehab aldeen mohammed abdalah
*/


/*
 Driver need to commenting functions and some edits
  */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

#include "Std_Types.h"
#include "Bit_Math.h"
#include "Det.h"

typedef enum {
    NVIC_WWDG,
    NVIC_PVD,
    NVIC_TAMPER,
    NVIC_RTC,
    NVIC_FLASH,
    NVIC_RCC,
    NVIC_EXTI0,
    NVIC_EXTI1,
    NVIC_EXTI2,
    NVIC_EXTI3,
    NVIC_EXTI4,
    NVIC_DMA1_Channel1,
    NVIC_DMA1_Channel2,
    NVIC_DMA1_Channel3,
    NVIC_DMA1_Channel4,
    NVIC_DMA1_Channel5,
    NVIC_DMA1_Channel6,
    NVIC_DMA1_Channel7,
    NVIC_ADC1_2,
    NVIC_CAN1_TX,
    NVIC_CAN1_RX0,
    NVIC_CAN1_RX1,
    NVIC_CAN1_SCE,
    NVIC_EXTI9_5,
    NVIC_TIM1_BRK,
    NVIC_TIM1_UP,
    NVIC_TIM1_TRG_COM,
    NVIC_TIM1_CC,
    NVIC_TIM2,
    NVIC_TIM3,
    NVIC_TIM4,
    NVIC_I2C1_EV,
    NVIC_I2C1_ER,
    NVIC_I2C2_EV,
    NVIC_I2C2_ER,
    NVIC_SPI1,
    NVIC_SPI2,
    NVIC_USART1,
    NVIC_USART2,
    NVIC_USART3,
    NVIC_EXTI15_10,
    NVIC_RTCAlarm,
    NVIC_OTG_FS_WKUP,
    NVIC_Reserved,
    NVIC_TIM5 = 50,
    NVIC_SPI3,
    NVIC_UART4,
    NVIC_UART5,
    NVIC_TIM6,
    NVIC_TIM7,
    NVIC_DMA2_Channel1,
    NVIC_DMA2_Channel2,
    NVIC_DMA2_Channel3,
    NVIC_DMA2_Channel4,
    NVIC_DMA2_Channel5,
    NVIC_ETH,
    NVIC_ETH_WKUP,
    NVIC_CAN2_TX,
    NVIC_CAN2_RX0,
    NVIC_CAN2_RX1,
    NVIC_CAN2_SCE,
    NVIC_OTG_FS
}IRQn_Type;

#define SIXTEEN_GROUPS_ZERO_SUB  	 	0x5FA00300
#define EIGHT_GROUPS_TWO_SUB  	  		0x5FA00400
#define FOUR_GROUPS_FOUR_SUB  	  		0x5FA00500
#define TWO_GROUPS_EIGHT_SUB  	  		0x5FA00600
#define ZERO_GROUPS_SIXTEEN_SUB  	  	0x5FA00700



/* Enable an interrupt */
void MNVIC_EnableIRQ(IRQn_Type IRQn);

/* Disable an interrupt */
void MNVIC_DisableIRQ(IRQn_Type IRQn);

/* enable pending an interrupt */
void MNVIC_PendingEnableIRQ(IRQn_Type IRQn);

/* disable pending an interrupt */
void MNVIC_PendingDisableIRQ(IRQn_Type IRQn);

/* to determine active flag state of interrupt */
uint8 MNVIC_GetActive(IRQn_Type IRQn);

/* Set the priority of an interrupt */
void MNVIC_SetPriority(IRQn_Type IRQn, uint8 priority);

/*to set the number of groups*/
void MNVIC_SetPriorityGroup (uint32 NumOfGroups);

/* to read the state of pending flag */
uint8 MNVIC_GetStatePendingIRQ(IRQn_Type IRQn);

/* to read the state of enable flag */
uint8 MNVIC_GetStateEnableIRQ(IRQn_Type IRQn  );

/* Get the priority of an interrupt */
uint8  MNVIC_GetPriority(IRQn_Type IRQn);

/*to set call back function*/
void  MNVIC_SetCallBackFunc (uint8 INT_Position,void (*Copy_ptr)(void));

/* to get info of diver */
void  NVIC_GetVersionInfo(Std_VersionInfoType* versioninfo);

#endif /* NVIC_INTERFACE_H_ */
