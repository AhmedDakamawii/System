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
#include "image2.h"


/*to appear a picture on TFT*/
/*try to make a code for drawing something on TFT  and to make a func takes 
start and end from user at main in different points  */


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



/*OUTPUT*/
      /*RESET PIN*/
MGPIO_VidSetPinDirection(0, 1, OUT_SPEED_2MHZ_PUSHPULL);
      /*AO PIN*/
MGPIO_VidSetPinDirection(0, 2, OUT_SPEED_2MHZ_PUSHPULL);
      /*CLK PIN*/
MGPIO_VidSetPinDirection(0, 5, OUT_SPEED_10MHZ_alternativeFUN_PP);
      /*MOSI PIN*/
MGPIO_VidSetPinDirection(0, 7, OUT_SPEED_10MHZ_alternativeFUN_PP);

/*TFT INIT*/
   HTFT_VidInit();
/*display image*/
HTFT_VidDisplayImage(image2);
/*fill color with white*/
//HTFT_VidDisplayFillColor(0xFFFF);
/*draw rect with certain area and black color*/
//HTFT_VidDrawRect(0,10,0,30,0x0000);


while(1)
{

}



}
