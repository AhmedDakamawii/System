/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Uart_Regs.h
 *  Module:  	  Uart
 *  Description:  Header File for Uart Registers
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Salma Hisham & Mohamed Emad & Mohamed Yehia
 *	Date:		  11/08/2023
 *********************************************************************************************************************/
#ifndef _UART_REGS_H_
#define _UART_REGS_H_

#include "Platform_Types.h"
#include "Macros.h"


#define UART_BASEADDRESS 0x40013800 


typedef struct
{
  uint32 PE : 1;                              /* Parity Error */
  uint32 FE : 1;                              /* Framing Error */
  uint32 NE : 1;                              /* Noise Error Flag */
  uint32 ORE : 1;                             /* Overrun Error */
  uint32 IDLE : 1;                            /* IDLE Line Detected */
  uint32 RXNE : 1;                            /* Read Data Register Not Empty */
  uint32 TC : 1 ;                             /* Transmission Complete */
  uint32 TXE : 1;                             /* Transmit data register empty */
  uint32 LBD : 1;                             /* LIN break detection flag */
  uint32 CTS : 1;                             /* CTS Flag */
  uint32 reserved : 22;                       /* Reserved bits */
} USART_SR_BF;

typedef union
{
  uint32 Reg;
  USART_SR_BF BF;
} USART_SR_TAG;



typedef struct
{
uint32 DR : 9;                                /* Data Value */
uint32 reserved : 23;                         /* Reserved Bits */
} USART_DR_BF;

typedef union
{
  uint32 Reg;
  USART_DR_BF BF;
} USART_DR_TAG;



typedef struct
{
  uint32 DIV_Fraction : 4;                    /* Fraction of USARTDIV */
  uint32 DIV_Mantissa : 12;                   /* Mantissa of USARTDIV */
  uint32 reserved : 16;                       /* Reserved Bits */
} USART_BRR_BF;

typedef union
{
  uint32 Reg;
  USART_BRR_BF BF;
} USART_BRR_TAG;



typedef struct
{
  uint32 SBK : 1;                            /* Send Break */
  uint32 RWU : 1;                            /* Receiver wakeup */
  uint32 RE : 1;                             /* Receiver Enable */
  uint32 TE : 1;                             /* Transmitter Enable */
  uint32 IDLEIE : 1;                         /* IDLE Interrupt Enable */
  uint32 RXNEIE : 1;                         /* RXNE Interrupt Enable */
  uint32 TCIE : 1;                           /* Transission complete interrupt enable */
  uint32 TXEIE : 1;                          /* TXE interrupt enable */
  uint32 PEIE : 1;                           /* PE interrupt enable */
  uint32 PS : 1;                             /* Parity selection */
  uint32 PCE : 1;                            /* Parity control enable */
  uint32 WAKE : 1;                           /* Wakeup method */
  uint32 M : 1;                              /* Word Length */
  uint32 UE : 1;                             /* USART Enable */
  uint32 reserved : 18;                      /* Reserved bits */
} USART_CR1_BF;

typedef union
{
  uint32 Reg;
  USART_CR1_BF BF;
} USART_CR1_TAG;



typedef struct
{
  uint32 ADD : 4;                           /* Address of the USART node */
  uint32 reserved_0 : 1;                    /* Reserved bit */
  uint32 LBDL : 1;                          /* Lin break detection length */
  uint32 LBDIE : 1;                         /* Lin break detection interrupt enable */
  uint32 reserved_2 : 1;                    /* Reserved bit */
  uint32 LBCL : 1;                          /* Last bit clock pulse */
  uint32 CPHA : 1;                          /* Clock Phase */
  uint32 CPOL : 1;                          /* Clock Polarity */
  uint32 CLKEN : 1;                         /* Clock Enable */
  uint32 STOP : 2;                          /* STOP bits */
  uint32 LINEN : 1;                         /* LIN mode enable */
  uint32 reserved_3 : 17;                   /* Reserved bit */
} USART_CR2_BF;


typedef union
{
  uint32 Reg;
  USART_CR2_BF BF;
} USART_CR2_TAG;



typedef struct
{
  uint32 EIE : 1;                           /* Error interrupt enable */
  uint32 IREN : 1;                          /* IrDA mode enable */
  uint32 IRLP : 1;                          /* IrDA low-power */
  uint32 HDSEL : 1;                         /* Half duplex selection */
  uint32 NACK : 1;                          /* Smartcard NACK enable */
  uint32 SCEN : 1;                          /* Smartcard mode enable */
  uint32 DMAR : 1;                          /* DMA enable receiver */
  uint32 DMAT : 1;                          /* DMA enable transmitter */
  uint32 RTSE : 1;                          /* RTS enable */
  uint32 CTSE : 1;                          /* CTS enable*/
  uint32 CTSIE : 1;                         /* CTS interrupt enable */  
  uint32 reserved : 21;                     /* reserved bits */
} USART_CR3_BF;


typedef union
{
  uint32 Reg;
  USART_CR3_BF BF;
} USART_CR3_TAG;



typedef struct
{
  uint32 PSC : 8;                          /* Prescaler value */
  uint32 GT : 8;                           /* Guard time value */
  uint32 reserved : 16;                    /* reserved bits */
} USART_GTPR_BF;


typedef union
{
  uint32 Reg;
  USART_GTPR_BF BF;
} USART_GTPR_TAG;


typedef struct
{
	USART_SR_TAG     SR;   /* Status register                   */
	USART_DR_TAG     DR;   /* Data Register                     */
	USART_BRR_TAG    BRR;  /* Baud Rate Register                */
	USART_CR1_TAG    CR1;  /* Control register 1                */
	USART_CR2_TAG    CR2;  /* Control register 2                */
	USART_CR3_TAG    CR3;  /* Control register 3                */
	USART_GTPR_TAG   GTPR; /* Guard time and prescaler register */
} USART;


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define MUART1 ((volatile USART *)0x40013800)
#define MUART2 ((volatile USART *)0x40004400)
#define MUART3 ((volatile USART *)0x40004800)


#endif














