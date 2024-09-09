 /******************************************************************************
 *
 * Module: NVIC
 *
 *	Module ID: 
 * 
 * File Name: MNVIC.c
 *
 * Description: NVIC Driver
 *
 * Author: Ahmed Sayed
 ******************************************************************************/

 #include "MNVIC_interface.h"
 #include "MNVIC_private.h"


 //#include "Det.h"

/***********************************[1]***********************************************
 * Service Name: MNVIC_SetPriorityGrouping
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): CopyU8GroupingOptions
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Set the Grouping and SubGrouping Options.
 ************************************************************************************/

#if API_ENABLE_SET_PRIORITY == API_ENABLE
void MNVIC_SetPriorityGrouping (uint32 CopyU8GroupingOptions){
#if MNVIC_DET_ENABLE==DET_ENABLE
	if (CopyU8GroupingOptions <(u32)0x5FA00300 || CopyU8GroupingOptions>0x5FA00700 )
	{
		Det_ReportError(MNVIC_MODULE_ID , ERROR_INVALID_ID);
	}
	else
#endif
	{
	SCB_AIRCR = CopyU8GroupingOptions;
	}
}
#endif

/***********************************[2]***********************************************
 * Service Name: MNVIC_EnableIRQ
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): IRQn
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Enable NVIC IRQ.
 ************************************************************************************/

#if API_ENABLE_ENABLE_IRQ == API_ENABLE
void MNVIC_EnableIRQ(uint8 IRQn){

#if MNVIC_DET_ENABLE==DET_ENABLE
	if (IRQn <(u8)0 || IRQn>(u8)59 )
	{
		Det_ReportError(MNVIC_MODULE_ID , ERROR_INVALID_ID);
	}
	else
#endif
	{
		/*switch case for the peripheral  that need to be enabled*/
		switch(IRQn)
		{
         case 0:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN0 =1;
		 break;
		 case 1:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN1 =1;
		 break;
		 case 2:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN2 =1;
		 break;
		 case 3:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN3 =1;
		 break;
		 case 4:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN4 =1;
		 break;
		 case 5:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN5 =1;
		 break;
		 case 6:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN6 =1;
		 break;
		 case 7:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN7 =1;
		 break;
		 case 8:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN8 =1;
		 break;
		 case 9:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN9 =1;
		 break;
		 case 10:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN10 =1;
		 break;
		 case 11:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN11 =1;
		 break;
		 case 12:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN12 =1;
		 break;
		 case 13:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN13 =1;
		 break;
		 case 14:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN14 =1;
		 break;
		 case 15:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN15 =1;
		 break;
		 case 16:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN16 =1;
		 break;
		 case 17:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN17 =1;
		 break;
		 case 18:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN18 =1;
		 break;
		 case 19:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN19 =1;
		 break;
		 case 20:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN20 =1;
		 break;
		 case 21:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN21 =1;
		 break;
		 case 22:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN22 =1;
		 break;
		 case 23:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN23 =1;
		 break;
		 case 24:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN24 =1;
		 break;
         case 25:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN25 =1;
		 break;
		 case 26:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN26 =1;
		 break;
		 case 27:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN27 =1;
		 break;
		 case 28:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN28 =1;
		 break;
		 case 29:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN29 =1;
		 break;
		 case 30:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN30 =1;
		 break;
		 case 31:
		 MNVIC->ISER0.BF.SET_ENABLE0_BIN31 =1;
		 break;
		 case 32:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN0 =1;
		 break;
         case 33:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN1 =1;
		 break;
         case 34:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN2 =1;
		 break;
         case 35:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN3 =1;
		 break;
         case 36:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN4 =1;
		 break;
         case 37:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN5 =1;
		 break;
         case 38:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN6 =1;
		 break;
         case 39:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN7 =1;
		 break;
         case 40:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN8 =1;
		 break;
         case 41:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN9 =1;
		 break;
         case 42:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN10 =1;
		 break;
         case 43:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN11 =1;
		 break;
         case 44:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN12 =1;
		 break;
         case 45:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN13 =1;
		 break;
         case 46:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN14 =1;
		 break;
         case 47:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN15 =1;
		 break;
         case 48:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN16 =1;
		 break;
         case 49:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN17 =1;
		 break;
         case 50:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN18 =1;
		 break;
         case 51:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN19 =1;
		 break;
         case 52:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN20 =1;
		 break;
         case 53:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN21 =1;
		 break;
         case 54:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN22 =1;
		 break;
         case 55:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN23 =1;
		 break;
         case 56:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN24 =1;
		 break;
         case 57:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN25 =1;
		 break;
         case 58:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN26 =1;
		 break;
         case 59:
		 MNVIC->ISER1.BF.SET_ENABLE1_BIN27 =1;
		 break;
                 
		}
       
	}

}
#endif

