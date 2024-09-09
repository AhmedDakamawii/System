/******************************************************************************
 *
 * File Name: main.c
 *
 * Description: Graduation Project Application (Standard car)
 *
 * Target: Stm32f103c8
 *
 * Author: Ahmed Sayed
 * 		   Salma Hisham
 * 		   Mohamed Hesham
 * 		   Mohamed Emad
 * 		   Mohamed Tamer
 * 		   Mohamed Yahia
 *
 * Sponsored By: Vechilevo GMBH
 *
 * SW_VER: V2_1_1
 ******************************************************************************/
#include "Gpt.h"
#include "RCC.h"
#include "Port.h"
#include "Dio.h"
#include "MNVIC_interface.h"
#include "dc_motor.h"
#include "Gpt.h"
#include "Uart.h"
#include "Can.h"
#include "MADC_private.h"
#include "MADC_cfg.h"
#include "MADC_interface.h"
#include "GPS.h"
#include "gsm.h"
#include "i2c.h"
#include "i2c_Types.h"
#include "MPU6050.h"
#include "Force_Sensor.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#define SYNCH_TIME 150
/*Task Handlers*/
TaskHandle_t ULTRASONIC_HANDLER;
TaskHandle_t GSM_Handler;
TaskHandle_t MOTOR_Handler;
TaskHandle_t GPS_Handler;
TaskHandle_t Accident_Handler;
TaskHandle_t Bluetooth_Handler;
TaskHandle_t CAN_Handler;

/* enum and definitions*/
typedef enum
{
priority_1=1,
priority_2=2,
priority_3=3,
priority_4=4,
priority_5=5,
priority_6=6,
priority_7=7,
priority_8=8,
priority_9=9,
priority_10=10,
}global_priorities;

typedef enum
{
first_Delay_1=1,
first_Delay_2=2,
first_Delay_3=3,
first_Delay_4=4,
first_Delay_5=5,
first_Delay_6=6,
first_Delay_7=7,
first_Delay_8=8,
first_Delay_9=9,
first_Delay_10=10,
}global_first_delay;

#define US_TH1 5
#define US_TH2 40
#define US_TH3 60

/*Semaphore to access Motor API*/
SemaphoreHandle_t xSemaphore;

/*Global Flag*/
uint8 stop_flag = 0;
/*Used Tasks*/
void ULTRASONIC_FUNC(void *pvParameters);
void GSM_SEND_TEXT_TASK(void *pvParameters);
void MOTOR_TASK(void *pvParameters);
void GPS_TASK(void *pvParameters);
void COLLISION_DETECTION_TASK(void *pvParameters);
void Bluetooth_TASK(void *pvParameters);
void CAN_TASK(void *pvParameters);
/*Global Location Struct*/
GGASTRUCT Local_Find_location;
/*Buffer for esp received can message */
CAN_Message received_esp;

/* part FOR MOTOR And bluetooth*/
uint8 MOTOR_STATE_R = 0;

uint8 MOTOR_STATE_spare = 0;
uint8 LOCATION_received[24] = { 0 };


