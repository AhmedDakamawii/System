


#include "Can.h"


uint32(*CAN1_RX1_CallBack)(void);
/*******************************************************************************
 * Service Name: MCAN_u32FiltersEnable
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to enable Filter banks
 *******************************************************************************/
static void MCAN_u32FiltersEnable()
{
	CAN1->FA1R.BF.FACT0=Can_Filter0_Enable;
	CAN1->FA1R.BF.FACT1=Can_Filter1_Enable;
	CAN1->FA1R.BF.FACT2=Can_Filter2_Enable;
	CAN1->FA1R.BF.FACT3=Can_Filter3_Enable;
	CAN1->FA1R.BF.FACT4=Can_Filter4_Enable;
	CAN1->FA1R.BF.FACT5=Can_Filter5_Enable;
	CAN1->FA1R.BF.FACT6=Can_Filter6_Enable;
	CAN1->FA1R.BF.FACT7=Can_Filter7_Enable;
	CAN1->FA1R.BF.FACT8=Can_Filter8_Enable;
	CAN1->FA1R.BF.FACT9=Can_Filter9_Enable;
	CAN1->FA1R.BF.FACT10=Can_Filter10_Enable;
	CAN1->FA1R.BF.FACT11=Can_Filter11_Enable;
	CAN1->FA1R.BF.FACT12=Can_Filter12_Enable;
	CAN1->FA1R.BF.FACT13=Can_Filter13_Enable;

}
/*******************************************************************************
 * Service Name: MCAN_u32FiltersMode
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to choose Filter Mode
 *******************************************************************************/
static void MCAN_u32FiltersMode()
{
	CAN1->FM1R.FBM0=Can_Filter0_Mode;
	CAN1->FM1R.FBM1=Can_Filter1_Mode;
	CAN1->FM1R.FBM2=Can_Filter2_Mode;
	CAN1->FM1R.FBM3=Can_Filter3_Mode;
	CAN1->FM1R.FBM4=Can_Filter4_Mode;
	CAN1->FM1R.FBM5=Can_Filter5_Mode;
	CAN1->FM1R.FBM6=Can_Filter6_Mode;
	CAN1->FM1R.FBM7=Can_Filter7_Mode;
	CAN1->FM1R.FBM8=Can_Filter8_Mode;
	CAN1->FM1R.FBM9=Can_Filter9_Mode;
	CAN1->FM1R.FBM10=Can_Filter10_Mode;
	CAN1->FM1R.FBM11=Can_Filter11_Mode;
	CAN1->FM1R.FBM12=Can_Filter12_Mode;
	CAN1->FM1R.FBM13=Can_Filter13_Mode;

}
/*******************************************************************************
 * Service Name: MCAN_u32FiltersScale
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to choose Filter Scale
 *******************************************************************************/
static void MCAN_u32FiltersScale()
{

	CAN1->FS1R.FSC0=Can_Filter0_Scale;
	CAN1->FS1R.FSC1=Can_Filter1_Scale;
	CAN1->FS1R.FSC2=Can_Filter2_Scale;
	CAN1->FS1R.FSC3=Can_Filter3_Scale;
	CAN1->FS1R.FSC4=Can_Filter4_Scale;
	CAN1->FS1R.FSC5=Can_Filter5_Scale;
	CAN1->FS1R.FSC6=Can_Filter6_Scale;
	CAN1->FS1R.FSC7=Can_Filter7_Scale;
	CAN1->FS1R.FSC8=Can_Filter8_Scale;
	CAN1->FS1R.FSC9=Can_Filter9_Scale;
	CAN1->FS1R.FSC10=Can_Filter10_Scale;
	CAN1->FS1R.FSC11=Can_Filter11_Scale;
	CAN1->FS1R.FSC12=Can_Filter12_Scale;
	CAN1->FS1R.FSC13=Can_Filter13_Scale;

}
/*******************************************************************************
 * Service Name: MCAN_u32FiltersAssign
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to control FIFO ASSIGNMENT
 *******************************************************************************/
