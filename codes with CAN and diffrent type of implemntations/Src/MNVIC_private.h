 /******************************************************************************
 *
 * Module: NVIC
 *
 * Module ID: N/A
 *
 * File Name: MNVIC_private.h
 *
 * Description: NVIC Driver
 *
 * Author: Ahmed Sayed
 ******************************************************************************/

#ifndef MNVIC_PRIVATE_H
#define MNVIC_PRIVATE_H
 #include "Std_Types.h"
 #include "Platform_Types.h"

#define MNVIC_MODULE_ID			  0x50
#define ERROR_INVALID_ID		  0x20

#define API_ENABLE				  1
#define API_DISABLE				  0

#define DET_ENABLE				  1
#define DET_DISABLE				  0

#define REG_SIZE				  32
#define BYTE_SIZE				  8
#define HALF_BYTE_SIZE			  4
#define ARRAY_SIZE				  3
#define SYSRESETREQ				  2



#define MNVIC_BASE_ADDRESS		  0xE000E100
#define SCB_AIRCR_ADDRESS  		  0xE000ED0C

/*Priority Group Selections*/
#define SIXTEEN_GROUPS_ZERO_SUB  	 	0x05FA0300
#define EIGHT_GROUPS_TWO_SUB  	  		0x05FA0400
#define FOUR_GROUPS_FOUR_SUB  	  		0x05FA0500
#define TWO_GROUPS_EIGHT_SUB  	  		0x05FA0600
#define ZERO_GROUPS_SIXTEEN_SUB  	  	0x05FA0700

#define MNVIC  			((volatile MNVIC_t *)MNVIC_BASE_ADDRESS)
#define MNVIC_STIR 		*( ( volatile uint32  *)0xE000EF00 )
#define SCB_AIRCR 		*( ( volatile uint32  *)SCB_AIRCR_ADDRESS)

/**************************************************************************
*                       Registers_bit_field                               *
***************************************************************************/
typedef struct 
{

    uint32 SET_ENABLE0_BIN0  : 1 ;
	uint32 SET_ENABLE0_BIN1  : 1 ;
	uint32 SET_ENABLE0_BIN2  : 1 ;
	uint32 SET_ENABLE0_BIN3  : 1 ;
	uint32 SET_ENABLE0_BIN4  : 1 ;
	uint32 SET_ENABLE0_BIN5  : 1 ;
	uint32 SET_ENABLE0_BIN6  : 1 ;
	uint32 SET_ENABLE0_BIN7  : 1 ;
	uint32 SET_ENABLE0_BIN8  : 1 ;
	uint32 SET_ENABLE0_BIN9  : 1 ;
	uint32 SET_ENABLE0_BIN10  : 1 ;
	uint32 SET_ENABLE0_BIN11  : 1 ;
	uint32 SET_ENABLE0_BIN12  : 1 ;
	uint32 SET_ENABLE0_BIN13  : 1 ;
	uint32 SET_ENABLE0_BIN14  : 1 ;
	uint32 SET_ENABLE0_BIN15  : 1 ;
	uint32 SET_ENABLE0_BIN16  : 1 ;
	uint32 SET_ENABLE0_BIN17  : 1 ;
	uint32 SET_ENABLE0_BIN18  : 1 ;
	uint32 SET_ENABLE0_BIN19  : 1 ;
	uint32 SET_ENABLE0_BIN20  : 1 ;
	uint32 SET_ENABLE0_BIN21  : 1 ;
	uint32 SET_ENABLE0_BIN22  : 1 ;
	uint32 SET_ENABLE0_BIN23  : 1 ;
	uint32 SET_ENABLE0_BIN24  : 1 ;
	uint32 SET_ENABLE0_BIN25  : 1 ;
	uint32 SET_ENABLE0_BIN26  : 1 ;
	uint32 SET_ENABLE0_BIN27  : 1 ;
	uint32 SET_ENABLE0_BIN28  : 1 ;
	uint32 SET_ENABLE0_BIN29  : 1 ;
	uint32 SET_ENABLE0_BIN30  : 1 ;
	uint32 SET_ENABLE0_BIN31  : 1 ;	
}NVIC_ISER0_BF;

typedef struct 
{

    uint32 SET_ENABLE1_BIN0  : 1 ;
	uint32 SET_ENABLE1_BIN1  : 1 ;
	uint32 SET_ENABLE1_BIN2  : 1 ;
	uint32 SET_ENABLE1_BIN3  : 1 ;
	uint32 SET_ENABLE1_BIN4  : 1 ;
	uint32 SET_ENABLE1_BIN5  : 1 ;
	uint32 SET_ENABLE1_BIN6  : 1 ;
	uint32 SET_ENABLE1_BIN7  : 1 ;
	uint32 SET_ENABLE1_BIN8  : 1 ;
	uint32 SET_ENABLE1_BIN9  : 1 ;
	uint32 SET_ENABLE1_BIN10  : 1 ;
	uint32 SET_ENABLE1_BIN11  : 1 ;
	uint32 SET_ENABLE1_BIN12  : 1 ;
	uint32 SET_ENABLE1_BIN13  : 1 ;
	uint32 SET_ENABLE1_BIN14  : 1 ;
	uint32 SET_ENABLE1_BIN15  : 1 ;
	uint32 SET_ENABLE1_BIN16  : 1 ;
	uint32 SET_ENABLE1_BIN17  : 1 ;
	uint32 SET_ENABLE1_BIN18  : 1 ;
	uint32 SET_ENABLE1_BIN19  : 1 ;
	uint32 SET_ENABLE1_BIN20  : 1 ;
	uint32 SET_ENABLE1_BIN21  : 1 ;
	uint32 SET_ENABLE1_BIN22  : 1 ;
	uint32 SET_ENABLE1_BIN23  : 1 ;
	uint32 SET_ENABLE1_BIN24  : 1 ;
	uint32 SET_ENABLE1_BIN25  : 1 ;
	uint32 SET_ENABLE1_BIN26  : 1 ;
	uint32 SET_ENABLE1_BIN27  : 1 ;
	uint32 SET_ENABLE1_BIN28  : 1 ;
	uint32 SET_ENABLE1_BIN29  : 1 ;
	uint32 SET_ENABLE1_BIN30  : 1 ;
	uint32 SET_ENABLE1_BIN31  : 1 ;		
}NVIC_ISER1_BF;

