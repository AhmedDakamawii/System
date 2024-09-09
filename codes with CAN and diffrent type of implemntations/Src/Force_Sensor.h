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

#ifndef FORCE_SENSOR_H_
#define FORCE_SENSOR_H_

#include "MADC_interface.h"
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
void Force_Init(void);
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
uint8 force_disicion(uint8 channel_used);

#endif /* FORCE_SENSOR_H_ */
/**********************************************************************************************************************
 *  END OF FILE: Force sensor
 *********************************************************************************************************************/