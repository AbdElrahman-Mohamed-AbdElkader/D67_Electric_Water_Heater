/*
 * SEVEN_SEGMENT_Program.c
 *
 * Created: 7/12/2024 9:06:01 PM
 *  Author: Carnival Stores
 */ 

#include "SEVEN_SEGMENT_Interface.h"

void SEVENSEGMENT_Initialize(void)
{
	DIO_SetPinDirection(SEVSEG_CONTROL_PORT, SEVSEG_PIN_EN, SEVSEG_OUTPUT);
	DIO_SetPinDirection(SEVSEG_CONTROL_PORT, SEVSEG_PIN_DIP, SEVSEG_OUTPUT);
}

void SEVENSEGMENT_Enable(void)
{
	DIO_SetPinValue(DIO_PORTD, DIO_PIN1, SEVSEG_HIGH);
}
void SEVENSEGMENT_Disable(void)
{
	DIO_SetPinValue(DIO_PORTD, DIO_PIN1, SEVSEG_LOW);
}
void SEVENSEGMENT_Enable_DecimalPoint(void)
{
	DIO_SetPinValue(SEVSEG_CONTROL_PORT, SEVSEG_PIN_DIP, SEVSEG_HIGH);
}
void SEVENSEGMENT_Disable_DecimalPoint(void)
{
	DIO_SetPinValue(SEVSEG_CONTROL_PORT, SEVSEG_PIN_DIP, SEVSEG_LOW);
}

void SEVENSEGMENT_DisplayNumber(uint8_t number)
{
	uint8_t units = number % 10;
	uint8_t tens = number / 10;
	SEVSEG_PORT = units<<4;
	SEVSEG_DATA_PORT=tens;
}