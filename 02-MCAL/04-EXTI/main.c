#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"

void TOGGLE_LED1 (void);
void TOGGLE_LED2 (void);
void main (void)
{


	MRCC_VidInitSysClock();
	/*enable RCC GPIOA*/
	MRCC_VidEnableClock(2, 2);
	/*enable RCC GPIOB*/
	MRCC_VidEnableClock(2, 3);
	/*enable RCC GPIOC*/
	MRCC_VidEnableClock(2, 4);

/*INIT STK Timer*/
     MSTK_voidInit();

/*OUTPUT*/
	MGPIO_VidSetPinDirection(0, 0 ,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(0, 10,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(0, 12,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(1, 10,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(1, 14,OUT_SPEED_2MHZ_PUSHPULL );
/*INPUT*/
MGPIO_VidSetPinDirection(1, 0, INPUT_PULLUPDOWN);
MGPIO_VidSetPinDirection(0, 1, INPUT_PULLUPDOWN);

/*PULL UP*/
MGPIO_VidSetPinValue(1, 0, 1);//PULL UP AT B0 AS WE OPEN EXTI0 PORT B
MGPIO_VidSetPinValue(0, 1, 1);//PULL UP AT A1 AS WE OPEN EXTI1 PORT A

/*enable AFIO CLK*/
	MRCC_VidEnableClock(2, 0);

/*EXTI*/

//ENABLE EXTI0 and use its ISR
MNVIC_VidEnableInterrupts(6);
MEXTI0_VidSetCallBack(TOGGLE_LED1);
MEXTI_VidSetSignalLatch(0,FALLING );//LINE 0 FALLING MODE
MAFIO_VidSetEXTIConfig(0,AFIO_PORTB);//pin B0
MNVIC_VidSetPriorty(6, 2, 3,NVIC_GROUP2_SUB2 );

//ENABLE EXTI1 and use its ISR
MNVIC_VidEnableInterrupts(7);
MEXTI1_VidSetCallBack(TOGGLE_LED2);
MEXTI_VidSetSignalLatch(1,RASING );//LINE 1 RASING MODE
MAFIO_VidSetEXTIConfig(1,AFIO_PORTA);//pin A1
//EXTI1 HAS HIGH piriorty and when we make EXTI0 WORK THEN EXTI1 , EXTI0 stop working until EXTI1 finshes
MNVIC_VidSetPriorty(7, 0, 1,NVIC_GROUP2_SUB2 );

while(1)
{
	

}



}

void TOGGLE_LED1 (void)
{
	MGPIO_VidSetPinValue(0, 0, 1);
	/*another function in asmembly to make delay as STK is used as interval period and can not be used in many tasks*/
	MSTK_voidSetBusyWaitms(1000);
	MGPIO_VidSetPinValue(0, 0, 0);
	MSTK_voidSetBusyWaitms(1000);
}
void TOGGLE_LED2 (void)
{
	MGPIO_VidSetPinValue(1, 10, 1);
	/*another function in asmembly to make delay as STK is used as interval period and can not be used in many tasks*/
	MSTK_voidSetBusyWaitms(1000);
	MGPIO_VidSetPinValue(1, 10, 0);
	MSTK_voidSetBusyWaitms(1000);
}