typedef struct 
{
    uint32 SET_ENABLE2_BIN0  : 1 ;
	uint32 SET_ENABLE2_BIN1  : 1 ;
	uint32 SET_ENABLE2_BIN2  : 1 ;
	uint32 SET_ENABLE2_BIN3  : 1 ;
	uint32 SET_ENABLE2_BIN4  : 1 ;
	uint32 SET_ENABLE2_BIN5  : 1 ;
	uint32 SET_ENABLE2_BIN6  : 1 ;
	uint32 SET_ENABLE2_BIN7  : 1 ;
	uint32 SET_ENABLE2_BIN8  : 1 ;
	uint32 SET_ENABLE2_BIN9  : 1 ;
	uint32 SET_ENABLE2_BIN10  : 1 ;
	uint32 SET_ENABLE2_BIN11  : 1 ;
	uint32 SET_ENABLE2_BIN12  : 1 ;
	uint32 SET_ENABLE2_BIN13  : 1 ;
	uint32 SET_ENABLE2_BIN14  : 1 ;
	uint32 SET_ENABLE2_BIN15  : 1 ;
	uint32 RESERVED1 : 16  ;
	
}NVIC_ISER2_BF;

typedef struct 
{

    uint32 CLEAR_ENABLE0_BIN0  : 1 ;
	uint32 CLEAR_ENABLE0_BIN1  : 1 ;
	uint32 CLEAR_ENABLE0_BIN2  : 1 ;
	uint32 CLEAR_ENABLE0_BIN3  : 1 ;
	uint32 CLEAR_ENABLE0_BIN4  : 1 ;
	uint32 CLEAR_ENABLE0_BIN5  : 1 ;
	uint32 CLEAR_ENABLE0_BIN6  : 1 ;
	uint32 CLEAR_ENABLE0_BIN7  : 1 ;
	uint32 CLEAR_ENABLE0_BIN8  : 1 ;
	uint32 CLEAR_ENABLE0_BIN9  : 1 ;
	uint32 CLEAR_ENABLE0_BIN10  : 1 ;
	uint32 CLEAR_ENABLE0_BIN11  : 1 ;
	uint32 CLEAR_ENABLE0_BIN12  : 1 ;
	uint32 CLEAR_ENABLE0_BIN13  : 1 ;
	uint32 CLEAR_ENABLE0_BIN14  : 1 ;
	uint32 CLEAR_ENABLE0_BIN15  : 1 ;
	uint32 CLEAR_ENABLE0_BIN16  : 1 ;
	uint32 CLEAR_ENABLE0_BIN17  : 1 ;
	uint32 CLEAR_ENABLE0_BIN18  : 1 ;
	uint32 CLEAR_ENABLE0_BIN19  : 1 ;
	uint32 CLEAR_ENABLE0_BIN20  : 1 ;
	uint32 CLEAR_ENABLE0_BIN21  : 1 ;
	uint32 CLEAR_ENABLE0_BIN22  : 1 ;
	uint32 CLEAR_ENABLE0_BIN23  : 1 ;
	uint32 CLEAR_ENABLE0_BIN24  : 1 ;
	uint32 CLEAR_ENABLE0_BIN25  : 1 ;
	uint32 CLEAR_ENABLE0_BIN26  : 1 ;
	uint32 CLEAR_ENABLE0_BIN27  : 1 ;
	uint32 CLEAR_ENABLE0_BIN28  : 1 ;
	uint32 CLEAR_ENABLE0_BIN29  : 1 ;
	uint32 CLEAR_ENABLE0_BIN30  : 1 ;
	uint32 CLEAR_ENABLE0_BIN31  : 1 ;	
	
}NVIC_ICER0_BF;

