 /***************************************************************/
 /* Author : ahmed elsayed                                      */
 /*version:  V01                                                */
 /*Date:                                                        */ 
 /*Describtion: DMA                                           */ 
/****************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_confg.h"

static void (*DMACH1_CallBack)(void)=NULL;
static void (*DMACH2_CallBack)(void)=NULL;
static void (*DMACH3_CallBack)(void)=NULL;

void MDMA_voidEnable( u8 Copy_u8ChannelNum )
{
		SET_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_EN );
}

void MDMA_voidDisable( u8 Copy_u8ChannelNum )
{
		CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_EN );
}
void MDMA_voidSetChannelPriority( u8 Copy_u8ChannelNum , u8 Copy_u8PriorityLevel )
{
	MDMA_voidDisable( Copy_u8ChannelNum );
	switch(Copy_u8PriorityLevel)
	{
		case MDMA_LOW_PRI       :  CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_PL0 );  
		                           CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_PL1 );  break;
		case MDMA_MEDIUM_PRI    :  SET_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_PL0 );  
		                           CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_PL1 );  break;
		case MDMA_HIGH_PRI      :  CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_PL0 );  
		                           SET_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_PL1 );  break;
		case MDMA_VERY_HIGH_PRI :  SET_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_PL0 );  
		                           SET_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_PL1 );  break;
		default                 :  /* Return ERROR */                                             break;
	}
}
void MDMA_voidSetChannelMode( u8 Copy_u8ChannelNum , u8 Copy_u8ChannelMode , u8 Copy_u8CircularState )
{
	MDMA_voidDisable( Copy_u8ChannelNum );
	if( Copy_u8ChannelMode == MDMA_MEM_TO_MEM )
	{
		SET_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_MEM2MEM );
		CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_DIR );
	}
	else if( Copy_u8ChannelMode == MDMA_PER_TO_MEM )
	{
		CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_MEM2MEM );
		CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_DIR );
	}
	else if( Copy_u8ChannelMode == MDMA_MEM_TO_PER )
	{
		CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_MEM2MEM );
		SET_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_DIR );
	}
	else if( Copy_u8ChannelMode == MDMA_PER_TO_PER )
	{
		CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_MEM2MEM );
		CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_DIR );
	}
	else
	{
		 /* Return ERROR */
	}
	if( Copy_u8CircularState == MDMA_CIRCULAR_EN )
	{
		SET_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_CIRC );
	}
	else if( Copy_u8CircularState == MDMA_CIRCULAR_DIS )
	{
		CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_CIRC );
	}
	else
	{
		 /* Return ERROR */
	}
}
void MDMA_voidClearInterruptFlags( u8 Copy_u8ChannelNum )
{
	CLR_BIT( MDMA->IFCR , (MDMA_CTEIF + Copy_u8ChannelNum * 4) );
	CLR_BIT( MDMA->IFCR , (MDMA_CHTIF + Copy_u8ChannelNum * 4) );
	CLR_BIT( MDMA->IFCR , (MDMA_CTCIF + Copy_u8ChannelNum * 4) );
	CLR_BIT( MDMA->IFCR , (MDMA_CGIF  + Copy_u8ChannelNum * 4) );
}

