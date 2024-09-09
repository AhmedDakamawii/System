#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"

#include "DIO_private.h"

#include "STOP.h"

u16 i =0;
/*as to hear a human voice we should be at frequency more than or equal 8000 we make an audio with 8000
 * sample/sec  and sec has 1000 msec so 1000/8000=0.125 msec = 125 usecso each 125 usec sample comes out
*/

//the array in file.h we should put before unsigned char word const to put the array in flash not in RAM

//
void VoidSetDAC(void)
{
	GPIOA_ODR= STOP_raw [i];
	i++;
	//max number of array used for the audio
	if (i==14507)
	{
		i=0;
	}
}


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
	MGPIO_VidSetPinDirection(0, 1 ,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(0, 2 ,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(0, 3 ,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(0, 4 ,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(0, 5 ,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(0, 6 ,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(0, 7 ,OUT_SPEED_2MHZ_PUSHPULL );

	MGPIO_VidSetPinDirection(0, 10,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(0, 12,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(1, 10,OUT_SPEED_2MHZ_PUSHPULL );
	MGPIO_VidSetPinDirection(1, 14,OUT_SPEED_2MHZ_PUSHPULL );

	//enter function each 125 usec to take a sample from audio
MSTK_voidSetIntervalPeriodicus(125, VoidSetDAC);



while(1)
{
	

}



}


