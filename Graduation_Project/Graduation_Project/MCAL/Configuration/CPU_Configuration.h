/*
 * CPU_Configuration.h
 *
 * Created: 7/12/2024 9:08:40 PM
 *  Author: Carnival Stores
 */ 


#ifndef CPU_CONFIGURATION_H_
#define CPU_CONFIGURATION_H_

#undef F_CPU
#define F_CPU 16000000
#include <avr/io.h>
#include <avr/eeprom.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"


#endif /* CPU_CONFIGURATION_H_ */