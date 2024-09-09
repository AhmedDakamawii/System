/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Port_Types.h
 *  Module:  	  Port_Types
 *
 *  Description:  Header file for Port Module' Types
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Salma Hisham
 *	Date:		  22/10/2023
 *********************************************************************************************************************/

#ifndef PORT_TYPES_H_
#define PORT_TYPES_H_

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define HIGH    1U
#define LOW     0U

#define PORT_TOTAL_NUMBER_OF_PINS 		35U

#define PORT_MACRO_GPIOA   0
#define PORT_MACRO_GPIOB   1
#define PORT_MACRO_GPIOC   2

#define GPIO_HIGH 1
#define GPIO_LOW 0

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

typedef enum
{
	PORTA=0,
	PORTB=1,
	PORTC=2
}Port_PortType;

typedef enum
{
	PIN0  = 0,
	PIN1  = 1,
	PIN2  = 2,
	PIN3  = 3,
	PIN4  = 4,
	PIN5  = 5,
	PIN6  = 6,
	PIN7  = 7,
	PIN8  = 8,
	PIN9  = 9,
	PIN10 = 10,
	PIN11 = 11,
	PIN12 = 12,
	PIN13 = 13,
	PIN14 = 14,
	PIN15 = 15
}Port_PinType;

typedef enum
{
	INPUT = 0,
	OUTPUT = 1
}Port_PinDirectionType;

typedef enum
{
	/*for DIO*/
	DIO_MODE  =  0,
	/*for timers*/
	TIM1_MODE =  1,
	TIM8_MODE =  2,
	TIM2_MODE =  3,
	TIM3_MODE =  4,
	TIM4_MODE =  5,
	TIM5_MODE =  6,
	/*for USART*/
	USART_MODE = 7,
	/*for SPI*/
	SPI_MODE   = 8,
	/*for I2S*/
	I2S_MODE   = 9,
	/*for I2C*/
	I2C_MODE   = 10,
	/*for CAN*/
	CAN_MODE   = 11,
	/*for USB*/
	USB_MODE   = 12,
	/*for OTG*/
	OTG_MODE   = 13,
	/*for SDIO*/
	SDIO_MODE  = 14,
	/*for ADC/DAC */
	ADC_MODE   = 15,
	DAC_MODE   = 16,
	/*for FSMC*/
	FSMC_MODE  = 17
}Port_PinModeType;



typedef enum
{
	DRIVE_10MHZ = 0,
	DRIVE_2MHZ =  1,
	DRIVE_50MHZ = 2
}Port_PinOutFrequencyType;

typedef enum
{
	ANALOG = 0,
	INPUT_FLOATING = 1,
	INPUT_PULL_DOWN = 2,
	INPUT_PULL_UP = 3
}Port_PinInputAttachType;

typedef enum
{
	GPO_PUSH_PULL  = 0,
	GPO_OPEN_DRAIN = 1,
	AFO_PUSH_PULL  = 2,
	AFO_OPEN_DRAIN = 3

}Port_PinOutputAttachType;

typedef enum
{
	PIN_LEVEL_LOW = 0 ,
	PIN_LEVEL_HIGH = 1 ,
}Port_PinLevelType;

typedef enum {
	CHANNEL_DISABLED = 0 ,
	CHANNEL_ENABLED = 1,
}Port_EnableType;

typedef enum{
Spi1_remap_mode=0,
I2C1_remap_mode=1,
USART1_remap_mode=2,
USART2_remap_mode=3,
USART3_remap_mode=4,
TIM1_remap_mode=5,
TIM2_remap_mode=6,
TIM3_remap_mode=7,
TIM4_remap_mode=8,
CAN_remap_mode=9,	
PDO1_remap_mode=10,
TIM9_remap_mode=11,
TIM10_remap_mode=12,
TIM11_remap_mode=13,
TIM13_remap_mode=14,
TIM14_remap_mode=15,
FSMC_NADV_REMAP_mode=16,
EXTIO
}Mode_remap;

