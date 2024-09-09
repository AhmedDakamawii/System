
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

	MGPIO_VidSetPinDirection(0, 0 ,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(0, 10,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(0, 12,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(1, 10,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(1, 14,OUT_SPEED_2MHZ_PUSHPULL );


while(1)
 {
/*make this leds on*/
MGPIO_VidSetPinValue(0, 10, 1);
MGPIO_VidSetPinValue(0, 12, 1);
MGPIO_VidSetPinValue(1, 10, 1);
MGPIO_VidSetPinValue(1, 14, 1);
//new method for make led on faster
MGPIO_VidSetPinFaster(0,0);
//lock the pin A0
MGPIO_VidLockPin(0,0);
/*TOGGLE PIN A10 BY ASSMBELY CODE*/
for (u16 i=0 ; i<500 ; i++)
{
	for (u16 j=0; j<1000 ; j++)
	{
asm("NOP");
	}
}

MGPIO_VidSetPinValue(0, 10, 0);
//new method for make led off faster
MGPIO_VidResetPinFaster(0,0);

for (u16 i=0; i<500 ; i++)
{
	for (u16 j=0; j<1000 ; j++)
	{
asm("NOP");
	}
}



 }

}