void MCAN_voidSendMessageGPS(uint8 *buffer) {
	uint8 buffer11[4] = { 0 };
	uint8 buffer12[4] = { 0 };
	uint8 buffer21[4] = { 0 };
	uint8 buffer22[4] = { 0 };
	uint8 buffer31[4] = { 0 };
	uint8 buffer32[4] = { 0 };
	uint8 i = 0;
	uint16 error_flag=0;
	received_esp.Data[0]=1;
	received_esp.Data[1]=1;
	received_esp.Data[2]=1;

//if(Local_Find_location.isfixValid==1 || Local_Find_location.isfixValid=='1')
//{
	error_flag=0;
	for (i = 0; i < 4; i++) {

		buffer11[i] = Local_Find_location.Full_location[i];

	}

	for (i = 0; i < 4; i++) {

		buffer12[i] = Local_Find_location.Full_location[i + 4];

	}


	while(received_esp.Data[0]==1)
	{
		error_flag++;
		if(error_flag>=SYNCH_TIME)
			break;

		Dio_WriteChannel(PORTA, PIN8, DIO_LEVEL_LOW);
	Dio_WriteChannel(PORTA, PIN8, DIO_LEVEL_HIGH);

		if (MCAN_pendingmessagescount(Filter_FIFO0) > 0) {

			MCAN_ReadMessage(&received_esp, Filter_FIFO0);
		} else if (MCAN_pendingmessagescount(Filter_FIFO1) > 0) {

			MCAN_ReadMessage(&received_esp, Filter_FIFO1);
		}
	MCAN_voidSendMessageSingleGPS(100, &buffer11, &buffer12);
	}

	error_flag=0;
	received_esp.Data[0]=1;
	received_esp.Data[1]=1;
	received_esp.Data[2]=1;


	for (i = 0; i < 4; i++)
		buffer21[i] = Local_Find_location.Full_location[i + 8];

	for (i = 0; i < 4; i++) {
		buffer22[i] = Local_Find_location.Full_location[i + 12];
	}




	while(received_esp.Data[1]==1)
	{
		error_flag++;
			if(error_flag>=SYNCH_TIME)
				break;

		Dio_WriteChannel(PORTA, PIN8, DIO_LEVEL_LOW);
		Dio_WriteChannel(PORTA, PIN8, DIO_LEVEL_HIGH);
		if (MCAN_pendingmessagescount(Filter_FIFO0) > 0) {

			MCAN_ReadMessage(&received_esp, Filter_FIFO0);
		} else if (MCAN_pendingmessagescount(Filter_FIFO1) > 0) {

			MCAN_ReadMessage(&received_esp, Filter_FIFO1);
		}
	MCAN_voidSendMessageSingleGPS(100, &buffer21, &buffer22);
	}





	for (i = 0; i < 4; i++)
		buffer31[i] = Local_Find_location.Full_location[i + 16];

	for (i = 0; i < 4; i++)
		buffer32[i] = Local_Find_location.Full_location[i + 20];

	error_flag=0;

	received_esp.Data[0]=1;
	received_esp.Data[1]=1;
	received_esp.Data[2]=1;

	while(received_esp.Data[2]==1)
	{
		error_flag++;
			if(error_flag>=SYNCH_TIME)
				break;

		Dio_WriteChannel(PORTA, PIN8, DIO_LEVEL_LOW);
	Dio_WriteChannel(PORTA, PIN8, DIO_LEVEL_HIGH);
		if (MCAN_pendingmessagescount(Filter_FIFO0) > 0) {

			MCAN_ReadMessage(&received_esp, Filter_FIFO0);
		} else if (MCAN_pendingmessagescount(Filter_FIFO1) > 0) {

			MCAN_ReadMessage(&received_esp, Filter_FIFO1);
		}
	MCAN_voidSendMessageSingleGPS(100, &buffer31, &buffer32);
	}

//}


}

// For delays in seconds use delaySeconds(TIMER3_DEF,seconds);

