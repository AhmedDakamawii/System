#ifndef GPS_NMEA_h
#define GPS_NMEA_h

#include "Platform_Types.h"
#include "Std_Types.h"



typedef struct  
{
uint8 hour;
uint8 sec;
uint8 min;
}timee;

typedef struct
{
float Latitude;
uint8 N_s;
float Longitude;
uint8 W_E;
}Location;

typedef struct 
{
uint8 Latitude_string[10];
	uint8 Longitude_string[10];
}Location_string;

typedef struct 
{
    timee tim;
    Location FINAL_LOC;
	Location_string FINAL_LOC_string;
    uint8 isfixValid;
	uint8 Full_location[24];
}GGASTRUCT;

void GetTIME_LOCATION(char *GGAbuffer);


#endif
