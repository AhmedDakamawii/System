/*********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Force_Sensor.c
 *  Module:  	  Force Sensor
 *
 *  Description:  Source file for Force Sensor
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Mohamed Tamer 
 *	Date:		  31/01/2024
 *********************************************************************************************************************/

/**** problems *******/


/* include LIB */
#include "Force_Sensor.h"
#include "Dio.h"



/*******************************************************************************
 * Service Name: Force_init
 * Service ID[hex]: 0x00
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Initialize force sensor (adc):
 *              - Enable gpio Bus and pin 
 *              - Enable Adc in that pin
 *******************************************************************************/
void Force_Init(void)
{
    ADC_vidInit();
    ADC_EnableState();
    ADC_vidMode();
    ADC_vidstartConversion();
}

/*******************************************************************************
 * Service Name: force_disicion 
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): boolean 1 or 0
 * Return value: None
 * Description: Function to deside that the system detect a force or not:
 *              - will give one for a force detection 
 *              - will give zero otherwise
 *******************************************************************************/
uint8 force_disicion(uint8 channel_used)
{
    uint16 TEMP=0;
    TEMP = ADC_vidRead(channel_used,ADC_7_5_CYCLE);
		//TEMP = (TEMP* 330) / 4096 ;
		/* Tamora TODO:
		YOU CAN TEST THIS BY A LED OR DEBUG BUT PLEASE USE A LED AS IN THE FUNCTION OR IN WHILE 
		34AN EL DEBUG MODE HAY3EED EL READING FAH USE LED A7SAN AND CHECK FOR HIGH OR LOW IN THE WHILE 1
		
		*/
		if (TEMP > 3000 ) 
		{
			return 1;
		}
		else
		{
			return 0;
		}

}