int main() {
	/*Binary returns to ensure Task creations*/
	BaseType_t ret1, ret2, ret3, ret4, ret5, ret6,ret7;

	RCC_Init();
	RCC_APB1PeripheralEnable(TIM4EN);
	RCC_APB1PeripheralEnable(TIM2EN);
	RCC_APB1PeripheralEnable(TIM3EN);
	RCC_APB1PeripheralEnable(USART2EN);
	RCC_APB1PeripheralEnable(USART3EN);
	RCC_APB2PeripheralEnable(USART1EN);
	RCC_APB1PeripheralEnable(CANEN);
	RCC_APB2PeripheralEnable(IOPAEN);
	RCC_APB2PeripheralEnable(IOPBEN);
	RCC_APB2PeripheralEnable(ADC1EN);

	Port_Init(&Port_ConfigType);
	Dio_WriteChannel(PORTA, PIN0, DIO_LEVEL_HIGH);
	MNVIC_SetPriorityGrouping(SIXTEEN_GROUPS_ZERO_SUB);

	MNVIC_SetPriority(TIM4_IRQ, priority_1);


	MNVIC_EnableIRQ(TIM4_IRQ);


	MTIM4_voidICUInit();

	USART_Init(&USART_configType);
	TIMER_init(&GPT_config2);

	MCAN_CANINIT();

	I2C_Init(&I2C_configType);
	MPU6050_Init();

	GSM_checkinit();

	Force_Init();
	/*********************	Task Creations	****************************/

	/*********************	Task [1]	****************************/
	ret1 = xTaskCreate(&ULTRASONIC_FUNC, "Distance read Task",
			(configSTACK_DEPTH_TYPE) 100, " UltraSonic", (UBaseType_t) priority_6,
			&ULTRASONIC_HANDLER);
	configASSERT(ret1 == pdPASS);
	/*********************	Task [2]	****************************/
	ret2 = xTaskCreate(&GSM_SEND_TEXT_TASK, "GSM Message Task",
			(configSTACK_DEPTH_TYPE) 100, "Task to send message through GSM",
			(UBaseType_t) priority_7, &GSM_Handler);
	configASSERT(ret2 == pdPASS);
	/*********************	Task [3]	****************************/
	ret3 = xTaskCreate(&MOTOR_TASK, "MOTOR Task",
			(configSTACK_DEPTH_TYPE) 100, "Motor Control Task(Motor,Bluetooth)",
			(UBaseType_t) priority_3, &MOTOR_Handler);
	configASSERT(ret3 == pdPASS);
	/*********************	Task [4]	****************************/
	ret4 = xTaskCreate(&GPS_TASK, "GPS Task", (configSTACK_DEPTH_TYPE) 100,
			"Send Location Task and CAN(GPS,CAN)", (UBaseType_t) priority_1,
			&GPS_Handler);
	configASSERT(ret4 == pdPASS);
	/*********************	Task [5]	****************************/
	ret5 = xTaskCreate(&COLLISION_DETECTION_TASK, "Collision Avoidance Task",
			(configSTACK_DEPTH_TYPE) 100, "ForceSensor, Gyroscope, UltraSonic",
			(UBaseType_t) priority_5, &Accident_Handler);
	configASSERT(ret5 == pdPASS);
	/*********************	Task [6]	****************************/
	ret6 = xTaskCreate(&Bluetooth_TASK, "Bluetooth Task",
			(configSTACK_DEPTH_TYPE) 100, "Bluetooth",
			(UBaseType_t) priority_4, &Bluetooth_Handler);
	configASSERT(ret6 == pdPASS);
	/*********************	Task [7]	****************************/
	ret7 = xTaskCreate(&CAN_TASK, "CAN TASK",
			(configSTACK_DEPTH_TYPE) 100, "CAN SEND DATA FROM GPS",
			(UBaseType_t) priority_1, &CAN_Handler);
	configASSERT(ret7 == pdPASS);
	/*********************************************************************************************/
	/*********************	Semaphore Creation	****************************/
	xSemaphore = xSemaphoreCreateMutex();

	/*System ON Led Indication*/
	Dio_WriteChannel(PORTC, PIN13, DIO_LEVEL_LOW);
	/*OS scheduler is on*/
	vTaskStartScheduler();
	while (1) {

	}
}
/***********************************[0]******************************************
 * Task Name: GSM_SEND_TEXT_TASK
 *
 * Task ID[hex]: 0x00
 *
 * Priority: 5ms
 *
 * First Delay: 6ms
 *
 * Periodcity: One time (When Car got crashed).
 *
 * Semaphores Used: N/A
 *
 * Notify/Notified: Notified by Collision Detection Task when Car is crashed
 *
 * Suspend/ Suspended by: Suspend all system tasks after sending Emergency Message
 * 						  to avoid Hazardous Consequences.
 * Resume/ Resumed by: N/A
 *
 * Hal Drivers Used: DC Motor, GSM
 *
 * MCAL Drivers Used: N/A
 *
 * Description: GSM Task to send message to the emergency center and stop the system after that.
 ********************************************************************************/
