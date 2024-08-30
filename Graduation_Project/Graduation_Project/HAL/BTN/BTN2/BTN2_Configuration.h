/*
 * BTN2_Configuration.h
 *
 * Created: 7/12/2024 9:04:16 PM
 *  Author: Carnival Stores
 */ 


#ifndef BTN2_CONFIGURATION_H_
#define BTN2_CONFIGURATION_H_

#include "CPU_Configuration.h"
#include "PERIPHERAL_LIBRARY.h"

#define BTN2_PIN       DIO_PIN2
#define BTN2_PORT      DIO_PORTD
#define BTN2_INPUT     DIO_INPUT
#define BTN2_LOW       DIO_LOW
#define BTN2_HIGH      DIO_HIGH
typedef enum
{
	BTN2_NPRESSED = BTN2_LOW,
	BTN2_PRESSED  = BTN2_HIGH
}btn2_state;



#endif /* BTN2_CONFIGURATION_H_ */