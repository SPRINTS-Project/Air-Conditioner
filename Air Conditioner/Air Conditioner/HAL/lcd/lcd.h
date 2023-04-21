/*
 * lcd.h
 *
 * Created: 4/21/2023 12:27:22 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 


#ifndef LCD_H_
#define LCD_H_

#include <stdint.h>


typedef struct
{
	uint8_t u8_mode;
	uint8_t u8_d0Pin;
	uint8_t u8_d1Pin;
	uint8_t u8_d2Pin;
	uint8_t u8_d3Pin;
	uint8_t u8_d4Pin;
	uint8_t u8_d5Pin;
	uint8_t u8_d6Pin;
	uint8_t u8_d7Pin;
}st_lcdConfigType;



typedef uint8_t u8_en_lcdErrorsType;

#define LCD_E_OK				((u8_en_lcdErrorsType)0x00)
#define LCD_E_NOT_OK			((u8_en_lcdErrorsType)0x05)


typedef uint8_t u8_en_lcdSpCharType;

#define LCD_EMPTY_HEART				((u8_en_lcdSpCharType)0X00)
#define LCD_FULL_HEART				((u8_en_lcdSpCharType)0X01)
#define LCD_BATTARY					((u8_en_lcdSpCharType)0X02)
#define LCD_BELL					((u8_en_lcdSpCharType)0X03)
#define LCD_SPEAKER					((u8_en_lcdSpCharType)0X04)
#define LCD_SMILE					((u8_en_lcdSpCharType)0X05)
#define LCD_PLUG					((u8_en_lcdSpCharType)0X06)
#define LCD_MUISC					((u8_en_lcdSpCharType)0X07)


u8_en_lcdErrorsType LCD_init (st_lcdConfigType* st_config);
u8_en_lcdErrorsType LCD_clear (void);
u8_en_lcdErrorsType LCD_setCursor (uint8_t u8_row,uint8_t u8_col);
u8_en_lcdErrorsType LCD_writeString (uint8_t* u8_data);
u8_en_lcdErrorsType LCD_writeSpChar (u8_en_lcdSpCharType u8_SpChar);


#endif /* KEYPAD_H	*/