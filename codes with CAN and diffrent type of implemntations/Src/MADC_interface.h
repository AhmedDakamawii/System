#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H
#include "STD_TYPES.h"
#include "MADC_private.h"
#include "MADC_cfg.h"

void ADC_vidInit();
void ADC_EnableState();
void ADC_vidMode();
void ADC_vidstartConversion();
uint16 ADC_vidRead(MADC_Channel Channel, MADC_SampleTime SampleTime_Cycles);

#endif