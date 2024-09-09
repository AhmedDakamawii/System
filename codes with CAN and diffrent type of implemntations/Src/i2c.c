/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  I2C.c
 *  Module:  	  I2C
 *  Description:  Source File for I2C
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Mohamed Yehia + Ahmed Sayed
 *	Date:		  18/10/2023
 *********************************************************************************************************************/

/******************************************************************************
 *                             Includes                                        *
 ******************************************************************************/

#include "i2c.h"




#define F_CPU               8000000

uint8 rxComplt=0;


uint32 TxLen; /* !< To store Tx len > */
uint32 RxLen; /* !< To store Rx len > */
uint8  TxRxState; /* !< To store Communication state > */
uint8  DevAddr; /* !< To store slave/device address > */
uint32 RxSize; /* !< To store Rx size  > */
uint8 *pRxBuffer; /* !< To store the app. Rx buffer address > */
uint8  pTxBuffer; /* !< To store the app. Tx buffer address > */


static void I2C_ClearADDRFlag(I2C_ID i2cid)
{

	volatile I2C *i2cptr = NULL_PTR;
	switch (i2cid)
	{
	case I2C1:
		i2cptr = MI2C1;
		break;

	case I2C2:
		i2cptr = MI2C2;
		break;
	}

	uint32 dummy_read;

	//check for device mode
	if(i2cptr->SR2.BF.MSL == 1)
	{
		//device is in master mode
		if( TxRxState == I2C_BUSY_IN_RX)
		{
			if( RxSize  == 1)
			{
				//first disable the ack
				i2cptr->CR1.BF.ACK = DISABLE;

				//clear the ADDR flag ( read SR1 , read SR2)
				dummy_read = i2cptr->SR1.Reg;
				dummy_read = i2cptr->SR2.Reg;
				(void)dummy_read;
			}

		}
		else if(TxRxState == I2C_BUSY_IN_TX)
		{
			//clear the ADDR flag ( read SR1 , read SR2)
			dummy_read = i2cptr->SR1.Reg;
			dummy_read = i2cptr->SR2.Reg;
			(void) dummy_read;
		}

	}

}


/*********************************************************************
 * @fn      		  - I2C_Init
 *
 * @brief             -
 *
 * @param[in]         -
 * @param[in]         -
 * @param[in]         -
 *
 * @return            -
 *
 * @Note              -

 */
