/**
*@file       NVIC_Private.h
*@version    1.0.0
*@brief      MCAL Nested vectored interrupt controller .
*@details    It contains private content of driver
*@author     Shehab aldeen mohammed abdalah
*/


#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_


typedef struct {
	volatile uint32  ISER [3]  ;  /* Interrupt set-enable registers */
	volatile uint32  Res_0[29] ;
	volatile uint32  ICER [3]  ;  /* Interrupt clear-enable registers */
	volatile uint32  Res_1[29] ;
	volatile uint32  ISPR [3]  ;  /* Interrupt set-pending registers */
	volatile uint32  Res_2[29] ;
	volatile uint32  ICPR [3]  ;  /* Interrupt clear-pending registers */
	volatile uint32  Res_3[29] ;
	volatile uint32  IABR [3]  ;  /* Interrupt active bit registers */
	volatile uint32  Res_4[61] ;
	volatile uint8   IP   [84] ;  /* Interrupt priority registers */
}NVIC_TYPEDEF;

#define NVIC          ((NVIC_TYPEDEF*)0xE000E100)

/* Software trigger interrupt register */
#define NVIC_STIR   *((volatile uint32 *)(0xE000EF00))

/* Application interrupt and reset control register */
#define SCB_AIRCR   *((volatile uint32 *)(0x0C+0xE000ED00))


#define HALF_BYTE          4
#define REG_SIZE           32


/* Random */
#define NVIC_E_PARAM_POINTER              0x13
#define NVIC_E_PARAM_INVALID_ARGUMENT     0x14


#define VENDOR_ID                  150
#define MODULE_ID                  118
#define NVIC_MAJOR_VERSION         1
#define NVIC_MINOR_VERSION         0
#define NVIC_PATCH_VERSION         0

#define MNVIC_EnableIRQ_ID                      1
#define MNVIC_DisableIRQ_ID                     2
#define MNVIC_PendingEnableIRQ_ID              3
#define MNVIC_PendingDisableIRQ_ID              4
#define MNVIC_GetActive_ID                      5
#define MNVIC_SetPriority_ID                    6
#define MNVIC_SetPriorityGroup_ID               7
#define MNVIC_GetStatePendingIRQ_ID             8
#define MNVIC_GetStateEnableIRQ_ID              9
#define MNVIC_GetPriority_ID                    10
#define MNVIC_SetCallBackFunc_ID                11
#define MNVIC_ISR_ID                            12

#endif /* NVIC_PRIVATE_H_ */
