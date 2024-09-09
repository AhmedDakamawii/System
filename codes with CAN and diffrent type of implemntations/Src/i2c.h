/******************************************************************************************
 *								APIs supported by this driver
 *		 For more information about the APIs check the function definitions
 ******************************************************************************************/
/*
 * Peripheral Clock setup
 */
//void I2C_PeriClockControl(I2C_RegDef_t *pI2Cx, uint8_t EnorDi);

/*
 * Init and De-init
 */

#include "Std_Types.h"
#include "Common_Macros.h"
#include "Compiler.h"
#include "Platform_Types.h"
#include "i2c_Regs.h"
#include "i2c_Types.h"
#include "i2c_Cfg.h"

#include <stdint.h>
#include "string.h"
#include "RCC.h"



void I2C_Init(const I2C_ConfigType *i2c_config);


/*
 * Data Send and Receive
 */

void I2C_MasterSendData(I2C_ID i2cid , uint8 RA, uint32 Len, uint8 SlaveAddr, uint8 Data , uint8 Sr , uint8 SENDorNOT);
void I2C_MasterReceiveData(I2C_ID i2cid, int *pRxBuffer, uint32 Len, uint8 SlaveAddr, uint8 Sr);

uint8 I2C_MasterSendDataIT(I2C_ID i2cid, uint8 Txbuffer, uint32 Len, uint8 SlaveAddr);
uint8 I2C_MasterReceiveDataIT(I2C_ID i2cid ,uint8 *RxBuffer, uint8 Len, uint8 SlaveAddr);

void I2C_CloseReceiveData(I2C_ID i2cid);
void I2C_CloseSendData(I2C_ID i2cid);

void I2C_GenerateStopCondition(I2C_ID i2cid);


/*
 * IRQ Configuration and ISR handling
 */

//void I2C_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
//void I2C_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void I2C_EV_IRQHandling(I2C_ID i2cid);
//void I2C_ER_IRQHandling(I2C_ID i2cid);


/*
 * Application callback
 */

void I2C_ApplicationEventCallback(I2C_ID i2cid,uint8 AppEv);
