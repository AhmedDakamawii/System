/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Port.h
 *  Module:  	  Port
 *
 *  Description:  Header file for Port Module
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Salma Hisham
 *	Date:		  22/10/2023
 *********************************************************************************************************************/

#ifndef PORT_H_
#define PORT_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Port_Types.h"
#include "Std_Types.h"
#include "Port_Cfg.h"
#include "Dio.h"
#include "Dio_Types.h"
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Port_Remap();
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
*       1. The id of the PORT.
 *		2. The id of the pin in the PORT.
 *  	3. The direction of pin: INPUT or OUTPUT
 *  	4. The initial value of the port pin
 *  	5. The initial port pin mode
 *  	6. The internal input type: Pull up, Pull down, Analog, Input floating
 *  	7. The internal output type: push pull, Open Drain
 *  	8. The driven frequency in case of output
*******************************************************************************/
void Port_Init(const Port_configType* ConfigPtr);


void EXTI_remap(Port_PortType PortId, Port_PinType ChannelId);

#endif /*PORT_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Port.h
 *********************************************************************************************************************/
