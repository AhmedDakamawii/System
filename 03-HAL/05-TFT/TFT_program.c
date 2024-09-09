 /***************************************************************/
 /* Author : ahmed elsayed                                      */
 /*version:  V01                                                */
 /*Date:                                                        */ 
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h" 
#include "STK_interface.h"
#include "SPI_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"

void HTFT_VidInit(void)
{
	/*reset pulse */
	MGPIO_VidSetPinValue(TFT_RESET_PIN,HIGH);
	MSTK_voidSetBusyWaitus(100);
	MGPIO_VidSetPinValue(TFT_RESET_PIN,LOW);
	MSTK_voidSetBusyWaitus(1);
	MGPIO_VidSetPinValue(TFT_RESET_PIN,HIGH);
	MSTK_voidSetBusyWaitus(100);
	MGPIO_VidSetPinValue(TFT_RESET_PIN,LOW);
	MSTK_voidSetBusyWaitus(100);
	MGPIO_VidSetPinValue(TFT_RESET_PIN,HIGH);
	MSTK_voidSetBusyWaitus(120000);
	
	/*SLPOUT COMMAND*/
	VoidWriteCommand(0x11);
	MSTK_voidSetBusyWaitus(150000);
     /*COLOER MODE COMMAND*/
	VoidWriteCommand(0x3A);
	/*choose color mode RGB565*/
	VoidWriteData(0x05);
	/*DISPLAY ON COMMAND*/
	VoidWriteCommand(0x29);

}
void HTFT_VidDisplayImage(const u16* Copy_Image)
{

/*you can change of the start and the end of x,y as you want your picture location to be at the screen*/

	/*SET X AXIS address*/
	VoidWriteCommand(0x2A);
	/*start (send most bit of the two bytes first)*/
	VoidWriteData(0);
	VoidWriteData(0);
	/*end (send most bit of the two bytes first)*/
	VoidWriteData(0);
	VoidWriteData(127);

	/*SET Y AXIS address*/
	VoidWriteCommand(0x2B);
	/*start (send most bit of the two bytes first)*/
	VoidWriteData(0);
	VoidWriteData(0);
	/*end (send most bit of the two bytes first)*/
	VoidWriteData(0);
	VoidWriteData(159);

	/*RAM WRITE*/
	VoidWriteCommand(0x2C);
	/*to make picture appeat not to draw on tft*/
// 20480 is number of pixels
	u8 Data;
	for(u16 counter = 0; counter< 20480;counter++)
		{
			Data = Copy_Image[counter] >> 8;

			/* Write the high byte */
			VoidWriteData(Data);
			/* Write the low byte */
			Data = Copy_Image[counter] & 0x00ff;
			VoidWriteData(Data);
		}

}
void HTFT_VidDisplayFillColor(u16 Copy_Imagecolor)
{

/*you can change of the start and the end of x,y as you want your picture location to be at the screen*/

	/*SET X AXIS address*/
	VoidWriteCommand(0x2A);
	/*start (send most bit of the two bytes first)*/
	VoidWriteData(0);
	VoidWriteData(0);
	/*end (send most bit of the two bytes first)*/
	VoidWriteData(0);
	VoidWriteData(127);

	/*SET Y AXIS address*/
	VoidWriteCommand(0x2B);
	/*start (send most bit of the two bytes first)*/
	VoidWriteData(0);
	VoidWriteData(0);
	/*end (send most bit of the two bytes first)*/
	VoidWriteData(0);
	VoidWriteData(159);

	/*RAM WRITE*/
	VoidWriteCommand(0x2C);
	/*to make picture appeat not to draw on tft*/
// 20480 is number of pixels
	for (u16 counter=0 ; counter<20480 ; counter++)
	{
/*send the most 8 bit first as each pixel take 16 bit*/
		VoidWriteData(Copy_Imagecolor>>8);
/*send the low 8 bit first as each pixel take 16 bit*/
		VoidWriteData(Copy_Imagecolor & 0xFF);
	}

}

void HTFT_VidDrawRect(u8 x1 , u8 x2 , u8 y1 , u8 y2 ,u16 Copy_Imagecolor)
{
/*you can also draw many shapes not only rect*/
/*you can change of the start and the end of x,y as you want your picture location to be at the screen*/
/*x2 must br >> x1 */
/*y2 must br >> y1 */
/*equ for rect*/
   u16 size =(x2-x1)*(y2-y1);
	/*SET X AXIS address*/
	VoidWriteCommand(0x2A);
	/*start (send most bit of the two bytes first)*/
	VoidWriteData(0);
	VoidWriteData(x1);
	/*end (send most bit of the two bytes first)*/
	VoidWriteData(0);
	VoidWriteData(x2);

	/*SET Y AXIS address*/
	VoidWriteCommand(0x2B);
	/*start (send most bit of the two bytes first)*/
	VoidWriteData(0);
	VoidWriteData(y1);
	/*end (send most bit of the two bytes first)*/
	VoidWriteData(0);
	VoidWriteData(y2);

	/*RAM WRITE*/
	VoidWriteCommand(0x2C);
	/*to make picture appeat not to draw on tft*/
// 20480 is number of pixels
	for (u16 counter=0 ; counter<size ; counter++)
	{
/*send the most 8 bit first as each pixel take 16 bit*/
		VoidWriteData(Copy_Imagecolor>>8);
/*send the low 8 bit first as each pixel take 16 bit*/
		VoidWriteData(Copy_Imagecolor & 0xFF);
	}

}

static void VoidWriteData (u8 Copy_Data)
{
	u8 Local_Temp;
	/*set A0 pin to HIGH*/
	MGPIO_VidSetPinValue(TFT_AO_PIN,HIGH);
/*send data over SPI*/
MSPI1_voidSendReceiveSynch(Copy_Data , &Local_Temp);

}

static void VoidWriteCommand (u8 Copy_Command)
{
		u8 Local_Temp;
		/*set A0 pin to LOW*/
	MGPIO_VidSetPinValue(TFT_AO_PIN,LOW);
/*send command over SPI*/
MSPI1_voidSendReceiveSynch(Copy_Command,&Local_Temp);

}
