/*********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Uart_types.h
 *  Module:  	  Uart
 *  Description:  Header File for Uart types
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Salma Hisham 
 *	Date:		  11/08/2023
 *********************************************************************************************************************/
#ifndef _UART_TYPES_H_
#define _UART_TYPES_H_

#include "Std_Types.h"

#define USART_TOTAL_NUMBER                     3
#define F_CPU                                  8000000
#define MAX_STRING_TO_BE_RECEIVED_USART1       100
#define MAX_STRING_TO_BE_RECEIVED_USART2       100
#define MAX_STRING_TO_BE_RECEIVED_USART3       100

 
/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Enable of USART prescalar and outputs */
typedef uint8 USART_Enable;    

/* Enable of USART Parity Control*/
typedef uint8 USART_ParityControlEnable;    

/* Enable of USART PE Interrupt */
typedef uint8 USART_PE_InterruptEnable;

/* Enable of USART TXE Interrupt */
typedef uint8 USART_TXE_InterruptEnable;

/* Enable of USART Transmission Complete Interrupt */
typedef uint8 USART_TC_InterruptEnable;

/* Enable of USART RXNE Interrupt */
typedef uint8 USART_RXNE_InterruptEnable;

/* Enable of USART IDLE Interrupt */
typedef uint8 USART_IDLE_InterruptEnable;

/* Enable of USART Transmitter */
typedef uint8 USART_TransmitterEnable;

/* Enable of USART Receiver */
typedef uint8 USART_ReceiverEnable;

/* Enable of USART LIN Mode */
typedef uint8 USART_LINEnable;

/* Enable of Clock */
typedef uint8 USART_ClockEnable;

/* Enable of USART LIN Break Detection Interrupt */
typedef uint8 USART_LIN_BreakDetectInterruptEnable;

/* Enable of USART CTS Interrupt */
typedef uint8 USART_CTS_InterruptEnable;

/* Enable of USART CTS */
typedef uint8 USART_CTSEnable;

/* Enable of USART RTS */
typedef uint8 USART_RTSEnable;

/* Enable of USART DMA Transmitter */
typedef uint8 USART_DMATransmitterEnable;

/* Enable of USART DMA receiver */
typedef uint8 USART_DMAReceiverEnable;

/* Enable of USART Smartcard mode */
typedef uint8 USART_SmartCardEnable;

/* Enable of USART Smartcard NACK */
typedef uint8 USART_SmartCardNACKEnable;

/* Enable of USART IrDA mode */
typedef uint8 USART_IrDAEnable;

/* Enable of USART Error Interrupt */
typedef uint8 USART_Error_InterruptEnable;

/* USART Guard Time */
typedef uint8 USART_GuardTime;

/* USART Prescaler */
typedef uint8 USART_Prescaler;


/* USART Number */
typedef enum
{
	USART1,
	USART2,
	USART3
}USART_ID;

/*USART Mode */
typedef enum
{
   USART_MODE_ONLY_TX,
   USART_MODE_ONLY_RX,
   USART_MODE_TXRX   
}UART_MODE;

/* USART Word Length */ 
typedef enum
{
  Eight,
  Nine
}USART_WordLength;

/*USART Buad Rate */
typedef enum
{
   USART_STD_BAUD_2400    = 2400,
   USART_STD_BAUD_9600    = 9600,
   USART_STD_BAUD_19200   = 19200,
   USART_STD_BAUD_38400   = 38400,
   USART_STD_BAUD_57600   = 57600,
   USART_STD_BAUD_115200  = 115200,
   USART_STD_BAUD_230400  = 230400,
   USART_STD_BAUD_460800  = 460800,
   USART_STD_BAUD_921600  = 921600,
   USART_STD_BAUD_2250000 = 2250000,
   SUART_STD_BAUD_4500000 = 4500000	  
}USART_BAUD;

/* USART Wakeup Method*/
typedef enum
{
  Idle,
  Address_Mark
}USART_Wakeup;

/* USART Parity Selection */
typedef enum
{
  Even,
  Odd
}USART_ParitySelection;

/* USART Receiver Wakeup */
typedef enum
{
  Active,
  Mute
}USART_ReceiverWakeup;

/* USART Send Break */
typedef enum
{
  NoBreak,
  Break
}USART_SendBreak;

/* Stop bits programming */
typedef enum
{
  OneBit,
  HalfBit,
  TwoBits,
  OneAndHalfBits
}USART_StopBits;

/* Select clock polarity */
typedef enum
{
  SteadyLow,
  SteadyHigh
}USART_ClockPolarity;

/* clock phase selection */
typedef enum
{
  First,
  Second
}USART_ClockPhase;

/* Half Duplex Selection */
typedef enum
{
  Selected,
  NotSelected
}USART_HalfDuplex;

/* IrDa Low power mode */
typedef enum
{
  Normal,
  LowPower
}USART_IrDALowPower;


/*
 * Configuration structure for UARTx peripheral
 */
typedef struct
{
	USART_ID                      USARTid;
	USART_BAUD                  USARTBaud;
	USART_WordLength              USARTWordLength;
	USART_StopBits              USARTStopBits;
	UART_MODE                 USARTMode;
	USART_ParityControlEnable   USARTParityControl;
	USART_ParitySelection         USARTParitySelection;
	USART_Enable                  USARTEnableType;
	USART_PE_InterruptEnable    USARTPEInterruptEnable;
}USART_Configurations;


typedef struct
{
	USART_Configurations UARTarray[USART_TOTAL_NUMBER];
}USART_ConfigType;


#endif