void MCAN_u32FiltersAssign()
{
	CAN1->FFA1R.FFA0=Can_Filter0_Assign;
	CAN1->FFA1R.FFA1=Can_Filter1_Assign;
	CAN1->FFA1R.FFA2=Can_Filter2_Assign;
	CAN1->FFA1R.FFA3=Can_Filter3_Assign;
	CAN1->FFA1R.FFA4=Can_Filter4_Assign;
	CAN1->FFA1R.FFA5=Can_Filter5_Assign;
	CAN1->FFA1R.FFA6=Can_Filter6_Assign;
	CAN1->FFA1R.FFA7=Can_Filter7_Assign;
	CAN1->FFA1R.FFA8=Can_Filter8_Assign;
	CAN1->FFA1R.FFA9=Can_Filter9_Assign;
	CAN1->FFA1R.FFA10=Can_Filter10_Assign;
	CAN1->FFA1R.FFA11=Can_Filter11_Assign;
	CAN1->FFA1R.FFA12=Can_Filter12_Assign;
	CAN1->FFA1R.FFA13=Can_Filter13_Assign;

}
/*******************************************************************************
 * Service Name: MCAN_voidSetIDs
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to choose Filters ID
 *******************************************************************************/
static void MCAN_voidSetIDs()
{
    #if Can_Filter0_Enable==Enable
	CAN1->Filter[Filter0].FR1=0;
	CAN1->Filter[Filter0].FR2=0;
CAN1->Filter[Filter0].FR1=Can_Filter0_ID1;
CAN1->Filter[Filter0].FR2=Can_Filter0_ID2;
#endif
  #if Can_Filter1_Enable==Enable
CAN1->Filter[Filter1].FR1=0;
CAN1->Filter[Filter1].FR2=0;
CAN1->Filter[Filter1].FR1=Can_Filter1_ID1;
CAN1->Filter[Filter1].FR2=Can_Filter1_ID2;
#endif
  #if Can_Filter2_Enable==Enable
CAN1->Filter[Filter2].FR1=0;
CAN1->Filter[Filter2].FR2=0;
CAN1->Filter[Filter2].FR1=Can_Filter2_ID1;
CAN1->Filter[Filter2].FR2=Can_Filter2_ID2;
#endif
  #if Can_Filter3_Enable==Enable
CAN1->Filter[Filter3].FR1=0;
CAN1->Filter[Filter3].FR2=0;
CAN1->Filter[Filter3].FR1=Can_Filter3_ID1;
CAN1->Filter[Filter3].FR2=Can_Filter3_ID2;
#endif
  #if Can_Filter4_Enable==Enable
CAN1->Filter[Filter4].FR1=0;
CAN1->Filter[Filter4].FR2=0;
CAN1->Filter[Filter4].FR1=Can_Filter4_ID1;
CAN1->Filter[Filter4].FR2=Can_Filter4_ID2;
#endif
  #if Can_Filter5_Enable==Enable
CAN1->Filter[Filter5].FR1=0;
CAN1->Filter[Filter5].FR2=0;
CAN1->Filter[Filter5].FR1=Can_Filter5_ID1;
CAN1->Filter[Filter5].FR2=Can_Filter5_ID2;
#endif
  #if Can_Filter6_Enable==Enable
CAN1->Filter[Filter6].FR1=0;
CAN1->Filter[Filter6].FR2=0;
CAN1->Filter[Filter6].FR1=Can_Filter6_ID1;
CAN1->Filter[Filter6].FR2=Can_Filter6_ID2;
#endif
  #if Can_Filter7_Enable==Enable
CAN1->Filter[Filter7].FR1=0;
CAN1->Filter[Filter7].FR2=0;
CAN1->Filter[Filter7].FR1=Can_Filter7_ID1;
CAN1->Filter[Filter7].FR2=Can_Filter7_ID2;
#endif
  #if Can_Filter8_Enable==Enable
CAN1->Filter[Filter8].FR1=0;
CAN1->Filter[Filter8].FR2=0;
CAN1->Filter[Filter8].FR1=Can_Filter8_ID1;
CAN1->Filter[Filter8].FR2=Can_Filter8_ID2;
#endif
  #if Can_Filter9_Enable==Enable
CAN1->Filter[Filter9].FR1=0;
CAN1->Filter[Filter9].FR2=0;
CAN1->Filter[Filter9].FR1=Can_Filter9_ID1;
CAN1->Filter[Filter9].FR2=Can_Filter9_ID2;
#endif
  #if Can_Filter10_Enable==Enable
CAN1->Filter[Filter10].FR1=0;
CAN1->Filter[Filter10].FR2=0;
CAN1->Filter[Filter10].FR1=Can_Filter10_ID1;
CAN1->Filter[Filter10].FR2=Can_Filter10_ID2;
#endif
  #if Can_Filter11_Enable==Enable
CAN1->Filter[Filter11].FR1=0;
CAN1->Filter[Filter11].FR2=0;
CAN1->Filter[Filter11].FR1=Can_Filter11_ID1;
CAN1->Filter[Filter11].FR2=Can_Filter11_ID2;
#endif
  #if Can_Filter12_Enable==Enable
CAN1->Filter[Filter12].FR1=0;
CAN1->Filter[Filter12].FR2=0;
CAN1->Filter[Filter12].FR1=Can_Filter12_ID1;
CAN1->Filter[Filter12].FR2=Can_Filter12_ID2;
#endif
  #if Can_Filter13_Enable==Enable
CAN1->Filter[Filter13].FR1=0;
CAN1->Filter[Filter13].FR2=0;
CAN1->Filter[Filter13].FR1=Can_Filter13_ID1;
CAN1->Filter[Filter13].FR2=Can_Filter13_ID2;
#endif
  #if Can_Filter14_Enable==Enable
CAN1->Filter[Filter14].FR1=Can_Filter14_ID1;
CAN1->Filter[Filter14].FR2=Can_Filter14_ID2;
#endif
  #if Can_Filter15_Enable==Enable
CAN1->Filter[Filter15].FR1=Can_Filter15_ID1;
CAN1->Filter[Filter15].FR2=Can_Filter15_ID2;
#endif
  #if Can_Filter16_Enable==Enable
CAN1->Filter[Filter16].FR1=Can_Filter16_ID1;
CAN1->Filter[Filter16].FR2=Can_Filter16_ID2;
#endif
  #if Can_Filter17_Enable==Enable
CAN1->Filter[Filter17].FR1=Can_Filter17_ID1;
CAN1->Filter[Filter17].FR2=Can_Filter17_ID2;
#endif
  #if Can_Filter18_Enable==Enable
CAN1->Filter[Filter18].FR1=Can_Filter18_ID1;
CAN1->Filter[Filter18].FR2=Can_Filter18_ID2;
#endif
  #if Can_Filter19_Enable==Enable
CAN1->Filter[Filter19].FR1=Can_Filter19_ID1;
CAN1->Filter[Filter19].FR2=Can_Filter19_ID2;
#endif
  #if Can_Filter20_Enable==Enable
CAN1->Filter[Filter20].FR1=Can_Filter20_ID1;
CAN1->Filter[Filter20].FR2=Can_Filter20_ID2;
#endif
  #if Can_Filter21_Enable==Enable
CAN1->Filter[Filter21].FR1=Can_Filter21_ID1;
CAN1->Filter[Filter21].FR2=Can_Filter21_ID2;
#endif
  #if Can_Filter22_Enable==Enable
CAN1->Filter[Filter22].FR1=Can_Filter22_ID1;
CAN1->Filter[Filter22].FR2=Can_Filter22_ID2;
#endif
  #if Can_Filter23_Enable==Enable
CAN1->Filter[Filter23].FR1=Can_Filter23_ID1;
CAN1->Filter[Filter23].FR2=Can_Filter23_ID2;
#endif
  #if Can_Filter24_Enable==Enable
CAN1->Filter[Filter24].FR1=Can_Filter24_ID1;
CAN1->Filter[Filter24].FR2=Can_Filter24_ID2;
#endif
  #if Can_Filter25_Enable==Enable
CAN1->Filter[Filter25].FR1=Can_Filter25_ID1;
CAN1->Filter[Filter25].FR2=Can_Filter25_ID2;
#endif
  #if Can_Filter26_Enable==Enable
CAN1->Filter[Filter26].FR1=Can_Filter26_ID1;
CAN1->Filter[Filter26].FR2=Can_Filter26_ID2;
#endif
  #if Can_Filter27_Enable==Enable
CAN1->Filter[Filter27].FR1=Can_Filter27_ID1;
CAN1->Filter[Filter27].FR2=Can_Filter27_ID2;
#endif

}
/*******************************************************************************
 * Service Name: MCAN_u8CheckReady
 * Service ID[hex]: 0x05
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): Mailbox number
 * Parameters (inout): None
 * Parameters (out): state of mailbox: Embty or not
 * Return value: None
 * Description: Function to check on availability of Mailbox
 *******************************************************************************/
