 /***************************************************************/
 /* Author : ahmed elsayed                                      */
 /*version:  V01                                                */
 /*Date:                                                        */ 
/****************************************************************/

#ifndef ESP_INTERFACE_H
#define ESP_INTERFACE_H

void ESP_VidInit(void);
void ESP_VIDConnectWifi( u8* Copy_u8UserName , u8* Copy_u8Password );
void ESP_VIDConnectServer( u8* Copy_u8Ip );
u8 ESP_VIDSendData( u8* Copy_u8link , u8* Copy_u8Length );


#endif
