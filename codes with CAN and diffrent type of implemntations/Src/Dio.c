/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Dio.c
 *  Module:  	  Dio
 *
 *  Description:  Source file for Dio Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Omar Tolba
 *	Date:		  27/9/2022
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Macros.h"
#include "Dio.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/*******************************************************************************
 * Service Name: Dio_WriteChannel
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in):  Port - Dio_PortType, Pin - Dio_PinType , Value -Dio_LevelType 
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Dio_LevelType
 * Description: Function for DIO Write Channel API
 *******************************************************************************/
void Dio_WriteChannel(Dio_PortType Port, Dio_PinType Pin, Dio_LevelType Value)
{
	switch (Port)
	{
	/*	Writing On PortA*/
	case PORTA:
		if (Value == DIO_LEVEL_HIGH)
		{
			MGPIOA->BSRR.REG = (1 << Pin);
		}
		else if (Value == DIO_LEVEL_LOW)
		{
			MGPIOA->BRR.REG = (1 << Pin);
		}
		break;

		/*	Writing On PortB*/
	case PORTB:
		if (Value == DIO_LEVEL_HIGH)
		{
			MGPIOB->BSRR.REG = (1 << Pin);
		}
		else if (Value == DIO_LEVEL_LOW)
		{
			MGPIOB->BRR.REG = (1 << Pin);
		}
		break;

		/*	Writing On PortC*/
	case PORTC:
		if (Value == DIO_LEVEL_HIGH)
		{
			MGPIOC->BSRR.REG = (1 << Pin);
		}
		else if (Value == DIO_LEVEL_LOW)
		{
			MGPIOC->BRR.REG = (1 << Pin);
		}
		break;
	}
}

/*******************************************************************************
 * Service Name: Dio_ReadChannel
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Port - Dio_PortType , Pin - Dio_PinType 
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Dio_LevelType
 * Description: Function for DIO read Channel API
 *******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_PortType Port, Dio_PinType Pin)
{
	switch (Port)
	{
	case PORTA:
		if (GET_BIT(MGPIOA->IDR.REG, Pin) == 1)
		{
			return DIO_LEVEL_HIGH;
		}
		else
		{
			return DIO_LEVEL_LOW;
		}
		break;

	case PORTB:
		if (GET_BIT(MGPIOB->IDR.REG, Pin) == 1)
		{
			return DIO_LEVEL_HIGH;
		}
		else
		{
			return DIO_LEVEL_LOW;
		}
		break;

	case PORTC:
		if(GET_BIT(MGPIOC->IDR.REG, Pin)==1)
		{
			return DIO_LEVEL_HIGH;
		}else
		{
			return DIO_LEVEL_LOW;
		}
		break;
	}
	return DIO_LEVEL_ERROR; /* Unreachable */
}

/*******************************************************************************
 * Service Name: Dio_ReadPort
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Port - Dio_PortType
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Dio_LevelType
 * Description: Function for DIO read Port API
 *******************************************************************************/
uint32 Dio_ReadPort(Dio_PortType Port)
{
	/*Local variable to hold Port value */
	uint32 portValue = 0;
	switch (Port)
	{
	case PORTA:
		portValue = MGPIOA->IDR.REG;
		break;

	case PORTB:
		portValue = MGPIOB->IDR.REG;
		break;

	case PORTC:
		portValue = MGPIOC->IDR.REG;
		break;
	}
	return portValue;
}

/*******************************************************************************
 * Service Name: Dio_WritePort
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Port - Dio_PortType, Value - uint8
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Dio_LevelType
 * Description: Function for DIO Write Port API
 *******************************************************************************/
void Dio_WritePort(Dio_PortType Port, uint32 value)
{
	switch (Port)
	{
	case PORTA:
		MGPIOA->ODR.REG = value;
		break;

	case PORTB:
		MGPIOB->ODR.REG = value;
		break;

	case PORTC:
		MGPIOC->ODR.REG = value;
		break;
	}
}

/*******************************************************************************
 * Service Name: Dio_FlipChannel
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): ChannelId - Dio_ChannelType
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Dio_LevelType
 * Description: Function for DIO flip Channel, then read Channel API
 *******************************************************************************/
Dio_LevelType Dio_FlipChannel(Dio_PortType PortId, Dio_PinType ChannelId)
{
	if (ChannelId >= NUM_CONFIGURED_CHANNELS)
	{
		return DIO_LEVEL_ERROR;
	}

	switch (PortId)
	{
	case PORTA:
		if (GET_BIT(MGPIOA->ODR.REG,ChannelId) == DIO_LEVEL_HIGH)
		{
			MGPIOA->BRR.REG = (1 << ChannelId);
			return DIO_LEVEL_LOW;
		}
		else if (GET_BIT(MGPIOA->ODR.REG,ChannelId) == DIO_LEVEL_LOW)
		{
			MGPIOA->BSRR.REG = (1 << ChannelId);
			return DIO_LEVEL_HIGH;
		}
		break;
	case PORTB:
		if (GET_BIT(MGPIOB->ODR.REG,ChannelId) == DIO_LEVEL_HIGH)
		{
			MGPIOB->BRR.REG = (1 << ChannelId);
			return DIO_LEVEL_LOW;
		}
		else if (GET_BIT(MGPIOB->ODR.REG,ChannelId) == DIO_LEVEL_LOW)
		{
			MGPIOB->BSRR.REG = (1 << ChannelId);
			return DIO_LEVEL_HIGH;
		}
		break;
	case PORTC:
		if (GET_BIT(MGPIOC->ODR.REG,ChannelId) == DIO_LEVEL_HIGH)
		{
			MGPIOC->BRR.REG = (1 << ChannelId);
			return DIO_LEVEL_LOW;
		}
		else if (GET_BIT(MGPIOC->ODR.REG,ChannelId) == DIO_LEVEL_LOW)
		{
			MGPIOC->BSRR.REG = (1 << ChannelId);
			return DIO_LEVEL_HIGH;
		}
		break;
	}
}
/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/