uint8 MCAN_u8CheckReady(uint8 copy_u8MailBoxNum)
{

	if (copy_u8MailBoxNum ==0)
	{
		return CAN1->TSR.TME0;

	}
	else if (copy_u8MailBoxNum ==1)
	{
		return CAN1->TSR.TME1;

	}
	else if (copy_u8MailBoxNum == 2)
	{
		return CAN1->TSR.TME2;

	}else
	{
		return  Wrong_Mailbox_number_error;
	}


}
/*
 * Service Name: MCAN_voidSendMessageSingle
 * Service ID[hex]: 0x20
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): Data low, Data high,message id
 * Parameters (inout): CAN MESSAGE
 * Parameters (out): None
 * Return value: None
 * Description: Function to directly create and send a can message in one function with less parameters
 */
void MCAN_voidSendMessageSingle(uint32 copy_u32ID, uint32 copy_u32LowData, uint32 copy_u32HighData )
{
	CAN_Message msg ;
	if(CAN1->TSR.TME0 == TRANSMIT_MAILBOX_READY)
	{
		MCAN_voidCreateMessage(copy_u32ID, copy_u32LowData, copy_u32HighData , 8 ,CAN_MSG_Standard_Format,
				               CAN_MSG_DataFrame,CAN_MAILBOX0, &msg );
	}
	else if (CAN1->TSR.TME1 == TRANSMIT_MAILBOX_READY)
	{
		MCAN_voidCreateMessage(copy_u32ID, copy_u32LowData, copy_u32HighData , 8 ,CAN_MSG_Standard_Format,
				               CAN_MSG_DataFrame,CAN_MAILBOX1, &msg );
	}else
	{
		MCAN_voidCreateMessage(copy_u32ID, copy_u32LowData, copy_u32HighData , 8 ,CAN_MSG_Standard_Format,
				               CAN_MSG_DataFrame,CAN_MAILBOX2, &msg );
	}
	MCAN_voidSendMessage (&msg);

}
/*
 * Service Name: MCAN_voidSendMessageSingleGPS
 * Service ID[hex]: 0x20
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): Data low, Data high,message id
 * Parameters (inout): CAN MESSAGE
 * Parameters (out): None
 * Return value: None
 * Description: Function to directly create and send a can message in one function with less parameters
 */
