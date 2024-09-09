/*******************************************************************************
 * File Name          : RCC_Cfg.h
 * Author             : Mohamed Emad
 * Date               : 27/09/2022
 * Description        : This file contains static configurations for RCC driver
 ********************************************************************************/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef RCC_Cfg_H
#define RCC_Cfg_H
/*Reset values for the registers of RCC*/
#define RESET_VALUE_CR       0x00000083
#define RESET_VALUE_CFGR     0x00000000
#define RESET_VALUE_CIR      0x00000000
#define RESET_VALUE_APB2RSTR 0x00000000
#define RESET_VALUE_APB1RSTR 0x00000000
#define RESET_VALUE_AHBENR   0x00000014
#define RESET_VALUE_APB2ENR  0x00000000
#define RESET_VALUE_APB1ENR  0x00000000
#define RESET_VALUE_BDCR     0x00000000
#define RESET_VALUE_CSR      0x0C000000
/*The source of the clock*/
#define CLK_SOURCE HSI
/*The source of the pll*/
#define PLL_SOURCE HSI
/*AHB prescaler used*/
#define AHB_PRESCALER AHB_PRESCALER_NO
/*APB1 prescaler*/
#define APB1_PRESCALER APB_PRESCALER_NO
/*APB2 prescaler*/
#define APB2_PRESCALER APB_PRESCALER_NO
/*PLL multiplication values*/
#define PLL_MUL_2           0b0000
#define PLL_MUL_3           0b0001
#define PLL_MUL_4           0b0010
#define PLL_MUL_5           0b0011
#define PLL_MUL_6           0b0100
#define PLL_MUL_7           0b0101
#define PLL_MUL_8           0b0110
#define PLL_MUL_9           0b0111
#define PLL_MUL_10          0b1000
#define PLL_MUL_11          0b1001
#define PLL_MUL_12          0b1010
#define PLL_MUL_13          0b1011
#define PLL_MUL_14          0b1100
#define PLL_MUL_15          0b1101
#define PLL_MUL_16          0b1110
/*AHB prescaler values*/
#define AHB_PRESCALER_NO    0b0000
#define AHB_PRESCALER_2     0b1000
#define AHB_PRESCALER_4     0b1001
#define AHB_PRESCALER_8     0b1010
#define AHB_PRESCALER_16    0b1011
#define AHB_PRESCALER_64    0b1100
#define AHB_PRESCALER_128   0b1101
#define AHB_PRESCALER_256   0b1110
#define AHB_PRESCALER_512   0b1111
/*APB prescaler values*/
#define APB_PRESCALER_NO    0b000
#define APB_PRESCALER_2     0b100
#define APB_PRESCALER_4     0b101
#define APB_PRESCALER_8     0b110
#define APB_PRESCALER_16    0b111
/* PLLM multiplication factor*/
#define PLLM_VALUE PLL_MUL_2
/*clk sources defined*/
#define HSI                 1
#define HSE                 2
#define PLL                 3
/* System Buses */
#define AHB                 1
#define APB1                2
#define APB2                3
enum Status
{
    NotRdy = 0,
    Rdy = 1,
    OutOfRange = 2
};
#endif