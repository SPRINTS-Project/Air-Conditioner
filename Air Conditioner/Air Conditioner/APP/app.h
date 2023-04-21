/*
 * app.h
 *
 * Created: 4/21/2023 12:27:22 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 


#ifndef APP_H_
#define APP_H_

#include <stdlib.h>

#include "../HAL/buzzer/buzzer.h"
#include "../HAL/keypad/keypad.h"
#include "../HAL/lcd/lcd.h"
#include "../HAL/temp_sensor/temp_sensor.h"
#include "../HAL/timer_manager/timer_manager.h"


#define APP_TIMER_0_INIT_VALUE		240

typedef uint8_t u8_programStateType;

#define APP_WELCOME				((u8_programStateType)0x00)
#define APP_SET_TEMP			((u8_programStateType)0x01)
#define APP_WORKING				((u8_programStateType)0x02)

void APP_start(void);


#endif /* APP_H	*/