 /***************************************************************/
 /* Author : ahmed elsayed                                      */
 /*version:  V01                                                */
 /*Date:                                                        */ 
/****************************************************************/

#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H

#define HIGH 1
#define LOW 0



void HTFT_VidInit(void);
void HTFT_VidDisplayImage(const u16* Copy_Image);
void HTFT_VidDisplayFillColor(u16 Copy_Imagecolor);
void HTFT_VidDrawRect(u8 x1 , u8 x2 , u8 y1 , u8 y2 ,u16 Copy_Imagecolor);


#endif