typedef struct 
{

    uint32 CLEAR_ENABLE1_BIN0  : 1 ;
	uint32 CLEAR_ENABLE1_BIN1  : 1 ;
	uint32 CLEAR_ENABLE1_BIN2  : 1 ;
	uint32 CLEAR_ENABLE1_BIN3  : 1 ;
	uint32 CLEAR_ENABLE1_BIN4  : 1 ;
	uint32 CLEAR_ENABLE1_BIN5  : 1 ;
	uint32 CLEAR_ENABLE1_BIN6  : 1 ;
	uint32 CLEAR_ENABLE1_BIN7  : 1 ;
	uint32 CLEAR_ENABLE1_BIN8  : 1 ;
	uint32 CLEAR_ENABLE1_BIN9  : 1 ;
	uint32 CLEAR_ENABLE1_BIN10  : 1 ;
	uint32 CLEAR_ENABLE1_BIN11  : 1 ;
	uint32 CLEAR_ENABLE1_BIN12  : 1 ;
	uint32 CLEAR_ENABLE1_BIN13  : 1 ;
	uint32 CLEAR_ENABLE1_BIN14  : 1 ;
	uint32 CLEAR_ENABLE1_BIN15  : 1 ;
	uint32 CLEAR_ENABLE1_BIN16  : 1 ;
	uint32 CLEAR_ENABLE1_BIN17  : 1 ;
	uint32 CLEAR_ENABLE1_BIN18  : 1 ;
	uint32 CLEAR_ENABLE1_BIN19  : 1 ;
	uint32 CLEAR_ENABLE1_BIN20  : 1 ;
	uint32 CLEAR_ENABLE1_BIN21  : 1 ;
	uint32 CLEAR_ENABLE1_BIN22  : 1 ;
	uint32 CLEAR_ENABLE1_BIN23  : 1 ;
	uint32 CLEAR_ENABLE1_BIN24  : 1 ;
	uint32 CLEAR_ENABLE1_BIN25  : 1 ;
	uint32 CLEAR_ENABLE1_BIN26  : 1 ;
	uint32 CLEAR_ENABLE1_BIN27  : 1 ;
	uint32 CLEAR_ENABLE1_BIN28  : 1 ;
	uint32 CLEAR_ENABLE1_BIN29  : 1 ;
	uint32 CLEAR_ENABLE1_BIN30  : 1 ;
	uint32 CLEAR_ENABLE1_BIN31  : 1 ;	
		
}NVIC_ICER1_BF;

typedef struct 
{

 
    uint32 CLEAR_ENABLE2_BIN0  : 1 ;
	uint32 CLEAR_ENABLE2_BIN1  : 1 ;
	uint32 CLEAR_ENABLE2_BIN2  : 1 ;
	uint32 CLEAR_ENABLE2_BIN3  : 1 ;
	uint32 CLEAR_ENABLE2_BIN4  : 1 ;
	uint32 CLEAR_ENABLE2_BIN5  : 1 ;
	uint32 CLEAR_ENABLE2_BIN6  : 1 ;
	uint32 CLEAR_ENABLE2_BIN7  : 1 ;
	uint32 CLEAR_ENABLE2_BIN8  : 1 ;
	uint32 CLEAR_ENABLE2_BIN9  : 1 ;
	uint32 CLEAR_ENABLE2_BIN10  : 1 ;
	uint32 CLEAR_ENABLE2_BIN11  : 1 ;
	uint32 CLEAR_ENABLE2_BIN12  : 1 ;
	uint32 CLEAR_ENABLE2_BIN13  : 1 ;
	uint32 CLEAR_ENABLE2_BIN14  : 1 ;
	uint32 CLEAR_ENABLE2_BIN15  : 1 ;
	uint32 RESERVED2  : 16 ;
}NVIC_ICER2_BF;

typedef struct 
{
    uint32 SET_PENDING0_BIN0  : 1 ;
	uint32 SET_PENDING0_BIN1  : 1 ;
	uint32 SET_PENDING0_BIN2  : 1 ;
	uint32 SET_PENDING0_BIN3  : 1 ;
	uint32 SET_PENDING0_BIN4  : 1 ;
	uint32 SET_PENDING0_BIN5  : 1 ;
	uint32 SET_PENDING0_BIN6  : 1 ;
	uint32 SET_PENDING0_BIN7  : 1 ;
	uint32 SET_PENDING0_BIN8  : 1 ;
	uint32 SET_PENDING0_BIN9  : 1 ;
	uint32 SET_PENDING0_BIN10  : 1 ;
	uint32 SET_PENDING0_BIN11  : 1 ;
	uint32 SET_PENDING0_BIN12  : 1 ;
	uint32 SET_PENDING0_BIN13  : 1 ;
	uint32 SET_PENDING0_BIN14  : 1 ;
	uint32 SET_PENDING0_BIN15  : 1 ;
	uint32 SET_PENDING0_BIN16  : 1 ;
	uint32 SET_PENDING0_BIN17  : 1 ;
	uint32 SET_PENDING0_BIN18  : 1 ;
	uint32 SET_PENDING0_BIN19  : 1 ;
	uint32 SET_PENDING0_BIN20  : 1 ;
	uint32 SET_PENDING0_BIN21  : 1 ;
	uint32 SET_PENDING0_BIN22  : 1 ;
	uint32 SET_PENDING0_BIN23  : 1 ;
	uint32 SET_PENDING0_BIN24  : 1 ;
	uint32 SET_PENDING0_BIN25  : 1 ;
	uint32 SET_PENDING0_BIN26  : 1 ;
	uint32 SET_PENDING0_BIN27  : 1 ;
	uint32 SET_PENDING0_BIN28  : 1 ;
	uint32 SET_PENDING0_BIN29  : 1 ;
	uint32 SET_PENDING0_BIN30  : 1 ;
	uint32 SET_PENDING0_BIN31  : 1 ;		
}NVIC_ISPR0_BF;

