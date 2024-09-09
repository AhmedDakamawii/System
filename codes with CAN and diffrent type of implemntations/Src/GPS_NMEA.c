#include "GPS_NMEA.h"

// power fucntion
// strlen function
// convert ascii to decimal function

#define buffer_length 12

GGASTRUCT Find_location;

float32 power_function(uint8 base, uint8 exp) {
	float32 value = 1;
	while (exp != 0) {
		value *= base; /* value = value*base; */
		--exp;
	}
	return value;
}
uint16 myAtoi(char *str) {
	// Initialize result
	float32 res = 0;

	// Iterate through all characters
	// of input string and update result
	// take ASCII character of corresponding digit and
	// subtract the code from '0' to get numerical
	// value and multiply res by 10 to shuffle
	// digits left to update running total
	uint8 i = 0;
	for (i = 0; str[i] != '\0'; ++i) {
		if (str[i] == '.')
			break;
		res = res * 10 + str[i] - '0';
	}
	// return result.
	return res;
}


void GetTIME_LOCATION(char *GGAbuffer) {
	uint8 inx = 0, resetvariable = 0, i, startinx = 0;
	char buffer[buffer_length] = { 0 };
	uint8 ggacounter = 0;
	uint16 loopcount = 0;
	for (loopcount = 0; loopcount < 500; loopcount++) {
		inx++;
		if (GGAbuffer[loopcount] == 'G' && GGAbuffer[loopcount + 1] == 'G'
				&& GGAbuffer[loopcount + 2] == 'A') {
			startinx = inx;
			ggacounter = 1;
			break;
		}
	}
	if (ggacounter == 1) {
		ggacounter = 0;
		while (GGAbuffer[inx] != ',')
			inx++;  // 1st ','
		inx++;
		while (GGAbuffer[inx] != ',')
			inx++;  // After time ','
		inx++;
		while (GGAbuffer[inx] != ',')
			inx++;  // after latitude ','
		inx++;
		while (GGAbuffer[inx] != ',')
			inx++;  // after NS ','
		inx++;
		while (GGAbuffer[inx] != ',')
			inx++;  // after longitude ','
		inx++;
		while (GGAbuffer[inx] != ',')
			inx++;  // after EW ','
		inx++;  // reached the character to identify the fix
		if (((GGAbuffer[inx] == '1') || (GGAbuffer[inx] == '2')
				|| (GGAbuffer[inx] == '6'))
				&& ((GGAbuffer[inx - 2] == 'E') || (GGAbuffer[inx - 2] == 'W'))) // 0 indicates no fix yet
				{
			Find_location.isfixValid = 1;   // fix available
			inx = startinx; // reset the index. We will start from the inx=0 and extract information now
		} else {
			Find_location.isfixValid = 0;   // If the fix is not available
			//	return 1;  // return error
		}
	}
	if (Find_location.isfixValid == 1) {
		while (GGAbuffer[inx] != ',')
			inx++;  // 1st ','
			/*********************** Get TIME ***************************/
//(Update the GMT Offset at the top of this file)

		inx++;   // reach the first number in time
		for (resetvariable = 0; resetvariable < buffer_length; resetvariable++)
			buffer[resetvariable] = 0;
		i = 0;
		while (GGAbuffer[inx] != ',') // copy upto the we reach the after time ','
		{
			buffer[i] = GGAbuffer[inx];
			i++;
			inx++;
		}

		/***************** Get LATITUDE  **********************/
		inx++;   // Reach the first number in the lattitude
		for (resetvariable = 0; resetvariable < buffer_length; resetvariable++)
			buffer[resetvariable] = 0;
		i = 0;
		//inx++;
		while (GGAbuffer[inx] != ',') // copy upto the we reach the after lattitude ','
		{
			buffer[i] = GGAbuffer[inx];
			i++;
			inx++;
		}
		inx++;


		uint32 num = (myAtoi(buffer)); // change the buffer to the number. It will only convert upto decimal
		uint16 minutes=(uint16)(num%100);
		uint32 multiplier = 10000000UL;
    uint32 tenMillionthsOfMinutes = minutes * multiplier;
		uint8 deg=num/100;
	
		uint8 j = 0;
		while (buffer[j] != '.')
			j++;   // Figure out how many digits before the decimal
		j++;

			uint8 i=0;
		for(i;i<5;i++)
		  {
				multiplier /= 10;
      tenMillionthsOfMinutes += (buffer[i+j] - '0') * multiplier;
			}		
	float32	billionths = (5 * tenMillionthsOfMinutes + 1) / 3;
			

Find_location.FINAL_LOC.Latitude =deg+billionths/ 1000000000.0;
			

		Find_location.FINAL_LOC.N_s = GGAbuffer[inx]; // save the N/S into the structure

		num = 0;
	uint8	declen = 0;
	
	float32	lat = 0;

		float32 dec_long = 0;
		/***************** Get Longitude  **********************/
		inx++;   // Reach the first number in the longitude
		for (resetvariable = 0; resetvariable < buffer_length; resetvariable++)
			buffer[resetvariable] = 0;
		i = 0;
		inx++;
		inx++;
		while (GGAbuffer[inx] != ',') // copy upto the we reach the after longitude ','
		{
			buffer[i] = GGAbuffer[inx];
			i++;
			inx++;
		}
		inx++;

				 num = (myAtoi(buffer)); // change the buffer to the number. It will only convert upto decimal
		 minutes=(uint16)(num%100);
		 multiplier = 10000000UL;
     tenMillionthsOfMinutes = minutes * multiplier;
		 deg=num/100;

		j = 0;
		while (buffer[j] != '.')
			j++;   // Figure out how many digits before the decimal
		j++;
		
			 i=0;
		for(i;i<5;i++)
		  {
				multiplier /= 10;
      tenMillionthsOfMinutes += (buffer[i+j] - '0') * multiplier;
			}		
		billionths = (5 * tenMillionthsOfMinutes + 1) / 3;
			

Find_location.FINAL_LOC.Longitude =deg+billionths/ 1000000000.0;


		Find_location.FINAL_LOC.W_E = GGAbuffer[inx]; // save the w/e into the structure
	}

}
