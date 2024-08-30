/*
 * LED1_Program.c
 *
 * Created: 7/12/2024 9:07:30 PM
 *  Author: Carnival Stores
 */ 

#include "LED1_Interface.h"

void LED1_Initialization(void)
{
	DIO_SetPinDirection(LED1_PORT, LED1_PIN, LED1_OUTPUT);
}
void LED1_ON (void)
{
	DIO_SetPinValue(LED1_PORT, LED1_PIN, LED1_HIGH);
}
void LED1_OFF(void)
{
	DIO_SetPinValue(LED1_PORT, LED1_PIN, LED1_LOW);
}
void LED1_Toggle(void)
{
	DIO_TogglePinValue(LED1_PORT, LED1_PIN);
}