typedef struct 
{

    uint32 SET_PENDING1_BIN0  : 1 ;
	uint32 SET_PENDING1_BIN1  : 1 ;
	uint32 SET_PENDING1_BIN2  : 1 ;
	uint32 SET_PENDING1_BIN3  : 1 ;
	uint32 SET_PENDING1_BIN4  : 1 ;
	uint32 SET_PENDING1_BIN5  : 1 ;
	uint32 SET_PENDING1_BIN6  : 1 ;
	uint32 SET_PENDING1_BIN7  : 1 ;
	uint32 SET_PENDING1_BIN8  : 1 ;
	uint32 SET_PENDING1_BIN9  : 1 ;
	uint32 SET_PENDING1_BIN10  : 1 ;
	uint32 SET_PENDING1_BIN11  : 1 ;
	uint32 SET_PENDING1_BIN12  : 1 ;
	uint32 SET_PENDING1_BIN13  : 1 ;
	uint32 SET_PENDING1_BIN14  : 1 ;
	uint32 SET_PENDING1_BIN15  : 1 ;
	uint32 SET_PENDING1_BIN16  : 1 ;
	uint32 SET_PENDING1_BIN17  : 1 ;
	uint32 SET_PENDING1_BIN18  : 1 ;
	uint32 SET_PENDING1_BIN19  : 1 ;
	uint32 SET_PENDING1_BIN20  : 1 ;
	uint32 SET_PENDING1_BIN21  : 1 ;
	uint32 SET_PENDING1_BIN22  : 1 ;
	uint32 SET_PENDING1_BIN23  : 1 ;
	uint32 SET_PENDING1_BIN24  : 1 ;
	uint32 SET_PENDING1_BIN25  : 1 ;
	uint32 SET_PENDING1_BIN26  : 1 ;
	uint32 SET_PENDING1_BIN27  : 1 ;
	uint32 SET_PENDING1_BIN28  : 1 ;
	uint32 SET_PENDING1_BIN29  : 1 ;
	uint32 SET_PENDING1_BIN30  : 1 ;
	uint32 SET_PENDING1_BIN31  : 1 ;		
}NVIC_ISPR1_BF;

typedef struct 
{
    uint32 SET_PENDING2_BIN0  : 1 ;
	uint32 SET_PENDING2_BIN1  : 1 ;
	uint32 SET_PENDING2_BIN2  : 1 ;
	uint32 SET_PENDING2_BIN3  : 1 ;
	uint32 SET_PENDING2_BIN4  : 1 ;
	uint32 SET_PENDING2_BIN5  : 1 ;
	uint32 SET_PENDING2_BIN6  : 1 ;
	uint32 SET_PENDING2_BIN7  : 1 ;
	uint32 SET_PENDING2_BIN8  : 1 ;
	uint32 SET_PENDING2_BIN9  : 1 ;
	uint32 SET_PENDING2_BIN10  : 1 ;
	uint32 SET_PENDING2_BIN11  : 1 ;
	uint32 SET_PENDING2_BIN12  : 1 ;
	uint32 SET_PENDING2_BIN13  : 1 ;
	uint32 SET_PENDING2_BIN14  : 1 ;
	uint32 SET_PENDING2_BIN15  : 1 ;
	uint32 RESERVED3  : 16 ;
}NVIC_ISPR2_BF;

typedef struct 
{

    uint32 CLEAR_PENDING0_BIN0  : 1 ;
	uint32 CLEAR_PENDING0_BIN1  : 1 ;
	uint32 CLEAR_PENDING0_BIN2  : 1 ;
	uint32 CLEAR_PENDING0_BIN3  : 1 ;
	uint32 CLEAR_PENDING0_BIN4  : 1 ;
	uint32 CLEAR_PENDING0_BIN5  : 1 ;
	uint32 CLEAR_PENDING0_BIN6  : 1 ;
	uint32 CLEAR_PENDING0_BIN7  : 1 ;
	uint32 CLEAR_PENDING0_BIN8  : 1 ;
	uint32 CLEAR_PENDING0_BIN9  : 1 ;
	uint32 CLEAR_PENDING0_BIN10  : 1 ;
	uint32 CLEAR_PENDING0_BIN11  : 1 ;
	uint32 CLEAR_PENDING0_BIN12  : 1 ;
	uint32 CLEAR_PENDING0_BIN13  : 1 ;
	uint32 CLEAR_PENDING0_BIN14  : 1 ;
	uint32 CLEAR_PENDING0_BIN15  : 1 ;
	uint32 CLEAR_PENDING0_BIN16  : 1 ;
	uint32 CLEAR_PENDING0_BIN17  : 1 ;
	uint32 CLEAR_PENDING0_BIN18  : 1 ;
	uint32 CLEAR_PENDING0_BIN19  : 1 ;
	uint32 CLEAR_PENDING0_BIN20  : 1 ;
	uint32 CLEAR_PENDING0_BIN21  : 1 ;
	uint32 CLEAR_PENDING0_BIN22  : 1 ;
	uint32 CLEAR_PENDING0_BIN23  : 1 ;
	uint32 CLEAR_PENDING0_BIN24  : 1 ;
	uint32 CLEAR_PENDING0_BIN25  : 1 ;
	uint32 CLEAR_PENDING0_BIN26  : 1 ;
	uint32 CLEAR_PENDING0_BIN27  : 1 ;
	uint32 CLEAR_PENDING0_BIN28  : 1 ;
	uint32 CLEAR_PENDING0_BIN29  : 1 ;
	uint32 CLEAR_PENDING0_BIN30  : 1 ;
	uint32 CLEAR_PENDING0_BIN31  : 1 ;		    	
}NVIC_ICPR0_BF;

