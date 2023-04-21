/*
 * keypad.h
 *
 * Created: 4/21/2023 12:27:22 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


#include <stdint.h>

typedef struct
{
	uint8_t u8_row1Pin;
	uint8_t u8_row2Pin;
	uint8_t u8_row3Pin;
	uint8_t u8_col1Pin;
	uint8_t u8_col2Pin;
	uint8_t u8_col3Pin;
	uint8_t u8_col4Pin;
}st_keypadConfigType;


typedef uint8_t u8_en_keypadErrorsType;
#define KEYPAD_E_OK					((u8_en_keypadErrorsType)0x00)
#define KEYPAD_E_NOT_OK				((u8_en_keypadErrorsType)0x07)

u8_en_keypadErrorsType KEYPAD_init (st_keypadConfigType* st_config);

u8_en_keypadErrorsType KEYPAD_read (uint8_t * u8_data);



#endif /* KEYPAD_H	*/