 /***************************************************************/
 /* Author : ahmed elsayed                                      */
 /*version:  V01                                                */
 /*Date:                                                        */ 
/****************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h" 
#include "STK_interface.h"

#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"

void ESP_VidInit(void)
{
	u8 result=0;
	while (result==0)
	{	/*stop echo*/
	MUSART1_VidTransmit( (u8*)"ATE0\r\n");
	result=VoidEspValidateCommand();
	}	
	result=0;
	while (result==0)
	{	
/*set staion mode which is option 1*/
MUSART1_VidTransmit( (u8*)"AT+CWMODE=1\r\n");
	result=VoidEspValidateCommand();
	}	
		result=0;


}

void ESP_VIDConnectWifi( u8* Copy_u8UserName , u8* Copy_u8Password )
{
	u8 result=0;
	while (result==0)
	{	
/*put wifi and password here*/
	MUSART1_VidTransmit( (u8*) "AT+CWJAP_CUR=\"");
	MUSART1_VidTransmit( (u8*) Copy_u8UserName);
	MUSART1_VidTransmit( (u8*) "\",\"");
	MUSART1_VidTransmit( (u8*) Copy_u8Password);
	MUSART1_VidTransmit( (u8*) "\"\r\n");
	result=VoidEspValidateCommand();
	}	

}
void ESP_VIDConnectServer( u8* Copy_u8Ip )
{
	u8 result=0;
	while (result==0)
	{	
	MUSART1_VidTransmit("AT+CIPSTART=\"TCP\",\"");
	MUSART1_VidTransmit( Copy_u8Ip);
	MUSART1_VidTransmit( "\",80\r\n"); /* 80 Port No. */
	result=VoidEspValidateCommand();
	}	

}
u8 ESP_VIDSendData( u8* Copy_u8link , u8* Copy_u8Length )
{
	u8 final_value=0;
	u8 result=0;
	while (result==0)
	{	
	MUSART1_VidTransmit("AT+CIPSEND=");
	MUSART1_VidTransmit( (u8*) Copy_u8Length);
	MUSART1_VidTransmit( (u8*) "\r\n");
	result=VoidEspValidateCommand();
	}
	result=0;
	while (result==0)
	{
		MUSART1_VidTransmit( (u8*) "GET ");
		MUSART1_VidTransmit( (u8*) Copy_u8link);
		MUSART1_VidTransmit( (u8*) "\r\n");
		result=VoidEspValidateCommand();
	}
	final_value= result-1;
	return final_value;

}

u8 VoidEspValidateCommand (void)
{
	u8 response[100]={0};
	u8 i=0;
	u8 nothing=0;
	u8 result=0;
	while (nothing!=255)
	{
		nothing=MUSART1_U8Receive();
		response[i]=nothing;
		i++;
	}
	/*check if ok or if connected*/
	if (response[2]=='O' &&response[3]=='K' )
	{
		result=1;
	}
	else if (response[31]=='O' &&response[32]=='K' )
	{
		result=1;
	}
	else if (response[11]=='O' &&response[12]=='K' )
	{
		result=1;
	}
	else if (response[24]=='O' &&response[25]=='K' )
	{
		/*if this the last one take the element and return  its value which is 1 or 0*/
		result=response[37];
		if(result == '1')
		{
			result=2;
		}
		else if(result == '0')
		{
			result=1;
		}
	}
	return result;
}
