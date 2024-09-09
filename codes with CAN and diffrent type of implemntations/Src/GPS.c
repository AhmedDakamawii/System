#include "GPS.h"

uint8 nmea_buffer[NMEA_code] = { 0 };
uint16 globaliterator = 0;
uint8 current_data[NMEA_code] = { 0 };

extern GGASTRUCT Find_location;
extern GGASTRUCT Local_Find_location;
#define USART_USED_GPS USART3



void Location2Text(float32 number, uint8* array) {
    uint32 integer_part = (uint32)number;
    float32 decimal_part = number - integer_part;

    // Convert the integer part to a string
    uint8 i = 0;
    if (integer_part == 0) {
        array[i++] = '0';
    } else {
        while (integer_part > 0) {
            int digit = integer_part % 10;
            array[i++] = digit + '0';
            integer_part /= 10;
        }
    }

    // Reverse the integer part in the array
    uint8 start = 0;
    uint8 end = i - 1;
    while (start < end) {
        uint8 temp = array[start];
        array[start] = array[end];
        array[end] = temp;
        start++;
        end--;
    }
    // Convert the decimal part to a string
    uint8 j = 0;
    while (j < 10) {
if(j==0){
array[i++]='.';
j++;
continue;
}
        decimal_part *= 10;
        uint32 digit = (uint32)decimal_part;
        array[i++] = digit + '0';
        decimal_part -= digit;
        j++;
		}
    // Null-terminate the array
    array[i]='\0';
}



/*********************************[0]********************************************
 * Service Name: Receive_uartinterrupt_GPS
 * Service ID[hex]: 0x00
 * Sync/Async: Asynchronous
 * Reentrancy: Non-Reentrant
 * Parameters (in): None
 * Parameters (inout): nmea_buffer
 * Parameters (out): None
 * Return value: None
 * Description: Function to Receive Data From NEO7M by UART
 *******************************************************************************/
void Receive_uartinterrupt_GPS() {

	nmea_buffer[globaliterator] = USART_ReceiveByte(USART_USED_GPS);
	globaliterator++;
	if (globaliterator == NMEA_code)
		globaliterator = 0;

}
/*********************************[1]********************************************
 * Service Name: GPS_INIT
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): nmea_buffer
 * Parameters (out): None
 * Return value: None
 * Description: Function to Receive Data From NEO-7M by UART
 *******************************************************************************/
void GPS_INIT() {
	USART_VidSetCallBack(Receive_uartinterrupt_GPS, USART_USED_GPS);
}
/*********************************[2]********************************************
 * Service Name: GPS_GETLOCATION
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Reentrancy: Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to Get Location Data
 *******************************************************************************/
void GPS_GETLOCATION() {
	clear_currentbuffer();
	uint16 i = 0;
	
	while(i<NMEA_code)
		{

				current_data[i] = USART_ReceiveByte(USART_USED_GPS);
		i++;
		}

	GetTIME_LOCATION(&current_data);
	if (!(((Find_location.FINAL_LOC.N_s == 'N')
			|| (Find_location.FINAL_LOC.N_s == 'S'))
			&& ((Find_location.FINAL_LOC.W_E == 'E')
					|| (Find_location.FINAL_LOC.W_E == 'W')))) {

		Find_location.isfixValid = 0;

	} else {
		Local_Find_location.isfixValid = 1;
		Local_Find_location.FINAL_LOC.Latitude =
				Find_location.FINAL_LOC.Latitude;
		Local_Find_location.FINAL_LOC.Longitude =
				Find_location.FINAL_LOC.Longitude;
		Local_Find_location.FINAL_LOC.N_s = Find_location.FINAL_LOC.N_s;
		Local_Find_location.FINAL_LOC.W_E = Find_location.FINAL_LOC.W_E;
	Location2Text(Local_Find_location.FINAL_LOC.Latitude,&Local_Find_location.FINAL_LOC_string.Latitude_string);
	Location2Text(Local_Find_location.FINAL_LOC.Longitude,&Local_Find_location.FINAL_LOC_string.Longitude_string);
		
		uint8 i=0;
		for(i;i<24;i++)
		{
			if(i<10)
		Local_Find_location.Full_location[i]=Local_Find_location.FINAL_LOC_string.Latitude_string[i];
			else if(i==10)
			Local_Find_location.Full_location[i]=	Find_location.FINAL_LOC.N_s;
			else if((i>10)&&(i<21))
				Local_Find_location.Full_location[i]=Local_Find_location.FINAL_LOC_string.Longitude_string[i-11];
			else if(i==21)
				Local_Find_location.Full_location[i]=	 Find_location.FINAL_LOC.W_E;
			else
				Local_Find_location.Full_location[i]='0';
				
		}
		
	}

}
/*********************************[3]********************************************
 * Service Name: clear_currentbuffer
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Reentrancy: Non-Reentrant
 * Parameters (in): None
 * Parameters (inout): None
 * Parameters (out): None
 * Return value: None
 * Description: Function to clear Buffer
 *******************************************************************************/
void clear_currentbuffer() {
	uint16 i = 0;
	for (i = 0; i < NMEA_code; i++)
current_data[i] = 0;
}
