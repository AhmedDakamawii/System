 /***************************************************************/
 /* Author : ahmed elsayed                                      */
 /*version:  V01                                                */
 /*Date:                                                        */ 
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h" 
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"

void STP_VoidSendSynchrouns(u8 Copy_DataToSend)
{
	u8 Local_Bit=0;
	// we should make varible s8
	for (s8 Local_s8Counter=7 ; Local_s8Counter>=0 ; Local_s8Counter--)
	{
		/* Send bit by bit of the 8 bits strating from MSb (BIT NUM 8) */
       Local_Bit= GET_BIT(Copy_DataToSend,Local_s8Counter);
	   MGPIO_VidSetPinValue(STP_SERIAL_DATA,Local_Bit);
	   		/* Send Pulse to Shift Clock */
	    MGPIO_VidSetPinValue(STP_SHIFT_CLK,1);
        MSTK_voidSetBusyWaitms(1);
	    MGPIO_VidSetPinValue(STP_SHIFT_CLK,0);
        MSTK_voidSetBusyWaitms(1);
		
	}
	/* Send Pulse to STORE Clock */
	    MGPIO_VidSetPinValue(STP_STORE_CLK,1);
        MSTK_voidSetBusyWaitms(1);
	    MGPIO_VidSetPinValue(STP_STORE_CLK,0);
        MSTK_voidSetBusyWaitms(1);

}
