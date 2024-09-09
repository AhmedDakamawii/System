/*
 * Systick_Cfg.h
 *
 *  Created on: Jul 26, 2023
 *      Author: HP
 */

#ifndef SYSTICK_CFG_H_
#define SYSTICK_CFG_H_

#include "Systick_Private.h"

/* Normal Clock  AHB           "PROCESSOR_CLOCK"
 * Prescalar /8  to AHB        "PRESCALAR_CLOCK"
 * */
#define SysTick_CTRL_CLKSOURCE_Msk    PRESCALAR_CLOCK

#endif /* SYSTICK_CFG_H_ */