void I2C_Init(const I2C_ConfigType *i2c_config)
{

    if (i2c_config == NULL_PTR)
    {
        return;
    }

    volatile I2C *i2cptr = NULL_PTR;
int i=0;
    for ( i = 0; i < I2C_TOTAL_NUMBER; i++)
    {
        if (i2c_config->I2Carray[i].I2Cenabletype == I2CDISABLE)
        {
            continue;
        }

        switch (i2c_config->I2Carray[i].I2Cid)
        {
         case I2C1:
            i2cptr = MI2C1;
            RCC_APB1PeripheralEnable(I2C1EN);
            break;

         case I2C2:
            i2cptr = MI2C2;
            RCC_APB1PeripheralEnable(I2C2EN);
            break;
        }

       if (i2c_config->I2Carray[i].I2Cinterruptenable == I2CIPENABLE)
       {
		    //Implement the code to enable ITBUFEN Control Bit
			i2cptr->CR2.BF.ITBUFEN = ENABLE;
			//Implement the code to enable ITEVFEN Control Bit
			i2cptr->CR2.BF.ITEVTEN = ENABLE;
			//Implement the code to enable ITERREN Control Bit
		//	i2cptr->CR2.BF.ITERREN = ENABLE;
       }

       else if (i2c_config->I2Carray[i].I2Cinterruptenable == I2CIPDISABLE)
       {
			i2cptr->CR2.BF.ITBUFEN = DISABLE;
			i2cptr->CR2.BF.ITEVTEN = DISABLE;
		//	i2cptr->CR2.BF.ITERREN = DISABLE;
       }
			 
			 
		//configure the FREQ field of CR2
		i2cptr->CR2.BF.FREQ = 0b001000;    // 8MHz

   		//program the device own address
		i2cptr->OAR1.BF.ADD_7_1 = i2c_config->I2Carray[i].I2Cdeviceaddress;
		i2cptr->OAR1.BF.Software_High = ENABLE;

		//CCR calculations

		if(i2c_config->I2Carray[i].I2Csclspeed <= I2C_SCL_SPEED_SM)
		{
		 //mode is standard mode
		 i2cptr->CCR.BF.F_S = 0;
		 i2cptr->CCR.BF.CCR = (F_CPU / ( 2 * i2c_config->I2Carray[i].I2Csclspeed ) );
		}
		else
	    {
		 //mode is fast mode
		 i2cptr->CCR.BF.F_S = 1;

		 //tempreg |= (pI2CHandle->I2C_Config.I2C_FMDutyCycle << 14);

		 if(i2c_config->I2Carray[i].I2Cfmdutycycle == I2C_FM_DUTY_2)
		 {
		 	i2cptr->CCR.BF.CCR = (F_CPU / ( 3 * i2c_config->I2Carray[i].I2Csclspeed ) );
		 }
		else
		 {
			i2cptr->CCR.BF.CCR = (F_CPU / ( 25 * i2c_config->I2Carray[i].I2Csclspeed ) );
	     }
	   }
	
      
		//TRISE Configuration
		if(i2c_config->I2Carray[i].I2Csclspeed <= I2C_SCL_SPEED_SM)
		{
			//mode is standard mode
			i2cptr->TRISE.BF.TRISE =  (( (F_CPU * 1000) / 1000000000U ) + 1) ;
		}
		else
		{
		    //mode is fast mode
		    i2cptr->TRISE.BF.TRISE =  (( (F_CPU * 300) / 1000000000U ) + 1);
		}
			 
			 i2cptr->CR1.BF.PE = ENABLE;

		//ACK control bit
		if (i2c_config->I2Carray[i].I2Cackcontrol == I2C_ACK_ENABLE)
		{
		   i2cptr->CR1.BF.ACK = ENABLE;
		}
        else
		{
          i2cptr->CR1.BF.ACK = DISABLE;
		}

		

	}
}


void I2C_GenerateStopCondition(I2C_ID i2cid)
{
	volatile I2C *i2cptr = NULL_PTR;
	uint32 dummy_read;

	switch (i2cid)
	{
		case I2C1:
		i2cptr = MI2C1;
		break;

		case I2C2:
		i2cptr = MI2C2;
		break;
	}

    i2cptr->CR1.BF.STOP = ENABLE;
}
/*************************************************************************************************************/

void I2C_MasterSendData(I2C_ID i2cid , uint8 RA, uint32 Len, uint8 SlaveAddr, uint8 Data , uint8_t Sr , uint8 SENDorNOT)
{
	volatile I2C *i2cptr = NULL_PTR;
	uint32 dummy_read;

	switch (i2cid)
    {
        case I2C1:
        i2cptr = MI2C1;
        break;

        case I2C2:
        i2cptr = MI2C2;
        break;
    }

	//1. Generate the START condition
	i2cptr->CR1.BF.START = ENABLE;

	//2. confirm that start generation is completed by checking the SB flag in the SR1
	//   Note: Until SB is cleared SCL will be stretched (pulled to LOW)
	while( i2cptr->SR1.BF.SB == 0 );

	//3. Send the address of the slave with r/nw bit set to w(0) (total 8 bits )
	SlaveAddr = SlaveAddr << 1;
	SlaveAddr &= ~(1);           //SlaveAddr is Slave address + r/nw bit=0
	i2cptr->DR.BF.DR = SlaveAddr;

	//4. Confirm that address phase is completed by checking the ADDR flag in teh SR1
	while( i2cptr->SR1.BF.ADDR == 0 );

	//5. clear the ADDR flag according to its software sequence
	//   Note: Until ADDR is cleared SCL will be stretched (pulled to LOW)
    dummy_read = i2cptr->SR1.Reg;
	dummy_read = i2cptr->SR2.Reg;
    (void)dummy_read;

	//6. send the data until len becomes 0
    if(SENDorNOT == I2C_SEND_DATA)
    {
	  while(Len > 0)
	  {
		while( (i2cptr->SR1.BF.TxE == 0) ); //Wait till TXE is set
		i2cptr->DR.BF.DR = RA;
		//pTxbuffer++;
		Len--;
	  }

		Len++;

	    while (Len > 0)
	    {
			while ((i2cptr->SR1.BF.TxE == 0)); //Wait till TXE is set
			i2cptr->DR.BF.DR = Data;
			//pTxbuffer++;
			Len--;
	    }
    }

    else
    {
		while (Len > 0)
		{
			while ((i2cptr->SR1.BF.TxE == 0)); //Wait till TXE is set
			i2cptr->DR.BF.DR = RA;
			//pTxbuffer++;
			Len--;
		}
	}


	//7. when Len becomes zero wait for TXE=1 and BTF=1 before generating the STOP condition
	//   Note: TXE=1 , BTF=1 , means that both SR and DR are empty and next transmission should begin
	//   when BTF=1 SCL will be stretched (pulled to LOW)

	while( (i2cptr->SR1.BF.TxE) == 0 );
	while( (i2cptr->SR1.BF.BTF) == 0  );


	//8. Generate STOP condition and master need not to wait for the completion of stop condition.
	//   Note: generating STOP, automatically clears the BTF
	if(Sr == I2C_DISABLE_SR )
       i2cptr->CR1.BF.STOP = ENABLE;
}
/*************************************************************************************************************/

