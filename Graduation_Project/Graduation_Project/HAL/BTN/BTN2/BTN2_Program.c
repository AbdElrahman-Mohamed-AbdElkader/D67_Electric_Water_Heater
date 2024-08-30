/*
 * BTN2_Program.c
 *
 * Created: 7/12/2024 9:04:40 PM
 *  Author: Carnival Stores
 */ 

#include "BTN2_Interface.h"

void BTN2_Initialize(void)
{
	DIO_SetPinDirection(BTN2_PORT, BTN2_PIN, BTN2_INPUT);
}
btn2_state BTN2_Read(void)
{
	uint8_t btnValue = BTN2_NPRESSED;
	btnValue = DIO_GetPinValue(BTN2_PORT, BTN2_PIN);
	return btnValue;
}