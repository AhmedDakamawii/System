 /***************************************************************/
 /* Author : ahmed elsayed                                      */
 /*version:  V01                                                */
 /*Date:                                                        */ 
 /*Describtion: IR                                           */ 
/****************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "IR_interface.h"
#include "DCMOTOR_interface.h"


volatile u8 Data=0;
//flag for know if this is the first falling edge or not
extern volatile u8 flag;
//this is to save the time of difference between each two adjacent falling edge in each index
extern volatile u32 Frame_data [50];
//this is the variable that contain the index of each falling edge
extern volatile u8 Edge_counter;

void VID_TakeAction (void)
{
	//as address  of each remote is always constant we will focus on data from index 17
	Data=0;
	u8 i;
	//test for value of start bit which is should equal 13500
if (Frame_data[0] >= 10000 && Frame_data[0] <= 15000)
{
	for (i=0;i<8;i++)
	{
		//thats mean we send 1 which is should equal 2250
	if(Frame_data[17+i]>= 2000 && Frame_data[17+i]<= 2300)
	{
		SET_BIT(Data , i);
	}
	else
	{
		//thats mean we send 0 which is should equal 1125
		CLR_BIT(Data , i);
	}
}
	VID_Play();
}
//make all equal 0 to be ready for another click on the remote
flag=0;
Frame_data[0]=0;
Edge_counter=0;
}

void VID_Play (void)
{
switch (Data)
{
case 69:
	DCMOTOR_VidRotatestop();
	break;
case 70:
	DCMOTOR_VidRotateforward();
	break;
case 71:
	DCMOTOR_VidRotatebackward();
	break;
case 68:
	DCMOTOR_VidRotateright();
	break;
case 64:
	DCMOTOR_VidRotateleft();
	break;
case 67:
	DCMOTOR_VidRotateleft();
	break;
case 7:
	DCMOTOR_VidRotateleft();
	break;
case 21:
	DCMOTOR_VidRotateleft();
	break;
case 9:
	DCMOTOR_VidRotateleft();
	break;
}
}