void I2C_MasterReceiveData(I2C_ID i2cid , int *pRxBuffer, uint32 Len, uint8 SlaveAddr, uint8 Sr)
{

	volatile I2C *i2cptr = NULL_PTR;
	uint32 dummy_read;

	switch (i2cid)
	{
	 case I2C1:
		i2cptr = MI2C1;
		break;

	 case I2C2:
		i2cptr = MI2C2;
		break;
	}

 	//1. Generate the START condition
	i2cptr->CR1.BF.START = ENABLE;

 	//2. confirm that start generation is completed by checking the SB flag in the SR1
 	//   Note: Until SB is cleared SCL will be stretched (pulled to LOW)
	while( i2cptr->SR1.BF.SB == 0 );


 	//3. Send the address of the slave with r/nw bit set to R(1) (total 8 bits )
	SlaveAddr = SlaveAddr << 1;
	SlaveAddr |= 1;           //SlaveAddr is Slave address + r/nw bit=1
	i2cptr->DR.BF.DR = SlaveAddr;

 	//4. wait until address phase is completed by checking the ADDR flag in the SR1
	while( i2cptr->SR1.BF.ADDR == 0 );


 	//procedure to read only 1 byte from slave
 	if(Len == 1)
 	{
 		//Disable Acking
 		i2cptr->CR1.BF.ACK = DISABLE;

 		//clear the ADDR flag
 		dummy_read = i2cptr->SR1.Reg;
 		dummy_read = i2cptr->SR2.Reg;
 		(void)dummy_read;

 		//wait until  RXNE becomes 1
 		while( i2cptr->SR1.BF.RxNE == 0 );

 		//generate STOP condition
 		if(Sr == I2C_DISABLE_SR )
 		   i2cptr->CR1.BF.STOP = ENABLE;

 		//read data in to buffer
 		*pRxBuffer = i2cptr->DR.BF.DR;

 	}


     //procedure to read data from slave when Len > 1
 	if(Len > 1)
 	{
 		//clear the ADDR flag
		dummy_read = i2cptr->SR1.Reg;
		dummy_read = i2cptr->SR2.Reg;
		(void) dummy_read;
uint32 i=0;
 		//read the data until Len becomes zero
 		for (  i = Len ; i > 0 ; i--)
 		{
 			//wait until RXNE becomes 1
 	 		while( i2cptr->SR1.BF.RxNE == 0 );

 			if(i == 2) //if last 2 bytes are remaining
 			{
 				//Disable Acking
 		 		i2cptr->CR1.BF.ACK = DISABLE;

 				//generate STOP condition
 		 		i2cptr->CR1.BF.STOP = ENABLE;
 			}

 			//read the data from data register in to buffer
 	 		*pRxBuffer = i2cptr->DR.BF.DR;

 			//increment the buffer address
 			pRxBuffer++;
 		}

     }

 	    //re-enable ACKing
		i2cptr->CR1.BF.ACK = ENABLE;
}



