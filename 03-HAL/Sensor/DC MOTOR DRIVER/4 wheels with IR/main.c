#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "AFIO_interface.h"
#include "IR_interface.h"
#include "DCMOTOR_interface.h"

/* YOU SHOULD KNOW THAT THIS FUNCTION GETS THE DATA ON EACH BUTTON AND EACH BUTTON HAS ONLY ONE VALUE 
EXAMPLE : RED BUTTON (SWITCH ON) ALWAYS EQUAL 69 'E' and each button after this is incremented by 1 
so mode button equal 70 and so on*/
/*you should know that  address is constant but i dont know if this is the address of remote or IR sensor 
which is constant for the same hardware but anyway no need to read or work with the address
*/
//you should know that the pin should be input floating and the same pin should be EXTI on falling mode
// SO IF WE USE IT WE CAN MAKE A CODE BY IF CONDTION TO SAY IF WE CLICK ON BUTTON WITH VALUE KZA WE SHOULD DO KZA AND SO ON
//flag for know if this is the first falling edge or not
volatile u8 flag=0;
//this is to save the time of difference between each two adjacent falling edge in each index
volatile u32 Frame_data [50]={0};
//this is the variable that contain the index of each falling edge
volatile u8 Edge_counter=0;
//this is function for EXTI interrupt enters it when falling edge is come
void voidGetFrame(void)
{
	if (flag == 0)
	{
		//start timer
   MSTK_voidSetIntervalSinglems(500, VID_TakeAction);
   flag=1;
	}
	else
	{
		//each Frame_data index contains the time between two adjacent falling edge
		Frame_data[Edge_counter]=MSTK_u32GetElapsedTime();
		/*after first time we get value at index 0 should be about 13500 usec as its the time between
		 begin of start bit and end of start bit (begin of address bit)  */
/*then we use function STK_voidSetIntervalSinglems again after adding a new lines in it to disable the timer 
at the begining of the function and start count from the first to make sure no systick interrupt will happen until no more falling edge*/
		/*then after this index will have the second difference in time between falling edge which should
be 2250usec if we send 1(recieve 0 at IR) and  should be 1125usec if we send 0(recieve 1 at IR) and so on
		 until there is no other falling edges now systick interrupt can be fired and system ended  */
		  MSTK_voidSetIntervalSinglems(500, VID_TakeAction);
		  Edge_counter++;
	}
}

void main (void)
 {

	MRCC_VidInitSysClock();
	/*enable RCC GPIOA*/
	MRCC_VidEnableClock(2, 2);
	/*enable RCC GPIOB*/
	MRCC_VidEnableClock(2, 3);
/*INIT STK Timer*/
     MSTK_voidInit();
     /*DC MOTOR*/
     DCMOTOR_VidLeftWheelsInit();
     DCMOTOR_VidRightWheelsInit();
/*OUTPUT*/

/*INPUT*/
    MGPIO_VidSetPinDirection(0, 0, INPUT_FLOATING);//input floating connected to output of IR
/*enable AFIO CLK*/
	MRCC_VidEnableClock(2, 0);
/*EXTI*/
//ENABLE EXTI0 and use its ISR
MNVIC_VidEnableInterrupts(6);
MEXTI0_VidSetCallBack(voidGetFrame);
MEXTI_VidSetSignalLatch(0,FALLING );//LINE 0 FALLING MODE
MAFIO_VidSetEXTIConfig(0,AFIO_PORTB);//pin B0



while(1)
{
	

}



}