typedef struct 
{

    uint32 CLEAR_PENDING1_BIN0  : 1 ;
	uint32 CLEAR_PENDING1_BIN1  : 1 ;
	uint32 CLEAR_PENDING1_BIN2  : 1 ;
	uint32 CLEAR_PENDING1_BIN3  : 1 ;
	uint32 CLEAR_PENDING1_BIN4  : 1 ;
	uint32 CLEAR_PENDING1_BIN5  : 1 ;
	uint32 CLEAR_PENDING1_BIN6  : 1 ;
	uint32 CLEAR_PENDING1_BIN7  : 1 ;
	uint32 CLEAR_PENDING1_BIN8  : 1 ;
	uint32 CLEAR_PENDING1_BIN9  : 1 ;
	uint32 CLEAR_PENDING1_BIN10  : 1 ;
	uint32 CLEAR_PENDING1_BIN11  : 1 ;
	uint32 CLEAR_PENDING1_BIN12  : 1 ;
	uint32 CLEAR_PENDING1_BIN13  : 1 ;
	uint32 CLEAR_PENDING1_BIN14  : 1 ;
	uint32 CLEAR_PENDING1_BIN15  : 1 ;
	uint32 CLEAR_PENDING1_BIN16  : 1 ;
	uint32 CLEAR_PENDING1_BIN17  : 1 ;
	uint32 CLEAR_PENDING1_BIN18  : 1 ;
	uint32 CLEAR_PENDING1_BIN19  : 1 ;
	uint32 CLEAR_PENDING1_BIN20  : 1 ;
	uint32 CLEAR_PENDING1_BIN21  : 1 ;
	uint32 CLEAR_PENDING1_BIN22  : 1 ;
	uint32 CLEAR_PENDING1_BIN23  : 1 ;
	uint32 CLEAR_PENDING1_BIN24  : 1 ;
	uint32 CLEAR_PENDING1_BIN25  : 1 ;
	uint32 CLEAR_PENDING1_BIN26  : 1 ;
	uint32 CLEAR_PENDING1_BIN27  : 1 ;
	uint32 CLEAR_PENDING1_BIN28  : 1 ;
	uint32 CLEAR_PENDING1_BIN29  : 1 ;
	uint32 CLEAR_PENDING1_BIN30  : 1 ;
	uint32 CLEAR_PENDING1_BIN31  : 1 ;		
}NVIC_ICPR1_BF;

typedef struct 
{

  
    uint32 CLEAR_PENDING2_BIN0  : 1 ;
	uint32 CLEAR_PENDING2_BIN1  : 1 ;
	uint32 CLEAR_PENDING2_BIN2  : 1 ;
	uint32 CLEAR_PENDING2_BIN3  : 1 ;
	uint32 CLEAR_PENDING2_BIN4  : 1 ;
	uint32 CLEAR_PENDING2_BIN5  : 1 ;
	uint32 CLEAR_PENDING2_BIN6  : 1 ;
	uint32 CLEAR_PENDING2_BIN7  : 1 ;
	uint32 CLEAR_PENDING2_BIN8  : 1 ;
	uint32 CLEAR_PENDING2_BIN9  : 1 ;
	uint32 CLEAR_PENDING2_BIN10  : 1 ;
	uint32 CLEAR_PENDING2_BIN11  : 1 ;
	uint32 CLEAR_PENDING2_BIN12  : 1 ;
	uint32 CLEAR_PENDING2_BIN13  : 1 ;
	uint32 CLEAR_PENDING2_BIN14  : 1 ;
	uint32 CLEAR_PENDING2_BIN15  : 1 ;
	uint32 RESERVED4  : 16 ;

}NVIC_ICPR2_BF;

typedef struct 
{
    uint32 ACTIVE_FLAGES0_BIN0  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN1  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN2  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN3  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN4  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN5  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN6  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN7  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN8  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN9  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN10  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN11  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN12  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN13  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN14  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN15  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN16  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN17  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN18  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN19  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN20  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN21  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN22  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN23  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN24  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN25  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN26  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN27  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN28  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN29  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN30  : 1 ;
	uint32 ACTIVE_FLAGES0_BIN31  : 1 ;			
}NVIC_IABR0_BF;

typedef struct 
{

    uint32 ACTIVE_FLAGES1_BIN0  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN1  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN2  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN3  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN4  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN5  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN6  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN7  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN8  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN9  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN10  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN11  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN12  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN13  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN14  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN15  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN16  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN17  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN18  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN19  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN20  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN21  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN22  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN23  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN24  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN25  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN26  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN27  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN28  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN29  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN30  : 1 ;
	uint32 ACTIVE_FLAGES1_BIN31  : 1 ;			
}NVIC_IABR1_BF;

