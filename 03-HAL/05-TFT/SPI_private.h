 /***************************************************************/
 /* Author : ahmed elsayed                                      */
 /*version:  V01                                                */
 /*Date:                                                        */ 
 /*Describtion: SPI                                           */ 
/****************************************************************/
#ifndef _SPI_PRIV_H
#define _SPI_PRIV_H
 
 /*SPI Registers*/
 
typedef struct{
	 volatile u32 CR1 ;
	 volatile u32 CR2 ;
	 volatile u32 SR ;
	 volatile u32 DR ;
	 volatile u32 CRCPR ;
	 volatile u32 RXCRCR ;
	 volatile u32 TXCRCR ;
	 volatile u32 I2SCFGR ;
	 volatile u32 I2SPR ;
	
 } SPI1_t;
 
 #define MSPI1 ((volatile SPI1_t *)0x40013000)
 
  
#endif
