/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Uart.c
 *  Module:  	  Uart
 *  Description:  Source File for Uart
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Salma Hisham & Mohamed Emad & Mohamed Yehia
 *	Date:		  12/08/2023
 *********************************************************************************************************************/

/******************************************************************************
 *                             Includes                                        *
 ******************************************************************************/
#include "Uart.h"
#include "Uart_Regs.h"
#include "Uart_Types.h"

#include "RCC.h"

#define THRESHOLD_VALUE  400UL

uint8 (*USART1_CallBack)(void);
void (*USART2_CallBack)(void);
void (*USART3_CallBack)(void);
uint8 received_string1[MAX_STRING_TO_BE_RECEIVED_USART1];
uint8 received_string2[MAX_STRING_TO_BE_RECEIVED_USART2];
uint8 received_string3[MAX_STRING_TO_BE_RECEIVED_USART3];

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
void USART_Init(const USART_ConfigType *usart_config) {
	if (usart_config == NULL_PTR) {
		return;
	}

	volatile USART *uartptr = NULL_PTR;
int i = 0;
	for ( i = 0; i < USART_TOTAL_NUMBER; i++) {
		if (usart_config->UARTarray[i].USARTEnableType == DISABLE) {
			continue;
		}

		switch (usart_config->UARTarray[i].USARTid) {
		case USART1:
			uartptr = MUART1;
			RCC_APB2PeripheralEnable(USART1EN);
			break;

		case USART2:
			uartptr = MUART2;
			RCC_APB1PeripheralEnable(USART2EN);
			break;

		case USART3:
			uartptr = MUART3;
			RCC_APB1PeripheralEnable(USART3EN);
			break;
		}
		uint32 mantissa = (F_CPU) / (16 * usart_config->UARTarray[i].USARTBaud);
		uint32 fraction = (((F_CPU * 100)
				/ (16 * usart_config->UARTarray[i].USARTBaud)) % 100) * 16;
		if (fraction > 1500) {
			mantissa += 1;
			fraction = 0;
		}
		if (usart_config->UARTarray[i].USARTWordLength == Eight) {
			uartptr->CR1.BF.M = 0;
		} else if (usart_config->UARTarray[i].USARTWordLength == Nine) {
			uartptr->CR1.BF.M = 1;
		} else {
			/*[TODO] error handling*/
		}
		if (usart_config->UARTarray[i].USARTStopBits == OneBit) {
			uartptr->CR2.BF.STOP = 0b00;
		} else if (usart_config->UARTarray[i].USARTStopBits == HalfBit) {
			uartptr->CR2.BF.STOP = 0b01;
		} else if (usart_config->UARTarray[i].USARTStopBits == TwoBits) {
			uartptr->CR2.BF.STOP = 0b10;
		} else if (usart_config->UARTarray[i].USARTStopBits == OneAndHalfBits) {
			uartptr->CR2.BF.STOP = 0b11;
		} else {
			/*[TODO] error handling*/
		}

		if (usart_config->UARTarray[i].USARTMode == USART_MODE_ONLY_TX) {
			uartptr->CR1.BF.TE = 1;
			uartptr->CR1.BF.RE = 0;
		}
		if (usart_config->UARTarray[i].USARTMode == USART_MODE_ONLY_RX) {
			uartptr->CR1.BF.TE = 0;
			uartptr->CR1.BF.RE = 1;
		}
		if (usart_config->UARTarray[i].USARTMode == USART_MODE_TXRX) {
			uartptr->CR1.BF.TE = 1;
			uartptr->CR1.BF.RE = 1;
		} else {
			/*[TODO] error handling*/
		}

		if (usart_config->UARTarray[i].USARTParityControl == DISABLE) {
			uartptr->CR1.BF.PCE = 0;
		} else if (usart_config->UARTarray[i].USARTParityControl == ENABLE) {
			uartptr->CR1.BF.PCE = 1;
			if (usart_config->UARTarray[i].USARTParitySelection == Even) {
				uartptr->CR1.BF.PS = Even;
			} else if (usart_config->UARTarray[i].USARTParitySelection == Odd) {
				uartptr->CR1.BF.PS = Odd;
			}
		}

		if (usart_config->UARTarray[i].USARTPEInterruptEnable == ENABLE) {
			//  uartptr->CR1.BF.TXEIE = ENABLE;
			uartptr->CR1.BF.RXNEIE = ENABLE;
			// uartptr->CR1.BF.TCIE = ENABLE;
		} else if (usart_config->UARTarray[i].USARTPEInterruptEnable == DISABLE) {
			uartptr->CR1.BF.TXEIE = DISABLE;
			uartptr->CR1.BF.RXNEIE = DISABLE;
			uartptr->CR1.BF.TCIE = DISABLE;

		}

		/*Put baud rate value in BRR register*/
		uartptr->BRR.Reg = (mantissa << 4) | (fraction / 100);
		/*Start the USART*/
		uartptr->CR1.BF.UE = ENABLE;
	}
}

