 /***************************************************************/
 /* Author : ahmed elsayed                                      */
 /*version:  V01                                                */
 /*Date:                                                        */ 
 /*Describtion: SPI                                           */ 
/****************************************************************/
#ifndef _SPI_INTER_H
#define _SPI_INTER_H
 
 #define LOW 0
 #define HIGH 1
 
 /*order of sending dada*/
 /*TFT use SPI_MSB*/
 #define SPI1_LSB 0
 #define SPI1_MSB 1
 
 /*send 8 bit or 16 bit */
 #define SPI1_8BIT 0
 #define SPI1_16BIT 1
 
 /*transmit recieve mode or recieve only mode  */
 #define SPI1_TRANS_RECIIEVE 0
 #define SPI1_RECIEVE_ONLY 1

  /*hardware or software management */
 #define SPI1_HARWARE_MANAGEMENT 0
 #define SPI1_SOFTWARE_MANAGEMENT  1
 
 /*enable or disabled*/
 #define SPI1_OFF 0
 #define SPI1_ON  1
 
 /*are you master or slave*/
 #define SPI1_MASTER 0
 #define SPI1_SLAVE  1
 
 /*clk polarity*/
 #define SPI1_FIRST_RAISINGEDGE 0
 #define SPI1_FIRST_FALLINGEDGE  1
 
 /*clk phase*/
 #define SPI1_WRITE_READ 0
 #define SPI1_READ_WRITE 1
 
 void MSPI1_voidInit(void); 

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive);

void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTransmit, void (*CallBack)(u8));

#endif
