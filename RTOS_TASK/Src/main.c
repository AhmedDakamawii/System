/******************************************************************************
 *
 * File Name: main.c
 *
 * Description: RTOS Tasks
 *
 * Author: Ahmed Sayed
 * 		   Alaa Youssif
 *
 * SW_VER: V2_1_1
 ******************************************************************************/

#include <stdint.h>
#include "MCU_Interface.h"
#include "FreeRTOS.h"
#include "task.h"
#include "LCD_Interface.h"
#include "Port_Interface.h"
#include "DIO_Interface.h"
#include "UART_Interface.h"
#include "queue.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

/*Task Handlers*/
TaskHandle_t ManageHandler;
TaskHandle_t ActionHandler;
TaskHandle_t LCDHandler;
TaskHandle_t LEDHandler;

/*Used Tasks*/
void MangmentTask_Func(void *pvParameters);
void ActionTask_Func(void *pvParameters);
void LCDTask_Func(void *pvParameters);
void LEDTask_Func(void *pvParameters);

/*Queue which is used to stop Racing condition in USART Buffer*/
QueueHandle_t MainQueue;

int main(void) {
	/*If the task was created successfully then pdPASS is returned.
	 * Otherwise errCOULD_NOT_ALLOCATE_REQUIRED_MEMORY is returned.*/
	BaseType_t ret1, ret2, ret3, ret4;
	/*MCU Initialization*/
	Mcu_Init();
	Mcu_EnumSetPerAPB2(APB2_PER_GPIOA);
	Mcu_EnumSetPerAPB2(APB2_PER_GPIOB);
	Mcu_EnumSetPerAPB2(APB2_PER_GPIOC);
	Mcu_VidRunnable();
	/*4 LED Pins init*/
	Port_EnumSetterPin(Port_A9, PORT_PIN_OUT | G_PUSH_PULL);
	Port_EnumSetterPin(Port_A10, PORT_PIN_OUT | G_PUSH_PULL);
	Port_EnumSetterPin(Port_A11, PORT_PIN_OUT | G_PUSH_PULL);
	Port_EnumSetterPin(Port_A12, PORT_PIN_OUT | G_PUSH_PULL);
	Port_VidRunnable();

	/*USART Peripheral Start*/
	USART_VidInit(arrOfUART);
	/*LCD Start*/
	LCD_VidInit();

	ret1 = xTaskCreate(&MangmentTask_Func, "Management Task",
			(configSTACK_DEPTH_TYPE) 100, "User Start select", (UBaseType_t) 2,
			&ManageHandler);
	configASSERT(ret1 == pdPASS);
	ret2 = xTaskCreate(&ActionTask_Func, "Action Task",
			(configSTACK_DEPTH_TYPE) 100, "User based decision task",
			(UBaseType_t) 1, &ActionHandler);
	configASSERT(ret2 == pdPASS);
	ret3 = xTaskCreate(&LCDTask_Func, "LCD Task", (configSTACK_DEPTH_TYPE) 100,
			"LCD String Display", (UBaseType_t) 0, &LCDHandler);
	configASSERT(ret3 == pdPASS);
	ret4 = xTaskCreate(&LEDTask_Func, "LED Task", (configSTACK_DEPTH_TYPE) 100,
			"LED Shape select", (UBaseType_t) 0, &LEDHandler);
	configASSERT(ret4 == pdPASS);

	/*Queue Created with size of 10 slots of 1 Byte*/
	MainQueue = xQueueCreate((UBaseType_t ) 10, (UBaseType_t ) sizeof(uint8));

	/*Start Scheduler*/
	vTaskStartScheduler();

	for (;;)
		;

}

/***********************************[1]***********************************************
 * Service Name: MangmentTask_Func
 * Service ID[hex]: 0x01
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): pvParameters (Ptr to void)
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Entry point of the system where the user can decide
 * 				which mode will operate either LCD or LED Mode
 *
 ************************************************************************************/

void MangmentTask_Func(void *pvParameters) {
	/*First delay of 1ms*/
	vTaskDelay(pdMS_TO_TICKS(1));
	uint8 UartRecieve;/*Local variable to send data to Queue*/

	for (;;) {
		UartRecieve = 0;
		/*Choose which mode to operate*/
		USART_TransmitString(UART3,
				"\nChoose option LED Mode --> 1  |or|  LCD Mode --> 2: ");

		while (UartRecieve != '1' && UartRecieve != '2') {
			UartRecieve = USART_ReceiveByte(UART3);
			/*System will brake if data is useful to avoid Queue Overflow*/
		}
		/*Send USART Data to queue*/
		xQueueSend(MainQueue, &UartRecieve, portMAX_DELAY);
		/*Notify Action Task to start*/
		xTaskNotify(ActionHandler, (uint32 ) 0, eIncrement);
		/*Mangment Task will be suspended*/
		vTaskSuspend(NULL);
	}
	/*Safety Check*/
	vTaskDelete(NULL_PTR);

}
/***********************************[2]***********************************************
 * Service Name: ActionTask_Func
 * Service ID[hex]: 0x02
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): pvParameters (Ptr to void)
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Action task Notify The user chosen task to operate
 ************************************************************************************/

