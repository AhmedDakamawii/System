#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "ESP_interface.h"
#include "AFIO_interface.h"
#include "UART_interface.h"

#define HIGH 1
#define LOW 0


void main(void)
{

	MRCC_VidInitSysClock();
	/*enable RCC GPIOA in APB2*/
	MRCC_VidEnableClock(RCC_APB2, 2);
	/*enable RCC GPIOB in APB2*/
	MRCC_VidEnableClock(RCC_APB2, 3);
	/*enable AFIO CLK in APB2*/
	MRCC_VidEnableClock(RCC_APB2, 0);

/*enable USART1 CLK in APB1*/
	MRCC_VidEnableClock(RCC_APB2, 14);


	/*INIT STK Timer*/
	     MSTK_voidInit();

	     /*INIT USART1*/
	     MUSART1_VidInit();

	     /*OUTPUT*/
	     MGPIO_VidSetPinDirection(0, 0, OUT_SPEED_2MHZ_PUSHPULL);

	     /*TX alternative function*/
MGPIO_VidSetPinDirection(0, 9, OUT_SPEED_50MHZ_alternativeFUN_PP);

/*INPUT*/
/*RX SHOULD BE INPUT FLOATING*/
MGPIO_VidSetPinDirection(0, 10, INPUT_FLOATING);

u8 value;

ESP_VidInit();
ESP_VIDConnectWifi( (u8*)"TEData_9485D7", (u8*)"h9c16788"); /* WI-FI Username and Password to connect */

	while(1)
	{
		/* Closed From Freeeee Website to change from led on to led off at the same debug */
		ESP_VIDConnectServer( (u8*)"23.179.32.37"); /* IP Address of Website */
		value=ESP_VIDSendData( (u8*)"http://dakamwii.freevar.com/status.txt", (u8*)"44");/* Length and Link of file to read from Website */
		if (value == 1 )
		{
				MGPIO_VidSetPinValue(0, 0, 1);
		}
		else if (value == 0 )
		{
				MGPIO_VidSetPinValue(0, 0, 0);
		}
	}
}
