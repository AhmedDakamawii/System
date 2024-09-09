
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"

void main (void)
{


	MRCC_VidInitSysClock();
	/*enable RCC GPIOA*/
	MRCC_VidEnableClock(2, 2);
	/*enable RCC GPIOB*/
	MRCC_VidEnableClock(2, 3);
	/*enable RCC GPIOC*/
	MRCC_VidEnableClock(2, 4);


	MGPIO_VidSetPinDirection(0, 0 ,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(0, 10,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(0, 12,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(1, 10,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(1, 14,OUT_SPEED_2MHZ_PUSHPULL );

//enable EXTIO AND EXTI1 FROM NVIC
MNVIC_VidEnableInterrupts(6);
MNVIC_VidEnableInterrupts(7);
/*change PRIORTY in EXTI0 and EXTI1 and make EXTI1 has higher PRIORTY*/
MNVIC_VidSetPriorty(7, 0, 0, NVIC_GROUP2_SUB2);
MNVIC_VidSetPriorty(6, 1, 1, NVIC_GROUP2_SUB2);
//set EXTI0 pending flag
MNVIC_VidSetPendingFlag(6);


while(1)
{

}

}

void EXTI0_IRQHandler (void)
{
MGPIO_VidSetPinValue(0, 0, 1);
//set EXTI1 pending flag
MNVIC_VidSetPendingFlag(7);
MGPIO_VidSetPinValue(1, 10, 1);


}
void EXTI1_IRQHandler (void)
{
	MGPIO_VidSetPinValue(0, 10, 1);
}
