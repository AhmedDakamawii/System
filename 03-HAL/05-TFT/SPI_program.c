 /***************************************************************/
 /* Author : ahmed elsayed                                      */
 /*version:  V01                                                */
 /*Date:                                                        */ 
 /*Describtion: SPI                                           */ 
/****************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_confg.h"
#include "DIO_interface.h"


void (*SPI1_CallBack)(u8);

void MSPI1_voidInit(void)
{
	/* CPOL =1 / CPHA = 1 / Prescaller = Clk/2 / SPI Enable / MSB First */
	MSPI1->CR1 = 0x0347;
}

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive)
{
	/* Clear For Slave Select Pin */
	MGPIO_VidSetPinValue(SPI1_SLAVE_PIN,LOW);
	
	/* Send Data */
	MSPI1 -> DR = Copy_u8DataToTransmit;
	
	/* Wait Busy Flag to finish */
	while (GET_BIT(MSPI1 -> SR, 7) == 1);

 	/* Return to the received data */
	*Copy_DataToReceive = MSPI1 -> DR;
	
	/* Set Salve Select Pin */
	MGPIO_VidSetPinValue(SPI1_SLAVE_PIN,HIGH);
}