/******************************************************************************
 *                           Byte TX & RX                                     *
 ******************************************************************************/

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
void USART_TransmitByte(uint8 data, USART_ID ID) {
	switch (ID) {
	case USART1:
		MUART1->DR.Reg = data;
		while (!MUART1->SR.BF.TC) {
		}
		MUART1->SR.BF.TC = 0;
		break;

	case USART2:
		MUART2->DR.Reg = data;
		while (!MUART2->SR.BF.TC) {
		}
		MUART2->SR.BF.TC = 0;
		break;

	case USART3:
		MUART3->DR.Reg = data;
		while (!MUART3->SR.BF.TC) {
		}
		MUART3->SR.BF.TC = 0;
		break;
	}

}

/************************************************************************************
 * Service Name: USART2_TransmitByte
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Service_ID: 0x02
 * Parameters (in): data to be transmitted (Byte)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: USART2 Transmits one byte
 ************************************************************************************/
/*void USART2_TransmitByte(uint8 data)
 {
 MUART2->DR.Reg = data;
 while (!MUART2->SR.BF.TC)
 {
 }
 MUART2->SR.BF.TC = 0;
 }*/

/************************************************************************************
 * Service Name: USART3_TransmitByte
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Service_ID: 0x03
 * Parameters (in): data to be transmitted (Byte)
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: USART3 Transmits one byte
 ************************************************************************************/
/*void USART3_TransmitByte(uint8 data)
 {
 MUART3->DR.Reg = data;
 while (!MUART3->SR.BF.TC)
 {
 }
 MUART3->SR.BF.TC = 0;
 }*/

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
uint8 USART_ReceiveByte(USART_ID ID) {
	uint8 data;
	uint32 timeout;

	switch (ID) {
	case USART1:
		{
			//while(MUART1->SR.BF.RXNE==0);

		data = MUART1->DR.Reg;

		MUART1->SR.BF.RXNE==0;
		break;
		}
		//		    MUART1->SR.BF.RXNE = 0;
//		    timeout=0;
//		 while((MUART1->SR.BF.RXNE == 0) && (timeout < THRESHOLD_VALUE))
//		 {
//		 timeout++;
//
//		 }
//		 if(timeout == THRESHOLD_VALUE)
//		 {
//		 data = 255;
//		 }
//		 else
//		 {
//		 data = MUART1->DR.Reg;
//		 timeout=0;
//		 }
//break;

	case USART2:
		/*    MUART2->SR.BF.RXNE = 0;
		 while((MUART2->SR.BF.RXNE == 0) && (timeout < THRESHOLD_VALUE))
		 {
		 timeout++;
		 }

		 if(timeout == THRESHOLD_VALUE)
		 {
		 data = 255;
		 }
		 else
		 {
		 data = MUART2->DR.Reg;
		 timeout=0;
		 }
		 */
		 	while(MUART2->SR.BF.RXNE==0);
		data = MUART2->DR.Reg;
		break;

	case USART3:
		/*
	 MUART3->SR.BF.RXNE = 0;
	 while((MUART3->SR.BF.RXNE == 0) && (timeout < THRESHOLD_VALUE))
	 {
	 timeout++;
	 }

	 if(timeout == THRESHOLD_VALUE)
	 {
	 data = 255;
	 }
	 else
	 {
	 data = MUART3->DR.Reg;
	 timeout=0;
	 }
	 */
	while(MUART3->SR.BF.RXNE==0);
		data = MUART3->DR.Reg;

		break;
	}

	return data;
}

