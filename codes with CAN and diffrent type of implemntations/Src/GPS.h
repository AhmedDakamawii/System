#ifndef GPS_h
#define GPS_h

#include "Platform_Types.h"
#include "Std_Types.h"
#include "Uart.h"
#include "GPS_NMEA.h"
#include "gpt.h"

#define NMEA_code  400

void GPS_INIT();
void GPS_GETLOCATION();
void Receive_uartinterrupt_GPS();
void clear_currentbuffer();
#endif