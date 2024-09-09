/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Can_Cfg.h
 *  Module:  	  Can_Cfg
 *
 *  Description:  Header file for CAN Module configurations
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Mohamed Hesham,Mohamed samy,Mohamed Tamer,Mohamed Walid
 *	Date:		  23/10/2022
 *********************************************************************************************************************/
#ifndef CAN_CONFIG_H_
#define CAN_CONFIG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/



/**************************************************************/
/* Filter Configuration  							          */
/**************************************************************/

#define Mask_mode   0
#define List_mode   1

#define Dual_scale_configuration   0
#define Single_scale_configuration 1

#define Filter_FIFO0 0
#define Filter_FIFO1 1

/* FilterX_Enable             -Enable       -Disable	  	  */
/**************************************************************/
/* FilterX_Mode               -List_mode    -Mask_mode		  */
/**************************************************************/
/* FilterX_Scale											  */
/* -Dual_scale_configuration    							  */
/* -Single_scale_configuration  							  */
/**************************************************************/
/* FilterX_Assign             -Filter_FIFO0  -Filter_FIFO1	  */
/**************************************************************/
/* FilterX_ID1 - FilterX_ID2   ---> Set The Filters IDs       */
/**************************************************************/
#define Can_Filter0_Enable    Enable
#define Can_Filter0_Mode      List_mode
#define Can_Filter0_Scale      Single_scale_configuration
#define Can_Filter0_Assign    Filter_FIFO1
#define Can_Filter0_ID1      (100<<21)
#define Can_Filter0_ID2       (100 << 21)
/**************************************************************/
#define Can_Filter1_Enable    Enable
#define Can_Filter1_Mode      List_mode
#define Can_Filter1_Scale      Single_scale_configuration
#define Can_Filter1_Assign    Filter_FIFO1
#define Can_Filter1_ID1       (1000 << 21)
#define Can_Filter1_ID2       (1000 << 21)
/**************************************************************/
#define Can_Filter2_Enable    Enable
#define Can_Filter2_Mode      List_mode
#define Can_Filter2_Scale      Single_scale_configuration
#define Can_Filter2_Assign    Filter_FIFO0
#define Can_Filter2_ID1       (10 << 21)
#define Can_Filter2_ID2       (10 << 21)
/**************************************************************/
#define Can_Filter3_Enable    Enable
#define Can_Filter3_Mode      List_mode
#define Can_Filter3_Scale      Single_scale_configuration
#define Can_Filter3_Assign    Filter_FIFO1
#define Can_Filter3_ID1       (10 << 21)
#define Can_Filter3_ID2       (10 << 21)
/**************************************************************/
#define Can_Filter4_Enable    Enable
#define Can_Filter4_Mode      List_mode
#define Can_Filter4_Scale      Single_scale_configuration
#define Can_Filter4_Assign    Filter_FIFO0
#define Can_Filter4_ID1       (10 << 21)
#define Can_Filter4_ID2       (10 << 21)
/**************************************************************/
#define Can_Filter5_Enable    Enable
#define Can_Filter5_Mode      List_mode
#define Can_Filter5_Scale      Single_scale_configuration
#define Can_Filter5_Assign    Filter_FIFO1
#define Can_Filter5_ID1       (10 << 21)
#define Can_Filter5_ID2       (10 << 21)
/**************************************************************/
#define Can_Filter6_Enable    Enable
#define Can_Filter6_Mode      List_mode
#define Can_Filter6_Scale      Single_scale_configuration
#define Can_Filter6_Assign    Filter_FIFO0
#define Can_Filter6_ID1       (10 << 21)
#define Can_Filter6_ID2       (10 << 21)
/**************************************************************/
#define Can_Filter7_Enable    Enable
#define Can_Filter7_Mode      List_mode
#define Can_Filter7_Scale      Single_scale_configuration
#define Can_Filter7_Assign    Filter_FIFO1
#define Can_Filter7_ID1       (10 << 21)
#define Can_Filter7_ID2       (10 << 21)
/**************************************************************/
#define Can_Filter8_Enable    Enable
#define Can_Filter8_Mode      List_mode
#define Can_Filter8_Scale      Single_scale_configuration
#define Can_Filter8_Assign    Filter_FIFO0
#define Can_Filter8_ID1       (10 << 21)
#define Can_Filter8_ID2       (10 << 21)
/**************************************************************/
#define Can_Filter9_Enable    Enable
#define Can_Filter9_Mode      List_mode
#define Can_Filter9_Scale      Single_scale_configuration
#define Can_Filter9_Assign    Filter_FIFO1
#define Can_Filter9_ID1       (10 << 21)
#define Can_Filter9_ID2       (10 << 21)
/**************************************************************/
#define Can_Filter10_Enable   Enable
#define Can_Filter10_Mode     List_mode
#define Can_Filter10_Scale     Single_scale_configuration
#define Can_Filter10_Assign   Filter_FIFO0
#define Can_Filter10_ID1      (10 << 21)
#define Can_Filter10_ID2      (10 << 21)
/**************************************************************/
#define Can_Filter11_Enable   Enable
#define Can_Filter11_Mode     List_mode
#define Can_Filter11_Scale     Single_scale_configuration
#define Can_Filter11_Assign   Filter_FIFO1
#define Can_Filter11_ID1      (10 << 21)
#define Can_Filter11_ID2      (10 << 21)
/**************************************************************/
#define Can_Filter12_Enable   Enable
#define Can_Filter12_Mode     List_mode
#define Can_Filter12_Scale     Single_scale_configuration
#define Can_Filter12_Assign   Filter_FIFO0
#define Can_Filter12_ID1      (10 << 21)
#define Can_Filter12_ID2      (10 << 21)
/**************************************************************/
#define Can_Filter13_Enable   Enable
#define Can_Filter13_Mode     List_mode
#define Can_Filter13_Scale     Single_scale_configuration
#define Can_Filter13_Assign   Filter_FIFO1
#define Can_Filter13_ID1      (10 << 21)
#define Can_Filter13_ID2      (10 << 21)
///**************************************************************/
//#define Can_Filter14_Enable   Disable
//#define Can_Filter14_Mode     List_mode
//#define Can_Filter14_Scale     Single_scale_configuration
//#define Can_Filter14_Assign   Filter_FIFO0
//#define Can_Filter14_ID1      (10 << 21)
//#define Can_Filter14_ID2      (10 << 21)
///**************************************************************/
//#define Can_Filter15_Enable   Disable
//#define Can_Filter15_Mode     List_mode
//#define Can_Filter15_Scale     Single_scale_configuration
//#define Can_Filter15_Assign   Filter_FIFO0
//#define Can_Filter15_ID1      (10 << 21)
//#define Can_Filter15_ID2      (10 << 21)
///**************************************************************/
//#define Can_Filter16_Enable   Disable
//#define Can_Filter16_Mode     List_mode
//#define Can_Filter16_Scale     Single_scale_configuration
//#define Can_Filter16_Assign   Filter_FIFO0
//#define Can_Filter16_ID1      (10 << 21)
//#define Can_Filter16_ID2      (10 << 21)
///**************************************************************/
//#define Can_Filter17_Enable   Disable
//#define Can_Filter17_Mode     List_mode
//#define Can_Filter17_Scale     Single_scale_configuration
//#define Can_Filter17_Assign   Filter_FIFO0
//#define Can_Filter17_ID1      (10 << 21)
//#define Can_Filter17_ID2      (10 << 21)
///**************************************************************/
//#define Can_Filter18_Enable   Disable
//#define Can_Filter18_Mode     List_mode
//#define Can_Filter18_Scale     Single_scale_configuration
//#define Can_Filter18_Assign   Filter_FIFO0
//#define Can_Filter18_ID1      (10 << 21)
//#define Can_Filter18_ID2      (10 << 21)
///**************************************************************/
//#define Can_Filter19_Enable   Disable
//#define Can_Filter19_Mode     List_mode
//#define Can_Filter19_Scale     Single_scale_configuration
//#define Can_Filter19_Assign   Filter_FIFO0
//#define Can_Filter19_ID1      (10 << 21)
//#define Can_Filter19_ID2      (10 << 21)
///**************************************************************/
//#define Can_Filter20_Enable   Disable
//#define Can_Filter20_Mode     List_mode
//#define Can_Filter20_Scale     Single_scale_configuration
//#define Can_Filter20_Assign   Filter_FIFO0
//#define Can_Filter20_ID1      (10 << 21)
//#define Can_Filter20_ID2      (10 << 21)
///**************************************************************/
//#define Can_Filter21_Enable   Disable
//#define Can_Filter21_Mode     List_mode
//#define Can_Filter21_Scale     Single_scale_configuration
//#define Can_Filter21_Assign   Filter_FIFO0
//#define Can_Filter21_ID1      (10 << 21)
//#define Can_Filter21_ID2      (10 << 21)
///**************************************************************/
//#define Can_Filter22_Enable   Disable
//#define Can_Filter22_Mode     List_mode
//#define Can_Filter22_Scale     Single_scale_configuration
//#define Can_Filter22_Assign   Filter_FIFO0
//#define Can_Filter22_ID1      (10 << 21)
//#define Can_Filter22_ID2      (10 << 21)
///**************************************************************/
//#define Can_Filter23_Enable   Disable
//#define Can_Filter23_Mode     List_mode
//#define Can_Filter23_Scale     Single_scale_configuration
//#define Can_Filter23_Assign   Filter_FIFO0
//#define Can_Filter23_ID1      (10 << 21)
//#define Can_Filter23_ID2      (10 << 21)
///**************************************************************/
//#define Can_Filter24_Enable   Disable
//#define Can_Filter24_Mode     List_mode
//#define Can_Filter24_Scale     Single_scale_configuration
//#define Can_Filter24_Assign   Filter_FIFO0
//#define Can_Filter24_ID1      (10 << 21)
//#define Can_Filter24_ID2      (10 << 21)
///**************************************************************/
//#define Can_Filter25_Enable   Disable
//#define Can_Filter25_Mode     List_mode
//#define Can_Filter25_Scale     Single_scale_configuration
//#define Can_Filter25_Assign   Filter_FIFO0
//#define Can_Filter25_ID1      (10 << 21)
//#define Can_Filter25_ID2      (10 << 21)
///**************************************************************/
//#define Can_Filter26_Enable   Disable
//#define Can_Filter26_Mode     List_mode
//#define Can_Filter26_Scale     Single_scale_configuration
//#define Can_Filter26_Assign   Filter_FIFO0
//#define Can_Filter26_ID1      (10 << 21)
//#define Can_Filter26_ID2      (10 << 21)
///**************************************************************/
//#define Can_Filter27_Enable   Disable
//#define Can_Filter27_Mode     List_mode
//#define Can_Filter27_Scale     Single_scale_configuration
//#define Can_Filter27_Assign   Filter_FIFO0
//#define Can_Filter27_ID1      (10 << 21)
//#define Can_Filter27_ID2      (10 << 21)
///**************************************************************/

/*
 *             Transmit Mailboxes
 */
#define CAN_MAILBOX0 0
#define CAN_MAILBOX1 1
#define CAN_MAILBOX2 2
/*
 *             CONTROL REGISTER CONFIGURATION
 */

#define CAN_MCR_SLEEP 0
#define CAN_MCR_TXFP  0
#define CAN_MCR_RFLM  0
#define CAN_MCR_NART  0
#define CAN_MCR_AWUM  0
#define CAN_MCR_ABOM  1
#define CAN_MCR_TTCM   0
#define CAN_MCR_RESET   0
#define CAN_MCR_DBFG   0
#define CAN_IER_FMPIE1 1
#define CAN_IER_FMPIE0 0


///**************************************************************/
///* 				Test mode configs		  */
// */
#define Test_Mode Disable

/**************************************************************/
/* 				init mode configs		  */
#define CAN_MCR_INRQ 1
#define CAN_MCR_SLEEP 0


#endif
