/*********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Uart.h
 *  Module:  	  Uart
 *  Description:  Header File Uart Module
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Salma Hisham & Mohamed Emad & Mohamed Yehia
 *	Date:		  12/08/2023
 *********************************************************************************************************************/
#ifndef _UART_H_
#define _UART_H_


#include "Std_Types.h"
#include "Uart_Types.h"
#include "Uart_Cfg.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for USART Init */
#define USART_Init_SID                              (uint8)0x00

/* Service ID for USART1 transmit byte */
#define USART1_TransmitByte_SID                     (uint8)0x01

/* Service ID for USART2 transmit byte */
#define USART2_TransmitByte_SID                     (uint8)0x02

/* Service ID for USART3 transmit byte */
#define USART3_TransmitByte_SID                     (uint8)0x03

/* Service ID for USART1 receive byte */
#define USART1_ReceiveByte_SID                       (uint8)0x04

/* Service ID for USART2 receive byte */
#define USART2_ReceiveByte_SID                       (uint8)0x05

/* Service ID for USART3 receive byte */
#define USART3_ReceiveByte_SID                       (uint8)0x06

/* Service ID for USART transmit String */
#define USART_TransmitString_SID                     (uint8)0x07

/* Service ID for USART receive string */
#define USART_ReceiveString_SID                      (uint8)0x08

/* Service ID for USART New Line*/
#define USART_NewLine_SID                            (uint8)0x09



/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
* Service Name: USART_Init
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Service_ID: 0x00 
* Parameters (in): Structure of array of structures
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Initializes the UART driver
************************************************************************************/
void USART_Init(const USART_ConfigType *usart_config);
/************************************************************************************
* Service Name: USART1_TransmitByte
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Service_ID: 0x01 
* Parameters (in): data to be transmitted (Byte)
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: USART1 Transmits one byte
************************************************************************************/
void USART_TransmitByte(uint8 data, USART_ID ID);
/************************************************************************************
* Service Name: USART1_ReceiveByte
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Service_ID: 0x04 
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): data received (Byte)
* Return value: None
* Description: USART1 Receives one byte
************************************************************************************/
uint8 USART_ReceiveByte(USART_ID ID);
/************************************************************************************
* Service Name: USART_TransmitString
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Service_ID: 0x07
* Parameters (in): data to be transmitted (string)
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Transmits string
************************************************************************************/
void USART_TransmitString(uint8 *string, USART_ID ID);
/************************************************************************************
* Service Name: *USART1_ReceiveString
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Service_ID: 0x08
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): data received ( String)
* Return value: None
* Description: Receives one  String
************************************************************************************/
uint8 *USART_ReceiveString(USART_ID ID);

/************************************************************************************
* Service Name: USART_NewLine
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Service_ID: 0x0B
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Transmits string
************************************************************************************/
void USART_NewLine(USART_ID ID);

void USART_VidSetCallBack( uint8 (*ptr) (void), USART_ID ID);



#endif













