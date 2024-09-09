/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  File:  		  Can_Reg.h
 *  Module:  	  Can_Reg
 *
 *  Description:  Header file for CAN Module Registers
 *
 *  -------------------------------------------------------------------------------------------------------------------
 *	Author: 	  Mohamed Hesham,Mohamed samy,Mohamed Tamer,Mohamed Walid
 *	Date:		  2/11/2022
 *********************************************************************************************************************/

#ifndef CAN_PRIVATE_H_
#define CAN_PRIVATE_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


#define CAN1 ((volatile CAN_t *)0x40006400)
#define CAN2 ((volatile CAN_t *)0x40006800)



/* sent and received messages structure */
typedef struct  {
  uint32  ID;                 // 29 bit identifier
  uint8   Data[8];            // Data field
  uint8   Length;                // Length of data field in bytes          ---options From  0  to  8
  uint8   Format;             // 0 - STANDARD, 1- EXTENDED IDENTIFIER   ---options CAN_MSG_Standard_Format - CAN_MSG_Extended_Format
  uint8   Type;               // 0 - DATA FRAME, 1 - REMOTE FRAME       ---options CAN_MSG_DataFrame - CAN_MSG_RemoteFram
  uint8   MailBoxNum;         // Number of Mailbox to send message with ---options CAN_TSR_TME0	- CAN_TSR_TME1 - CAN_TSR_TME2
  uint8   FilterMatchIndex;   // the index of the filter that the received message passed through
} CAN_Message;


#define Reset_Value 0X0000

/*
 * STATUS FOR MAILBOXES
 * 0: NOT READY
 * 1: READY
 * 234: WRONG MAILBOX NUMBER
 * 233: WRONG FIFO_NUMBER
 */
#define Wrong_FIFO_number_error -1

#define Wrong_Mailbox_number_error 234

#define TRANSMIT_MAILBOX_READY   1

#define TRANSMIT_MAILBOX_NOTREADY 0

/* enable and Disable Values for bits   */
#define Enable  1
#define Disable 0

/* Definition of the Messages Format    */
#define CAN_MSG_Standard_Format   0
#define CAN_MSG_Extended_Format   1

/* Ready and not ready Macros */

#define CAN_Rdy     1
#define CAN_NotRdy  0

/* Definition of the Messages Format    */
#define CAN_MSG_DataFrame    0
#define CAN_MSG_RemoteFram   1

/*
 *  MCR REGISTER BITFIELD
 */

typedef struct
{
	uint32 INRQ  : 1 ;
	uint32 SLEEP : 1 ;
	uint32     TXFP   : 1 ;
	uint32 RFLM: 1 ;
	uint32 NART : 1 ;
	uint32 AWUM  : 1 ;
	uint32 ABOM  : 1 ;
	uint32 TTCM : 1 ;
	uint32   : 7 ;
	uint32     RESET   : 1 ;
	uint32 DBFG : 1 ;
	uint32        : 15 ;
}CAN_MCR_BF;


/*
 *  MSR REGISTER BITFIELD
 */
typedef struct
{
    uint32 INNAK  : 1 ;
    uint32 SLAK : 1 ;
    uint32     ERRI   : 1 ;
    uint32 WKUI: 1 ;
    uint32 SLAKI : 1 ;
    uint32   : 3 ;
    uint32 TXM  : 1 ;
    uint32 RXM : 1 ;
    uint32  SAMP : 1 ;
    uint32     RX   : 1 ;
    uint32   : 20 ;
}CAN_MSR_BF;
// FOR CREATE MESSAGE
#define CAN_DATA_BYTE0_Shift  0
/* Byte 1 Shift 									 */
#define CAN_DATA_BYTE1_Shift  8
/* Byte 2 Shift 									 */
#define CAN_DATA_BYTE2_Shift  16
/* Byte 3 Shift 									 */
#define CAN_DATA_BYTE3_Shift  24

/*
 *  DATALOW BYTE REGISTER BITFIELD
 */
typedef struct
{
    uint32 DATA0  : 8 ;
    uint32 DATA1 : 8 ;
    uint32     DATA2   : 8 ;
    uint32 DATA3: 8 ;
}CAN_DATAL_BF;

/*
 *  DATAHIGH BYTE REGISTER BITFIELD
 */
typedef struct
{
    uint32 DATA4  : 8 ;
    uint32 DATA5 : 8 ;
    uint32     DATA6   : 8 ;
    uint32 DATA7: 8 ;
}CAN_DATAH_BF;