void MCAN_voidSendMessageSingleGPS(uint32 copy_u32ID, uint8 *copy_u32LowData,  uint8 *copy_u32HighData)
{
	CAN_Message msg ;
	uint8 i=0;
	uint8 buffer1[4]={0};
	uint8 buffer2[4]={0};
	for(i=0;i<4;i++)
	{
	buffer1[i]=copy_u32LowData[i];
	buffer2[i]=copy_u32HighData[i];
	}
	if(CAN1->TSR.TME0 == TRANSMIT_MAILBOX_READY)
	{
		MCAN_voidCreateMessageGPS(copy_u32ID, &buffer1, &buffer2 , 8 ,CAN_MSG_Standard_Format,
				               CAN_MSG_DataFrame,CAN_MAILBOX0, &msg );
	}
	else if (CAN1->TSR.TME1 == TRANSMIT_MAILBOX_READY)
	{
		MCAN_voidCreateMessageGPS(copy_u32ID,&buffer1, &buffer2 , 8 ,CAN_MSG_Standard_Format,
				               CAN_MSG_DataFrame,CAN_MAILBOX1, &msg );
	}else
	{
		MCAN_voidCreateMessageGPS(copy_u32ID, &buffer1, &buffer2 , 8 ,CAN_MSG_Standard_Format,
				               CAN_MSG_DataFrame,CAN_MAILBOX2, &msg );
	}
	MCAN_voidSendMessage (&msg);

}
/*
 * Service Name: MCAN_voidSendMessageburst
 * Service ID[hex]: 0x21
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): Message ID ,a pointer to uint32 array containing the data , the length of the array that represents the data
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to directly create and send a can message in one function with less parameters
 */
