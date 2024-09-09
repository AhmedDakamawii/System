/**
*@file       EXTIx_Private.h
*@version    1.0.0
*@brief      MCAL ................
*@details    ...........................
*@author     Shehab aldeen mohammed abdalah
*/

#ifndef EXTIX_PRIVATE_H_
#define EXTIX_PRIVATE_H_

#include "Std_Types.h"

/****************************************************************************
************************  Version info  *************************************
*****************************************************************************/
/* Random */
#define VENDOR_ID                  150
#define MODULE_ID                  111
#define EXTIx_MAJOR_VERSION         1
#define EXTIx_MINOR_VERSION         0
#define EXTIx_PATCH_VERSION         0

#define EXTIx_E_PARAM_INVALID_PARAMETER         0x0A      /* Invalid channel requested         */
#define EXTIx_E_PARAM_POINTER                   0x20      /* API service called with a NULL pointer */

typedef struct {
	volatile uint32 IMR;              /* Interrupt mask register */
	volatile uint32 EMR;              /* Event mask register */
	volatile uint32 RTSR;             /* Falling trigger selection register */
	volatile uint32 FTSR;             /* Falling trigger selection register */
	volatile uint32 SWIER;            /* Software interrupt event register */
	volatile uint32 PR;               /* Pending register */
}EXTIX_REG;


typedef struct {
	volatile uint32 EVCR;              /* Event control register */
	volatile uint32 MAPR;              /* AF remap and debug I/O configuration register */
	volatile uint32 EXTICR1;           /* External interrupt configuration register 1 */
	volatile uint32 EXTICR2;           /* External interrupt configuration register 2 */
	volatile uint32 EXTICR3;           /* External interrupt configuration register 3 */
	volatile uint32 EXTICR4;           /* External interrupt configuration register 4 */
	volatile uint32 Res0;
	volatile uint32 MAPR2;             /* AF remap and debug I/O configuration register2 */
}AFIO_REG;

/* base address */
#define EXTI        ((EXTIX_REG *)(0x40010400))
#define AFIO        ((AFIO_REG  *)(0x40010400))

#endif /* EXTIX_PRIVATE_H_ */
