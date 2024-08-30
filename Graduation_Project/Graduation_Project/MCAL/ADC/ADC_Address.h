/*
 * ADC_Address.h
 *
 * Created: 8/2/2024 7:09:03 PM
 *  Author: Carnival Stores
 */ 


#ifndef ADC_ADDRESS_H_
#define ADC_ADDRESS_H_

#include "CPU_Configuration.h"

#define _ADC_ADCL    (*(volatile uint8_t*)(0x24))
#define _ADC_ADCH    (*(volatile uint8_t*)(0x25))
#define _ADC_ADMUX   (*(volatile uint8_t*)(0x27))
#define _ADC_ADCSRA  (*(volatile uint8_t*)(0x26))
#define _ADC_SFIOR   (*(volatile uint8_t*)(0x50))

#define _ADC_DATA    (*(volatile uint16_t*)(0x24))



#endif /* ADC_ADDRESS_H_ */