void GSM_SEND_TEXT_TASK(void *pvParameters) {
	vTaskDelay(pdMS_TO_TICKS(first_Delay_7));
	uint32 i=0;
	uint8 flag=0;
	while (1) {
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
		flag=0;

		for(i=0;i<=1500000;i++)
		{
			//DcMotor_Rotate('P');
			if(Dio_ReadChannel(PORTA,PIN0)==0)
				{

				flag=1;
				break;
				}

		}
		if(flag==0)
		{
			DcMotor_Rotate('P');
		vTaskSuspendAll();
		GSM_SendHelpMessage();
		vTaskSuspend(GSM_Handler);
		}

	}

}
/***********************************[1]*******************************************
 * Task Name: MOTOR_TASK
 *
 * Task ID[hex]: 0x01
 *
 * Priority: 1ms
 *
 * First Delay: 1ms
 *
 * Periodcity: 150 ms
 *
 * Semaphores Used: Use Semaphore to access DcMotor_Rotate API
 *
 * Notify/Notified: N/A
 *
 * Suspend/ Suspended by: Suspend UltraSonic Task.
 * 						  Suspended by GSM (System End point).
 *
 * Resume/ Resumed by: Resume UltraSonic Task
 *
 * Hal Drivers Used: Motor Driver
 *
 * MCAL Drivers Used: N/A
 *
 * Description: Motor control task to move the car
 *********************************************************************************/
void MOTOR_TASK(void *pvParameters) {
	vTaskDelay(pdMS_TO_TICKS(first_Delay_3));



	while (1) {

		if((MOTOR_STATE_R == 'R' || MOTOR_STATE_R == 'L'
				|| MOTOR_STATE_R == 'F' || MOTOR_STATE_R == 'B'|| MOTOR_STATE_R == 'P'))
		{
			if( xSemaphoreTake( xSemaphore, pdMS_TO_TICKS(1) ) == pdTRUE )
        {
				vTaskSuspend(ULTRASONIC_HANDLER);
			DcMotor_Rotate(MOTOR_STATE_R);
			xSemaphoreGive( xSemaphore );
			vTaskResume(ULTRASONIC_HANDLER);
        }
		}else
			if((MOTOR_STATE_spare == 'R' || MOTOR_STATE_spare == 'L'
					|| MOTOR_STATE_spare == 'F' || MOTOR_STATE_spare == 'B'|| MOTOR_STATE_spare == 'P'))
				{

				if( xSemaphoreTake( xSemaphore, pdMS_TO_TICKS(1) ) == pdTRUE )
			        {
					vTaskSuspend(ULTRASONIC_HANDLER);
						DcMotor_Rotate(MOTOR_STATE_spare);
						xSemaphoreGive( xSemaphore );
						vTaskResume(ULTRASONIC_HANDLER);
			        }
				}
		vTaskDelay(pdMS_TO_TICKS(150));

	}
}
/***********************************[2]*******************************************
 * Task Name: GPS_TASK
 *
 * Task ID[hex]: 0x02
 *
 * Priority: 1ms
 *
 * First Delay: 1ms
 *
 * Periodcity:
 *
 * Semaphores Used: N/A
 *
 * Notify/Notified: N/A
 *
 * Suspend/ Suspended by: Suspended by GSM (System End point).
 *
 * Resume/ Resumed by: N/A
 *
 * Hal Drivers Used: GPS Driver
 *
 * MCAL Drivers Used: N/A
 *
 * Description: GPS Task to update location
 *********************************************************************************/
void GPS_TASK(void *pvParameters) {
	vTaskDelay(pdMS_TO_TICKS(first_Delay_2));

	while (1) {


		GPS_GETLOCATION();


	}

}