typedef struct 
{

    uint32 ACTIVE_FLAGES2_BIN0  : 1 ;
	uint32 ACTIVE_FLAGES2_BIN1  : 1 ;
	uint32 ACTIVE_FLAGES2_BIN2  : 1 ;
	uint32 ACTIVE_FLAGES2_BIN3  : 1 ;
	uint32 ACTIVE_FLAGES2_BIN4  : 1 ;
	uint32 ACTIVE_FLAGES2_BIN5  : 1 ;
	uint32 ACTIVE_FLAGES2_BIN6  : 1 ;
	uint32 ACTIVE_FLAGES2_BIN7  : 1 ;
	uint32 ACTIVE_FLAGES2_BIN8  : 1 ;
	uint32 ACTIVE_FLAGES2_BIN9  : 1 ;
	uint32 ACTIVE_FLAGES2_BIN10  : 1 ;
	uint32 ACTIVE_FLAGES2_BIN11  : 1 ;
	uint32 ACTIVE_FLAGES2_BIN12  : 1 ;
	uint32 ACTIVE_FLAGES2_BIN13  : 1 ;
	uint32 ACTIVE_FLAGES2_BIN14  : 1 ;
	uint32 ACTIVE_FLAGES2_BIN15  : 1 ;
	uint32 RESERVED5  : 16 ;

}NVIC_IABR2_BF;

typedef struct 
{

    uint32 IP0_0   : 8 ;
	uint32 IP0_1   : 8 ;
	uint32 IP0_2   : 8 ;
    uint32 IP0_3   : 8 ;

}NVIC_IPR0_BF;

typedef struct 
{
    uint32 IP1_0   : 8 ;
	uint32 IP1_1   : 8 ;
	uint32 IP1_2   : 8 ;
    uint32 IP1_3   : 8 ;
}NVIC_IPR1_BF;

typedef struct 
{
    uint32 IP2_0   : 8 ;
	uint32 IP2_1   : 8 ;
	uint32 IP2_2   : 8 ;
    uint32 IP2_3   : 8 ;

}NVIC_IPR2_BF;

typedef struct 
{
    uint32 IP3_0   : 8 ;
	uint32 IP3_1   : 8 ;
	uint32 IP3_2   : 8 ;
    uint32 IP3_3   : 8 ;

}NVIC_IPR3_BF;

typedef struct 
{
    uint32 IP4_0   : 8 ;
	uint32 IP4_1   : 8 ;
	uint32 IP4_2   : 8 ;
    uint32 IP4_3   : 8 ;
}NVIC_IPR4_BF;

typedef struct 
{
    uint32 IP5_0   : 8 ;
	uint32 IP5_1   : 8 ;
	uint32 IP5_2   : 8 ;
    uint32 IP5_3   : 8 ;
}NVIC_IPR5_BF;

typedef struct 
{
    uint32 IP6_0   : 8 ;
	uint32 IP6_1   : 8 ;
	uint32 IP6_2   : 8 ;
    uint32 IP6_3   : 8 ;
}NVIC_IPR6_BF;

typedef struct 
{
    uint32 IP7_0   : 8 ;
	uint32 IP7_1   : 8 ;
	uint32 IP7_2   : 8 ;
    uint32 IP7_3   : 8 ;
}NVIC_IPR7_BF;

typedef struct 
{
    uint32 IP8_0   : 8 ;
	uint32 IP8_1   : 8 ;
	uint32 IP8_2   : 8 ;
    uint32 IP8_3   : 8 ;
}NVIC_IPR8_BF;

typedef struct 
{
    uint32 IP9_0   : 8 ;
	uint32 IP9_1   : 8 ;
	uint32 IP9_2   : 8 ;
    uint32 IP9_3   : 8 ;
}NVIC_IPR9_BF;

typedef struct 
{
    uint32 IP10_0   : 8 ;
	uint32 IP10_1   : 8 ;
	uint32 IP10_2   : 8 ;
    uint32 IP10_3   : 8 ;
}NVIC_IPR10_BF;

typedef struct 
{
    uint32 IP11_0   : 8 ;
	uint32 IP11_1   : 8 ;
	uint32 IP11_2   : 8 ;
    uint32 IP11_3   : 8 ;
}NVIC_IPR11_BF;

typedef struct 
{
    uint32 IP12_0   : 8 ;
	uint32 IP12_1   : 8 ;
	uint32 IP12_2   : 8 ;
    uint32 IP12_3   : 8 ;
}NVIC_IPR12_BF;

typedef struct 
{
    uint32 IP13_0   : 8 ;
	uint32 IP13_1   : 8 ;
	uint32 IP13_2   : 8 ;
    uint32 IP13_3   : 8 ;
}NVIC_IPR13_BF;

typedef struct 
{
    uint32 IP14_0   : 8 ;
	uint32 IP14_1   : 8 ;
	uint32 IP14_2   : 8 ;
    uint32 IP14_3   : 8 ;
}NVIC_IPR14_BF;

typedef struct 
{
    uint32 IP15_0   : 8 ;
	uint32 IP15_1   : 8 ;
	uint32 IP15_2   : 8 ;
    uint32 IP15_3   : 8 ;
}NVIC_IPR15_BF;

