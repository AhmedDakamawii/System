/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Port_Lcfg.c
 *  Module:  	  Port_Lcfg
 *
 *  Description:  Source file for Port Module Configurations
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Salma Hisham
 *	Date:		    24/10/2023
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Port_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
const Port_configType Port_ConfigType =
{
		/************************************ PORTA ************************************/
		PORTA, PIN0, CHANNEL_ENABLED, INPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ, // Push Button for accident
		PORTA, PIN1, CHANNEL_ENABLED, OUTPUT, PIN_LEVEL_LOW, ANALOG, AFO_PUSH_PULL,DRIVE_10MHZ,  // pwm timer2 channel2 for h bridge
		PORTA, PIN2, CHANNEL_ENABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, AFO_PUSH_PULL,DRIVE_10MHZ, // uart2 tx for gsm
		PORTA, PIN3, CHANNEL_ENABLED, INPUT, PIN_LEVEL_LOW, INPUT_FLOATING, AFO_PUSH_PULL,DRIVE_10MHZ, //uart2 rx for gsm
		PORTA, PIN4, CHANNEL_ENABLED, INPUT, PIN_LEVEL_LOW, INPUT_FLOATING, AFO_OPEN_DRAIN,DRIVE_10MHZ, // Force sensor 1
		PORTA, PIN5, CHANNEL_ENABLED, INPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ, // force sensor 2
		PORTA, PIN6, CHANNEL_DISABLED, OUTPUT, PIN_LEVEL_LOW, ANALOG, GPO_PUSH_PULL,DRIVE_10MHZ, //UNUSED PIN
		PORTA, PIN7, CHANNEL_ENABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_PULL_UP, GPO_PUSH_PULL,DRIVE_10MHZ,//LED FOR ULTRASONIC
		PORTA, PIN8, CHANNEL_ENABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_PULL_DOWN, GPO_PUSH_PULL,DRIVE_10MHZ,//UNUSED PIN
		PORTA, PIN9, CHANNEL_ENABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, AFO_PUSH_PULL,DRIVE_10MHZ,//uart1 tx for bluetooth
		PORTA, PIN10, CHANNEL_ENABLED, INPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,//uart1 rx for bluetooth
		PORTA, PIN11, CHANNEL_ENABLED, INPUT, PIN_LEVEL_LOW, INPUT_FLOATING, AFO_PUSH_PULL,DRIVE_10MHZ,// can rx for esp32
		PORTA, PIN12, CHANNEL_ENABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, AFO_PUSH_PULL,DRIVE_10MHZ,// can tx for esp32
		PORTA, PIN13, CHANNEL_DISABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,//UNUSED PIN
		PORTA, PIN14, CHANNEL_DISABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,//UNUSED PIN
		PORTA, PIN15, CHANNEL_DISABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,// JTAG!!!
		/************************************ PORTB ************************************/
		PORTB, PIN0, CHANNEL_ENABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,//LED
		PORTB, PIN1, CHANNEL_ENABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,// ultrasonic trigger pin
		PORTB, PIN2, CHANNEL_DISABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,//UNUSED PIN
		PORTB, PIN3, CHANNEL_DISABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,// JTAG!!!
		PORTB, PIN4, CHANNEL_DISABLED, INPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,// JTAG!!!
		PORTB, PIN5, CHANNEL_DISABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,// Led indicator for incoming ambulance
		PORTB, PIN6, CHANNEL_ENABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, AFO_OPEN_DRAIN,DRIVE_10MHZ,// scl for i2c gyro
		PORTB, PIN7, CHANNEL_ENABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, AFO_OPEN_DRAIN,DRIVE_10MHZ,// sda for i2c gyro
		PORTB, PIN8, CHANNEL_ENABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,//
		PORTB, PIN9, CHANNEL_ENABLED, INPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,// ULTRASONIC ECHO BY ICU TIMER4 CHANNEL4
		PORTB, PIN10, CHANNEL_ENABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, AFO_PUSH_PULL,DRIVE_10MHZ,//uart3 tx for gps
		PORTB, PIN11, CHANNEL_ENABLED, INPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,//uart3 rx for gps
		PORTB, PIN12, CHANNEL_ENABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,//motor right side control pins
		PORTB, PIN13, CHANNEL_ENABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,//motor right side control pins
		PORTB, PIN14, CHANNEL_ENABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,//motor left side control pins
		PORTB, PIN15, CHANNEL_ENABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,//motor left side control pins
		/************************************ PORTC ************************************/
		PORTC, PIN13, CHANNEL_ENABLED, OUTPUT, PIN_LEVEL_HIGH, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ, // LED FOR INIT
		PORTC, PIN14, CHANNEL_DISABLED, OUTPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,
		PORTC, PIN15, CHANNEL_DISABLED, INPUT, PIN_LEVEL_LOW, INPUT_FLOATING, GPO_PUSH_PULL,DRIVE_10MHZ,
};

/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 *********************************************************************************************************************/
