 /***************************************************************/
 /* Author : ahmed elsayed                                      */
 /*version:  V01                                                */
 /*Date:                                                        */ 
 /*Describtion: DMA                                           */ 
/****************************************************************/
#ifndef _DMA_PRIV_H
#define _DMA_PRIV_H
 
 /*DMA Registers*/
 /*he put this in this shape because the 6 registers  in channel 0 will be next to each other in address
 then the 6 registers  in channel 1 and so on*/

	typedef struct{
	u32 CCR                ;
	u32 CNDTR              ;
	u32 CPAR               ;
	u32 CMAR               ;
	u32 RESERVED           ;
}DMA_Channel;

typedef struct{
	u32 ISR                ;
	u32 IFCR               ;
	DMA_Channel CHANNEL[7] ;
}DMA_t;

#define MDMA              ((volatile DMA_t *)0x40020000)




#define MDMA_EN           0
#define MDMA_TCIE         1
#define MDMA_HTIE         2
#define MDMA_TEIE         3
#define MDMA_DIR          4
#define MDMA_CIRC         5
#define MDMA_PINC         6
#define MDMA_MINC         7
#define MDMA_PSIZE0       8
#define MDMA_PSIZE1       9
#define MDMA_MSIZE0       10
#define MDMA_MSIZE1       11
#define MDMA_PL0          12
#define MDMA_PL1          13
#define MDMA_MEM2MEM      14



#define MDMA_CGIF         0
#define MDMA_CTCIF        1
#define MDMA_CHTIF        2
#define MDMA_CTEIF        3



 

 
 
  
#endif
