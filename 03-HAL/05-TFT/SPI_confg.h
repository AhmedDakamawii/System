 /***************************************************************/
 /* Author : ahmed elsayed                                      */
 /*version:  V01                                                */
 /*Date:                                                        */ 
 /*Describtion: SPI                                           */ 
/****************************************************************/
#ifndef _SPI_CONFG_H
#define _SPI_CONFG_H

 
/*write it in apair port,pin
if more than one slave put more than one config*/ 
#define SPI1_SLAVE_PIN GPIOA,15 

/*CHOOSE LSB OR MSB*/
#define SPI1_ORDER  SPI1_MSB

 /*choose to send 8 bit or 16 bit*/
#define SPI1_SEND_SIZE   SPI1_8BIT

 /*transmit recieve mode or recieve only mode  */
#define SPI1_MODE  SPI1_TRANS_RECIIEVE

/*enable or disabled*/
#define SPI1_ENABLE  SPI1_ON

/*are you master or slave*/
 #define   SPI1_SELECTION   SPI1_MASTER 

 /*clk polarity first egde is raising or falling  */
 #define SPI1_POLARITY  SPI1_FIRST_FALLINGEDGE 
 
 /*clk phase write then read or read then write */
 #define SPI1_PHASE  SPI1_WRITE_READ 
 


#endif