/***********************************[3]***********************************************
 * Service Name: MNVIC_DisableIRQ
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): IRQn
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Disable NVIC IRQ.
 ************************************************************************************/

#if API_ENABLE_DISABLE_IRQ == API_ENABLE
void MNVIC_DisableIRQ(uint8 IRQn){

#if MNVIC_DET_ENABLE==DET_ENABLE
	if (IRQn <(u8)0 || IRQn>(u8)59 )
	{
		Det_ReportError(MNVIC_MODULE_ID , ERROR_INVALID_ID);
	}
	else
#endif
	{
		/*switch case for the peripheral  that need to be disabled*/
	    switch(IRQn)
		{
         case 0:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN0 =1;
		 break;
		 case 1:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN1 =1;
		 break;
		 case 2:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN2 =1;
		 break;
		 case 3:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN3 =1;
		 break;
		 case 4:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN4 =1;
		 break;
		 case 5:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN5 =1;
		 break;
		 case 6:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN6 =1;
		 break;
		 case 7:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN7 =1;
		 break;
		 case 8:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN8 =1;
		 break;
		 case 9:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN9 =1;
		 break;
		 case 10:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN10 =1;
		 break;
		 case 11:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN11 =1;
		 break;
		 case 12:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN12 =1;
		 break;
		 case 13:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN13 =1;
		 break;
		 case 14:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN14 =1;
		 break;
		 case 15:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN15 =1;
		 break;
		 case 16:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN16 =1;
		 break;
		 case 17:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN17 =1;
		 break;
		 case 18:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN18 =1;
		 break;
		 case 19:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN19 =1;
		 break;
		 case 20:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN20 =1;
		 break;
		 case 21:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN21 =1;
		 break;
		 case 22:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN22 =1;
		 break;
		 case 23:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN23 =1;
		 break;
		 case 24:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN24 =1;
		 break;
        case 25:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN25 =1;
		 break;
		 case 26:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN26 =1;
		 break;
		 case 27:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN27 =1;
		 break;
		 case 28:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN28 =1;
		 break;
		 case 29:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN29 =1;
		 break;
		 case 30:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN30 =1;
		 break;
		 case 31:
		 MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN31 =1;
		 break;
         case 32:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN0 =1;
		 break;
         case 33:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN1 =1;
		 break;
         case 34:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN2 =1;
		 break;
         case 35:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN3 =1;
		 break;
         case 36:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN4 =1;
		 break;
         case 37:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN5 =1;
		 break;
         case 38:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN6 =1;
		 break;
         case 39:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN7 =1;
		 break;
         case 40:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN8 =1;
		 break;
         case 41:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN9 =1;
		 break;
         case 42:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN10 =1;
		 break;
         case 43:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN11 =1;
		 break;
         case 44:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN12 =1;
		 break;
         case 45:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN13 =1;
		 break;
         case 46:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN14 =1;
		 break;
         case 47:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN15 =1;
		 break;
         case 48:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN16 =1;
		 break;
         case 49:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN17 =1;
		 break;
         case 50:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN18 =1;
		 break;
         case 51:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN19 =1;
		 break;
         case 52:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN20 =1;
		 break;
         case 53:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN21 =1;
		 break;
         case 54:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN22 =1;
		 break;
         case 55:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN23 =1;
		 break;
         case 56:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN24 =1;
		 break;
         case 57:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN25 =1;
		 break;
         case 58:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN26 =1;
		 break;
         case 59:
		 MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN27 =1;
		 break;
          		 
		}
      
	}
	}


#endif