/*
 *  TSR REGISTER BITFIELD
 */
typedef struct
{
    uint32 RQCP0  : 1 ;
    uint32 TXOK0 : 1 ;
    uint32     ALST0   : 1 ;
    uint32 TEER0: 1 ;
    uint32   : 3 ;
    uint32 APRQ0 : 1 ;
    uint32 RQCP1  : 1 ;
    uint32 TXOK1: 1 ;
    uint32     ALST1   : 1 ;
    uint32 TEER1: 1 ;
    uint32   : 3 ;
    uint32 APRQ1 : 1 ;
    uint32 RQCP2  : 1 ;
    uint32 TXOK2 : 1 ;
    uint32     ALST2   : 1 ;
    uint32 TEER2: 1 ;
    uint32   : 3 ;
    uint32 APRQ2 : 1 ;
    uint32 CODE  : 2 ;
    uint32 TME0 : 1 ;
    uint32 TME1 : 1 ;
    uint32 TME2 : 1 ;
    uint32  LOW0 : 1 ;
    uint32  LOW1 : 1 ;
    uint32  LOW2 : 1 ;
}CAN_TSR_BF;


/*
 *  RF0R  REGISTER BITFIELD
 */
typedef struct
{
    uint32 FMP0  : 2 ;
    uint32  : 1 ;
    uint32     FULL0   : 1 ;
    uint32 FOVR0: 1 ;
    uint32 RFOM0 : 1 ;
    uint32   : 26 ;
}CAN_RF0R_BF;

/*
 *  RF1R  REGISTER BITFIELD
 */
typedef struct
{
    uint32 FMP1  : 2 ;
    uint32  : 1 ;
    uint32     FULL1  : 1 ;
    uint32 FOVR1: 1 ;
    uint32 RFOM1 : 1 ;
    uint32   : 26 ;
}CAN_RF1R_BF;

/*
 *  IER  REGISTER BITFIELD
 */
typedef struct
{
    uint32 TMEI  : 1 ;
    uint32 FMPIE0 : 1 ;
    uint32     FFIE0   : 1 ;
    uint32 FOVIE0: 1 ;
    uint32 FMPIE1 : 1 ;
    uint32     FFIE1   : 1 ;
    uint32 FOVIE1: 1 ;
    uint32   : 1 ;
    uint32 EWGIE : 1 ;
    uint32 EPVIE  : 1 ;
    uint32 BOFIE: 1 ;
    uint32     LECIE   : 1 ;
    uint32   : 3 ;
    uint32 ERRIE : 1 ;
    uint32 WJUIE  : 1 ;
    uint32 SLKIE : 1 ;
    uint32   : 14 ;

}CAN_IER_BF;

/*
 *  ESR REGISTER BITFIELD
 */
typedef struct
{
    uint32 EWGF  : 1 ;
    uint32  EPFF: 1 ;
    uint32     BOFF  : 1 ;
    uint32   : 1;
    uint32 LEC: 3 ;
    uint32   : 9;
    uint32 TEC : 8 ;
    uint32  REC : 8 ;
}CAN_ESR_BF;
/*
 *  BTR REGISTER BITFIELD & union to access register as a whole
 */
typedef struct
{
    uint32 BRB  : 10 ;
    uint32  : 6 ;
    uint32     TS1  : 4 ;
    uint32   TS2: 3;
    uint32 : 1 ;
    uint32   SJW: 2;
    uint32  : 4 ;
    uint32  LBKM : 1 ;
    uint32  SILM : 1 ;
}CAN_BTR_BF;
typedef union
{
	CAN_BTR_BF BF;
	uint32 R;
}CAN_BTR;
/*
 *  TIR REGISTER BITFIELD & union to access register as a whole
 */
typedef struct
{
    uint32 TXRQ  : 1 ;
    uint32 RTR : 1 ;
    uint32     IDE  : 1 ;
    uint32   EXID: 18;
    uint32 STID: 11 ;

}CAN_TIR_BF;
typedef union
{
	CAN_TIR_BF BF;
	uint32 R;
}CAN_TIR;
/*
 *  TDTR REGISTER BITFIELD
 */
typedef struct
{
    uint32 DLC  : 4 ;
    uint32 :4;
    uint32 TGT : 1 ;
    uint32 :7;
    uint32     TIME  : 16 ;
}CAN_TDTR_BF;
/*
 *  RIR REGISTER BITFIELD
 */
