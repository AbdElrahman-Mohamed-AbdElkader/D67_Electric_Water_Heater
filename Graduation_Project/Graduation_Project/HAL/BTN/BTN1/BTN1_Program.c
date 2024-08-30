/*
 * BTN1_Program.c
 *
 * Created: 7/12/2024 9:04:03 PM
 *  Author: Carnival Stores
 */ 

#include "BTN1_Interface.h"

void BTN1_Initialize(void)
{
	DIO_SetPinDirection(BTN1_PORT, BTN1_PIN, BTN1_INPUT);
}
btn1_state BTN1_Read(void)
{
	uint8_t btnValue = BTN1_NPRESSED;
	btnValue = DIO_GetPinValue(BTN1_PORT, BTN1_PIN);
	return btnValue;
}