/***********************************[4]***********************************************
 * Service Name: MNVIC_GetPendingIRQ
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): IRQn
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: Pending Flag IRQ Status
 * Description: Get Pending Flag value.
 ************************************************************************************/

#if API_ENABLE_Get_Pending_IRQ == API_ENABLE
uint32 MNVIC_GetPendingIRQ (uint8 IRQn) 				//Return true(IRQ-Number) if IRQn is pending
{

#if MNVIC_DET_ENABLE==DET_ENABLE
	if (IRQn <(u8)0 || IRQn>(u8)59 )
	{
		Det_ReportError(MNVIC_MODULE_ID , ERROR_INVALID_ID);
	}
	else
	
#endif

	{
		/*switch case for the pending peripheral to be known*/

		switch(IRQn)
		{
         case 0:
		return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN0 ;
		 break;
		 case 1:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN1 ;
		 break;
		 case 2:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN2 ;
		 break;
		 case 3:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN3 ;
		 break;
		 case 4:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN4 ;
		 break;
		 case 5:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN5 ;
		 break;
		 case 6:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN6 ;
		 break;
		 case 7:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN7 ;
		 break;
		 case 8:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN8 ;
		 break;
		 case 9:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN9 ;
		 break;
		 case 10:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN10 ;
		 break;
		 case 11:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN11 ;
		 break;
		 case 12:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN12 ;
		 break;
		 case 13:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN13 ;
		 break;
		 case 14:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN14 ;
		 break;
		 case 15:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN15 ;
		 break;
		 case 16:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN16 ;
		 break;
		 case 17:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN17 ;
		 break;
		 case 18:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN18 ;
		 break;
		 case 19:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN19 ;
		 break;
		 case 20:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN20 ;
		 break;
		 case 21:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN21 ;
		 break;
		 case 22:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN22 ;
		 break;
		 case 23:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN23 ;
		 break;
		 case 24:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN24 ;
		 break;
        case 25:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN25 ;
		 break;
		 case 26:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN26 ;
		 break;
		 case 27:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN27 ;
		 break;
		 case 28:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN28 ;
		 break;
		 case 29:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN29 ;
		 break;
		 case 30:
		 return MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN30 ;
		 break;
		 case 31:
		 return  MNVIC->ICER0.BF.CLEAR_ENABLE0_BIN31 ;
		 break;
	     case 32:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN0;
		 break;
         case 33:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN1;
		 break;
         case 34:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN2;
		 break;
         case 35:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN3;
		 break;
         case 36:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN4;
		 break;
         case 37:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN5;
		 break;
         case 38:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN6;
		 break;
         case 39:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN7;
		 break;
         case 40:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN8;
		 break;
         case 41:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN9;
		 break;
         case 42:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN10;
		 break;
         case 43:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN11;
		 break;
         case 44:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN12;
		 break;
         case 45:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN13;
		 break;
         case 46:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN14;
		 break;
         case 47:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN15;
		 break;
         case 48:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN16;
		 break;
         case 49:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN17;
		 break;
         case 50:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN18;
		 break;
         case 51:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN19;
		 break;
         case 52:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN20;
		 break;
         case 53:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN21;
		 break;
         case 54:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN22;
		 break;
         case 55:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN23;
		 break;
         case 56:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN24;
		 break;
         case 57:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN25;
		 break;
         case 58:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN26;
		 break;
         case 59:
		 return MNVIC->ICER1.BF.CLEAR_ENABLE1_BIN27;
		 break;
          		 

		}	
	}


}
#endif

/***********************************[5]***********************************************
 * Service Name: MNVIC_SetPendingIRQ
 * Service ID[hex]: 0x05
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): IRQn
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Set Pending Flag.
 ************************************************************************************/
