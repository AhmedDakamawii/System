#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"
#include "IR_interface.h"
#include "DCMOTOR_interface.h"
#include "TIMER_interface.h"
#include "CC_interface.h"
#include "ultrasonic_interface.h"


void main (void)
 {
	MRCC_VidInitSysClock();
	/*enable RCC GPIOA in APB2*/
	MRCC_VidEnableClock(RCC_APB2, 2);
	/*enable RCC GPIOB in APB2*/
	MRCC_VidEnableClock(RCC_APB2, 3);
	/*enable AFIO CLK in APB2*/
	MRCC_VidEnableClock(RCC_APB2, 0);
/*enable TIMER2 CLK in APB1*/
	MRCC_VidEnableClock(RCC_APB1, 0);
	/*enable RCC tim3 in APB2*/
	MRCC_VidEnableClock(RCC_APB1, 1);
	/*enable RCC tim4 in APB2*/
   MRCC_VidEnableClock(RCC_APB1, 2);
	/*TIMER 2 INIT and */
	MTIM2_voidInit();
	MNVIC_VidEnableInterrupts(28);
/*INIT STK Timer*/
     MSTK_voidInit();
     /*DC MOTOR*/
     DCMOTOR1_VidInit();
     DCMOTOR2_VidInit();
/*dont forget we use EXTI0  in IR*/
     Void_IRINIT();

     /*ultrasonic*/
     Ultrasonic_voidInit();
/*OUTPUT*/

/*INPUT*/
    MGPIO_VidSetPinDirection(1, 0, INPUT_FLOATING);//input floating connected to output of IR
    MGPIO_VidSetPinDirection(0, 0, OUT_SPEED_2MHZ_alternativeFUN_PP);//PWM

while(1)
{
/*if we use IR no cruise control*/
	CruiseControl_Void_TakeAction();
}



}
