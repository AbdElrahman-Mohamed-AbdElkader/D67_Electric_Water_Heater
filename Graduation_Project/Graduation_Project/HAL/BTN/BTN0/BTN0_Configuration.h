/*
 * BTN0_Configuration.h
 *
 * Created: 7/12/2024 9:02:25 PM
 *  Author: Carnival Stores
 */ 


#ifndef BTN0_CONFIGURATION_H_
#define BTN0_CONFIGURATION_H_

#include "CPU_Configuration.h"
#include "PERIPHERAL_LIBRARY.h"

#define BTN0_PIN       DIO_PIN0
#define BTN0_PORT      DIO_PORTB
#define BTN0_INPUT     DIO_INPUT
#define BTN0_LOW       DIO_LOW
#define BTN0_HIGH      DIO_HIGH
typedef enum
{
	BTN0_NPRESSED = BTN0_LOW,
	BTN0_PRESSED  = BTN0_HIGH
}btn0_state;



#endif /* BTN0_CONFIGURATION_H_ */