#if API_ENABLE_SET_PENDING_IRQ == API_ENABLE
void MNVIC_SetPendingIRQ (uint8 IRQn)
{
#if MNVIC_DET_ENABLE == DET_ENABLE
	if (IRQn <(u8)0 || IRQn>(u8)59 )
	{
		Det_ReportError(MNVIC_MODULE_ID , ERROR_INVALID_ID);
	}
	else
#endif
	{
		/*switch case for the pending peripheral to be enabled*/
		switch(IRQn)
		{
         case 0:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN0 =1;
		 break;
		 case 1:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN1 =1;
		 break;
		 case 2:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN2 =1;
		 break;
		 case 3:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN3 =1;
		 break;
		 case 4:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN4 =1;
		 break;
		 case 5:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN5 =1;
		 break;
		 case 6:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN6 =1;
		 break;
		 case 7:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN7 =1;
		 break;
		 case 8:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN8 =1;
		 break;
		 case 9:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN9 =1;
		 break;
		 case 10:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN10 =1;
		 break;
		 case 11:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN11 =1;
		 break;
		 case 12:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN12 =1;
		 break;
		 case 13:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN13 =1;
		 break;
		 case 14:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN14 =1;
		 break;
		 case 15:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN15 =1;
		 break;
		 case 16:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN16 =1;
		 break;
		 case 17:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN17 =1;
		 break;
		 case 18:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN18 =1;
		 break;
		 case 19:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN19 =1;
		 break;
		 case 20:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN20 =1;
		 break;
		 case 21:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN21 =1;
		 break;
		 case 22:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN22 =1;
		 break;
		 case 23:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN23 =1;
		 break;
		 case 24:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN24 =1;
		 break;
        case 25:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN25 =1;
		 break;
		 case 26:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN26 =1;
		 break;
		 case 27:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN27 =1;
		 break;
		 case 28:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN28 =1;
		 break;
		 case 29:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN29 =1;
		 break;
		 case 30:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN30 =1;
		 break;
		 case 31:
		 MNVIC->ISPR0.BF.SET_PENDING0_BIN31 =1;
		 break;
         case 32:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN0 =1;
		 break;
         case 33:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN1 =1;
		 break;
         case 34:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN2 =1;
		 break;
         case 35:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN3 =1;
		 break;
         case 36:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN4 =1;
		 break;
         case 37:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN5 =1;
		 break;
         case 38:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN6 =1;
		 break;
         case 39:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN7 =1;
		 break;
         case 40:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN8 =1;
		 break;
         case 41:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN9 =1;
		 break;
         case 42:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN10 =1;
		 break;
         case 43:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN11 =1;
		 break;
         case 44:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN12 =1;
		 break;
         case 45:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN13 =1;
		 break;
         case 46:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN14 =1;
		 break;
         case 47:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN15 =1;
		 break;
         case 48:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN16 =1;
		 break;
         case 49:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN17 =1;
		 break;
         case 50:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN18 =1;
		 break;
         case 51:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN19 =1;
		 break;
         case 52:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN20 =1;
		 break;
         case 53:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN21 =1;
		 break;
         case 54:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN22 =1;
		 break;
         case 55:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN23 =1;
		 break;
         case 56:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN24 =1;
		 break;
         case 57:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN25 =1;
		 break;
         case 58:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN26 =1;
		 break;
         case 59:
		 MNVIC->ISPR1.BF.SET_PENDING1_BIN27 =1;
		 break;

		}
	}
}
#endif

/***********************************[6]***********************************************
 * Service Name: MNVIC_ClearPendingIRQ
 * Service ID[hex]: 0x06
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): IRQn
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Clear Pending Flag.
 ************************************************************************************/