void MCAN_voidSendMessageBurst(uint32 copy_u32ID ,uint32 * copy_u32DataArray , uint32 copy_u32DataAmount)
{uint32 counter=0 ;
		for ( counter=0 ; counter < copy_u32DataAmount ; counter++)
	{
		MCAN_voidSendMessageSingle( copy_u32ID, copy_u32DataArray[counter] , counter );
	}

}
/*******************************************************************************
 * Service Name: MCAN_voidSendMessage
 * Service ID[hex]: 0x06
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in):None
 * Parameters (inout): CAN MESSAGE
 * Parameters (out): None
 * Return value: None
 * Description: Function to set transmit mailbox to send message
 *******************************************************************************/
void MCAN_voidSendMessage (CAN_Message *msg)
{
	volatile uint8 local_mailbox_indicator = MCAN_u8CheckReady(msg->MailBoxNum);
	if( local_mailbox_indicator != Wrong_Mailbox_number_error )
	{
	if ( local_mailbox_indicator ==  TRANSMIT_MAILBOX_READY )
		{
			/*Reset the value of TIR Register*/
			CAN1->TMAILBOX[(msg->MailBoxNum)].TIR.R= 0;

			/* Reset the value of DLC bits before setting it*/
			( CAN1->TMAILBOX[(msg->MailBoxNum)].TDTR.DLC ) = 0 ;

			/* Set the Data Length Code Value */
			 CAN1->TMAILBOX[msg->MailBoxNum].TDTR.DLC =  msg->Length ;


			/* Check on the ID format Standard or Extended */
			/* Standard Format Execution program */
			if(msg->Format == CAN_MSG_Standard_Format)
			{
				   /* configure TIR for the required mail box
				   * Set the ID
				   * Set the Frame Remote Transmission Request
				   * Set the Standard Frame Format
				   */
				 CAN1->TMAILBOX[(msg->MailBoxNum)].TIR.BF.RTR=msg->Type;
				 CAN1->TMAILBOX[(msg->MailBoxNum)].TIR.BF.IDE=CAN_MSG_Standard_Format;
				 CAN1->TMAILBOX[(msg->MailBoxNum)].TIR.BF.STID=msg->ID;


			}
			/* Extended Format Execution program */
			else
			{

			}
			CAN1->TMAILBOX[((msg->MailBoxNum))].TDLR.DATA0=msg->Data[0];
			CAN1->TMAILBOX[((msg->MailBoxNum))].TDLR.DATA1=msg->Data[1];
			CAN1->TMAILBOX[((msg->MailBoxNum))].TDLR.DATA2=msg->Data[2];
			CAN1->TMAILBOX[((msg->MailBoxNum))].TDLR.DATA3=msg->Data[3];
			/* Data Input in the High Data Register */
			CAN1->TMAILBOX[((msg->MailBoxNum))].TDHR.DATA4=msg->Data[4];
			CAN1->TMAILBOX[((msg->MailBoxNum))].TDHR.DATA5=msg->Data[5];
			CAN1->TMAILBOX[((msg->MailBoxNum))].TDHR.DATA6=msg->Data[6];
			CAN1->TMAILBOX[((msg->MailBoxNum))].TDHR.DATA7=msg->Data[7];



			/* Transmit MailBox Request (Send Message) */
			 CAN1->TMAILBOX[(msg->MailBoxNum)].TIR.BF.TXRQ=1;


		}
		else
		{
			//Do Nothing
		}
	}
	else
	{
// TODO ERROR
	}



}

/*******************************************************************************
 * Service Name: MCAN_voidCreateMessage
 * Service ID[hex]: 0x07
 * Sync/Async: Synchronous
 * Reentrancy: Non Reentrant
 * Parameters (in): Data low, Data high,message id, data length, format type,mailbox number
 * Parameters (inout): CAN MESSAGE
 * Parameters (out): None
 * Return value: None
 * Description: Function to create message which is meant to be sent later
 *******************************************************************************/