//  /*********************************************************************
//   * @fn      		  - I2C_MasterSendDataIT
//   *
//   * @brief             -
//   *
//   * @param[in]         -
//   * @param[in]         -
//   * @param[in]         -
//   *
//   * @return            -
//   *
//   * @Note              -

//   */
//  uint8 I2C_MasterSendDataIT(I2C_ID i2cid, uint8 TxBuffer, uint32 Len, uint8 SlaveAddr)
//  {

// 	volatile I2C *i2cptr = NULL_PTR;
// 	switch (i2cid)
// 	{
// 	case I2C1:
// 		i2cptr = MI2C1;
// 		break;

// 	case I2C2:
// 		i2cptr = MI2C2;
// 		break;
// 	}

//  	uint8 busystate =  TxRxState;

//  	if( (busystate != I2C_BUSY_IN_TX) && (busystate != I2C_BUSY_IN_RX))
//  	{
//  		 pTxBuffer = TxBuffer;
//  		  TxLen = Len;
//  		  TxRxState = I2C_BUSY_IN_TX;
//  		  DevAddr = SlaveAddr;

// 		//Implement code to Generate START Condition
// 		i2cptr->CR1.BF.START = ENABLE;


//  	}

//  	return busystate;
//  }


//  /*********************************************************************
//   * @fn      		  - I2C_MasterReceiveDataIT
//   *
//   * @brief             -
//   *
//   * @param[in]         -
//   * @param[in]         -
//   * @param[in]         -
//   *
//   * @return            -
//   *
//   * @Note              -

//   */
//  uint8 I2C_MasterReceiveDataIT(I2C_ID i2cid , uint8 *RxBuffer, uint8 Len, uint8 SlaveAddr)
//  {

// 	volatile I2C *i2cptr = NULL_PTR;
// 	switch (i2cid)
// 	{
// 	case I2C1:
// 		i2cptr = MI2C1;
// 		break;

// 	case I2C2:
// 		i2cptr = MI2C2;
// 		break;
// 	}

//  	uint8 busystate =   TxRxState;

//  	if( (busystate != I2C_BUSY_IN_TX) && (busystate != I2C_BUSY_IN_RX))
//  	{
// 		  pRxBuffer = RxBuffer;
//  		  RxLen = Len;
//  		  TxRxState = I2C_BUSY_IN_RX;
//  		  RxSize = Len;
//  		  DevAddr = SlaveAddr;

// 		//Implement code to Generate START Condition
// 		i2cptr->CR1.BF.START = ENABLE;

//  	}

//  	return busystate;
//  }



//  static void I2C_MasterHandleTXEInterrupt(I2C_ID i2cid )
//  {

// 	volatile I2C *i2cptr = NULL_PTR;
// 	switch (i2cid)
// 	{
// 	case I2C1:
// 		i2cptr = MI2C1;
// 		break;

// 	case I2C2:
// 		i2cptr = MI2C2;
// 		break;
// 	}

//  	if( TxLen > 0)
//  	{
//  		//1. load the data in to DR
//  		i2cptr->DR.BF.DR =  pTxBuffer;

//  		//2. decrement the TxLen
//  		 TxLen--;

//  		//3. Increment the buffer address
//  		 pTxBuffer++;

//  	}

//  }

//  static void I2C_MasterHandleRXNEInterrupt(I2C_ID i2cid )
//  {

// 	volatile I2C *i2cptr = NULL_PTR;
// 	switch (i2cid)
// 	{
// 	case I2C1:
// 		i2cptr = MI2C1;
// 		break;

// 	case I2C2:
// 		i2cptr = MI2C2;
// 		break;
// 	}

//  	//We have to do the data reception
//  	if(RxSize == 1)
//  	{
//  	   *pRxBuffer = i2cptr->DR.BF.DR;
//  		 RxLen--;

