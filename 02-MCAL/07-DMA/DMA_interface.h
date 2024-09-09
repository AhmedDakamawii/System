 /***************************************************************/
 /* Author : ahmed elsayed                                      */
 /*version:  V01                                                */
 /*Date:                                                        */ 
 /*Describtion: DMA                                           */ 
/****************************************************************/
#ifndef _DMA_INTER_H
#define _DMA_INTER_H
/* Options For Channel Priority Level */
#define MDMA_LOW_PRI                          0
#define MDMA_MEDIUM_PRI                       1
#define MDMA_HIGH_PRI                         2
#define MDMA_VERY_HIGH_PRI                    3

/* Options For Channel Numbers */
#define MDMA_CHANNEL1                         0
#define MDMA_CHANNEL2                         1
#define MDMA_CHANNEL3                         2
#define MDMA_CHANNEL4                         3
#define MDMA_CHANNEL5                         4
#define MDMA_CHANNEL6                         5
#define MDMA_CHANNEL7                         6

/* Options For Channel Modes */
#define MDMA_MEM_TO_MEM                       0
#define MDMA_PER_TO_MEM                       1
#define MDMA_MEM_TO_PER                       2
#define MDMA_PER_TO_PER                       3

/* Options For Interrupt Source */
#define MDMA_TRANSFER_ERR                     0
#define MDMA_HALF_TRANSFER                    1
#define MDMA_COMPLETE_TRANSFER                2

/* Options For Channel Data Transfer Size */
#define MDMA_BYTE                             0
#define MDMA_HALF_WORD                        1
#define MDMA_WORD                             2

/* Options For Channel Circular Mode */
#define MDMA_CIRCULAR_DIS                     0
#define MDMA_CIRCULAR_EN                      1

/* Options For Channel ( Source or Destination ) Increment Modes */
#define MDMA_INC_DIS                          0
#define MDMA_INC_EN                           1


void MDMA_voidEnable( u8 Copy_u8ChannelNum );
void MDMA_voidDisable( u8 Copy_u8ChannelNum );
void MDMA_voidSetChannelPriority( u8 Copy_u8ChannelNum , u8 Copy_u8PriorityLevel );
void MDMA_voidSetChannelMode( u8 Copy_u8ChannelNum , u8 Copy_u8ChannelMode , u8 Copy_u8CircularState );
void MDMA_voidInterruptSource( u8 Copy_u8ChannelNum , u8 Copy_u8INTSrc );
void MDMA_voidSetDataFlow( u8 Copy_u8ChannelNum , u8 Copy_u8SrcSize , u8 Copy_u8DstSize , u8 Copy_u8SrcIncMode , u8 Copy_u8DstIncMode );
void MDMA_voidChannelStart(u8 Copy_ChannelId ,u32 *Copy_PtrAdrressSource ,u32 *Copy_PtrAdrressDest ,u16 Copy_BlockLength);
void MDMACH1_VidSetCallBack(void (*Ptr)(void));
void MDMACH2_VidSetCallBack(void (*Ptr)(void));
void MDMACH3_VidSetCallBack(void (*Ptr)(void));
void MDMA_voidClearInterruptFlags( u8 Copy_u8ChannelNum );



#endif
