/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Can.h
 *  Module:  	  Can
 *
 *  Description:  Header file for CAN Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Mohamed Hesham,Mohamed samy,Mohamed Tamer,Mohamed Walid
 *	Date:		  23/10/2022
 *********************************************************************************************************************/

#ifndef CAN_INTERFACE_H_
#define CAN_INTERFACE_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"
#include "Platform_Types.h"
#include "Can_Regs.h"
#include "Can_Cfg.h"

/**********************************************************************************************************************
 * FUNCTIONS PROTOTYPES
 *********************************************************************************************************************/
/*******************************************************************************
 * Service Name: MCAN_CANINIT
 * Service ID[hex]: 0x10
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to intialize CAN
 *******************************************************************************/
void MCAN_CANINIT();
/*******************************************************************************
 * Service Name: MCAN_u8CheckReady
 * Service ID[hex]: 0x05
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Mailbox number
 * Parameters (inout): None
 * Parameters (out): state of mailbox: Embty or not
 * Return value: None
 * Description: Function to check on availability of Mailbox
 *******************************************************************************/
uint8 MCAN_u8CheckReady(uint8 copy_u8MailBoxNum);
/*
 * Service Name: MCAN_voidSendMessageSingle
 * Service ID[hex]: 0x20
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): Data low, Data high,message id
 * Parameters (inout): CAN MESSAGE
 * Parameters (out): None
 * Return value: None
 * Description: Function to directly create and send a can message in one function with less parameters
 */
void MCAN_voidSendMessageSingle(uint32 copy_u32ID, uint32 copy_u32LowData, uint32 copy_u32HighData );
void MCAN_voidSendMessageSingleGPS(uint32 copy_u32ID, uint8 * copy_u32LowData,  uint8 * copy_u32HighData );
/*
 * Service Name: MCAN_voidSendMessageburst
 * Service ID[hex]: 0x21
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): Message ID ,a pointer to uint32 array containing the data , the length of the array that represents the data
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to directly create and send a can message in one function with less parameters
 */
void MCAN_voidSendMessageBurst(uint32 copy_u32ID ,uint32 * copy_u32DataArray , uint32 copy_u32DataAmount);
/*******************************************************************************
 * Service Name: MCAN_voidSendMessage
 * Service ID[hex]: 0x06
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in):None
 * Parameters (inout): CAN MESSAGE
 * Parameters (out): None
 * Return value: None
 * Description: Function to set transmit mailbox to send message
 *******************************************************************************/
void MCAN_voidSendMessage (CAN_Message *msg);
/*******************************************************************************
 * Service Name: MCAN_voidCreateMessage
 * Service ID[hex]: 0x07
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): Data low, Data high,message id, data length, format type,mailbox number
 * Parameters (inout): CAN MESSAGE
 * Parameters (out): None
 * Return value: None
 * Description: Function to create message which is meant to be sent later
 *******************************************************************************/
void MCAN_voidCreateMessage (uint32 copy_u32ID, uint32 copy_u32LowData, uint32 copy_u32HighData, uint8 copy_u8Length, uint8 copy_u8Format,
		                     uint8 copy_u8Type, uint8 copy_u8Mailbox, CAN_Message *msg);
void MCAN_voidCreateMessageGPS (uint32 copy_u32ID, uint8 * copy_u32LowData,  uint8 * copy_u32HighData, uint8 copy_u8Length, uint8 copy_u8Format,
		                     uint8 copy_u8Type, uint8 copy_u8Mailbox, CAN_Message *msg);
/*******************************************************************************
 * Service Name: MCAN_ReadMessage
 * Service ID[hex]: 0x14
 * Sync/Async: Synchronous
 * Reentrancy:  Non Reentrant
 * Parameters (in): FIFO NUMBER
 * Parameters (inout): CAN MESSAGE
 * Parameters (out): None
 * Return value: None
 * Description: Function to read message from fifo
 *******************************************************************************/

void MCAN_ReadMessage(CAN_Message * message, uint8 FIFONumber);
/*******************************************************************************
 * Service Name: MCAN_pendingmessagescount
 * Service ID[hex]: 0x15
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): FIFO NUMBER
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Availability of message
 * Description: Function to check on received messages
 *******************************************************************************/
uint8 MCAN_pendingmessagescount(uint8 FIFOnumber);

void CAN1_RX1_VidSetCallBack( uint32 (*ptr) (void));

#endif
