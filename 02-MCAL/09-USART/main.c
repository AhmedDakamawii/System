#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
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
	/*enable USART2 CLK in APB1*/
	MRCC_VidEnableClock(RCC_APB1, 17);

	/*INIT STK Timer*/
	     MSTK_voidInit();

	     /*INIT USART1*/
         MUSART1_VidInit();
	     /*INIT USART1*/
	     MUSART2_VidInit();

	     /*OUTPUT*/
	     MGPIO_VidSetPinDirection(0, 0, OUT_SPEED_2MHZ_PUSHPULL);

	     /*TX1*/
MGPIO_VidSetPinDirection(0, 9, OUT_SPEED_50MHZ_alternativeFUN_PP);

/*INPUT*/
/*RX1 SHOULD BE INPUT FLOATING*/
MGPIO_VidSetPinDirection(0, 10, INPUT_FLOATING);

/*TX2*/
MGPIO_VidSetPinDirection(0, 2, OUT_SPEED_50MHZ_alternativeFUN_PP);

/*RX2 SHOULD BE INPUT FLOATING*/
MGPIO_VidSetPinDirection(0, 3, INPUT_FLOATING);

u8 value;
		MUSART2_VidTransmit((u8*)"97");

	while(1)
	{
		value = MUSART2_U8Receive();
			if(value == '5')
			{
				MGPIO_VidSetPinValue(GPIOA,0,HIGH);
			}
			if(value == 'r')
			{
				MGPIO_VidSetPinValue(GPIOA,0,LOW);
			}
	}
}