void MDMA_voidInterruptSource( u8 Copy_u8ChannelNum , u8 Copy_u8INTSrc )
{
MDMA_voidClearInterruptFlags( Copy_u8ChannelNum );
	switch(Copy_u8INTSrc)
	{
		case MDMA_TRANSFER_ERR      :  SET_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_TEIE );  break;
		case MDMA_HALF_TRANSFER     :  SET_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_HTIE );  break;
		case MDMA_COMPLETE_TRANSFER :  SET_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_TCIE );  break;
		default                     :  /* Return ERROR */                                              break;
	}	
}
void MDMA_voidSetDataFlow( u8 Copy_u8ChannelNum , u8 Copy_u8SrcSize , u8 Copy_u8DstSize , u8 Copy_u8SrcIncMode , u8 Copy_u8DstIncMode )
{
	MDMA_voidDisable( Copy_u8ChannelNum );
	if( Copy_u8MEMIncMode == MDMA_INC_EN )
	{
		SET_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_MINC );
	}
	else if( Copy_u8MEMIncMode == MDMA_INC_DIS )
	{
		CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_MINC );
	}
	else
	{
		 /* Return ERROR */
	}
	if( Copy_u8PERIncMode == MDMA_INC_EN )
	{
		SET_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_PINC );
	}
	else if( Copy_u8PERIncMode == MDMA_INC_DIS )
	{
		CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_PINC );
	}
	else
	{
		 /* Return ERROR */
	}
	switch(Copy_u8MEMSize)
	{
		case MDMA_BYTE      : CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_MSIZE0 );
		                      CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_MSIZE1 );  break;
		case MDMA_HALF_WORD : SET_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_MSIZE0 );
		                      CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_MSIZE1 );  break;
		case MDMA_WORD      : CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_MSIZE0 );
		                      SET_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_MSIZE1 );  break;
		default                 :  /* Return ERROR */                                           break;
	}
	switch(Copy_u8PERSize)
	{
		case MDMA_BYTE      : CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_PSIZE0 );
		                      CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_PSIZE1 );  break;
		case MDMA_HALF_WORD : SET_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_PSIZE0 );
		                      CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_PSIZE1 );  break;
		case MDMA_WORD      : CLR_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_PSIZE0 );
		                      SET_BIT( MDMA->CHANNEL[ Copy_u8ChannelNum ].CCR , MDMA_PSIZE1 );  break;
		default                 :  /* Return ERROR */                                           break;
	}
	
}
   
   
   
   
void  MDMA_voidChannelStart(u8 Copy_ChannelId ,u32 *Copy_PtrAdrressSource ,u32 *Copy_PtrAdrressDest ,u16 Copy_BlockLength)
{
		/*Make sure channel is disabled at first so that the system wont work while iam writing on registers*/
		CLR_BIT (MDMA->CHANNEL[Copy_ChannelId].CCR , 0);//disable DMA at channel given
			/*write the addresses*/
//if data transfer from memory to memory the register CPAR which is for prephiral address should be the source
MDMA->CHANNEL[Copy_ChannelId].CPAR = Copy_PtrAdrressSource;
MDMA->CHANNEL[Copy_ChannelId].CMAR = Copy_PtrAdrressDest;
		/*Block length*/
MDMA->CHANNEL[Copy_ChannelId].CNDTR = Copy_BlockLength;

                 /*enable DMA again*/
	SET_BIT(MDMA->CHANNEL[Copy_ChannelId].CCR,0);

}
//channel 1 we call it in the main by channel 0
void DMA1_Channel1_IRQHandler(void)
{
/*here put break point then depug to see that DMA finshes transfer while processor is far away from finshing*/
	DMACH1_CallBack();
	/*Clear Interrupt flag*/
	SET_BIT(MDMA->IFCR , 0);		/*Clear Global Interrupt flag of channel1*/
	SET_BIT(MDMA->IFCR , 1);		/*Clear transfer complete Interrupt flag of channel1*/
}

void MDMACH1_VidSetCallBack(void (*Ptr)(void))
{
	DMACH1_CallBack=Ptr;
}

//channel 2 we call it in the main by channel 0
void DM1_Channel2_IRQHandler(void)
{
/*here put break point then depug to see that DMA finshes transfer while processor is far away from finshing*/
	DMACH2_CallBack();
	/*Clear Interrupt flag*/
	SET_BIT(MDMA->IFCR , 4);		/*Clear Global Interrupt flag of channel1*/
	SET_BIT(MDMA->IFCR , 5);		/*Clear transfer complete Interrupt flag of channel1*/
}

void MDMACH2_VidSetCallBack(void (*Ptr)(void))
{
	DMACH2_CallBack=Ptr;
}

//channel 3 we call it in the main by channel 0
void DMA1_Channel3_IRQHandler(void)
{
/*here put break point then depug to see that DMA finshes transfer while processor is far away from finshing*/
	DMACH3_CallBack();
	/*Clear Interrupt flag*/
	SET_BIT(MDMA->IFCR , 8);		/*Clear Global Interrupt flag of channel1*/
	SET_BIT(MDMA->IFCR , 9);		/*Clear transfer complete Interrupt flag of channel1*/
}

void MDMACH3_VidSetCallBack(void (*Ptr)(void))
{
	DMACH3_CallBack=Ptr;
}
