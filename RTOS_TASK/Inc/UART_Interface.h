/*
 * File        : USART_interface.h
 * Author      : Yassin
 * Date        : 06/08/2023

 */
 
/**
 * \mainpage
 * \section Brief
 * This is file includes headers and Macros for the USART Section.
 * \section Details
 * We have 9 function explaind in 3 function to each USART.
 * \section SoftwareContext
 * This is the Software Context
 * this service is used to use UART by init it then we can transimate and recieve
 *
 *
 *
 */

#ifndef UART_Interface_h
#define UART_Interface_h

#include "UART_Private.h"
#include "UART_Config.h"





typedef struct
{
	USART_ID USARTid;
	USART_BAUD USARTBaud;
	M USARTWordLength;
	STOP USARTStopBits;
	USART_MODE USARTMode;
	PSnPCE USARTParitySelection;
    //u8 USART_HWFlowControl;
    //u8 UART_dma_mode;
    UE USARTEnableType;
  //u8    USARTPEInterruptEnable;
}USART_Configurations;


typedef struct
{
	USART_Configurations UART_Array[NUMBER_OF_USED_UARTS];
}USART_ConfigType;

extern USART_ConfigType arrOfUART[NUMBER_OF_USED_UARTS];

void USART_VidInit(const USART_ConfigType *USART_CFG);

void USART_TransmitString(USART_ID UART_ID, uint8 *string_Copy_U8Data);

uint8 USART_ReceiveByte(USART_ID UART_ID);

void UART_ReciveString();
#endif