/***********************************[3]*******************************************
 * Task Name: ULTRASONIC_FUNC
 *
 * Task ID[hex]: 0x03
 *
 * Priority: 4ms
 *
 * First Delay: 5ms
 *
 * Periodcity: 150ms
 *
 * Semaphores Used: Use Semaphore to access DcMotor_Rotate API
 *
 * Notify/Notified:
 *
 * Suspend/ Suspended by: Suspend Motor Task when Threshold front distance occured to stop.
 * 						  Suspended by Motor Task.
 * 						  Suspended by GSM (System End point).
 *
 * Resume/ Resumed by: Resumed by Motor Task
 *
 * Hal Drivers Used: Motor Driver
 *
 * MCAL Drivers Used: GPIO (LED indication when Car forced to stop)
 *
 * Description:UltraSonic Task to measure the distance between the car front and any obstacles,
 * 			   if the distance less than 40cm the car will stop.
 *********************************************************************************/
void ULTRASONIC_FUNC(void *pvParameters) {
	vTaskDelay(pdMS_TO_TICKS(first_Delay_6));
	uint8 DISTANCEREAD1 = 0;
	uint8 i = 0;

	while (1) {

		Dio_WriteChannel(PORTB, PIN1, DIO_LEVEL_HIGH);
		for (i = 0; i < 4; i++)
			;
		Dio_WriteChannel(PORTB, PIN1, DIO_LEVEL_LOW);
		DISTANCEREAD1 = MTIM4_GetDistance();

		if ( (DISTANCEREAD1 < US_TH3) )
			{
			Dio_WriteChannel(PORTA, PIN7, DIO_LEVEL_HIGH);


		if ((DISTANCEREAD1 >US_TH1) && (DISTANCEREAD1 < US_TH2) )
		{

			if( xSemaphoreTake( xSemaphore, pdMS_TO_TICKS(10) ) == pdTRUE )
					        {


				vTaskSuspend(MOTOR_Handler);

			DCMOTOR_voidULTRAstop();
			xSemaphoreGive( xSemaphore );
		//	Dio_WriteChannel(PORTA, PIN7, DIO_LEVEL_HIGH);

					        }

		}
			}
		else
		{

			Dio_WriteChannel(PORTA, PIN7, DIO_LEVEL_LOW);
		}

		vTaskDelay(pdMS_TO_TICKS(150));
	}

}
/***********************************[4]*******************************************
 * Task Name: COLLISION_DETECTION_TASK
 *
 * Task ID[hex]: 0x04
 *
 * Priority: 3ms
 *
 * First Delay: 4ms
 *
 * Periodcity:35ms
 *
 * Semaphores Used: N/A
 *
 * Notify/Notified: Notify GSM Task to start.
 *
 * Suspend/ Suspended by:Suspended by GSM (System End point)
 *
 * Resume/ Resumed by: N/A
 *
 * Hal Drivers Used: Gyroscope - Force sensor
 *
 * MCAL Drivers Used: GPIO (Accident occurrence LED indicator).
 *
 * Description: Collision task to detect if the car got hit or roll over then it notify GSM Task.
 *********************************************************************************/
void COLLISION_DETECTION_TASK(void *pvParameters) {
	vTaskDelay(pdMS_TO_TICKS(first_Delay_5));
	uint8 CollisionFlag1 = 0;
	uint8 CollisionFlag2 = 0;

	uint8 crash = 0;

	while (1) {

		crash = MPU6050_Read_Accel();
		CollisionFlag1 = force_disicion(Channel_4);
		CollisionFlag2 = force_disicion(Channel_5);
		if (CollisionFlag1 == TRUE || CollisionFlag2 == TRUE || crash == TRUE) {
			Dio_WriteChannel(PORTB, PIN0, DIO_LEVEL_HIGH);

			xTaskNotify(GSM_Handler, (uint32 ) 0, eIncrement);
		} else {
			Dio_WriteChannel(PORTB, PIN0, DIO_LEVEL_LOW);
		}

		vTaskDelay(pdMS_TO_TICKS(35));

	}

}




