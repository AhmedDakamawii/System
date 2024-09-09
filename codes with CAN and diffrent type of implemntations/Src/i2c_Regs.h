/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		    I2C_Regs.h
 *  Module:  	    I2C
 *  Description:  Header File for I2C Registers
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Ahmed Sayed & Mohamed Yehia
 *	Date:		  15/10/2023
 *********************************************************************************************************************/
#ifndef _I2C_REGS_H_
#define _I2C_REGS_H_




#define I2C_BASEADDRESS 0x40005400 


typedef struct
{
  uint32 PE: 1;                          /* Peripheral enable */
  uint32 SMBUS:  1;                      /* SMBus mode */
  uint32 reserved_0 : 1;                 /* Reserved bits */
  uint32 SMBTYPE:  1;                    /* SMBus type */
  uint32 ENARP: 1;                       /* ARP enable */
  uint32 ENPEC:  1;                      /* PEC enable */
  uint32 ENGC:  1 ;                      /* General call enable */
  uint32 NOSTRETCH:  1;                  /* Clock stretching disable (Slave mode) */
  uint32 START:  1;                      /* Start generation */
  uint32 STOP: 1;                        /* Stop generation */
  uint32 ACK:  1;                        /* Acknowledge enable */
  uint32 POS:  1;                        /* Acknowledge/PEC Position (for data reception) */
  uint32 PEC:  1;                        /* Packet error checking */
  uint32 ALERT:  1;                      /* SMBus alert */
  uint32 reserved_1 :  1;                /* Reserved bits */
  uint32 SWRST:    1;                    /* Software reset */
  uint32 reserved_2 :  16;               /* Reserved bits */
  
} I2C_CR1_BF;

typedef union
{
  uint32    Reg;
  I2C_CR1_BF BF;
} I2C_CR1_TAG;



typedef struct
{
uint32 FREQ : 6;                             /* Peripheral clock frequency */
uint32 reserved_0: 2;                         /* Reserved Bits */
uint32 ITERREN: 1;                           /* Error interrupt enable */
uint32 ITEVTEN: 1;                           /* Event interrupt enable */
uint32 ITBUFEN: 1;                           /* Buffer interrupt enable */
uint32 DMAEN: 1;                             /* DMA requests enable */
uint32 LAST: 1;                              /* DMA last transfer */
uint32 reserved_1: 19;                         /* Reserved Bits */

} I2C_CR2_BF;

typedef union
{
  uint32    Reg;
  I2C_CR2_BF BF;
} I2C_CR2_TAG;



typedef struct
{
  uint32 ADD0: 1;                      /* Interface address */
  uint32 ADD_7_1: 7;                  /* Interface address */
  uint32 ADD_9_8: 2;                   /* Interface address */
  uint32 reserved_0: 4;                  /* reserved */
  uint32 Software_High: 1;             /* Should always be kept at 1 by software */
  uint32 ADDMODE: 1;                   /* Addressing mode (slave mode) */
  uint32 reserved_1: 16;                 /* reserved */

} I2C_OAR1_BF;

typedef union
{
  uint32     Reg;
  I2C_OAR1_BF BF;
} I2C_OAR1_TAG;


typedef struct
{
  uint32 ENDUAL:     1;                       /* Dual addressing mode enable */
  uint32 ADD2_7_1:  7;                       /* Interface address */
  uint32 reserved: 24;                      /* reserved */
  
} I2C_OAR2_BF;

typedef union
{
  uint32     Reg;
  I2C_OAR2_BF BF;
} I2C_OAR2_TAG;


typedef struct
{
  uint32 DR: 8;                       /* 8-bit data register */
  uint32 reserved: 24;                    /* Reserved bits */

} I2C_DR_BF;


typedef union
{
  uint32   Reg;
  I2C_DR_BF BF;
} I2C_DR_TAG;