#if API_ENABLE_CLEAR_PENDING_IRQ == API_ENABLE
void MNVIC_ClearPendingIRQ (uint8 IRQn)
{

#if MNVIC_DET_ENABLE == DET_ENABLE
	if (IRQn <(u8)0 || IRQn>(u8)59 )
	{
		Det_ReportError(MNVIC_MODULE_ID , ERROR_INVALID_ID);
	}
	else
#endif
	{
	/*switch case for the pending peripheral to be disabled*/

		switch(IRQn)
		{
         case 0:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN0 =1;
		 break;
		 case 1:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN1 =1;
		 break;
		 case 2:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN2 =1;
		 break;
		 case 3:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN3 =1;
		 break;
		 case 4:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN4 =1;
		 break;
		 case 5:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN5 =1;
		 break;
		 case 6:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN6 =1;
		 break;
		 case 7:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN7 =1;
		 break;
		 case 8:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN8 =1;
		 break;
		 case 9:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN9 =1;
		 break;
		 case 10:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN10 =1;
		 break;
		 case 11:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN11 =1;
		 break;
		 case 12:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN12 =1;
		 break;
		 case 13:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN13 =1;
		 break;
		 case 14:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN14 =1;
		 break;
		 case 15:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN15 =1;
		 break;
		 case 16:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN16 =1;
		 break;
		 case 17:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN17 =1;
		 break;
		 case 18:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN18 =1;
		 break;
		 case 19:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN19 =1;
		 break;
		 case 20:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN20 =1;
		 break;
		 case 21:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN21 =1;
		 break;
		 case 22:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN22 =1;
		 break;
		 case 23:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN23 =1;
		 break;
		 case 24:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN24 =1;
		 break;
        case 25:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN25 =1;
		 break;
		 case 26:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN26 =1;
		 break;
		 case 27:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN27 =1;
		 break;
		 case 28:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN28 =1;
		 break;
		 case 29:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN29 =1;
		 break;
		 case 30:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN30 =1;
		 break;
		 case 31:
		 MNVIC->ICPR0.BF.CLEAR_PENDING0_BIN31 =1;
		 break;
	     case 32:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN0 =1;
		 break;
         case 33:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN1 =1;
		 break;
         case 34:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN2 =1;
		 break;
         case 35:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN3 =1;
		 break;
         case 36:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN4 =1;
		 break;
         case 37:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN5 =1;
		 break;
         case 38:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN6 =1;
		 break;
         case 39:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN7 =1;
		 break;
         case 40:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN8 =1;
		 break;
         case 41:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN9 =1;
		 break;
         case 42:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN10 =1;
		 break;
         case 43:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN11 =1;
		 break;
         case 44:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN12 =1;
		 break;
         case 45:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN13 =1;
		 break;
         case 46:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN14 =1;
		 break;
         case 47:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN15 =1;
		 break;
         case 48:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN16 =1;
		 break;
         case 49:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN17 =1;
		 break;
         case 50:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN18 =1;
		 break;
         case 51:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN19 =1;
		 break;
         case 52:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN20 =1;
		 break;
         case 53:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN21 =1;
		 break;
         case 54:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN22 =1;
		 break;
         case 55:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN23 =1;
		 break;
         case 56:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN24 =1;
		 break;
         case 57:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN25 =1;
		 break;
         case 58:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN26 =1;
		 break;
         case 59:
		 MNVIC->ICPR1.BF.CLEAR_PENDING1_BIN27 =1;
		 break;

		}
	}
}
#endif

/***********************************[7]***********************************************
 * Service Name: MNVIC_GetActive
 * Service ID[hex]: 0x07
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): IRQn
 * Parameters (InOut): None
 * Parameters (Out): uint32
 * Return value: uint32
 * Description: Get IRQ Active Flag Status.
 ************************************************************************************/