typedef enum
{
SJW_RESET =0b000,
SWJ_NO_RESET =0b001,
SJW_SW =0b010,
SWJ_NONE =0b100
}SWJ_CFG_remap;

typedef enum
{
Spi1_no_remap =0,
Spi1_remap =1

}Spi1_remap_remap;

typedef enum
{
I2C1_REMAP_no_remap =0,
I2C1_REMAP_remap =1

}I2C1_REMAP;
typedef enum
{
USART1_REMAP_no_remap =0,
USART1_REMAP_remap =1

}USART1_REMAP;
typedef enum
{
USART2_REMAP_no_remap =0,
USART2_REMAP_remap =1

}USART2_REMAP;
typedef enum
{
USART3_REMAP_no_remap =0,
USART3_REMAP_partialremap =1,
USART3_REMAP_fullremap =0b11
}USART3_REMAP;
typedef enum
{
TIM1_REMAP_no_remap =0,
TIM1_REMAP_partialremap =1,
TIM1_REMAP_fullremap =0b11
}TIM1_REMAP;
typedef enum
{
TIM2_REMAP_no_remap =0,
TIM2_REMAP_partialremap1 =1,
TIM2_REMAP_partialremap2 =0b10,
TIM2_REMAP_fullremap =0b11,
}TIM2_REMAP;
typedef enum
{
TIM3_REMAP_no_remap =0,
TIM3_REMAP_partialremap =1,
TIM3_REMAP_fullremap =0b11,
}TIM3_REMAP;
typedef enum
{
TIM4_REMAP_no_remap =0,
TIM4_REMAP_remap =1,
}TIM4_REMAP;

typedef enum
{
	CAN_REMAP_PA,
	CAN_REMAP_PB=0b10,
	CAN_REMAP_PD=0b11,
}CAN_REMAP;

typedef enum
{
PDO1_REMAP_no_remap =0,
PD01_REMAP_remap =1,
}PD01_REMAP;
typedef enum
{
TIM9_REMAP_no_remap =0,
TIM9_REMAP_remap =1,
}TIM9_REMAP;
typedef enum
{
TIM10_REMAP_no_remap =0,
TIM10_REMAP_remap =1,
}TIM10_REMAP;
typedef enum
{
TIM11_REMAP_no_remap =0,
TIM11_REMAP_remap =1,
}TIM11_REMAP;
typedef enum
{
TIM13_REMAP_no_remap =0,
TIM13_REMAP_remap =1,
}TIM13_REMAP;
typedef enum
{
TIM14_REMAP_no_remap =0,
TIM14_REMAP_remap =1,
}TIM14_REMAP;
typedef enum
{
FSMC_NADV_REMAP_no_remap =0,
FSMC_NADV_REMAP_remap =1,
}FSMC_NADV_REMAP;

/*
 * Description: Structure to configure an individual pin:
 *		1. The id of the PORT.
 *		2. The id of the pin in the PORT.
 *  	3. The direction of pin: INPUT or OUTPUT
 *  	4. The initial value of the port pin
 *  	5. The initial port pin mode
 *  	6. The internal input type: Pull up, Pull down, Analog, Input floating
 *  	7. The internal output type: push pull, Open Drain
 *  	8. The driven frequency in case of output
 */
typedef struct
{
	Port_PortType portType;
	Port_PinType pinType;
	Port_EnableType enableType;
	Port_PinDirectionType pinDirectionType;
	Port_PinLevelType pinLevelType;
	// Port_PinModeType pinModeType;
	Port_PinInputAttachType pinInputAttachType;
	Port_PinOutputAttachType pinOutputAttachType;
	Port_PinOutFrequencyType pinOutFrequencyType;
}Port_PinConfigType;

/*
 * Description: Structure to configure an individual pin:
 *  	=> Array of structure containing all the pin configuration for each pin in the port
 */
typedef struct
{
	Port_PinConfigType pinConfigType[PORT_TOTAL_NUMBER_OF_PINS];
}Port_configType;

#endif /* PORT_TYPES_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Port_Types.h
 *********************************************************************************************************************/