typedef struct
{
  uint32 SB:    1;                           /* Start bit (Master mode) */
  uint32 ADDR:  1;                          /* Address sent (master mode)/matched (slave mode) */
  uint32 BTF:  1;                          /* Byte transfer finished */
  uint32 ADD10:  1;                         /* 10-bit header sent (Master mode) */
  uint32 STOPF: 1;                          /* Stop detection (slave mode) */
  uint32 reserved_0: 1;                          /* reserved bits */
  uint32 RxNE:  1;                          /* Data register not empty (receivers) */
  uint32 TxE:  1;                          /* Data register empty (transmitters) */
  uint32 BERR:  1;                          /* Bus error */
  uint32 ARLO:  1;                          /* Arbitration lost (master mode) */
  uint32 AF:  1;                         /* Acknowledge failure */ 
  uint32 OVR:  1;                         /* Overrun/Underrun */  
  uint32 PECERR:     1;                         /* PEC Error in reception */  
  uint32 reserved_1: 1;                         /* reserved bits */  
  uint32 TIMEOUT:    1;                         /* Timeout or Tlow error */  
  uint32 SMBALERT:  1;                         /* SMBus alert */  
  uint32 reserved_2: 16;                     /* reserved bits */
} I2C_SR1_BF;


typedef union
{
  uint32 Reg;
  I2C_SR1_BF BF;
} I2C_SR1_TAG;



typedef struct
{
  uint32 MSL:   1;                          /* Master/slave */
  uint32 BUSY:   1;                         /* Bus busy */
  uint32 TRA: 1;                           /* Transmitter/receiver */
  uint32 reserved_0: 1;                    /* reserved */
  uint32 GENCALL:  1;                      /* General call address (Slave mode) */
  uint32 SMBDEFAULT: 1;                   /* SMBus device default address (Slave mode) */
  uint32 SMBHOST: 1;                       /* SMBus host header (Slave mode) */
  uint32 DUALF: 1;                        /* Dual flag (Slave mode) */
  uint32 PEC: 8;                           /* error checking register */
  uint32 reserved_1: 16;                    /* reserved bits */
} I2C_SR2_BF;


typedef union
{
  uint32    Reg;
  I2C_SR2_BF BF;
} I2C_SR2_TAG;



typedef struct
{
  uint32 CCR:   12;                         /* Clock control register in Fm/Sm mode (Master mode)e */
  uint32 reserved_0:   2;                   /* reserved bits */
  uint32 DUTY: 1;                           /* Fm mode duty cycle */
  uint32 F_S: 1;                            /* I2C master mode selection */
  uint32 reserved_1: 16;                   /* reserved bits */
} I2C_CCR_BF;


typedef union
{
  uint32    Reg;
  I2C_CCR_BF BF;
} I2C_CCR_TAG;



typedef struct
{
  uint32 TRISE:   6;                      /* Maximum rise time in Fm/Sm mode (Master mode) */
  uint32 reserved : 26;                   /* reserved bits */
} I2C_TRISE_BF;


typedef union
{
  uint32      Reg;
  I2C_TRISE_BF BF;
} I2C_TRISE_TAG;


typedef struct
{
  I2C_CR1_TAG     CR1;       /* I2C Control register 1 */
  I2C_CR2_TAG     CR2 ;      /* I2C Control register 2 */
  I2C_OAR1_TAG    OAR1 ;     /* I2C Own address register 1 */
  I2C_OAR2_TAG    OAR2 ;     /* I2C Own address register 2 */
  I2C_DR_TAG      DR   ;     /* I2C Data register */
  I2C_SR1_TAG     SR1  ;     /* I2C Status register 1 */
  I2C_SR2_TAG     SR2  ;     /* I2C Status register 2 */
  I2C_CCR_TAG     CCR  ;     /* I2C Clock control register */
  I2C_TRISE_TAG   TRISE ;    /* I2C TRISE register */

} I2C;


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define MI2C1 ((volatile I2C *)0x40005400)
#define MI2C2 ((volatile I2C *)0x40005800)


#endif
