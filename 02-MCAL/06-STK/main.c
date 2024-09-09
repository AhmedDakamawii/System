#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"

void SET_LED (void);
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


	MGPIO_VidSetPinDirection(0, 0 ,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(0, 10,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(0, 12,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(1, 10,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(1, 14,OUT_SPEED_2MHZ_PUSHPULL );




while(1)
{
	/*TO TEST SetIntervalPeriodi*/
	
//STK_voidSetIntervalPeriodicms(3000, SET_LED);

/*TO TEST SetBusyWait*/

MGPIO_VidSetPinValue(0, 0, 1);
MSTK_voidSetBusyWaitms(1000);
MGPIO_VidSetPinValue(0, 0, 0);
MSTK_voidSetBusyWaitms(1000);
}



}

void SET_LED (void)
{
	MGPIO_VidSetPinValue(0, 0, 1);
	/*another function in asmembly to make delay as STK is used as interval period and can not be used in many tasks*/
	for (u16 i=0 ; i<900 ; i++)
		{
			for (u16 j=0; j<900 ; j++)
			{
		asm("NOP");
			}

}
	MGPIO_VidSetPinValue(0, 0, 0);

}