typedef struct 
{
    uint32 IP16_0   : 8 ;
	uint32 IP16_1   : 8 ;
	uint32 IP16_2   : 8 ;
    uint32 IP16_3   : 8 ;
}NVIC_IPR16_BF;

typedef struct 
{
    uint32 IP17_0   : 8 ;
	uint32 IP17_1   : 8 ;
	uint32 IP17_2   : 8 ;
    uint32 IP17_3   : 8 ;
}NVIC_IPR17_BF;

typedef struct 
{
    uint32 IP18_0   : 8 ;
	uint32 IP18_1   : 8 ;
	uint32 IP18_2   : 8 ;
    uint32 IP18_3   : 8 ;
}NVIC_IPR18_BF;

typedef struct 
{
    uint32 IP19_0   : 8 ;
	uint32 IP19_1   : 8 ;
	uint32 IP19_2   : 8 ;
    uint32 IP19_3   : 8 ;
}NVIC_IPR19_BF;

typedef struct 
{

    uint32 IP20   : 8 ;
	uint32 RESERVED5  : 24 ;

}NVIC_IPR20_BF;


/**************************************************************************
*                       Registers_Unions                                  *
***************************************************************************/
typedef union
{
    NVIC_ISER0_BF BF;
    uint32 R ;
}NVIC_ISER0_union;

typedef union
{
    NVIC_ISER1_BF BF;
    uint32 R ;
}NVIC_ISER1_union;

typedef union
{
    NVIC_ISER2_BF BF;
    uint32 R ;
}NVIC_ISER2_union;

typedef union
{
    NVIC_ICER0_BF BF;
    uint32 R ;
}NVIC_ICER0_union;

typedef union
{
    NVIC_ICER1_BF BF;
    uint32 R ;
}NVIC_ICER1_union;

typedef union
{
    NVIC_ICER2_BF BF;
    uint32 R ;
}NVIC_ICER2_union;

typedef union
{
    NVIC_ISPR0_BF BF;
    uint32 R ;
}NVIC_ISPR0_union;

typedef union
{
    NVIC_ISPR1_BF BF;
    uint32 R ;
}NVIC_ISPR1_union;

typedef union
{
    NVIC_ISPR2_BF BF;
    uint32 R ;
}NVIC_ISPR2_union;

typedef union
{
    NVIC_ICPR0_BF BF;
    uint32 R ;
}NVIC_ICPR0_union;

typedef union
{
    NVIC_ICPR1_BF BF;
    uint32 R ;
}NVIC_ICPR1_union;

typedef union
{
    NVIC_ICPR2_BF BF;
    uint32 R ;
}NVIC_ICPR2_union;

typedef union
{
    NVIC_IABR0_BF BF;
    uint32 R ;
}NVIC_IABR0_union;

typedef union
{
    NVIC_IABR1_BF BF;
    uint32 R ;
}NVIC_IABR1_union;

typedef union
{
    NVIC_IABR2_BF BF;
    uint32 R ;
}NVIC_IABR2_union;

typedef union
{
    NVIC_IPR0_BF BF;
    uint32 R ;
}NVIC_IPR0_union;

typedef union
{
    NVIC_IPR1_BF BF;
    uint32 R ;
}NVIC_IPR1_union;


typedef union
{
    NVIC_IPR2_BF BF;
    uint32 R ;
}NVIC_IPR2_union;

typedef union
{
    NVIC_IPR3_BF BF;
    uint32 R ;
}NVIC_IPR3_union;

typedef union
{
    NVIC_IPR4_BF BF;
    uint32 R ;
}NVIC_IPR4_union;

typedef union
{
    NVIC_IPR5_BF BF;
    uint32 R ;
}NVIC_IPR5_union;

typedef union
{
    NVIC_IPR6_BF BF;
    uint32 R ;
}NVIC_IPR6_union;

typedef union
{
    NVIC_IPR7_BF BF;
    uint32 R ;
}NVIC_IPR7_union;

typedef union
{
    NVIC_IPR8_BF BF;
    uint32 R ;
}NVIC_IPR8_union;

typedef union
{
    NVIC_IPR9_BF BF;
    uint32 R ;
}NVIC_IPR9_union;

typedef union
{
    NVIC_IPR10_BF BF;
    uint32 R ;
}NVIC_IPR10_union;

typedef union
{
    NVIC_IPR11_BF BF;
    uint32 R ;
}NVIC_IPR11_union;

typedef union
{
    NVIC_IPR12_BF BF;
    uint32 R ;
}NVIC_IPR12_union;

typedef union
{
    NVIC_IPR13_BF BF;
    uint32 R ;
}NVIC_IPR13_union;

typedef union
{
    NVIC_IPR14_BF BF;
    uint32 R ;
}NVIC_IPR14_union;

typedef union
{
    NVIC_IPR15_BF BF;
    uint32 R ;
}NVIC_IPR15_union;

typedef union
{
    NVIC_IPR16_BF BF;
    uint32 R ;
}NVIC_IPR16_union;

typedef union
{
    NVIC_IPR17_BF BF;
    uint32 R ;
}NVIC_IPR17_union;

typedef union
{
    NVIC_IPR18_BF BF;
    uint32 R ;
}NVIC_IPR18_union;

typedef union
{
    NVIC_IPR19_BF BF;
    uint32 R ;
}NVIC_IPR19_union;

