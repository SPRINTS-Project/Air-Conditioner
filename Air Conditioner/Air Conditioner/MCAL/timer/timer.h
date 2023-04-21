/*
 * timer.h
 *
 * Created: 4/21/2023 12:27:22 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "timer_types.h"

u8_en_timerErrorsType TIMER_init (st_timerConfigType* st_config);
u8_en_timerErrorsType TIMER_start (st_timerConfigType* st_config);
u8_en_timerErrorsType TIMER_stop (u8_en_timerNumberType u8_a_timerNum);
u8_en_timerErrorsType TIMER_reset (st_timerConfigType* st_config);
u8_en_timerErrorsType TIMER_setCallBack( void(*a_timerCallBack)(void), u8_en_timerNumberType u8_a_timerNum );


#endif	/*	TIMER_H	*/