//  	}


//  	if( RxSize > 1)
//  	{
//  		if( RxLen == 2)
//  		{
//  			//clear the ack bit
//  			i2cptr->CR1.BF.ACK = DISABLE;
//  		}

//  			//read DR
//  		    *pRxBuffer = i2cptr->DR.BF.DR;
//  			 pRxBuffer++;
//  			 RxLen--;
//  	}

//  	if( RxLen == 0 )
//  	{
//  		//close the I2C data reception and notify the application

//  		//1. generate the stop condition
// 	    i2cptr->CR1.BF.STOP = ENABLE;

//  		//2 . Close the I2C rx
//  		I2C_CloseReceiveData(i2cid);

//  		//3. Notify the application
//  		I2C_ApplicationEventCallback(i2cid,I2C_EV_RX_CMPLT);
//  	}
//  }


// void I2C_CloseReceiveData(I2C_ID i2cid)
// {

// 	volatile I2C *i2cptr = NULL_PTR;
// 	switch (i2cid)
// 	{
// 	case I2C1:
// 		i2cptr = MI2C1;
// 		break;

// 	case I2C2:
// 		i2cptr = MI2C2;
// 		break;
// 	}

// 	//Implement the code to disable ITBUFEN Control Bit
// //	i2cptr->CR2.BF.ITBUFEN = DISABLE;

// 	//Implement the code to disable ITEVFEN Control Bit
// //	i2cptr->CR2.BF.ITEVTEN = DISABLE;

// 	 TxRxState = I2C_READY;
// 	 pRxBuffer = NULL;
// 	 RxLen = 0;
// 	 RxSize = 0;

// 	i2cptr->CR1.BF.ACK = ENABLE;
// }

// void I2C_CloseSendData(I2C_ID i2cid)
// {

// 	volatile I2C *i2cptr = NULL_PTR;
// 	switch (i2cid)
// 	{
// 	case I2C1:
// 		i2cptr = MI2C1;
// 		break;

// 	case I2C2:
// 		i2cptr = MI2C2;
// 		break;
// 	}

//  	//Implement the code to disable ITBUFEN Control Bit
//  //	i2cptr->CR2.BF.ITBUFEN = DISABLE;

//  	//Implement the code to disable ITEVFEN Control Bit
//  //	i2cptr->CR2.BF.ITEVTEN = DISABLE;


//  	 TxRxState = I2C_READY;
//  	 pTxBuffer = NULL;
//  	 TxLen = 0;
// }


//  void I2C_EV_IRQHandling(I2C_ID i2cid)
//  {
//  	//Interrupt handling for both master and slave mode of a device

// 	volatile I2C *i2cptr = NULL_PTR;
// 	switch (i2cid)
// 	{
// 	case I2C1:
// 		i2cptr = MI2C1;
// 		break;

// 	case I2C2:
// 		i2cptr = MI2C2;
// 		break;
// 	}

//     uint32 dummySB;
//  	uint32 temp1, temp2, temp3;

//  	temp1   = i2cptr->CR2.BF.ITEVTEN;
//  	temp2   = i2cptr->CR2.BF.ITBUFEN;

//  	temp3  = i2cptr->SR1.BF.SB;
//  	//1. Handle For interrupt generated by SB event
//  	//	Note : SB flag is only applicable in Master mode
//  	if(temp1 && temp3)
//  	{
//  		//The interrupt is generated because of SB event
//  		//This block will not be executed in slave mode because for slave SB is always zero
//  		//In this block lets executed the address phase
// 		dummySB = i2cptr->SR1.Reg;

		
//  		if( TxRxState == I2C_BUSY_IN_TX)
//  		{
//  		   DevAddr =  DevAddr << 1;
//  		   DevAddr &= ~(1);         //SlaveAddr is Slave address + r/nw bit=0
// 		   i2cptr->DR.BF.DR =  DevAddr;
//  		}
//  		else if ( TxRxState == I2C_BUSY_IN_RX )
//  		{
//  			 DevAddr =  DevAddr << 1;
//  			 DevAddr |= 1;           //SlaveAddr is Slave address + r/nw bit=1
//  			 i2cptr->DR.BF.DR = DevAddr;
//  		}
//  	}
//  /**********************************************************************************/