void MCAN_voidCreateMessage (uint32 copy_u32ID, uint32 copy_u32LowData, uint32 copy_u32HighData, uint8 copy_u8Length, uint8 copy_u8Format,
		                     uint8 copy_u8Type, uint8 copy_u8Mailbox, CAN_Message *msg)
{
	msg->ID = copy_u32ID;
	msg->Length = copy_u8Length;
	msg->Type = copy_u8Type;
	msg->Format = copy_u8Format;
	msg->MailBoxNum = copy_u8Mailbox;

	/* the data assigned in the structure*/
	msg->Data[0] = (copy_u32LowData >> CAN_DATA_BYTE0_Shift);
	msg->Data[1] = (copy_u32LowData >> CAN_DATA_BYTE1_Shift);
	msg->Data[2] = (copy_u32LowData >> CAN_DATA_BYTE2_Shift);
	msg->Data[3] = (copy_u32LowData >> CAN_DATA_BYTE3_Shift);
	msg->Data[4] = (copy_u32HighData >> CAN_DATA_BYTE0_Shift);
	msg->Data[5] = (copy_u32HighData >> CAN_DATA_BYTE1_Shift);
	msg->Data[6] = (copy_u32HighData >> CAN_DATA_BYTE2_Shift);
	msg->Data[7] = (copy_u32HighData >> CAN_DATA_BYTE3_Shift);
}
void MCAN_voidCreateMessageGPS (uint32 copy_u32ID, uint8 *copy_u32LowData,  uint8 *copy_u32HighData, uint8 copy_u8Length, uint8 copy_u8Format,
		                     uint8 copy_u8Type, uint8 copy_u8Mailbox, CAN_Message *msg)
{
	msg->ID = copy_u32ID;
	msg->Length = copy_u8Length;
	msg->Type = copy_u8Type;
	msg->Format = copy_u8Format;
	msg->MailBoxNum = copy_u8Mailbox;

	/* the data assigned in the structure*/
	msg->Data[0] = copy_u32LowData[0] ;
	msg->Data[1] = copy_u32LowData[1] ;
	msg->Data[2] = copy_u32LowData[2] ;
	msg->Data[3] = copy_u32LowData[3];
	msg->Data[4] = copy_u32HighData[0];
	msg->Data[5] = copy_u32HighData[1];
	msg->Data[6] = copy_u32HighData[2];
	msg->Data[7] = (copy_u32HighData[3]);
}
/*******************************************************************************
 * Service Name: MCAN_voidSetUp
 * Service ID[hex]: 0x08
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set up can configuration
 *******************************************************************************/
static void MCAN_voidSetUp(void){



	CAN1->MCR.TXFP=CAN_MCR_TXFP;
	CAN1->MCR.RFLM=CAN_MCR_RFLM;
	CAN1->MCR.NART=CAN_MCR_NART;
	CAN1->MCR.AWUM=CAN_MCR_AWUM;
	CAN1->MCR.ABOM=CAN_MCR_ABOM;
	CAN1->MCR.TTCM=CAN_MCR_TTCM;
	CAN1->MCR.DBFG=CAN_MCR_DBFG;

	CAN1->IER.FMPIE0=CAN_IER_FMPIE0;
	CAN1->IER.FMPIE1=CAN_IER_FMPIE1;											
	


}

/*******************************************************************************
 * Service Name: MCAN_voidMode
 * Service ID[hex]: 0x09
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to set test mode
 *******************************************************************************/
static void MCAN_voidMode(void){

#if (Test_Mode==Enable) //if we want test mode
	{
		CAN1->BTR.R=Baud_Rate;
		CAN1->BTR.BF.LBKM=1;
		CAN1->BTR.BF.SILM=1;


	}
#elif (Test_Mode==Disable)
	{
		CAN1->BTR.R=Baud_Rate;
;

	}
#endif

}
/*******************************************************************************
 * Service Name: MCAN_voidInitMode
 * Service ID[hex]: 0x11
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to enter initialization mode
 *******************************************************************************/
static void MCAN_voidInitMode(void){

	CAN1->MCR.INRQ=CAN_MCR_INRQ;

	while(CAN1->MSR.INNAK==0 );
	CAN1->MCR.SLEEP=0;

    while (CAN1->MSR.SLAK==1);


}

/*******************************************************************************
 * Service Name: MCAN_voidStart
 * Service ID[hex]: 0x12
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to enter normal mode
 *******************************************************************************/
