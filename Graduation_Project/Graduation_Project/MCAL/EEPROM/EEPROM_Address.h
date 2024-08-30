/*
 * EEPROM_Address.h
 *
 * Created: 7/12/2024 8:54:08 PM
 *  Author: Carnival Stores
 */ 


#ifndef EEPROM_ADDRESS_H_
#define EEPROM_ADDRESS_H_

#include "CPU_Configuration.h"

#define _EEPROM_EEAR  (* (volatile uint16_t*) (0x3E))
#define _EEPROM_EECR  (* (volatile uint8_t* ) (0x3C))
#define _EEPROM_EEDR  (* (volatile uint8_t* ) (0x3D))
#define _EEPROM_EEARL (* (volatile uint8_t* ) (0x3E))
#define _EEPROM_EEARH (* (volatile uint8_t* ) (0x3F))



#endif /* EEPROM_ADDRESS_H_ */