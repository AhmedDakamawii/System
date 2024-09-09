#include "GSM.h"

//volatile uint8 GSM_BUFFER[buffersize] = { 0 };
//volatile uint8 globaliterator1 = 0;
extern GGASTRUCT Local_Find_location;
#define USART_USED_GSM USART2



/*********************************[0]**********************************************
 * Service Name: UART_GSMINTERRUPT
 * Service ID[hex]: 0x00
 * Sync/Async: Asynchronous
 * Reentrancy: Non-Reentrant
 * Parameters (in): None
 * Parameters (inout): GSM_BUFFER
 * Parameters (out): None
 * Return value: None
 * Description: Function to Receive Data From SIM800L by UART
 *******************************************************************************/
//void UART_GSMINTERRUPT() {
	//GSM_BUFFER[globaliterator1] = USART_ReceiveByte(USART_USED_GSM);
	//globaliterator1++;
//}
/********************************[1]********************************************
 * Service Name: GSM_Clear_Buffer
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Non-Reentrant
 * Parameters (in): None
 * Parameters (inout): GSM_BUFFER
 * Parameters (out): None
 * Return value: None
 * Description: Function to clear GSM Buffer
 *******************************************************************************/
//void GSM_Clear_Buffer() {
	//globaliterator1 = 0;
	//int i = 0;
	//for (i = 0; i < buffersize; i++)
	//	GSM_BUFFER[i] = 0;
//}

/********************************[2]********************************************
 * Service Name: GSM_checkinit
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Initialzation Function to GSM
 *******************************************************************************/
void GSM_checkinit() {
	//USART_VidSetCallBack(UART_GSMINTERRUPT, USART_USED_GSM);
	USART_TransmitString((uint8*) "AAT\r\n", USART_USED_GSM); // handshake
	delaySeconds(TIMER3_DEF,0.05);
	USART_TransmitString((uint8*) "ATI\r\n", USART_USED_GSM); // sim module
	delaySeconds(TIMER3_DEF,0.05);
	USART_TransmitString((uint8*) "AT+CSQ\r\n", USART_USED_GSM); // signal strength need to be higher than 5
	delaySeconds(TIMER3_DEF,0.05);
	//GSM_Clear_Buffer();
	USART_TransmitString((uint8*) "AT+CFUN=1\r\n", USART_USED_GSM); // signal strength need to be higher than 5
	delaySeconds(TIMER3_DEF,0.05);
	USART_TransmitString((uint8*) "AT+CBC\r\n", USART_USED_GSM); // voltage connected
	delaySeconds(TIMER3_DEF,0.05);
	//GSM_Clear_Buffer();
	USART_TransmitString((uint8*) "AT+CCID\r\n", USART_USED_GSM); // sim card valid or not and return value of simcard number
	delaySeconds(TIMER3_DEF,0.05);
	USART_TransmitString((uint8*) "AT+COPS?\r\n", USART_USED_GSM); // network registered
	delaySeconds(TIMER3_DEF,0.05);
	//GSM_Clear_Buffer();
	USART_TransmitString((uint8*) "AT+CREG?\r\n", USART_USED_GSM); // 1 home network 5 roaming network
	delaySeconds(TIMER3_DEF,0.05);
	USART_TransmitString((uint8*) "AT+CMGF=1\r\n", USART_USED_GSM); //sms message format protocol data unit
	

	//GSM_Clear_Buffer();
}
/********************************[3]********************************************
 * Service Name: GSM_SendMessage
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): GSM_DATA
 * Parameters (out): None
 * Return value: None
 * Description: Function to Send SMS from GSM to chosen Number
 *******************************************************************************/
void GSM_SendMessage(uint8 *GSM_DATA) {
	USART_TransmitString((uint8*) "AT+CMGS=\"+201065080338\"\r\n",USART_USED_GSM); // number to send to
	delaySeconds(TIMER3_DEF,0.05);
	USART_TransmitString("GSM TEST LETS GO\r\n", USART_USED_GSM);
	USART_TransmitByte(26, USART_USED_GSM);
	USART_TransmitString("\r\n", USART_USED_GSM);
	
	//GSM_Clear_Buffer();
}

void GSM_SendHelpMessage() {
	uint8 i=0;
	USART_TransmitString((uint8*) "AT+CMGS=\"+201065080338\"\r\n",USART_USED_GSM); // number to send to
//	USART_TransmitString((uint8*) "AT+CMGS=\"+201025829140\"\r\n",USART_USED_GSM); // number to send to

	delaySeconds(TIMER3_DEF,0.05);
	USART_TransmitString(" Emergency - Accident at:  ", USART_USED_GSM);

	
	for(i=0;i<22;i++)
	{
		USART_TransmitByte(Local_Find_location.Full_location[i], USART_USED_GSM);
		delaySeconds(TIMER3_DEF,0.01);
	}


	USART_TransmitByte(26, USART_USED_GSM);
	USART_TransmitString("\r\n", USART_USED_GSM);

}

