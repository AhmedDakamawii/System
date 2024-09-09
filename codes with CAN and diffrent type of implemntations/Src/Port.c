/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Port.c
 *  Module:  	  Port
 *
 *  Description:  Source file for Port Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Salma Hisham
 *	Date:		  22/10/2023
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Macros.h"

#include "Port.h"

#include "RCC.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void Port_Remap()
{

	
	AFIO->MAPR.BF.SPI1_REMAP=SPI1_cfg;
	AFIO->MAPR.BF.I2C1_REMAP=I2C1_cfg;
	AFIO->MAPR.BF.USART1_REMAP=USART1_cfg;
	AFIO->MAPR.BF.USART2_REMAP=USART2_cfg;
	AFIO->MAPR.BF.USART3_REMAP=USART3_cfg;
	AFIO->MAPR.BF.TIM1_REMAP=TIM1_cfg;
	AFIO->MAPR.BF.TIM2_REMAP=TIM2_cfg;
	AFIO->MAPR.BF.TIM3_REMAP=TIM3_cfg;
	AFIO->MAPR.BF.TIM4_REMAP=TIM4_cfg;
	AFIO->MAPR.BF.CAN_REMAP=CAN_cfg;
	AFIO->MAPR.BF.PD01_REMAP=PD01_cfg;
	AFIO->MAPR2.BF.TIM9_REMAP=TIM9_cfg;
	AFIO->MAPR2.BF.TIM10_REMAP=TIM10_cfg;
	AFIO->MAPR2.BF.TIM11_REMAP=TIM11_cfg;
	AFIO->MAPR2.BF.TIM13_REMAP=TIM13_cfg;
	AFIO->MAPR2.BF.TIM14_REMAP=TIM14_cfg;
	AFIO->MAPR2.BF.FSMC_NADV=FSMC_NADV_cfg;



}
/*******************************************************************************
 * Service Name: Port_Init
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): ConfigPtr - Pointer to post-build (Linking) configuration data
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Setup the Port configuration:
 *  	1. The direction of pin: INPUT or OUTPUT
 *  	2. The initial value of the port pin
 *  	3. The initial port pin mode
 *  	4. The internal input type: Pull up, Pull down, Analog, Input floating
 *  	5. The internal output type: push pull, Open Drain
 *  	6. The driven frequency in case of output
 *******************************************************************************/
