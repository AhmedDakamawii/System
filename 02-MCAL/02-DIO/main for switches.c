#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "DIO_interface.h"

void main (void)
{


	MRCC_VidInitSysClock();
	/*enable RCC GPIOA*/
	MRCC_VidEnableClock(2, 2);
	/*enable RCC GPIOB*/
	MRCC_VidEnableClock(2, 3);
	/*enable RCC GPIOC*/
	MRCC_VidEnableClock(2, 4);

	MGPIO_VidSetPinDirection(0, 10,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(0, 12,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(1, 10,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(1, 14,OUT_SPEED_2MHZ_PUSHPULL );

	MGPIO_VidSetPinDirection(0,0,INPUT_PULLUPDOWN);
	MGPIO_VidSetPinValue(0, 0, 1);
u8 switch_result=0;
while(1)
 {
	/*use switches and make led on during clicking on the switch by using PULL UP*/
	/*as in pull up if switch is clicked 0 is appear as a input and pull down is the inverse*/
	switch_result=MGPIO_U8GetPinValue(0,0);
if (0==switch_result)
{
	for (u16 i=0 ; i<500 ; i++)
	{
		for (u16 j=0; j<500 ; j++)
		{
	asm("NOP");
		}
	}
	MGPIO_VidSetPinValue(1, 10, 1);

}
else
{
	MGPIO_VidSetPinValue(1, 10, 0);

}


 }

}