typedef union
{
    NVIC_IPR20_BF BF;
    uint32 R ;
}NVIC_IPR20_union;



/*MNVIC Registers*/
typedef struct {
	volatile NVIC_ISER0_union  ISER0;
	volatile NVIC_ISER1_union  ISER1;
	volatile NVIC_ISER2_union  ISER2;
	volatile uint32 RES0[29];
	volatile NVIC_ICER0_union  ICER0;
	volatile NVIC_ICER1_union  ICER1;
	volatile NVIC_ICER2_union  ICER2;
	volatile uint32 RES1[29];
	volatile NVIC_ISPR0_union  ISPR0;
	volatile NVIC_ISPR1_union  ISPR1;
	volatile NVIC_ISPR2_union  ISPR2;
	volatile uint32 RES2[29];
	volatile NVIC_ICPR0_union  ICPR0;
	volatile NVIC_ICPR1_union  ICPR1;
	volatile NVIC_ICPR2_union  ICPR2;
	volatile uint32 RES3[29];
	volatile NVIC_IABR0_union  IABR0;
	volatile NVIC_IABR1_union  IABR1;
	volatile NVIC_IABR2_union  IABR2;
	volatile uint32 RES4[61];
	volatile NVIC_IPR0_union  IPR0;
	volatile NVIC_IPR1_union  IPR1;
	volatile NVIC_IPR2_union  IPR2;
	volatile NVIC_IPR3_union  IPR3;
	volatile NVIC_IPR4_union  IPR4;
	volatile NVIC_IPR5_union  IPR5;
	volatile NVIC_IPR6_union  IPR6;
	volatile NVIC_IPR7_union  IPR7;
	volatile NVIC_IPR8_union  IPR8;
	volatile NVIC_IPR9_union  IPR9;
	volatile NVIC_IPR10_union  IPR10;
	volatile NVIC_IPR11_union  IPR11;
	volatile NVIC_IPR12_union  IPR12;
	volatile NVIC_IPR13_union  IPR13;
	volatile NVIC_IPR14_union  IPR14;
	volatile NVIC_IPR15_union  IPR15;
	volatile NVIC_IPR16_union  IPR16;
	volatile NVIC_IPR17_union  IPR17;
	volatile NVIC_IPR18_union  IPR18;
	volatile NVIC_IPR19_union  IPR19;
	volatile NVIC_IPR20_union  IPR20;
} MNVIC_t;

/*typedef struct {
	volatile ISER[3];
	u32 RES0[29];
	u32 ISCR[3];
	u32 RES1[29];
	u32 ISPR[3];
	u32 RES2[29];
	u32 ICPR[3];
	u32 IABR[3];
	u32 RES3[61];
	u8 	IP[84];
} MNVIC_t;
*/
/*MNVIC_ConfigType->IP[ID/32]=ID%32;*/
typedef enum {

	WWDG_IRQ       ,
	PVD_IRQ            ,
	TAMPER_IRQ      ,
	RTC_IRQ            ,
	FLASH_IRQ        ,
	RCC_IRQ            ,
	EXTI0_IRQ         ,
	EXTI1_IRQ         ,
	EXTI2_IRQ         ,
	EXTI3_IRQ,
	EXTI4_IRQ,
	DMA1_Channel1_IRQ,
	DMA1_Channel2_IRQ,
	DMA1_Channel3_IRQ,
	DMA1_Channel4_IRQ,
	DMA1_Channel5_IRQ,
	DMA1_Channel6_IRQ,
	DMA1_Channel7_IRQ,
	ADC1_2_IRQ,
	USB_HP_CAN_T_IRQ ,
	USB_LP_CAN_T_IRQ  ,
	CAN_RX1_IRQ           ,
	CAN_SCE_IRQ           ,
	EXTI9_5_IRQ             ,
	TIM_BRK_IRQ            ,
	TIM1_UP_IRQ            ,
	TIM1_TRG_COM_IRQ ,
	TIM1_CC_IRQ            ,
	TIM2_IRQ                  ,
	TIM3_IRQ                  ,
	TIM4_IRQ                  ,
	I2C1_EV_IRQ            ,
	I2C1_ER_IRQ            ,
	I2C2_EV_IRQ            ,
	I2C2_ER_IRQ            ,
	SPI1_IRQ                   ,
	SPI2_IRQ                   ,
	USART1_IRQ              ,
	USART2_IRQ              ,
	USART3_IRQ              ,
	EXTI15_10_IRQ         ,
	TRCAlarm_IRQ           ,
	USBWakeUp_IRQ      ,
	TIM8_BRK_IRQ          ,
	TIM8_UP_IRQ            ,
	TIM8_TRG_COM_IRQ ,
	TIM8_CC_IRQ            ,
	ADC3_IRQ                 ,
	FSMC_IRQ                 ,
	SDIO_IRQ                  ,
	TIM5_IRQ                  ,
	SPI3_IRQ                   ,
	UART4_IRQ                ,
	UART5_IRQ                ,
	TIM6_IRQ           	      ,
	TIM7_IRQ           	      ,
	DMA2_Channel_IRQ  ,
	DMA2_Channe2_IRQ ,
	DMA2_Channe3_IRQ ,
	DMA2_Channe4_IRQ

}IRQ_ID;


#endif

