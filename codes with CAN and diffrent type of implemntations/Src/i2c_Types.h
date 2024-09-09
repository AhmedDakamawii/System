/*********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  I2C_Types.h
 *  Module:  	  I2C
 *  Description:  Header File for I2C types
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Mohamed Yehia + Ahmed Sayed 
 *	Date:		  18/10/2023
 *********************************************************************************************************************/

#ifndef I2C_TYPES_H_
#define I2C_TYPES_H_

#include "Std_Types.h"

//#define NULL ((void*)0)

#define I2C_TOTAL_NUMBER       2


/*
 * I2C application states
 */
#define I2C_READY 			    0
#define I2C_BUSY_IN_RX 			1
#define I2C_BUSY_IN_TX 			2
#define I2C_DISABLE_SR  	    0
#define I2C_ENABLE_SR   	    1
#define I2C_SEND_DATA  	        0
#define I2C_NOT_SEND_DATA   	1


/*
 * I2C related status flags definitions
 */
#define I2C_FLAG_TXE   		( 1 << I2C_SR1_TXE)
#define I2C_FLAG_RXNE   	( 1 << I2C_SR1_RXNE)
#define I2C_FLAG_SB			( 1 << I2C_SR1_SB)
#define I2C_FLAG_OVR  		( 1 << I2C_SR1_OVR)
#define I2C_FLAG_AF   		( 1 << I2C_SR1_AF)
#define I2C_FLAG_ARLO 		( 1 << I2C_SR1_ARLO)
#define I2C_FLAG_BERR 		( 1 << I2C_SR1_BERR)
#define I2C_FLAG_STOPF 		( 1 << I2C_SR1_STOPF)
#define I2C_FLAG_ADD10 		( 1 << I2C_SR1_ADD10)
#define I2C_FLAG_BTF  		( 1 << I2C_SR1_BTF)
#define I2C_FLAG_ADDR 		( 1 << I2C_SR1_ADDR)
#define I2C_FLAG_TIMEOUT 	( 1 << I2C_SR1_TIMEOUT)

//#define I2C_DISABLE_SR  	RESET
//#define I2C_ENABLE_SR   	SET


/*
 * I2C application events macros
 */
#define I2C_EV_TX_CMPLT  	 	0
#define I2C_EV_RX_CMPLT  	 	1
#define I2C_EV_STOP       		2

#define I2C_ERROR_BERR 	 		3
#define I2C_ERROR_ARLO  		4
#define I2C_ERROR_AF    		5
#define I2C_ERROR_OVR   		6
#define I2C_ERROR_TIMEOUT 		7
#define I2C_EV_DATA_REQ         8
#define I2C_EV_DATA_RCV         9


/* I2C Number */
typedef enum
{
	I2C1,
	I2C2
}I2C_ID;

/* I2C Enable */
typedef enum
{
	I2CDISABLE,
	I2CENABLE
}I2C_EnableType;


/* I2C Interrupt Enable */
typedef enum
{
	I2CIPDISABLE,
	I2CIPENABLE
}I2C_InterruptEnable;

/*
 * @I2C_SCLSpeed
 */
typedef enum
{
  I2C_SCL_SPEED_SM 	 =   100000,
  I2C_SCL_SPEED_FM4K =	 400000,
  I2C_SCL_SPEED_FM2K =   200000
}I2C_SCLSpeed;


/*
 * @I2C_AckControl
 */
typedef enum
{       
  I2C_ACK_DISABLE,
  I2C_ACK_ENABLE       
}I2C_AckControl;


/*
 * @I2C_FMDutyCycle
 */
typedef enum
{
   I2C_FM_DUTY_2,        
   I2C_FM_DUTY_16_9     
}I2C_FMDutyCycle;

typedef enum
{
   I2C_MY_ADDRESS = 0x61,
}I2C_DeviceAddress;





/*
 *Configuration structure for I2Cx peripheral
 */

typedef struct
{
    I2C_ID                 I2Cid;
	I2C_EnableType         I2Cenabletype;
    I2C_InterruptEnable    I2Cinterruptenable;
    I2C_SCLSpeed           I2Csclspeed;
	I2C_DeviceAddress      I2Cdeviceaddress;
	I2C_AckControl         I2Cackcontrol;
	I2C_FMDutyCycle        I2Cfmdutycycle;
}I2C_Configurations;




typedef struct
{
	I2C_Configurations I2Carray[I2C_TOTAL_NUMBER];
}I2C_ConfigType;


#endif