void Port_Init(const Port_configType *ConfigPtr)
{
	if (ConfigPtr == NULL_PTR)
	{
		// TODO:Assert Error to error log function
		return;
	}

	/* an index used to loop over the pins */
	uint8 pin;
	/* Pointer used to traverse on all ports */
	volatile GPIO *portPtr = NULL_PTR;

	/* loop over all pins */
	for (pin = 0; pin < PORT_TOTAL_NUMBER_OF_PINS; pin++)
	{
		if (ConfigPtr->pinConfigType[pin].enableType == CHANNEL_DISABLED)
		{
			/* skip this loop if the channel is disabled*/
			continue;
		}

		switch (ConfigPtr->pinConfigType[pin].portType)
		{
		case PORTA:
			/* Assignning portPtr to the corresponding port pointer*/
			portPtr = MGPIOA;
			/* Initalizing RCC for PortA*/
			RCC_APB2PeripheralEnable(IOPAEN);
			break;
		case PORTB:
			/* Assignning portPtr to the corresponding port pointer*/
			portPtr = MGPIOB;
			/* Initalizing RCC for PortB*/
			RCC_APB2PeripheralEnable(IOPBEN);
			break;
		case PORTC:
			/* Assignning portPtr to the corresponding port pointer*/
			portPtr = MGPIOC;
			/* Initalizing RCC for PortC*/
			RCC_APB2PeripheralEnable(IOPCEN);
			break;
		}

		// switch (ConfigPtr->pinConfigType[pin].pinModeType)
		// {
		// case DIO_MODE:
		// 	/*[TODO]:modify needed register*/
		// 	break;
		// case TIM1_MODE:
		// 	/*[TODO]:modify needed register*/
		// 	break;
		// case TIM8_MODE:
		// 	/*[TODO]:modify needed register*/
		// 	break;
		// case TIM2_MODE:
		// 	/*[TODO]:modify needed register*/
		// 	break;
		// case TIM3_MODE:
		// 	/*[TODO]:modify needed register*/
		// 	break;
		// case TIM4_MODE:
		// 	/*[TODO]:modify needed register*/
		// 	break;
		// case TIM5_MODE:
		// 	/*[TODO]:modify needed register*/
		// 	break;
		// case USART_MODE:
		// 	/*[TODO]:modify needed register*/
		// 	break;
		// case SPI_MODE:
		// 	/*[TODO]:modify needed register*/
		// 	break;
		// case I2S_MODE:
		// 	/*[TODO]:modify needed register*/
		// 	break;
		// case I2C_MODE:
		// 	/*[TODO]:modify needed register*/
		// 	break;
		// case CAN_MODE:
		// 	/*[TODO]:modify needed register*/
		// 	break;
		// case USB_MODE:
		// 	/*[TODO]:modify needed register*/
		// 	break;
		// case OTG_MODE:
		// 	/*[TODO]:modify needed register*/
		// 	break;
		// case SDIO_MODE:
		// 	/*[TODO]:modify needed register*/
		// 	break;
		// case ADC_MODE:
		// 	/*[TODO]:modify needed register*/
		// 	break;
		// case DAC_MODE:
		// 	/*[TODO]:modify needed register*/
		// 	break;
		// case FSMC_MODE:
		// 	/*[TODO]:modify needed register*/
		// 	break;
		// }

		/* Configure output frequency*/
		if (ConfigPtr->pinConfigType[pin].pinDirectionType == OUTPUT)
		{
			switch (ConfigPtr->pinConfigType[pin].pinOutFrequencyType)
			{
				/*
				insert Specific frequencty bits in the corresponding Register
				*/
			case DRIVE_10MHZ:
				if (ConfigPtr->pinConfigType[pin].pinType <= 7)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 0:
						portPtr->CRL.BF.MODE0 = 0b01;
						break;
					case 1:
						portPtr->CRL.BF.MODE1 = 0b01;
						break;
					case 2:
						portPtr->CRL.BF.MODE2 = 0b01;
						break;
					case 3:
						portPtr->CRL.BF.MODE3 = 0b01;
						break;
					case 4:
						portPtr->CRL.BF.MODE4 = 0b01;
						break;
					case 5:
						portPtr->CRL.BF.MODE5 = 0b01;
						break;
					case 6:
						portPtr->CRL.BF.MODE6 = 0b01;
						break;
					case 7:
						portPtr->CRL.BF.MODE7 = 0b01;
						break;
					}
				}
				else if (ConfigPtr->pinConfigType[pin].pinType <= 15)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 8:
						portPtr->CRH.BF.MODE8 = 0b01;
						break;
					case 9:
						portPtr->CRH.BF.MODE9 = 0b01;
						break;
					case 10:
						portPtr->CRH.BF.MODE10 = 0b01;
						break;
					case 11:
						portPtr->CRH.BF.MODE11 = 0b01;
						break;
					case 12:
						portPtr->CRH.BF.MODE12 = 0b01;
						break;
					case 13:
						portPtr->CRH.BF.MODE13 = 0b01;
						break;
					case 14:
						portPtr->CRH.BF.MODE14 = 0b01;
						break;
					case 15:
						portPtr->CRH.BF.MODE15 = 0b01;
						break;
					}
				}
				break;

			case DRIVE_2MHZ:
				if (ConfigPtr->pinConfigType[pin].pinType <= 7)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 0:
						portPtr->CRL.BF.MODE0 = 0b10;
						break;
					case 1:
						portPtr->CRL.BF.MODE1 = 0b10;
						break;
					case 2:
						portPtr->CRL.BF.MODE2 = 0b10;
						break;
					case 3:
						portPtr->CRL.BF.MODE3 = 0b10;
						break;
					case 4:
						portPtr->CRL.BF.MODE4 = 0b10;
						break;
					case 5:
						portPtr->CRL.BF.MODE5 = 0b10;
						break;
					case 6:
						portPtr->CRL.BF.MODE6 = 0b10;
						break;
					case 7:
						portPtr->CRL.BF.MODE7 = 0b10;
						break;
					}
				}
				else if (ConfigPtr->pinConfigType[pin].pinType <= 15)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 8:
						portPtr->CRH.BF.MODE8 = 0b10;
						break;
					case 9:
						portPtr->CRH.BF.MODE9 = 0b10;
						break;
					case 10:
						portPtr->CRH.BF.MODE10 = 0b10;
						break;
					case 11:
						portPtr->CRH.BF.MODE11 = 0b10;
						break;
					case 12:
						portPtr->CRH.BF.MODE12 = 0b10;
						break;
					case 13:
						portPtr->CRH.BF.MODE13 = 0b10;
						break;
					case 14:
						portPtr->CRH.BF.MODE14 = 0b10;
						break;
					case 15:
						portPtr->CRH.BF.MODE15 = 0b10;
						break;
					}
				}
				break;

			case DRIVE_50MHZ:
				if (ConfigPtr->pinConfigType[pin].pinType <= 7)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 0:
						portPtr->CRL.BF.MODE0 = 0b11;
						break;
					case 1:
						portPtr->CRL.BF.MODE1 = 0b11;
						break;
					case 2:
						portPtr->CRL.BF.MODE2 = 0b11;
						break;
					case 3:
						portPtr->CRL.BF.MODE3 = 0b11;
						break;
					case 4:
						portPtr->CRL.BF.MODE4 = 0b11;
						break;
					case 5:
						portPtr->CRL.BF.MODE5 = 0b11;
						break;
					case 6:
						portPtr->CRL.BF.MODE6 = 0b11;
						break;
					case 7:
						portPtr->CRL.BF.MODE7 = 0b11;
						break;
					}
				}
				else if (ConfigPtr->pinConfigType[pin].pinType <= 15)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 8:
						portPtr->CRH.BF.MODE8 = 0b11;
						break;
					case 9:
						portPtr->CRH.BF.MODE9 = 0b11;
						break;
					case 10:
						portPtr->CRH.BF.MODE10 = 0b11;
						break;
					case 11:
						portPtr->CRH.BF.MODE11 = 0b11;
						break;
					case 12:
						portPtr->CRH.BF.MODE12 = 0b11;
						break;
					case 13:
						portPtr->CRH.BF.MODE13 = 0b11;
						break;
					case 14:
						portPtr->CRH.BF.MODE14 = 0b11;
						break;
					case 15:
						portPtr->CRH.BF.MODE15 = 0b11;
						break;
					}
				}
				break;
			}
			/* Configure Output Attach Type */
			switch (ConfigPtr->pinConfigType[pin].pinOutputAttachType)
			{
				/* Insert output mode bits in the corresponding Register*/
			case GPO_PUSH_PULL:
				if (ConfigPtr->pinConfigType[pin].pinType <= 7)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 0:
						portPtr->CRL.BF.CNF0 = 0b00;
						break;
					case 1:
						portPtr->CRL.BF.CNF1 = 0b00;
						break;
					case 2:
						portPtr->CRL.BF.CNF2 = 0b00;
						break;
					case 3:
						portPtr->CRL.BF.CNF3 = 0b00;
						break;
					case 4:
						portPtr->CRL.BF.CNF4 = 0b00;
						break;
					case 5:
						portPtr->CRL.BF.CNF5 = 0b00;
						break;
					case 6:
						portPtr->CRL.BF.CNF6 = 0b00;
						break;
					case 7:
						portPtr->CRL.BF.CNF7 = 0b00;
						break;
					}
				}
				else if (ConfigPtr->pinConfigType[pin].pinType <= 15)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 8:
						portPtr->CRH.BF.CNF8 = 0b00;
						break;
					case 9:
						portPtr->CRH.BF.CNF9 = 0b00;
						break;
					case 10:
						portPtr->CRH.BF.CNF10 = 0b00;
						break;
					case 11:
						portPtr->CRH.BF.CNF11 = 0b00;
						break;
					case 12:
						portPtr->CRH.BF.CNF12 = 0b00;
						break;
					case 13:
						portPtr->CRH.BF.CNF13 = 0b00;
						break;
					case 14:
						portPtr->CRH.BF.CNF14 = 0b00;
						break;
					case 15:
						portPtr->CRH.BF.CNF15 = 0b00;
						break;
					}
				}
				break;
			case GPO_OPEN_DRAIN:
				if (ConfigPtr->pinConfigType[pin].pinType <= 7)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 0:
						portPtr->CRL.BF.CNF0 = 0b01;
						break;
					case 1:
						portPtr->CRL.BF.CNF1 = 0b01;
						break;
					case 2:
						portPtr->CRL.BF.CNF2 = 0b01;
						break;
					case 3:
						portPtr->CRL.BF.CNF3 = 0b01;
						break;
					case 4:
						portPtr->CRL.BF.CNF4 = 0b01;
						break;
					case 5:
						portPtr->CRL.BF.CNF5 = 0b01;
						break;
					case 6:
						portPtr->CRL.BF.CNF6 = 0b01;
						break;
					case 7:
						portPtr->CRL.BF.CNF7 = 0b01;
						break;
					}
				}
				else if (ConfigPtr->pinConfigType[pin].pinType <= 15)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 8:
						portPtr->CRH.BF.CNF8 = 0b01;
						break;
					case 9:
						portPtr->CRH.BF.CNF9 = 0b01;
						break;
					case 10:
						portPtr->CRH.BF.CNF10 = 0b01;
						break;
					case 11:
						portPtr->CRH.BF.CNF11 = 0b01;
						break;
					case 12:
						portPtr->CRH.BF.CNF12 = 0b01;
						break;
					case 13:
						portPtr->CRH.BF.CNF13 = 0b01;
						break;
					case 14:
						portPtr->CRH.BF.CNF14 = 0b01;
						break;
					case 15:
						portPtr->CRH.BF.CNF15 = 0b01;
						break;
					}
				}
				break;
			case AFO_PUSH_PULL:
				if (ConfigPtr->pinConfigType[pin].pinType <= 7)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 0:
						portPtr->CRL.BF.CNF0 = 0b10;
						break;
					case 1:
						portPtr->CRL.BF.CNF1 = 0b10;
						break;
					case 2:
						portPtr->CRL.BF.CNF2 = 0b10;
						break;
					case 3:
						portPtr->CRL.BF.CNF3 = 0b10;
						break;
					case 4:
						portPtr->CRL.BF.CNF4 = 0b10;
						break;
					case 5:
						portPtr->CRL.BF.CNF5 = 0b10;
						break;
					case 6:
						portPtr->CRL.BF.CNF6 = 0b10;
						break;
					case 7:
						portPtr->CRL.BF.CNF7 = 0b10;
						break;
					}
				}
				else if (ConfigPtr->pinConfigType[pin].pinType <= 15)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 8:
						portPtr->CRH.BF.CNF8 = 0b10;
						break;
					case 9:
						portPtr->CRH.BF.CNF9 = 0b10;
						break;
					case 10:
						portPtr->CRH.BF.CNF10 = 0b10;
						break;
					case 11:
						portPtr->CRH.BF.CNF11 = 0b10;
						break;
					case 12:
						portPtr->CRH.BF.CNF12 = 0b10;
						break;
					case 13:
						portPtr->CRH.BF.CNF13 = 0b10;
						break;
					case 14:
						portPtr->CRH.BF.CNF14 = 0b10;
						break;
					case 15:
						portPtr->CRH.BF.CNF15 = 0b10;
						break;
					}
				}
				break;
			case AFO_OPEN_DRAIN:
				if (ConfigPtr->pinConfigType[pin].pinType <= 7)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 0:
						portPtr->CRL.BF.CNF0 = 0b11;
						break;
					case 1:
						portPtr->CRL.BF.CNF1 = 0b11;
						break;
					case 2:
						portPtr->CRL.BF.CNF2 = 0b11;
						break;
					case 3:
						portPtr->CRL.BF.CNF3 = 0b11;
						break;
					case 4:
						portPtr->CRL.BF.CNF4 = 0b11;
						break;
					case 5:
						portPtr->CRL.BF.CNF5 = 0b11;
						break;
					case 6:
						portPtr->CRL.BF.CNF6 = 0b11;
						break;
					case 7:
						portPtr->CRL.BF.CNF7 = 0b11;
						break;
					}
				}
				else if (ConfigPtr->pinConfigType[pin].pinType <= 15)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 8:
						portPtr->CRH.BF.CNF8 = 0b11;
						break;
					case 9:
						portPtr->CRH.BF.CNF9 = 0b11;
						break;
					case 10:
						portPtr->CRH.BF.CNF10 = 0b11;
						break;
					case 11:
						portPtr->CRH.BF.CNF11 = 0b11;
						break;
					case 12:
						portPtr->CRH.BF.CNF12 = 0b11;
						break;
					case 13:
						portPtr->CRH.BF.CNF13 = 0b11;
						break;
					case 14:
						portPtr->CRH.BF.CNF14 = 0b11;
						break;
					case 15:
						portPtr->CRH.BF.CNF15 = 0b11;
						break;
					}
				}
				break;
			}

			/*Drive the required voltage*/
			switch (ConfigPtr->pinConfigType[pin].pinLevelType)
			{
			case PIN_LEVEL_HIGH:
				portPtr->BSRR.REG = (1 << ConfigPtr->pinConfigType[pin].pinType);
				break;
			case PIN_LEVEL_LOW:
				portPtr->BRR.REG = (1 << ConfigPtr->pinConfigType[pin].pinType);
			}
		}
		else if (ConfigPtr->pinConfigType[pin].pinDirectionType == INPUT)
		{
			/* Configure Input attach type*/
			switch (ConfigPtr->pinConfigType[pin].pinInputAttachType)
			{
			/* Insert specific mode bits in the corresponding Register*/
			case ANALOG:
				if (ConfigPtr->pinConfigType[pin].pinType <= 7)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 0:
						portPtr->CRL.BF.CNF0 = 0b00;
						portPtr->CRL.BF.MODE0 = 0b00;
						break;
					case 1:
						portPtr->CRL.BF.CNF1 = 0b00;
						portPtr->CRL.BF.MODE1 = 0b00;
						break;
					case 2:
						portPtr->CRL.BF.CNF2 = 0b00;
						portPtr->CRL.BF.MODE2 = 0b00;
						break;
					case 3:
						portPtr->CRL.BF.CNF3 = 0b00;
						portPtr->CRL.BF.MODE3 = 0b00;
						break;
					case 4:
						portPtr->CRL.BF.CNF4 = 0b00;
						portPtr->CRL.BF.MODE4 = 0b00;
						break;
					case 5:
						portPtr->CRL.BF.CNF5 = 0b00;
						portPtr->CRL.BF.MODE5 = 0b00;
						break;
					case 6:
						portPtr->CRL.BF.CNF6 = 0b00;
						portPtr->CRL.BF.MODE6 = 0b00;
						break;
					case 7:
						portPtr->CRL.BF.CNF7 = 0b00;
						portPtr->CRL.BF.MODE7 = 0b00;
						break;
					}
				}
				else if (ConfigPtr->pinConfigType[pin].pinType <= 15)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 8:
						portPtr->CRH.BF.CNF8 = 0b00;
						portPtr->CRH.BF.MODE8 = 0b00;
						break;
					case 9:
						portPtr->CRH.BF.CNF9 = 0b00;
						portPtr->CRH.BF.MODE9 = 0b00;
						break;
					case 10:
						portPtr->CRH.BF.CNF10 = 0b00;
						portPtr->CRH.BF.MODE10 = 0b00;
						break;
					case 11:
						portPtr->CRH.BF.CNF11 = 0b00;
						portPtr->CRH.BF.MODE11 = 0b00;
						break;
					case 12:
						portPtr->CRH.BF.CNF12 = 0b00;
						portPtr->CRH.BF.MODE12 = 0b00;
						break;
					case 13:
						portPtr->CRH.BF.CNF13 = 0b00;
						portPtr->CRH.BF.MODE13 = 0b00;
						break;
					case 14:
						portPtr->CRH.BF.CNF14 = 0b00;
						portPtr->CRH.BF.MODE14 = 0b00;
						break;
					case 15:
						portPtr->CRH.BF.CNF15 = 0b00;
						portPtr->CRH.BF.MODE15 = 0b00;
						break;
					}
				}
				break;

			case INPUT_FLOATING:
				if (ConfigPtr->pinConfigType[pin].pinType <= 7)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 0:
						portPtr->CRL.BF.CNF0 = 0b01;
						portPtr->CRL.BF.MODE0 = 0b00;
						break;
					case 1:
						portPtr->CRL.BF.CNF1 = 0b01;
						portPtr->CRL.BF.MODE1 = 0b00;
						break;
					case 2:
						portPtr->CRL.BF.CNF2 = 0b01;
						portPtr->CRL.BF.MODE2 = 0b00;
						break;
					case 3:
						portPtr->CRL.BF.CNF3 = 0b01;
						portPtr->CRL.BF.MODE3 = 0b00;
						break;
					case 4:
						portPtr->CRL.BF.CNF4 = 0b01;
						portPtr->CRL.BF.MODE4 = 0b00;
						break;
					case 5:
						portPtr->CRL.BF.CNF5 = 0b01;
						portPtr->CRL.BF.MODE5 = 0b00;
						break;
					case 6:
						portPtr->CRL.BF.CNF6 = 0b01;
						portPtr->CRL.BF.MODE6 = 0b00;
						break;
					case 7:
						portPtr->CRL.BF.CNF7 = 0b01;
						portPtr->CRL.BF.MODE7 = 0b00;
						break;
					}
				}
				else if (ConfigPtr->pinConfigType[pin].pinType <= 15)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 8:
						portPtr->CRH.BF.CNF8 = 0b01;
						portPtr->CRH.BF.MODE8 = 0b00;
						break;
					case 9:
						portPtr->CRH.BF.CNF9 = 0b01;
						portPtr->CRH.BF.MODE9 = 0b00;
						break;
					case 10:
						portPtr->CRH.BF.CNF10 = 0b01;
						portPtr->CRH.BF.MODE10 = 0b00;
						break;
					case 11:
						portPtr->CRH.BF.CNF11 = 0b01;
						portPtr->CRH.BF.MODE11 = 0b00;
						break;
					case 12:
						portPtr->CRH.BF.CNF12 = 0b01;
						portPtr->CRH.BF.MODE12 = 0b00;
						break;
					case 13:
						portPtr->CRH.BF.CNF13 = 0b01;
						portPtr->CRH.BF.MODE13 = 0b00;
						break;
					case 14:
						portPtr->CRH.BF.CNF14 = 0b01;
						portPtr->CRH.BF.MODE14 = 0b00;
						break;
					case 15:
						portPtr->CRH.BF.CNF15 = 0b01;
						portPtr->CRH.BF.MODE15 = 0b00;
						break;
					}
				}
				break;

			case INPUT_PULL_DOWN:
				if (ConfigPtr->pinConfigType[pin].pinType <= 7)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 0:
						portPtr->CRL.BF.CNF0 = 0b10;
						portPtr->CRL.BF.MODE0 = 0b00;
						break;
					case 1:
						portPtr->CRL.BF.CNF1 = 0b10;
						portPtr->CRL.BF.MODE1 = 0b00;
						break;
					case 2:
						portPtr->CRL.BF.CNF2 = 0b10;
						portPtr->CRL.BF.MODE2 = 0b00;
						break;
					case 3:
						portPtr->CRL.BF.CNF3 = 0b10;
						portPtr->CRL.BF.MODE3 = 0b00;
						break;
					case 4:
						portPtr->CRL.BF.CNF4 = 0b10;
						portPtr->CRL.BF.MODE4 = 0b00;
						break;
					case 5:
						portPtr->CRL.BF.CNF5 = 0b10;
						portPtr->CRL.BF.MODE5 = 0b00;
						break;
					case 6:
						portPtr->CRL.BF.CNF6 = 0b10;
						portPtr->CRL.BF.MODE6 = 0b00;
						break;
					case 7:
						portPtr->CRL.BF.CNF7 = 0b10;
						portPtr->CRL.BF.MODE7 = 0b00;
						break;
					}
				}
				else if (ConfigPtr->pinConfigType[pin].pinType <= 15)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 8:
						portPtr->CRH.BF.CNF8 = 0b10;
						portPtr->CRH.BF.MODE8 = 0b00;
						break;
					case 9:
						portPtr->CRH.BF.CNF9 = 0b10;
						portPtr->CRH.BF.MODE9 = 0b00;
						break;
					case 10:
						portPtr->CRH.BF.CNF10 = 0b10;
						portPtr->CRH.BF.MODE10 = 0b00;
						break;
					case 11:
						portPtr->CRH.BF.CNF11 = 0b10;
						portPtr->CRH.BF.MODE11 = 0b00;
						break;
					case 12:
						portPtr->CRH.BF.CNF12 = 0b10;
						portPtr->CRH.BF.MODE12 = 0b00;
						break;
					case 13:
						portPtr->CRH.BF.CNF13 = 0b10;
						portPtr->CRH.BF.MODE13 = 0b00;
						break;
					case 14:
						portPtr->CRH.BF.CNF14 = 0b10;
						portPtr->CRH.BF.MODE14 = 0b00;
						break;
					case 15:
						portPtr->CRH.BF.CNF15 = 0b10;
						portPtr->CRH.BF.MODE15 = 0b00;
						break;
					}
				}
				break;

			case INPUT_PULL_UP:
				if (ConfigPtr->pinConfigType[pin].pinType <= 7)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 0:
						portPtr->CRL.BF.CNF0 = 0b10;
						portPtr->CRL.BF.MODE0 = 0b00;
						break;
					case 1:
						portPtr->CRL.BF.CNF1 = 0b10;
						portPtr->CRL.BF.MODE1 = 0b00;
						break;
					case 2:
						portPtr->CRL.BF.CNF2 = 0b10;
						portPtr->CRL.BF.MODE2 = 0b00;
						break;
					case 3:
						portPtr->CRL.BF.CNF3 = 0b10;
						portPtr->CRL.BF.MODE3 = 0b00;
						break;
					case 4:
						portPtr->CRL.BF.CNF4 = 0b10;
						portPtr->CRL.BF.MODE4 = 0b00;
						break;
					case 5:
						portPtr->CRL.BF.CNF5 = 0b10;
						portPtr->CRL.BF.MODE5 = 0b00;
						break;
					case 6:
						portPtr->CRL.BF.CNF6 = 0b10;
						portPtr->CRL.BF.MODE6 = 0b00;
						break;
					case 7:
						portPtr->CRL.BF.CNF7 = 0b10;
						portPtr->CRL.BF.MODE7 = 0b00;
						break;
					}
				}
				else if (ConfigPtr->pinConfigType[pin].pinType <= 15)
				{
					switch (ConfigPtr->pinConfigType[pin].pinType)
					{
					case 8:
						portPtr->CRH.BF.CNF8 = 0b10;
						portPtr->CRH.BF.MODE8 = 0b00;
						break;
					case 9:
						portPtr->CRH.BF.CNF9 = 0b10;
						portPtr->CRH.BF.MODE9 = 0b00;
						break;
					case 10:
						portPtr->CRH.BF.CNF10 = 0b10;
						portPtr->CRH.BF.MODE10 = 0b00;
						break;
					case 11:
						portPtr->CRH.BF.CNF11 = 0b10;
						portPtr->CRH.BF.MODE11 = 0b00;
						break;
					case 12:
						portPtr->CRH.BF.CNF12 = 0b10;
						portPtr->CRH.BF.MODE12 = 0b00;
						break;
					case 13:
						portPtr->CRH.BF.CNF13 = 0b10;
						portPtr->CRH.BF.MODE13 = 0b00;
						break;
					case 14:
						portPtr->CRH.BF.CNF14 = 0b10;
						portPtr->CRH.BF.MODE14 = 0b00;
						break;
					case 15:
						portPtr->CRH.BF.CNF15 = 0b10;
						portPtr->CRH.BF.MODE15 = 0b00;
						break;
					}
				}
				break;
			}
		}
	}
	Port_Remap();
}




