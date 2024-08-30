/*
 * EEPROM_Interface.h
 *
 * Created: 7/12/2024 8:54:29 PM
 *  Author: Carnival Stores
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

#include "EEPROM_Private.h"

void EEPROM_Write_Byte(uint16_t uinAddress, uint8_t uinData);
uint8_t EEPROM_Read_Byte(uint16_t uinAddress);
eeprom_status EEPROM_Erase_Byte(uint16_t uinAddress);

void eeprom_write_dword (uint32_t *__p, uint32_t __value);

void eeprom_write_float (float *__p, float __value);

void eeprom_write_block (const void *__src, void *__dst, size_t __n);

void eeprom_update_byte (uint8_t *__p, uint8_t __value);

void eeprom_update_word (uint16_t *__p, uint16_t __value);

void eeprom_update_dword (uint32_t *__p, uint32_t __value);

void eeprom_update_float (float *__p, float __value);

void eeprom_update_block (const void *__src, void *__dst, size_t __n);



#endif /* EEPROM_INTERFACE_H_ */