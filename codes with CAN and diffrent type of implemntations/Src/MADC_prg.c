#include "STD_TYPES.h"
#include "Macros.h"
#include "RCC_Regs.h"
#include "RCC_cfg.h"
#include "RCC.h"
#include "MADC_private.h"
#include "MADC_cfg.h"
#include "MADC_interface.h"

void ADC_vidInit(){
/*ADC clock prescaler*/
#if ADC_clock_prescaler == PCLK2_divided_by_2
  
  (RCC->CFGR).BF.ADC_PRE=0x0;

#elif ADC_clock_prescaler == PCLK2_divided_by_4,
(RCC->CFGR).BF.ADC_PRE=0x1;
#elif ADC_clock_prescaler == PCLK2_divided_by_6,
(RCC->CFGR).BF.ADC_PRE=0x2;
#elif ADC_clock_prescaler == PCLK2_divided_by_8,
 (RCC->CFGR).BF.ADC_PRE=0x3;
#endif

#if ADC_Peripheral == ADC1
/*Enable the ADC clock for the specified peripheral*/
  (RCC->APB2ENR).BF.ADC1EN=0x1;

/* Alignement of data*/
#if Data_Align == RIGHT_ALIGNEMENT
  CLEAR_BIT(ADC_1->CR2, ALIGN);
#elif Data_Align == LEFT_ALIGNEMENT,
  SET_BIT(ADC_1->CR2, ALIGN);
#endif
#elif ADC_Peripheral == ADC2
  /*Enable the ADC clock for the specified peripheral*/
(RCC->APB2ENR).BF.ADC2EN=0x1;
/* Clear All CR2 */
  ADC_2->CR2  = 0;
/*Configure the ADC channel*/ 
  ADC_2->SQR1 = 0x00000000;  // Clear register
  ADC_2->SQR2 = 0x00000000; 
  ADC_2->SQR3 = Channel;  // Set the channel to be converted
  /* Alignement of data*/
#if Data_Align == RIGHT_ALIGNEMENT
  CLEAR_BIT(ADC_2->CR2, ALIGN);
#elif Data_Align == LEFT_ALIGNEMENT,
  SET_BIT(ADC_2->CR2, ALIGN);
#endif
#elif ADC_Peripheral == ADC3
  /*Enable the ADC clock for the specified peripheral*/
(RCC->APB2ENR).BF.ADC3EN=0x1;
/* Clear All CR2 */
  ADC_3>CR2  = 0;
/*Configure the ADC channel*/ 
  ADC_3->SQR1 = 0x00000000;  // Clear register
  ADC_3->SQR2 = 0x00000000; 
  ADC_3->SQR3 = Channel;  // Set the channel to be converted
  /* Alignement of data*/
#if Data_Align == RIGHT_ALIGNEMENT
  CLEAR_BIT(ADC_3->CR2, ALIGN);
#elif Data_Align == LEFT_ALIGNEMENT,
  SET_BIT(ADC_3->CR2, ALIGN);
#endif
#endif

}

void ADC_EnableState(){
    #if ADC_Peripheral == ADC1
        #if ADC_State == ENABLE_ADC
	    /* ADC ON again */
	    SET_BIT(ADC_1->CR2, ADON);
        /* wait for stability */
	   // MSTK_voidSetBusyWaitus(1);
	   // SET_BIT(ADC_1->CR2, ADON);

		#elif ADC_State == DISABLE_ADC
        /* ADC ON again */
	    CLEAR_BIT(ADC_1->CR2, ADON);
        #endif
    #elif ADC_Peripheral == ADC2
        #if ADC_State == ENABLE_ADC
	    /* ADC ON again */
	    SET_BIT(ADC_2->CR2, ADON);
        /* wait for stability */
	    MSTK_voidSetBusyWaitms(100);
	    SET_BIT(ADC_2->CR2, ADON);

		#elif ADC_State == DISABLE_ADC
        /* ADC ON again */
	    CLEAR_BIT(ADC_2->CR2, ADON);
        #endif   
    #elif ADC_Peripheral == ADC3
        #if ADC_State == ENABLE_ADC
	    /* ADC ON again */
	    SET_BIT(ADC_3->CR2, ADON);
        /* wait for stability */
	    MSTK_voidSetBusyWaitms(100);
        SET_BIT(ADC_3->CR2, ADON);
		#elif ADC_State == DISABLE_ADC
        /* ADC ON again */
	    CLEAR_BIT(ADC_3->CR2, ADON);
        #endif
    #endif
}