//  	temp3  = i2cptr->SR1.BF.ADDR;
//  	//2. Handle For interrupt generated by ADDR event
//  	//Note : When master mode : Address is sent
//  	//		 When Slave mode   : Address matched with own address
//  	if(temp1 && temp3)
//  	{
//  		// interrupt is generated because of ADDR event
//  		I2C_ClearADDRFlag(i2cid);
//  	}
//  /********************************************************************************/


//  	temp3  = i2cptr->SR1.BF.TxE;
//  	//5. Handle For interrupt generated by TXE event
//  	if(temp1 && temp2 && temp3)
//  	{
//  		//Check for device mode
//  		if(i2cptr->SR2.BF.MSL == 1)
//  		{
//  			//TXE flag is set
//  			//We have to do the data transmission
//  			if( TxRxState == I2C_BUSY_IN_TX)
//  			{
//  				I2C_MasterHandleTXEInterrupt(i2cid);
//  			}
//  		}
//  		else
//  		{

//  		}
//  	}
// /********************************************************************************/
		
//  	temp3  = i2cptr->SR1.BF.BTF;
//  	//3. Handle For interrupt generated by BTF(Byte Transfer Finished) event
//  	if(temp1 && temp3)
//  	{
//  		//BTF flag is set
//  		if( TxRxState == I2C_BUSY_IN_TX)
//  		{
//  			//make sure that TXE is also set .
//  			if(i2cptr->SR1.BF.TxE )
//  			{
//  				//BTF, TXE = 1
//  				if(TxLen == 0 )
//  				{
//  					//1. generate the STOP condition
//  				    i2cptr->CR1.BF.STOP = ENABLE;

//  					//2. reset all the member elements of the handle structure.
//  					I2C_CloseSendData(i2cid);

//  					//3. notify the application about transmission complete
//  			  //I2C_ApplicationEventCallback(i2cid,I2C_EV_TX_CMPLT);

//  				}
//  			}

//  		}
//  		else if ( TxRxState == I2C_BUSY_IN_RX )
//  		{

//  		}
//  	}
  /********************************************************************************/

// 	temp3  = pI2CHandle->pI2Cx->SR1 & ( 1 << I2C_SR1_STOPF);
// 	//4. Handle For interrupt generated by STOPF event
// 	// Note : Stop detection flag is applicable only slave mode . For master this flag will never be set
// 	//The below code block will not be executed by the master since STOPF will not set in master mode
// 	if(temp1 && temp3)
// 	{
// 		//STOF flag is set
// 		//Clear the STOPF ( i.e 1) read SR1 2) Write to CR1 )
//
// 		pI2CHandle->pI2Cx->CR1 |= 0x0000;
//
// 		//Notify the application that STOP is detected
// 		I2C_ApplicationEventCallback(pI2CHandle,I2C_EV_STOP);
// 	}

  
  /********************************************************************************/

//  	temp3  = i2cptr->SR1.BF.RxNE;
//  	//6. Handle For interrupt generated by RXNE event
//  	if(temp1 && temp2 && temp3)
//  	{
//  		//check device mode .
//  		if(i2cptr->SR2.BF.MSL == 1)
//  		{
//  			//The device is master

//  			//RXNE flag is set
//  			if(TxRxState == I2C_BUSY_IN_RX)
//  			{
//  				I2C_MasterHandleRXNEInterrupt(i2cid);

//  			}

//  		}
//  		else
//  		{

//  		}
//  	}
//  }



 /*********************************************************************
  * @fn      		  - I2C_ER_IRQHandling
  *
  * @brief             -
  *
  * @param[in]         -
  * @param[in]         -
  * @param[in]         -
  *
  * @return            -
  *
  * @Note

  */

// void I2C_ER_IRQHandling(I2C_ID i2cid)
// {

// 	volatile I2C *i2cptr = NULL_PTR;
// 	switch (i2cid)
// 	{
// 	case I2C1:
// 		i2cptr = MI2C1;
// 		break;

