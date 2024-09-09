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
#include "TFT_interface.h"
#include "SPI_interface.h"
#include "image.h"


/*to appear a picture on TFT*/
/*try to make a code for drawing something on TFT srart and end from different points you get from user
 in main */


void main (void)
 {


	MRCC_VidInitSysClock();
	/*enable RCC GPIOA in APB2*/
	MRCC_VidEnableClock(RCC_APB2, 2);
	/*enable RCC GPIOB in APB2*/
	MRCC_VidEnableClock(RCC_APB2, 3);
	/*enable AFIO CLK in APB2*/
	MRCC_VidEnableClock(RCC_APB2, 0);

	/*enable SPI1 CLK in APB2*/
	MRCC_VidEnableClock(RCC_APB2, 12);


/*INIT STK Timer*/
     MSTK_voidInit();

    /*SPI INIT*/
     MSPI1_voidInit();

     /*TFT INIT*/
     HTFT_VidInit();

/*OUTPUT*/
      /*RESET PIN*/
MGPIO_VidSetPinDirection(0, 1, OUT_SPEED_2MHZ_PUSHPULL);
      /*AO PIN*/
MGPIO_VidSetPinDirection(0, 2, OUT_SPEED_2MHZ_PUSHPULL);
      /*CLK PIN*/
MGPIO_VidSetPinDirection(0, 5, OUT_SPEED_10MHZ_alternativeFUN_PP);
      /*MOSI PIN*/
MGPIO_VidSetPinDirection(0, 7, OUT_SPEED_10MHZ_alternativeFUN_PP);


/*display image*/
HTFT_VidDisplayImage(image);



while(1)
{

}



}