#if API_ENABLE_GET_ACTIVE_IRQ == API_ENABLE
uint32 MNVIC_GetActive (uint8 IRQn)
{
#if MNVIC_DET_ENABLE == DET_ENABLE
	if (IRQn <(u8)0 || IRQn>(u8)59 )
	{
		Det_ReportError(MNVIC_MODULE_ID , ERROR_INVALID_ID);
	}
	else
#endif
	{
	/*switch case for the active flag to be known*/
		switch(IRQn)
		{
         case 0:
		return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN0 ;
		 break;
		 case 1:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN1 ;
		 break;
		 case 2:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN2 ;
		 break;
		 case 3:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN3 ;
		 break;
		 case 4:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN4 ;
		 break;
		 case 5:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN5 ;
		 break;
		 case 6:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN6 ;
		 break;
		 case 7:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN7 ;
		 break;
		 case 8:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN8 ;
		 break;
		 case 9:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN9 ;
		 break;
		 case 10:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN10 ;
		 break;
		 case 11:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN11 ;
		 break;
		 case 12:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN12 ;
		 break;
		 case 13:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN13 ;
		 break;
		 case 14:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN14 ;
		 break;
		 case 15:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN15 ;
		 break;
		 case 16:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN16 ;
		 break;
		 case 17:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN17 ;
		 break;
		 case 18:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN18 ;
		 break;
		 case 19:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN19 ;
		 break;
		 case 20:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN20 ;
		 break;
		 case 21:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN21 ;
		 break;
		 case 22:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN22 ;
		 break;
		 case 23:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN23 ;
		 break;
		 case 24:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN24 ;
		 break;
        case 25:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN25 ;
		 break;
		 case 26:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN26 ;
		 break;
		 case 27:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN27 ;
		 break;
		 case 28:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN28 ;
		 break;
		 case 29:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN29 ;
		 break;
		 case 30:
		 return MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN30 ;
		 break;
		 case 31:
		 return  MNVIC->IABR0.BF.ACTIVE_FLAGES0_BIN31 ;
		 break;
		case 32:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN0;
		 break;
         case 33:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN1;
		 break;
         case 34:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN2;
		 break;
         case 35:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN3;
		 break;
         case 36:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN4;
		 break;
         case 37:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN5;
		 break;
         case 38:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN6;
		 break;
         case 39:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN7;
		 break;
         case 40:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN8;
		 break;
         case 41:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN9;
		 break;
         case 42:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN10;
		 break;
         case 43:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN11;
		 break;
         case 44:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN12;
		 break;
         case 45:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN13;
		 break;
         case 46:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN14;
		 break;
         case 47:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN15;
		 break;
         case 48:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN16;
		 break;
         case 49:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN17;
		 break;
         case 50:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN18;
		 break;
         case 51:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN19;
		 break;
         case 52:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN20;
		 break;
         case 53:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN21;
		 break;
         case 54:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN22;
		 break;
         case 55:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN23;
		 break;
         case 56:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN24;
		 break;
         case 57:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN25;
		 break;
         case 58:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN26;
		 break;
         case 59:
		 return MNVIC->IABR1.BF.ACTIVE_FLAGES1_BIN27;
		 break;
        
		}
	}

}
#endif

/***********************************[8]***********************************************
 * Service Name: MNVIC_SetPriority
 * Service ID[hex]: 0x08
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): IRQn
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Set IRQ Priority.
 ************************************************************************************/

#if API_ENABLE_SET_PRIORITY == API_ENABLE
void   MNVIC_SetPriority (uint8 IRQn, uint8 CopyU8Priority)
{
#if MNVIC_DET_ENABLE == DET_ENABLE
	if (IRQn <(u8)0 || IRQn>(u8)59 )
	{
		Det_ReportError(MNVIC_MODULE_ID , ERROR_INVALID_ID);
	}
	else
#endif
	
	{
		CopyU8Priority = CopyU8Priority << 4;/*shift the prority number*/
	/*switch case for the peripheral to assign the priority*/

		switch (IRQn)
		{
		case 0:
		MNVIC->IPR0.BF.IP0_0 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;

		case 1 :
		MNVIC->IPR0.BF.IP0_1 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;

	    case 2 :
		MNVIC->IPR0.BF.IP0_2 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;

	    case 3 :
		MNVIC->IPR0.BF.IP0_3 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 4 :
		MNVIC->IPR1.BF.IP1_0 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 5 :
		MNVIC->IPR1.BF.IP1_1 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 6 :
		MNVIC->IPR1.BF.IP1_2 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 7 :
				
		MNVIC->IPR1.BF.IP1_3  =CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 8 :
		MNVIC->IPR2.BF.IP2_0 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 9 :
		MNVIC->IPR2.BF.IP2_1 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 10 :
		MNVIC->IPR2.BF.IP2_2 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 11 :
		MNVIC->IPR2.BF.IP2_3 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 12 :
		MNVIC->IPR3.BF.IP3_0 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 13 :
		MNVIC->IPR3.BF.IP3_1 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 14 :
		MNVIC->IPR3.BF.IP3_2 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 15 :
		MNVIC->IPR3.BF.IP3_3 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 16 :
		MNVIC->IPR4.BF.IP4_0 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 17 :
		MNVIC->IPR4.BF.IP4_1 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 18 :
		MNVIC->IPR4.BF.IP4_2 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 19 :
		MNVIC->IPR4.BF.IP4_3 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 20 :
		MNVIC->IPR5.BF.IP5_0 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 21 :
		MNVIC->IPR5.BF.IP5_1 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 22 :
		MNVIC->IPR5.BF.IP5_2 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 23 :
		MNVIC->IPR5.BF.IP5_3 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 24 :
		MNVIC->IPR6.BF.IP6_0 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
		case 25 :
		MNVIC->IPR6.BF.IP6_1 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
		case 26 :
		MNVIC->IPR6.BF.IP6_2 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
		case 27 :
		MNVIC->IPR6.BF.IP6_3 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
		case 28 :
		MNVIC->IPR7.BF.IP7_0 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;

		case 37 :
		MNVIC->IPR9.BF.IP9_1 = CopyU8Priority ;/*Assign Priority to MSB of IRQ Eight Bits " UART "*/
		break;
		}
		
	}

}
#endif
/***********************************[9]***********************************************
 * Service Name: MNVIC_GetPriority
 * Service ID[hex]: 0x09
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): IRQn
 * Parameters (InOut): None
 * Parameters (Out): uint32
 * Return value: uint32
 * Description: Get IRQ Priority.
 ************************************************************************************/
