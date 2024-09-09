 /******************************************************************************
 *
 * Module: NVIC
 *
 * Module ID: N/A
 *
 * File Name: MNVIC_interface.h
 *
 * Description: NVIC Driver
 *
 * Author: Ahmed Sayed
 ******************************************************************************/

#ifndef MNVIC_INTERFACE_H
#define MNVIC_INTERFACE_H

 #include "MNVIC_cfg.h"
 #include "Std_Types.h"
 #include "Macros.h"
 #include "Platform_Types.h"
 #include "MNVIC_private.h"

/***********************************[1]***********************************************
 * Service Name: MNVIC_SetPriorityGrouping
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): CopyU8GroupingOptions
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Set the Grouping and SubGrouping Options.
 ************************************************************************************/
void MNVIC_SetPriorityGrouping(uint32 CopyU8GroupingOptions);
/***********************************[2]***********************************************
 * Service Name: MNVIC_EnableIRQ
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): IRQn
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Enable NVIC IRQ.
 ************************************************************************************/
void MNVIC_EnableIRQ(uint8 IRQn); 								
/***********************************[3]***********************************************
 * Service Name: MNVIC_DisableIRQ
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): IRQn
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Disable NVIC IRQ.
 ************************************************************************************/
void MNVIC_DisableIRQ(uint8 IRQn);								
/***********************************[4]***********************************************
 * Service Name: MNVIC_GetPendingIRQ
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): IRQn
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: Pending Flag IRQ Status
 * Description: Get Pending Flag value.
 ************************************************************************************/
uint32 MNVIC_GetPendingIRQ(uint8 IRQn);
/***********************************[5]***********************************************
 * Service Name: MNVIC_SetPendingIRQ
 * Service ID[hex]: 0x05
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): IRQn
 * Parameters (InOut): None
 * Parameters (Out): uint32
 * Return value: uint32
 * Description: Set Pending Flag.
 ************************************************************************************/
void MNVIC_SetPendingIRQ(uint8 IRQn);
/***********************************[6]***********************************************
 * Service Name: MNVIC_ClearPendingIRQ
 * Service ID[hex]: 0x06
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): IRQn
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Clear Pending Flag.
 ************************************************************************************/
void MNVIC_ClearPendingIRQ(uint8 IRQn); 
/***********************************[7]***********************************************
 * Service Name: MNVIC_GetActive
 * Service ID[hex]: 0x07
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): IRQn
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Get IRQ Active Flag Status.
 ************************************************************************************/
uint32 MNVIC_GetActive(uint8 IRQn); 
/***********************************[8]***********************************************
 * Service Name: MNVIC_SetPriority
 * Service ID[hex]: 0x08
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): IRQn
 * Parameters (InOut): None
 * Parameters (Out): uint32
 * Return value: uint32
 * Description: Set IRQ Priority.
 ************************************************************************************/
void MNVIC_SetPriority(uint8 IRQn, uint8 CopyU8Priority);
/***********************************[9]***********************************************
 * Service Name: MNVIC_GetPriority
 * Service ID[hex]: 0x09
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): IRQn
 * Parameters (InOut): None
 * Parameters (Out): uint32
 * Return value: uint32
 * Description: Get IRQ Priority.
 ************************************************************************************/
uint32 MNVIC_GetPriority(uint8 IRQn); 
/***********************************[10]***********************************************
 * Service Name: MNVIC_SystemReset
 * Service ID[hex]: 0x0A
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): None
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Reset System.
 ************************************************************************************/
void MNVIC_SystemReset(void); 

#endif
