/*
 * DIO_Configuration.h
 *
 * Created: 7/12/2024 9:09:29 PM
 *  Author: Carnival Stores
 */ 


#ifndef DIO_CONFIGURATION_H_
#define DIO_CONFIGURATION_H_

#include "DIO_Address.h"
#include "CPU_Configuration.h"


typedef enum
{
	DIO_PORTA = 0,
	DIO_PORTB = 1,
	DIO_PORTC = 2,
	DIO_PORTD = 3
}dioPort;

typedef enum
{
	DIO_PIN0 = 0,
	DIO_PIN1 = 1,
	DIO_PIN2 = 2,
	DIO_PIN3 = 3,
	DIO_PIN4 = 4,
	DIO_PIN5 = 5,
	DIO_PIN6 = 6,
	DIO_PIN7 = 7
}dioPin;

typedef enum
{
	DIO_INPUT  = 0,
	DIO_OUTPUT = 1
}dioState;

typedef enum
{
	DIO_LOW  = 0,
	DIO_HIGH = 1
}dioStatus;

typedef enum
{
	DIO_FALSE  = 0,
	DIO_TRUE   = 1
}dioReturn;




#endif /* DIO_CONFIGURATION_H_ */