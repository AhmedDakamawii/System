#include "Platform_Types.h"
#include "Std_Types.h"
#include "Uart.h"
#include "Gpt.h"
#include "GPS.h""


void GSM_checkinit();
void GSM_SendMessage(uint8 *GSM_DATA);
void GSM_SendHelpMessage();
void GSM_readmessage(uint8 *GSM_RECEIVED);
void GSM_Sendcall();
void GSM_Clear_Buffer();
void UART_GSMINTERRUPT();

#define buffersize 100
