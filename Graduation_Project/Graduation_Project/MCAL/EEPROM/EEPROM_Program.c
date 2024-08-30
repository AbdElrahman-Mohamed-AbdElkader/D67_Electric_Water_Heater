/*
 * EEPROM_Program.c
 *
 * Created: 7/12/2024 8:54:49 PM
 *  Author: Carnival Stores
 */ 

#include "EEPROM_Interface.h"

void EEPROM_Write_Byte(uint16_t uinAddress, uint8_t uinData)
{
	while(_EEPROM_EECR & (1<<EEWE));
	if(uinAddress >= 0 && uinAddress < 1024)
	{
		_EEPROM_EEAR = uinAddress;
		_EEPROM_EEDR = uinData;
		_EEPROM_EECR |= (1<<EEMWE);
		_EEPROM_EECR |= (1<<EEWE);
	}
}

uint8_t EEPROM_Read_Byte(uint16_t uinAddress)
{
	uint8_t eepromData = 0;
	while(_EEPROM_EECR & (1<<EEWE));
	if(uinAddress >= 0 && uinAddress < 1024)
	{
		_EEPROM_EEAR = uinAddress;
		_EEPROM_EECR |= (1<<EERE);
		eepromData = _EEPROM_EEDR;
	}
	return eepromData;
}

eeprom_status EEPROM_Erase_Byte(uint16_t uinAddress)
{
	return EEPROM_OK;
}