typedef struct
{
	  uint32 :1;
    uint32 RTR  : 1 ;
    uint32 IDE:1;
    uint32 EXID : 18 ;
    uint32 STD:11;

}CAN_RIR_BF;
/*
 *  RDTR REGISTER BITFIELD
 */
typedef struct
{
    uint32 DLC  : 4 ;
    uint32 :4;
    uint32 FMI : 8 ;
    uint32     TIME  : 16 ;
}CAN_RDTR_BF;
/*
 *  FMR REGISTER BITFIELD
 */
typedef struct
{
    uint32 FINIT  : 1 ;
    uint32 :7;
    uint32 CAN2SB : 6 ;
    uint32       : 18 ;
}CAN_FMR_BF;


/*
 *  FM1R REGISTER BITFIELD
 */
typedef struct
{
    uint32 FBM0  : 1 ;
    uint32 FBM1  : 1 ;
    uint32 FBM2  : 1 ;
    uint32 FBM3  : 1 ;
    uint32 FBM4  : 1 ;
    uint32 FBM5  : 1 ;
    uint32 FBM6  : 1 ;
    uint32 FBM7  : 1 ;
    uint32 FBM8  : 1 ;
    uint32 FBM9  : 1 ;
    uint32 FBM10  : 1 ;
    uint32 FBM11  : 1 ;
    uint32 FBM12  : 1 ;
    uint32 FBM13  : 1 ;
    uint32 FBM14  : 1 ;
    uint32 FBM15  : 1 ;
    uint32 FBM16  : 1 ;
    uint32 FBM17  : 1 ;
    uint32 FBM18  : 1 ;
    uint32 FBM19  : 1 ;
    uint32 FBM20  : 1 ;
    uint32 FBM21  : 1 ;
    uint32 FBM22  : 1 ;
    uint32 FBM23  : 1 ;
    uint32 FBM24  : 1 ;
    uint32 FBM25  : 1 ;
    uint32 FBM26  : 1 ;
    uint32 FBM27  : 1 ;
    uint32       : 4 ;
}CAN_FM1R_BF;
/*
 *  FS1R REGISTER BITFIELD
 */
typedef struct
{
    uint32 FSC0  : 1 ;
    uint32 FSC1  : 1 ;
    uint32 FSC2  : 1 ;
    uint32 FSC3  : 1 ;
    uint32 FSC4  : 1 ;
    uint32 FSC5  : 1 ;
    uint32 FSC6  : 1 ;
    uint32 FSC7  : 1 ;
    uint32 FSC8  : 1 ;
    uint32 FSC9  : 1 ;
    uint32 FSC10  : 1 ;
    uint32 FSC11  : 1 ;
    uint32 FSC12  : 1 ;
    uint32 FSC13  : 1 ;
    uint32 FSC14  : 1 ;
    uint32 FSC15  : 1 ;
    uint32 FSC16  : 1 ;
    uint32 FSC17  : 1 ;
    uint32 FSC18  : 1 ;
    uint32 FSC19  : 1 ;
    uint32 FSC20  : 1 ;
    uint32 FSC21  : 1 ;
    uint32 FSC22  : 1 ;
    uint32 FSC23  : 1 ;
    uint32 FSC24  : 1 ;
    uint32 FSC25  : 1 ;
    uint32 FSC26  : 1 ;
    uint32 FSC27  : 1 ;
    uint32       : 4 ;
}CAN_FS1R_BF;
/*
 *  FFA1R REGISTER BITFIELD
 */
typedef struct
{
    uint32 FFA0  : 1 ;
    uint32 FFA1  : 1 ;
    uint32 FFA2  : 1 ;
    uint32 FFA3  : 1 ;
    uint32 FFA4  : 1 ;
    uint32 FFA5  : 1 ;
    uint32 FFA6  : 1 ;
    uint32 FFA7  : 1 ;
    uint32 FFA8  : 1 ;
    uint32 FFA9  : 1 ;
    uint32 FFA10  : 1 ;
    uint32 FFA11  : 1 ;
    uint32 FFA12  : 1 ;
    uint32 FFA13  : 1 ;
    uint32 FFA14  : 1 ;
    uint32 FFA15  : 1 ;
    uint32 FFA16  : 1 ;
    uint32 FFA17  : 1 ;
    uint32 FFA18  : 1 ;
    uint32 FFA19  : 1 ;
    uint32 FFA20  : 1 ;
    uint32 FFA21  : 1 ;
    uint32 FFA22  : 1 ;
    uint32 FFA23  : 1 ;
    uint32 FFA24  : 1 ;
    uint32 FFA25  : 1 ;
    uint32 FFA26  : 1 ;
    uint32 FFA27  : 1 ;
    uint32       : 4 ;
}CAN_FFA1R_BF;
/*
 *  FA1R REGISTER BITFIELD
 */