/************************************************************************************
 * Service Name: USART2_ReceiveByte
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Service_ID: 0x05
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): data received (Byte)
 * Return value: None
 * Description: USART2 Receives one byte
 ************************************************************************************/
/*
 uint8 USART2_ReceiveByte(void)
 {
 uint8 data;
 uint32 timeout;

 MUART2->SR.BF.RXNE = 0;
 while((MUART2->SR.BF.RXNE == 0) && (timeout < THRESHOLD_VALUE))
 {
 timeout++;
 }

 if(timeout == THRESHOLD_VALUE)
 {
 data = 255;
 }
 else
 {
 data = MUART2->DR.Reg;
 }
 return data;
 }
 */

/************************************************************************************
 * Service Name: USART3_ReceiveByte
 * Sync/Async: Synchronous
 * Reentrancy: reentrant
 * Service_ID: 0x06
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): data received (Byte)
 * Return value: None
 * Description: USART3 Receives one byte
 ************************************************************************************/
/*uint8 USART3_ReceiveByte(void)
 {
 uint8 data;
 uint32 timeout;

 MUART3->SR.BF.RXNE = 0;
 while((MUART3->SR.BF.RXNE == 0) && (timeout < THRESHOLD_VALUE))
 {
 timeout++;
 }

 if(timeout == THRESHOLD_VALUE)
 {
 data = 255;
 }
 else
 {
 data = MUART3->DR.Reg;
 }
 return data;
 }*/

void USART_VidSetCallBack(uint8 (*ptr)(void), USART_ID ID) {

	switch (ID) {
	case USART1:
		USART1_CallBack = ptr;
		break;

	case USART2:
		USART2_CallBack = ptr;
		break;

	case USART3:
		USART3_CallBack = ptr;
		break;
	}

}

/*void USART2_VidSetCallBack( void (*ptr) (void) ){

 USART2_CallBack = ptr ;

 }

 void USART3_VidSetCallBack( void (*ptr) (void) ){

 USART3_CallBack = ptr ;

 }*/

void USART1_IRQHandler(void) {

	USART1_CallBack();
	MUART1->SR.Reg = 0;
}

void USART2_IRQHandler(void) {

	USART2_CallBack();
	MUART2->SR.Reg = 0;

}

void USART3_IRQHandler(void) {

	USART3_CallBack();
	MUART3->SR.Reg = 0;

}

/******************************************************************************
 *                         String TX & RX                                     *
 ******************************************************************************/

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
void USART_TransmitString(uint8 *string_data, USART_ID ID) {
	int i = 0;
	for ( i = 0; string_data[i] != '\0'; i++) {
		USART_TransmitByte(string_data[i], ID);

	}
	//   USART_TransmitByte('#', ID);

}

/*void USART2_TransmitString(uint8 *string_data)
 {
 for (int i = 0 ; string_data[i] != '\0' ; i++)
 {
 USART2_TransmitByte(string_data[i]);

 }
 USART2_TransmitByte('#');
 }

 void USART3_TransmitString(uint8 *string_data)
 {
 for (int i = 0 ; string_data[i] != '\0' ; i++)
 {
 USART3_TransmitByte(string_data[i]);

 }
 USART3_TransmitByte('#');

 }*/

uint8* USART_ReceiveString(USART_ID ID) {
	uint8 data;
	int i;
	for (i = 0; (data = USART_ReceiveByte(ID)) != '#'; i++) {
		received_string1[i] = data;
	}
	received_string1[i] = '\0';
	return (received_string1);

}
/*
 uint8 *USART2_ReceiveString(void)
 {
 uint8 data;
 int i;
 for (int i = 0; data = USART2_ReceiveByte() != '#'; i++)
 {
 received_string2[i] = data;
 }
 received_string2[i] = '\0';
 return (received_string2) ;


 }


 uint8 *USART3_ReceiveString(void)
 {
 uint8 data;
 int i;
 for (int i = 0; data = USART3_ReceiveByte() != '#'; i++)
 {
 received_string3[i] = data;
 }
 received_string3[i] = '\0';
 return (received_string3) ;


 }*/

void USART_NewLine(USART_ID ID) {
	USART_TransmitByte('\r', ID);
	USART_TransmitByte('\n', ID);
}