void ADC_vidMode(){
#if ADC_Peripheral == ADC1
        #if Conversion_Mode == ADC_SINGLE_CONVERSION
	    CLEAR_BIT(ADC_1->CR2,CONT);
		#elif Conversion_Mode == ADC_CONTINOUS_CONVERSION
        SET_BIT(ADC_1->CR2,CONT);
        #endif
#elif ADC_Peripheral == ADC2
        #if Conversion_Mode == ADC_SINGLE_CONVERSION
	    CLEAR_BIT(ADC_2->CR2,CONT);
		#elif Conversion_Mode == ADC_CONTINOUS_CONVERSION
        SET_BIT(ADC_2->CR2,CONT);
        #endif 
#elif ADC_Peripheral == ADC3
        #if Conversion_Mode == ADC_SINGLE_CONVERSION
	    CLEAR_BIT(ADC_3->CR2,CONT);
		#elif Conversion_Mode == ADC_CONTINOUS_CONVERSION
        SET_BIT(ADC_3->CR2,CONT);
        #endif 
#endif    

}

void ADC_vidstartConversion(){
    #if ADC_Peripheral == ADC1
    /*Initialize calibration register.*/    
    SET_BIT(ADC_1->CR2,RSTCAL);
    while(GET_BIT(ADC_1->CR2,RSTCAL));
    /*start the calibration*/
    SET_BIT(ADC_1->CR2,CAL);
    while(GET_BIT(ADC_1->CR2,CAL));
#elif ADC_Peripheral == ADC2
    /*Initialize calibration register.*/    
    SET_BIT(ADC_2->CR2,RSTCAL);
    while(GET_BIT(ADC_2->CR2,RSTCAL));
    /*start the calibration*/
    SET_BIT(ADC_2->CR2,CAL);
    while(GET_BIT(ADC_2->CR2,CAL));
#elif ADC_Peripheral == ADC3
     /*Initialize calibration register.*/    
    SET_BIT(ADC_3->CR2,RSTCAL);
    while(GET_BIT(ADC_3->CR2,RSTCAL));
    /*start the calibration*/
    SET_BIT(ADC_3->CR2,CAL);
    while(GET_BIT(ADC_3->CR2,CAL));
#endif    


}

uint16 ADC_value ;

uint16 ADC_vidRead(MADC_Channel Channel, MADC_SampleTime SampleTime_Cycles){
 #if ADC_Peripheral == ADC1
/* Clear All CR2 */
/*Configure the ADC channel*/ 
  ADC_1->SQR1 = 0x00000000;  // Clear register
  ADC_1->SQR2 = 0x00000000; 
  ADC_1->SQR3 = Channel;  // Set the channel to be converted
  
 /* Sample t0ime selection*/
  ADC_1->SMPR2 &= ~((uint32)(0b111)<<(Channel * 3));
  ADC_1->SMPR2 |=  ((uint32)(SampleTime_Cycles)<<(Channel * 3));
 
  while ((GET_BIT(ADC_1->SR,EOC)==0));  // If conversion has finished
		ADC_value = ADC_1->DR & 0x0FFF; // Read AD converted value

		SET_BIT(ADC_1->CR2,0); // Start new conversion

#elif ADC_Peripheral == ADC2
/* Clear All CR2 */
  ADC_2->CR2  = 0;
/*Configure the ADC channel*/ 
  ADC_2->SQR1 = 0x00000000;  // Clear register
  ADC_2->SQR2 = 0x00000000; 
  ADC_2->SQR3 = Channel;  // Set the channel to be converted
  
   /* Sample time selection*/
  ADC_2->SMPR2 &= ~((uint32)(0b111)<<(Channel * 3));
  ADC_2->SMPR2 |=  ((uint32)(SampleTime_Cycles)<<(Channel * 3));

if (GET_BIT(ADC_2->SR,EOC)) { // If conversion has finished
		ADC_value = ADC_2->DR & 0x0FFF; // Read AD converted value

		SET_BIT(ADC_2->CR2,0); // Start new conversion
	}
  #elif ADC_Peripheral == ADC3
/* Clear All CR2 */
  ADC_3->CR2  = 0;
/*Configure the ADC channel*/ 
  ADC_3->SQR1 = 0x00000000;  // Clear register
  ADC_3->SQR2 = 0x00000000; 
  ADC_3->SQR3 = Channel;  // Set the channel to be converted

   /* Sample time selection*/
  ADC_3->SMPR2 &= ~((uint32)(0b111)<<(Channel * 3));
  ADC_3->SMPR2 |=  ((uint32)(SampleTime_Cycles)<<(Channel * 3));

  if (GET_BIT(ADC_3->SR,EOC)) { // If conversion has finished
		ADC_value = ADC_3->DR & 0x0FFF; // Read AD converted value

		SET_BIT(ADC_3->CR2,0); // Start new conversion
	}
#endif 
return ADC_value;
}