typedef struct
{
    uint32 FACT0  : 1 ;
    uint32 FACT1  : 1 ;
    uint32 FACT2  : 1 ;
    uint32 FACT3  : 1 ;
    uint32 FACT4  : 1 ;
    uint32 FACT5  : 1 ;
    uint32 FACT6  : 1 ;
    uint32 FACT7  : 1 ;
    uint32 FACT8  : 1 ;
    uint32 FACT9  : 1 ;
    uint32 FACT10  : 1 ;
    uint32 FACT11  : 1 ;
    uint32 FACT12  : 1 ;
    uint32 FACT13  : 1 ;
    uint32 FACT14  : 1 ;
    uint32 FACT15  : 1 ;
    uint32 FACT16  : 1 ;
    uint32 FACT17  : 1 ;
    uint32 FACT18  : 1 ;
    uint32 FACT19  : 1 ;
    uint32 FACT20  : 1 ;
    uint32 FACT21  : 1 ;
    uint32 FACT22  : 1 ;
    uint32 FACT23  : 1 ;
    uint32 FACT24  : 1 ;
    uint32 FACT25  : 1 ;
    uint32 FACT26  : 1 ;
    uint32 FACT27  : 1 ;
    uint32       : 4 ;
}CAN_FA1R_BF;
typedef union
{
	CAN_FA1R_BF BF;
	uint32 R;
}CAN_FA1R;


#define FILTER_INIT_MODE 1
#define FILTER_ACTIVE_MODE 0

#define Filter0		0
#define Filter1		1
#define Filter2		2
#define Filter3		3
#define Filter4		4
#define Filter5		5
#define Filter6		6
#define Filter7		7
#define Filter8		8
#define Filter9		9
#define Filter10	10
#define Filter11	11
#define Filter12	12
#define Filter13	13
#define Filter14	14
#define Filter15	15
#define Filter16	16
#define Filter17	17
#define Filter18	18
#define Filter19	19
#define Filter20	20
#define Filter21	21
#define Filter22	22
#define Filter23	23
#define Filter24	24
#define Filter25	25
#define Filter26	26
#define Filter27	27


/* 				Baud Rate			  */
#define Baud_Rate     0x00050000 // 1MB
//#define Baud_Rate 0x001c0000 //500KB




typedef struct
{
  volatile uint32 FR1;
  volatile uint32 FR2;
} CAN_FilterRegister;

typedef struct
{

  volatile CAN_TIR TIR;
  volatile CAN_TDTR_BF TDTR;
  volatile CAN_DATAL_BF TDLR;
  volatile CAN_DATAH_BF TDHR;
} CAN_TxMailBox;

/*			  FIFO MailBox Structure for register Description			   */

typedef struct
{

  volatile CAN_RIR_BF RIR;
  volatile CAN_RDTR_BF RDTR;
  volatile CAN_DATAL_BF RDLR;
  volatile CAN_DATAH_BF RDHR;
} CAN_FIFOMailBox;
/*
 *  CAN REGISTERS
 *
 */
typedef struct Can_Private
{

   volatile CAN_MCR_BF MCR;
   volatile CAN_MSR_BF MSR;
   volatile CAN_TSR_BF TSR;
   volatile CAN_RF0R_BF RF0R;
   volatile CAN_RF1R_BF RF1R;
   volatile CAN_IER_BF IER;
   volatile CAN_ESR_BF ESR;
   volatile CAN_BTR BTR;
 volatile uint32 RESERVED1[88];
 CAN_TxMailBox TMAILBOX[3];
CAN_FIFOMailBox FIFO[2];
    volatile uint32 RESERVED2[12];
   volatile CAN_FMR_BF FMR;
   volatile CAN_FM1R_BF FM1R;
   volatile uint32 RESERVED3;
   volatile CAN_FS1R_BF FS1R;
      volatile uint32 RESERVED4;
   volatile CAN_FFA1R_BF FFA1R;
   volatile uint32 RESERVED5;
     volatile CAN_FA1R FA1R;
   volatile uint32 RESERVED6[8];
     CAN_FilterRegister Filter[28];

}CAN_t;


#endif