/***********************************[5]***********************************************************
 * Task Name: Bluetooth_TASK
 *
 * Task ID[hex]: 0x05
 *
 * Priority: 2ms
 *
 * First Delay: 3ms
 *
 * Periodcity: 110ms
 *
 * Semaphores Used: Use Semaphore to access DcMotor_Rotate API
 *
 * Notify/Notified: N/A
 *
 * Suspend/ Suspended by: Suspend UltraSonic Task -- Suspended by GSM (System End point).
 *
 * Resume/ Resumed by: Resume Motor Task -Resume Ultra Sonic
 *
 * Hal Drivers Used: N/A
 *
 * MCAL Drivers Used: USART (to recieve from Bluetooth).
 *
 * Description: Bluetooth task to recieve directions from mobile application.
 **************************************************************************************************/
void Bluetooth_TASK(void *pvParameters) {
	vTaskDelay(pdMS_TO_TICKS(first_Delay_4));
	uint8 flagr = 0;
uint8 local_r=0,local_spare=0;
	while (1) {
		flagr++;
		if (flagr == TRUE)
		{
			if( xSemaphoreTake( xSemaphore, pdMS_TO_TICKS(10) ) == pdTRUE )
							        {
			MOTOR_STATE_R = USART_ReceiveByte(USART1);
			local_r=MOTOR_STATE_R;

			xSemaphoreGive( xSemaphore );
							        }
		}
		else if (flagr == 2)
		{
			flagr = 0;
			if( xSemaphoreTake( xSemaphore, pdMS_TO_TICKS(10) ) == pdTRUE )
									        {
				MOTOR_STATE_spare = USART_ReceiveByte(USART1);
				local_spare=MOTOR_STATE_spare;
					xSemaphoreGive( xSemaphore );
									        }
		}
		if((local_r=='B')||(local_spare=='B'))
		{
			vTaskSuspend(ULTRASONIC_HANDLER);
			DcMotor_Rotate('B');
		}
			else 	if((MOTOR_STATE_R == 'R' || MOTOR_STATE_R == 'L' || MOTOR_STATE_R == 'F' ||  MOTOR_STATE_R == 'P')||
					(MOTOR_STATE_spare == 'R' || MOTOR_STATE_spare == 'L'
							|| MOTOR_STATE_spare == 'F'  || MOTOR_STATE_spare == 'P'))
			{
			vTaskResume(ULTRASONIC_HANDLER);
			}
			if((MOTOR_STATE_R == 'R' || MOTOR_STATE_R == 'L'
				|| MOTOR_STATE_R == 'F' || MOTOR_STATE_R == 'B'|| MOTOR_STATE_R == 'P'))
			vTaskResume(MOTOR_Handler);
		else
					if((MOTOR_STATE_spare == 'R' || MOTOR_STATE_spare == 'L'
							|| MOTOR_STATE_spare == 'F' || MOTOR_STATE_spare == 'B'|| MOTOR_STATE_spare == 'P'))
						vTaskResume(MOTOR_Handler);


		vTaskDelay(pdMS_TO_TICKS(110));
	}

}

/***********************************[6]*******************************************
 * Task Name: CAN_TASK
 *
 * Task ID[hex]: 0x06
 *
 * Priority: 1ms
 *
 * First Delay: 2ms
 *
 * Periodcity:
 *
 * Semaphores Used: N/A
 *
 * Notify/Notified: N/A
 *
 * Suspend/ Suspended by: Suspended by GSM (System End point).
 *
 * Resume/ Resumed by: N/A
 *
 * Hal Drivers Used: CAN Driver
 *
 * MCAL Drivers Used: N/A
 *
 * Description: CAN TASK TO SEND LOCATION
 *********************************************************************************/

void CAN_TASK(void *pvParameters)
{
	vTaskDelay(pdMS_TO_TICKS(first_Delay_1));

	while (1) {



 		MCAN_voidSendMessageGPS(&Local_Find_location.Full_location);


	}

}


