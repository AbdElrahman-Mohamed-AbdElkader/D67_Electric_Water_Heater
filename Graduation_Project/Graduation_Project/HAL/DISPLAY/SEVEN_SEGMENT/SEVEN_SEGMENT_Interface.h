/*
 * SEVEN_SEGMENT_Interface.h
 *
 * Created: 7/12/2024 9:05:47 PM
 *  Author: Carnival Stores
 */ 


#ifndef SEVEN_SEGMENT_INTERFACE_H_
#define SEVEN_SEGMENT_INTERFACE_H_

#include "SEVEN_SEGMENT_Private.h"

void SEVENSEGMENT_Initialize(void);
void SEVENSEGMENT_Enable(void);
void SEVENSEGMENT_Disable(void);
void SEVENSEGMENT_Enable_DecimalPoint(void);
void SEVENSEGMENT_Disable_DecimalPoint(void);
void SEVENSEGMENT_DisplayNumber(uint8_t number);




#endif /* SEVEN_SEGMENT_INTERFACE_H_ */