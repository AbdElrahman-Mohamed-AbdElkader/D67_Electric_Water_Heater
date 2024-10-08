/*
 * SEVEN_SEGMENT_Configuration.h
 *
 * Created: 7/12/2024 9:05:40 PM
 *  Author: Carnival Stores
 */ 


#ifndef SEVEN_SEGMENT_CONFIGURATION_H_
#define SEVEN_SEGMENT_CONFIGURATION_H_

#include "CPU_Configuration.h"
#include "PERIPHERAL_LIBRARY.h"

#define SEVSEG_PORT           _DIO_PORTB
#define SEVSEG_DATA_PORT      _DIO_PORTA
#define SEVSEG_CONTROL_PORT   _DIO_PORTD
#define SEVSEG_PIN_A DIO_PIN4
#define SEVSEG_PIN_B DIO_PIN5
#define SEVSEG_PIN_C DIO_PIN6
#define SEVSEG_PIN_D DIO_PIN7

#define SEVSEG_PIN_E DIO_PIN0
#define SEVSEG_PIN_F DIO_PIN1
#define SEVSEG_PIN_G DIO_PIN2
#define SEVSEG_PIN_H DIO_PIN3

#define SEVSEG_PIN_EN DIO_PIN1
#define SEVSEG_PIN_DIP DIO_PIN3
#define SEVSEG_OUTPUT DIO_OUTPUT
#define SEVSEG_LOW  DIO_LOW
#define SEVSEG_HIGH DIO_HIGH



#endif /* SEVEN_SEGMENT_CONFIGURATION_H_ */