#if API_ENABLE_GET_PRIORITY == API_ENABLE
uint32 MNVIC_GetPriority (uint8 IRQn)
{
#if MNVIC_DET_ENABLE == DET_ENABLE
	if (IRQn <(u8)0 || IRQn>(u8)59 )
	{
		Det_ReportError(MNVIC_MODULE_ID , ERROR_INVALID_ID)
	}
	else
#endif
	{
	/*switch case for the peripheral to get the priority*/

				switch (IRQn)
		{
		case 0:
		return MNVIC->IPR0.BF.IP0_0;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;

		case 1 :
		return MNVIC->IPR0.BF.IP0_1;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;

	    case 2 :
		return MNVIC->IPR0.BF.IP0_2;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;

	    case 3 :
		return MNVIC->IPR0.BF.IP0_3;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 4 :
		return MNVIC->IPR1.BF.IP1_0;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 5 :
		return MNVIC->IPR1.BF.IP1_1;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 6 :
		return MNVIC->IPR1.BF.IP1_2;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 7 :
		return MNVIC->IPR1.BF.IP1_3;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 8 :
		return MNVIC->IPR2.BF.IP2_0;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 9 :
		return MNVIC->IPR2.BF.IP2_1;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 10 :
		return MNVIC->IPR2.BF.IP2_2;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 11 :
		return MNVIC->IPR2.BF.IP2_3;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 12 :
		return MNVIC->IPR3.BF.IP3_0;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 13 :
		return MNVIC->IPR3.BF.IP3_1;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 14 :
		return MNVIC->IPR3.BF.IP3_2;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 15 :
		return MNVIC->IPR3.BF.IP3_3;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 16 :
		return MNVIC->IPR4.BF.IP4_0;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 17 :
		return MNVIC->IPR4.BF.IP4_1;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 18 :
		return MNVIC->IPR4.BF.IP4_2;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 19 :
		return MNVIC->IPR4.BF.IP4_3;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 20 :
		return MNVIC->IPR5.BF.IP5_0;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 21 :
		return MNVIC->IPR5.BF.IP5_1;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 22 :
		return MNVIC->IPR5.BF.IP5_2;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 23 :
		return MNVIC->IPR5.BF.IP5_3;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
	    case 24 :
		return MNVIC->IPR6.BF.IP6_0;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
		case 25 :
		return MNVIC->IPR6.BF.IP6_1;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
		case 26 :
		return MNVIC->IPR6.BF.IP6_2;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
		case 27 :
		return MNVIC->IPR6.BF.IP6_3  ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		
		case 28 :
		return MNVIC->IPR7.BF.IP7_0 ;/*Assign Priority to MSB of IRQ Eight Bits*/
		break;
		}
	}
}
#endif

/***********************************[10]***********************************************
 * Service Name: MNVIC_SystemReset
 * Service ID[hex]: 0x0A
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): None
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Reset System.
 ************************************************************************************/

#if API_ENABLE_SYSTEM_RESET == API_ENABLE
void MNVIC_SystemReset (void)
{
	SET_BIT(SCB_AIRCR,SYSRESETREQ);
}
#endif
