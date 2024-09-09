#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "DMA_Interface.h"
#include "RCC_Interface.h"
#include "NVIC_Interface.h"
#include "DMA_Interface.h"

void LED_ON (void)
{
	MGPIO_VidSetPinValue(0,7,1);
}

u16 Local_u16Index;
void main(void)
{
	u32 Arr1[1000]={0};
	u32 Arr2[1000];

	u32 Arr3[1000]={0};
	u32 Arr4[1000];

MGPIO_VidSetPinDirection(0,7,OUT_SPEED_2MHZ_PUSHPULL);

	/*Enable clock on DMA Peripheral*/
	MRCC_VidEnableClock(0,1);
//channel 1  -> 0
 MDMA_voidEnable(0);
  MDMA_voidSetChannelPriority( 0,MDMA_VERY_HIGH_PRI );
 MDMA_voidSetChannelMode( 0 ,  MDMA_MEM_TO_MEM, MDMA_CIRCULAR_DIS );
 MDMA_voidInterruptSource(0 , MDMA_COMPLETE_TRANSFER);
 MDMA_voidSetDataFlow(0,MDMA_WORD , MDMA_WORD ,MDMA_INC_EN , MDMA_INC_EN);

 
	MDMACH1_VidSetCallBack(LED_ON);
//DMA ENABLE ON NVIC
	MNVIC_VidEnableInterrupts(11);
	MDMA_voidChannelStart(0,Arr1,Arr2,1000);//CHANNEL 0 (CHANNEL 1)

	for( Local_u16Index=0;Local_u16Index<1000;Local_u16Index++)
	{
		Arr4[Local_u16Index]=Arr3[Local_u16Index];
	}


	while(1)
	{

	}
}
