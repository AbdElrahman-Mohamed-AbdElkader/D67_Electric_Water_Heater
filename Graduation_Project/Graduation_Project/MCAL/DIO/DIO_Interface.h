/*
 * DIO_Interface.h
 *
 * Created: 7/12/2024 9:09:40 PM
 *  Author: Carnival Stores
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "DIO_Private.h"

void DIO_SetPinDirection(dioPort port, dioPin pin, dioState state);

void DIO_SetPinValue(dioPort port, dioPin pin, dioStatus status);

void DIO_TogglePinValue(dioPort port, dioPin pin);

uint8_t DIO_GetPinValue(dioPort port, dioPin pin);

void DIO_SetPinPullUp(dioPort port, dioPin pin);



#endif /* DIO_INTERFACE_H_ */