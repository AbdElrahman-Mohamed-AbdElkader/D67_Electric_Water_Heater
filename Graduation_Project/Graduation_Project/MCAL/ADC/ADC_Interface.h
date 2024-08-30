/*
 * ADC_Interface.h
 *
 * Created: 8/2/2024 7:09:26 PM
 *  Author: Carnival Stores
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_Private.h"

void ADC_Initialize_WithInterrupt(adc_vref vref, adc_prescaler prescalar);

void ADC_Initialize_WithoutInterrupt(adc_vref vref, adc_prescaler prescalar);

uint16_t ADC_Read(adc_channel channel);



#endif /* ADC_INTERFACE_H_ */