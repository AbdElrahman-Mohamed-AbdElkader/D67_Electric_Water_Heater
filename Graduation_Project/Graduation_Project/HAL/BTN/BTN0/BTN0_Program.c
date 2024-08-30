/*
 * BTN0_Program.c
 *
 * Created: 7/12/2024 9:02:54 PM
 *  Author: Carnival Stores
 */ 

#include "BTN0_Interface.h"

void BTN0_Initialize(void)
{
	DIO_SetPinDirection(BTN0_PORT, BTN0_PIN, BTN0_INPUT);
}
btn0_state BTN0_Read(void)
{
	uint8_t btnValue = BTN0_NPRESSED;
	btnValue = DIO_GetPinValue(BTN0_PORT, BTN0_PIN);
	return btnValue;
}