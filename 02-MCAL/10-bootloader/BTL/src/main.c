/*
 * main.c
 *
 *  Created on: Oct 13, 2020
 *      Author: Ahmed ELSAYED
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "UART_interface.h"
#include "FPEC_interface.h"

void Parser_voidParseRecord(u8* Copy_u8BufData);

volatile u8  u8RecBuffer[100]   ;
volatile u8  u8RecCounter    = 0;
volatile u8  u8TimeOutFlag   = 0;
volatile u16 u16TimerCounter = 0;
volatile u8  u8BLWriteReq    = 1;
typedef void (*Function_t)(void);
Function_t addr_to_call = 0;

void func(void)
{
#define SCB_VTOR   *((volatile u32*)0xE000ED08)

	SCB_VTOR = 0x08001000;

	addr_to_call = *(Function_t*)(0x08001004);
	addr_to_call();
}


void main(void)
{
	u8 Local_u8RecStatus;

	MRCC_VidInitSysClock();
	MRCC_VidEnableClock(RCC_APB2,14); /* USART1 */
	MRCC_VidEnableClock(RCC_APB2,2);  /* PortA  */
	MRCC_VidEnableClock(RCC_AHB,4);   /* FPEC   */


	MGPIO_VidSetPinDirection(GPIOA,9,0b1010);   /* TX AFPP */
	MGPIO_VidSetPinDirection(GPIOA,10,0b0100);  /* RC Input Floating */

	MUSART1_VidInit();

	MSTK_voidInit();

	MSTK_voidSetIntervalSinglems(15000,func);

	while(u8TimeOutFlag == 0)
	{

		Local_u8RecStatus = MUSART1_U8ReceiveBootLoader( &(u8RecBuffer[u8RecCounter]) );
		if (Local_u8RecStatus == 1)
		{
			MSTK_voidStopInterval();

			if(u8RecBuffer[u8RecCounter] == '\n')
			{
				if (u8BLWriteReq == 1)
				{
					FPEC_voidEraseAppArea();
					u8BLWriteReq = 0;
				}
				
				/* Parse */
				Parser_voidParseRecord(u8RecBuffer);
				MUSART1_VidTransmit("ok");
				u8RecCounter = 0;
			}

			else
			{
				u8RecCounter ++ ;
			}

			MSTK_voidSetIntervalSinglems(15000,func);
		}

		else
		{

		}
	}
}
