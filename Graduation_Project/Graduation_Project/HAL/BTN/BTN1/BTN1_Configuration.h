/*
 * BTN1_Configuration.h
 *
 * Created: 7/12/2024 9:03:11 PM
 *  Author: Carnival Stores
 */ 


#ifndef BTN1_CONFIGURATION_H_
#define BTN1_CONFIGURATION_H_

#include "CPU_Configuration.h"
#include "PERIPHERAL_LIBRARY.h"

#define BTN1_PIN       DIO_PIN6
#define BTN1_PORT      DIO_PORTD
#define BTN1_INPUT     DIO_INPUT
#define BTN1_LOW       DIO_LOW
#define BTN1_HIGH      DIO_HIGH
typedef enum
{
	BTN1_NPRESSED = BTN1_LOW,
	BTN1_PRESSED  = BTN1_HIGH
}btn1_state;



#endif /* BTN1_CONFIGURATION_H_ */