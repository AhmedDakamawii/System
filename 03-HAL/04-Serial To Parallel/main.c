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
#include "STP_interface.h"

//use only 3 pins and get 8 pins by IC 74595 
//we also can use only 3 pins and get 16 pins by two of IC 74595
void main (void)
 {


	MRCC_VidInitSysClock();
	/*enable RCC GPIOA in APB2*/
	MRCC_VidEnableClock(RCC_APB2, 2);
	/*enable RCC GPIOB in APB2*/
	MRCC_VidEnableClock(RCC_APB2, 3);
	/*enable AFIO CLK in APB2*/

/*INIT STK Timer*/
     MSTK_voidInit();

/*OUTPUT*/
MGPIO_VidSetPinDirection(0, 0, OUT_SPEED_2MHZ_PUSHPULL);
MGPIO_VidSetPinDirection(0, 1, OUT_SPEED_2MHZ_PUSHPULL);
MGPIO_VidSetPinDirection(0, 2, OUT_SPEED_2MHZ_PUSHPULL);

STP_VoidSendSynchrouns(0xAA); //AA=10101010


while(1)
{
// send eight 1's to turn on all leds only one at a time
for (u8 i=0 ; i<8 ; i++)
{
	STP_VoidSendSynchrouns(1<<i);
	MSTK_voidSetBusyWaitms(300);

}
}



}