void EXTI_remap(Port_PortType PortId, Port_PinType ChannelId)
{
switch(ChannelId)
{
	case PIN0:
	{
		AFIO->EXTICR1.BF.EXTI0=PortId;
		break;
	}
	case PIN1:
	{
		AFIO->EXTICR1.BF.EXTI1=PortId;
		break;
	}
	case PIN2:
	{
		AFIO->EXTICR1.BF.EXTI2=PortId;
		break;
	}
	case PIN3:
	{
		AFIO->EXTICR1.BF.EXTI3=PortId;
		break;
	}
	case PIN4:
	{
		AFIO->EXTICR2.BF.EXTI4=PortId;
		break;
	}
	case PIN5:
	{
		AFIO->EXTICR2.BF.EXTI5=PortId;
		break;
	}
	case PIN6:
	{
		AFIO->EXTICR2.BF.EXTI6=PortId;
		break;
	}
	case PIN7:
	{
		AFIO->EXTICR2.BF.EXTI7=PortId;
		break;
	}
	case PIN8:
	{
		AFIO->EXTICR3.BF.EXTI8=PortId;
		break;
	}
	case PIN9:
	{
		AFIO->EXTICR3.BF.EXTI9=PortId;
		break;
	}
	case PIN10:
	{
		AFIO->EXTICR3.BF.EXTI10=PortId;
		break;
	}
	case PIN11:
	{
		AFIO->EXTICR3.BF.EXTI11=PortId;
		break;
	}
	case PIN12:
	{
		AFIO->EXTICR4.BF.EXTI12=PortId;
		break;
	}
	case PIN13:
	{
		AFIO->EXTICR4.BF.EXTI13=PortId;
		break;
	}
	case PIN14:
	{
		AFIO->EXTICR4.BF.EXTI14=PortId;
		break;
	}
	case PIN15:
	{
		AFIO->EXTICR4.BF.EXTI15=PortId;
		break;
	}
	
}
}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/