// 	case I2C2:
// 		i2cptr = MI2C2;
// 		break;
// 	}

//  	uint32 temp1,temp2;

//      //Know the status of  ITERREN control bit in the CR2
//  	temp2 = i2cptr->CR2.BF.ITERREN;


//  /***********************Check for Bus error************************************/
//  	temp1 = i2cptr->SR1.BF.BERR;
//  	if(temp1  && temp2 )
//  	{
//  		//This is Bus error

//  		//Implement the code to clear the buss error flag
//  		i2cptr->SR1.BF.BERR = DISABLE;

//  		//Implement the code to notify the application about the error
//  	   I2C_ApplicationEventCallback(i2cid,I2C_ERROR_BERR);
//  	}

//  /***********************Check for arbitration lost error************************************/
//  	temp1 = i2cptr->SR1.BF.ARLO;
//  	if(temp1  && temp2)
//  	{
//  		//This is arbitration lost error

//  		//Implement the code to clear the arbitration lost error flag
//  		i2cptr->SR1.BF.ARLO = DISABLE;

//  		//Implement the code to notify the application about the error
//  		I2C_ApplicationEventCallback(i2cid,I2C_ERROR_ARLO);

//  	}

//  /***********************Check for ACK failure  error************************************/

//  	temp1 = i2cptr->SR1.BF.AF;
//  	if(temp1  && temp2)
//  	{
//  		//This is ACK failure error

//  	    //Implement the code to clear the ACK failure error flag
//  		i2cptr->SR1.BF.AF = DISABLE;

//  		//Implement the code to notify the application about the error
//  		I2C_ApplicationEventCallback(i2cid,I2C_ERROR_AF);
//  	}

//  /***********************Check for Overrun/underrun error************************************/
//  	temp1 = i2cptr->SR1.BF.OVR;
//  	if(temp1  && temp2)
//  	{
//  		//This is Overrun/underrun

//  	    //Implement the code to clear the Overrun/underrun error flag
//  		i2cptr->SR1.BF.OVR = DISABLE;

//  		//Implement the code to notify the application about the error
//  		I2C_ApplicationEventCallback(i2cid,I2C_ERROR_OVR);
//  	}

//  /***********************Check for Time out error************************************/
//  	temp1 = i2cptr->SR1.BF.TIMEOUT;
//  	if(temp1  && temp2)
//  	{
//  		//This is Time out error

//  	    //Implement the code to clear the Time out error flag
//  		i2cptr->SR1.BF.TIMEOUT = DISABLE;

//  		//Implement the code to notify the application about the error
//  		I2C_ApplicationEventCallback(i2cid,I2C_ERROR_TIMEOUT);
//  	}

// }



// void I2C1_EV_IRQHandler (void)
// {
// 	I2C_EV_IRQHandling(I2C1);
// }


// void I2C1_ER_IRQHandler (void)
// {
// 	I2C_ER_IRQHandling(I2C1);
// }


// void I2C_ApplicationEventCallback(I2C_ID i2cid,uint8 AppEv)
// {

// 	volatile I2C *i2cptr = NULL_PTR;
// 	switch (i2cid)
// 	{
// 	case I2C1:
// 		i2cptr = MI2C1;
// 		break;

// 	case I2C2:
// 		i2cptr = MI2C2;
// 		break;
// 	}

//      if(AppEv == I2C_EV_TX_CMPLT)
//      {
//     	 //printf("Tx is completed\n");
//      }
//      else if (AppEv == I2C_EV_RX_CMPLT)
//      {
//     	// printf("Rx is completed\n");
//     	// rxComplt = 1;
//      }
//      else if (AppEv == I2C_ERROR_AF)
//      {
//     	 //printf("Error : Ack failure\n");

//     	 //in master ack failure happens when slave fails to send ack for the byte
//     	 //sent from the master.
//     	 I2C_CloseSendData(I2C1);

//     	 //generate the stop condition to release the bus
//     	   i2cptr->CR1.BF.STOP = ENABLE;

//     	 //Hang in infinite loop
//     	 while(1);
//      }
// }