static void MCAN_voidStart(void){

	CAN1->MCR.INRQ=0;
	 while(CAN1->MSR.INNAK);

	 while(CAN1->MSR.SLAK);
}


/*******************************************************************************
 * Service Name: MCAN_voidFiltersInit
 * Service ID[hex]: 0x13
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to intialize filter banks
 *******************************************************************************/
static void MCAN_voidFiltersInit()
{
	CAN1->FMR.FINIT=FILTER_INIT_MODE;

CAN1->FA1R.R=Reset_Value;

MCAN_u32FiltersMode();
MCAN_u32FiltersScale();
MCAN_u32FiltersAssign();
MCAN_voidSetIDs();
MCAN_u32FiltersEnable();
CAN1->FMR.FINIT=0;


}
/*******************************************************************************
 * Service Name: MCAN_ReadMessage
 * Service ID[hex]: 0x14
 * Sync/Async: Synchronous
 * Reentrancy:  Non Reentrant
 * Parameters (in): FIFO NUMBER
 * Parameters (inout): CAN MESSAGE
 * Parameters (out): None
 * Return value: None
 * Description: Function to read message from fifo
 *******************************************************************************/
void MCAN_ReadMessage(CAN_Message * message, uint8 FIFONumber)
{
	if (FIFONumber >1)
	{
		return;
	}

	if( CAN1->FIFO[FIFONumber].RIR.IDE == CAN_MSG_Standard_Format)
	{
		message->Format= CAN_MSG_Standard_Format;
		message->ID= CAN1->FIFO[FIFONumber].RIR.IDE;

				}
	else
	{
		return;
	}
	message->Type = CAN1->FIFO[FIFONumber].RIR.RTR;
	message->FilterMatchIndex =CAN1->FIFO[FIFONumber].RDTR.FMI;
	message->Length=CAN1->FIFO[FIFONumber].RDTR.DLC;

	message->Data[0]=CAN1->FIFO[FIFONumber].RDLR.DATA0;
		message->Data[1]=CAN1->FIFO[FIFONumber].RDLR.DATA1;
		message->Data[2]=CAN1->FIFO[FIFONumber].RDLR.DATA2;
		message->Data[3]=CAN1->FIFO[FIFONumber].RDLR.DATA3;
		message->Data[4]=CAN1->FIFO[FIFONumber].RDHR.DATA4;
				message->Data[5]=CAN1->FIFO[FIFONumber].RDHR.DATA5;
				message->Data[6]=CAN1->FIFO[FIFONumber].RDHR.DATA6;
				message->Data[7]=CAN1->FIFO[FIFONumber].RDHR.DATA7;


	if(FIFONumber == 1)
	{
		CAN1->RF1R.RFOM1=1;

	}
	else
	{
		CAN1->RF0R.RFOM0=1;

	}


}
/*******************************************************************************
 * Service Name: MCAN_pendingmessagescount
 * Service ID[hex]: 0x15
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): FIFO NUMBER
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: Availability of message
 * Description: Function to check on received messages
 *******************************************************************************/
uint8 MCAN_pendingmessagescount(uint8 FIFOnumber)
{
	if(FIFOnumber>1)
	{
		return Wrong_FIFO_number_error;
	}
	else if (FIFOnumber ==1 )
	{
		return CAN1->RF1R.FMP1;

	}
	else
	{
		return CAN1->RF0R.FMP0;

	}
}
/*******************************************************************************
 * Service Name: MCAN_CANINIT
 * Service ID[hex]: 0x10
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to intialize CAN
 *******************************************************************************/
void MCAN_CANINIT()
{

	MCAN_voidSetUp();               // Setup the CAN Registers with Configurations
	MCAN_voidInitMode();  // Leave the Sleep mode and Enter The Initialization Mode 
	MCAN_voidFiltersInit();         // Initialize The Filters
	MCAN_voidMode();  // Initialize the Mode to enter Test-Mode or not
	MCAN_voidStart();		       // Leave the Initialization Mode and Enter The Normal Mode


}

CAN1_RX1_IRQHandler()
{
CAN1_RX1_CallBack();
}
void CAN1_RX1_VidSetCallBack( uint32 (*ptr) (void))
{
           CAN1_RX1_CallBack = ptr ;           
}