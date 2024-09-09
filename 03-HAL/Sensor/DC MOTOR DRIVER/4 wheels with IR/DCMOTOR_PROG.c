#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_INTERFACE.h"
#include "STK_INTERFACE.h"
#include "DCMOTOR_INTERFACE.h"
#include "DCMOTOR_PRIVATE.h"
//#include "TIMER_INTERFACE.h"

u8 backward=0;
u8 forward=0;

void DCMOTOR_VidLeftWheelsInit(void)
{
/*set the direction of the two input pins of the dc motor of the two left wheels to be OUT_SPEED_2MHZ_PUSHPULL pins */
	MGPIO_VidSetPinDirection(DC_MOTOR_PORT , DC_MOTOR_PIN1 ,0b0010 );
	MGPIO_VidSetPinDirection(DC_MOTOR_PORT , DC_MOTOR_PIN2 ,0b0010 );
	MGPIO_VidSetPinDirection(DC_MOTOR_PORT , DC_MOTOR_PIN5 ,0b0010 );
	MGPIO_VidSetPinDirection(DC_MOTOR_PORT , DC_MOTOR_PIN6 ,0b0010 );
		/*initialize the dc motor to be stop at the beginning*/
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , LOW);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , LOW);
    MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN5 , LOW);
    MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN6 , LOW);
}
void DCMOTOR_VidRightWheelsInit(void)
{
/*set the direction of the two input pins of the dc motor of the two right wheels to be OUT_SPEED_2MHZ_PUSHPULL pins */
	MGPIO_VidSetPinDirection(DC_MOTOR_PORT , DC_MOTOR_PIN3 , 0b0010);
	MGPIO_VidSetPinDirection(DC_MOTOR_PORT , DC_MOTOR_PIN4 , 0b0010);
    MGPIO_VidSetPinDirection(DC_MOTOR_PORT , DC_MOTOR_PIN7 , 0b0010);
	MGPIO_VidSetPinDirection(DC_MOTOR_PORT , DC_MOTOR_PIN8 , 0b0010);
		/*initialize the dc motor to be stop at the beginning*/
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN3 , LOW);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN4 , LOW);
    MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN7 , LOW);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN8 , LOW);
}

//not used
void DCMOTOR_VidRotate(u8 direction,u8 direction2)
{

//	 TIMER2_SetOCROPWM(100);
{switch(direction){
	case STOP:
		/*make the dc motor stop*/
		MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , LOW);
		MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , LOW);
		break;
	case CLK_WISE:
		/*make the dc motor start in CLOCK_WISE direction*/
		MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , LOW);
		MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , HIGH);

		break;
	case ANTI_CLK_WISE:
		/*make the dc motor start in ANTI_CLOCK_WISE  direction*/
		MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , HIGH);
		MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , LOW);

		break;
	}
switch(direction2){
	case STOP:
		/*make the dc motor stop*/
		MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN3 , LOW);
		MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN4 , LOW);
		break;
	case CLK_WISE:
		/*make the dc motor start in CLOCK_WISE direction*/
		MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN3 , LOW);
		MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN4 , HIGH);
		break;
	case ANTI_CLK_WISE:
		/*make the dc motor start in ANTI_CLOCK_WISE  direction*/
		MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN3 , HIGH);
		MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN4 , LOW);
		break;
	}
}
//TIMER2_SetOCROPWM(100);

}




void DCMOTOR_VidRotateright(void)
{
	//TIMER2_SetOCROPWM(70);

	//UPPER AND LOWER left wheel clk wise
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , LOW);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , HIGH);
    MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN5 , LOW);
    MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN6 , HIGH);
	//UPPER AND LOWER right wheel stop
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN3 , LOW);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN4 , LOW);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN7 , LOW);
    MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN8 , LOW);

	//then after some delay return stop
MSTK_voidSetBusyWaitms(500);
//stop
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN3 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN4 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN5 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN6 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN7 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN8 , LOW);

}
void DCMOTOR_VidRotateleft(void)
{

	//TIMER2_SetOCROPWM(70);

	//UPPER AND LOWER left wheel STOP
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , LOW);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , LOW);
    MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN5 , LOW);
    MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN6 , LOW);
	//UPPER AND LOWER right wheel clk wise
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN3 , LOW);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN4 , HIGH);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN7 , LOW);
    MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN8 , HIGH);

	//then after some delay return stop
MSTK_voidSetBusyWaitms(500);
//stop
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN3 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN4 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN5 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN6 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN7 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN8 , LOW);

}


void DCMOTOR_VidRotatestop(void)
{
//TIMER2_SetOCROPWM(50);
MSTK_voidSetBusyWaitms(500);
//then
//TIMER2_SetOCROPWM(30);
MSTK_voidSetBusyWaitms(500);
//then stop
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN3 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN4 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN5 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN6 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN7 , LOW);
MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN8 , LOW);
}

void DCMOTOR_VidRotateforward(void)
{
	
			if (forward == 0)
			//TIMER2_SetOCROPWM(50);
			forward++;
			backward=0;
			if( forward == 1)
			//TIMER2_SetOCROPWM(70);
			forward++;
			backward=0;
			if (forward == 2)
			//TIMER2_SetOCROPWM(100);
			backward=0;
			forward++;
	
	//all clk wise
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , LOW);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , HIGH);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN3 , LOW);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN4 , HIGH);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN5 , LOW);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN6 , HIGH);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN7 , LOW);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN8 , HIGH);
}
void DCMOTOR_VidRotatebackward(void)
{
	
		if (backward == 0)
		//TIMER2_SetOCROPWM(50);
		backward++;
		forward=0;
		if (backward == 1)
		//TIMER2_SetOCROPWM(70);
		backward++;
		forward=0;
		if (backward == 2)
		//TIMER2_SetOCROPWM(100);
		backward++;
		forward=0;
		
		//all anti clk wise
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , HIGH);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , LOW);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN3 , HIGH);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN4 , LOW);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN5 , HIGH);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN6 , LOW);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN7 , HIGH);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN8 , LOW);
}
//not used
void DCMOTOR_VidRotate180(void)
{
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , HIGH);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , LOW);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN3 , LOW);
	MGPIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN4 , HIGH);
}
