/*
 * LED2_Program.c
 *
 * Created: 7/12/2024 9:08:05 PM
 *  Author: Carnival Stores
 */ 

#include "LED2_Interface.h"

void LED2_Initialization(void)
{
	DIO_SetPinDirection(LED2_PORT, LED2_PIN, LED2_OUTPUT);
}
void LED2_ON (void)
{
	DIO_SetPinValue(LED2_PORT, LED2_PIN, LED2_HIGH);
}
void LED2_OFF(void)
{
	DIO_SetPinValue(LED2_PORT, LED2_PIN, LED2_LOW);
}
void LED2_Toggle(void)
{
	DIO_TogglePinValue(LED2_PORT, LED2_PIN);
}