void ActionTask_Func(void *pvParameters) {
	/*Fisrt delay of 2ms*/
	vTaskDelay(pdMS_TO_TICKS(2));
	/*Local variable to recieve data from Queue*/
	uint8 DesicionMessage;

	for (;;) {
		DesicionMessage = 0;
		/*Wait For Notications for maximum time*/
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
		/*If Data transfer is done the task will operate and store in variable from queue*/
		xQueueReceive(MainQueue, &DesicionMessage, portMAX_DELAY);

		/*User based switch*/
		switch (DesicionMessage) {
		case '1':
			/*LED Task Notify*/
			xTaskNotify(LEDHandler, (uint32 ) 0, eIncrement);
			break;
		case '2':
			/*LCD Task Notify*/
			xTaskNotify(LCDHandler, (uint32 ) 0, eIncrement);
			break;
		}

		vTaskSuspend(NULL);
	}
	vTaskDelete(NULL_PTR);

}
/***********************************[3]***********************************************
 * Service Name: LEDTask_Func
 * Service ID[hex]: 0x03
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): pvParameters (Ptr to void)
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Task which handle User chosen Led to light then resume the program
 ************************************************************************************/

void LEDTask_Func(void *pvParameters) {
	/*First Delay of 3ms*/
	vTaskDelay(pdMS_TO_TICKS(3));

	uint8 LEDMessage;
	for (;;) {
		LEDMessage = 0;
		/*Wait for notification from Action Task*/
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

		USART_TransmitString(UART3, "\nChoose LED [1:4]: ");
		/*Till Data is useful*/
		while (LEDMessage != '1' && LEDMessage != '2' && LEDMessage != '3'
				&& LEDMessage != '4') {
			LEDMessage = USART_ReceiveByte(UART3);
		}

		/*User choose Led to operate*/
		switch (LEDMessage) {
		case '1':
			USART_TransmitString(UART3, "\nGreen Led ON");
			Dio_WriteChannel(Dio_A9, STD_ON);
			Dio_WriteChannel(Dio_A10, STD_OFF);
			Dio_WriteChannel(Dio_A11, STD_OFF);
			Dio_WriteChannel(Dio_A12, STD_OFF);
			break;
		case '2':
			USART_TransmitString(UART3, "\nBlue LED ON");
			Dio_WriteChannel(Dio_A9, STD_OFF);
			Dio_WriteChannel(Dio_A10, STD_OFF);
			Dio_WriteChannel(Dio_A11, STD_ON);
			Dio_WriteChannel(Dio_A12, STD_OFF);
			break;
		case '3':
			Dio_WriteChannel(Dio_A9, STD_OFF);
			Dio_WriteChannel(Dio_A10, STD_ON);
			Dio_WriteChannel(Dio_A11, STD_OFF);
			Dio_WriteChannel(Dio_A12, STD_OFF);

			USART_TransmitString(UART3, "\nRed LED ON");
			break;
		case '4':
			USART_TransmitString(UART3, "\nWhite LED ON");
			Dio_WriteChannel(Dio_A9, STD_OFF);
			Dio_WriteChannel(Dio_A10, STD_OFF);
			Dio_WriteChannel(Dio_A11, STD_OFF);
			Dio_WriteChannel(Dio_A12, STD_ON);
			break;
		}
		/*Resume management task and action task from suspended state*/
		vTaskResume(ManageHandler);
		vTaskResume(ActionHandler);

	}
	vTaskDelete(NULL_PTR);

}
/***********************************[4]***********************************************
 * Service Name: LCDTask_Func
 * Service ID[hex]: 0x04
 * Sync/Async: Synchronous
 * Renterancy: Reentrant
 * Parameters (in): pvParameters (Ptr to void)
 * Parameters (InOut): None
 * Parameters (Out): None
 * Return value: None
 * Description: Task which shows string on LCD then resume the program
 ************************************************************************************/

void LCDTask_Func(void *pvParameters) {
	/*First Delay of 3ms*/
	vTaskDelay(pdMS_TO_TICKS(3));

	for (;;) {
		/*Wait for notification from Action Task*/
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
		/*User Transmit String through Uart the LCD prints it*/
		UART_ReciveString();
		/*Resume management task and action task from suspended state*/
		vTaskResume(ManageHandler);
		vTaskResume(ActionHandler);

	}

	vTaskDelete(NULL_PTR);

}

