/*
 * timer_manager.h
 *
 * Created: 4/21/2023 12:27:22 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 


#ifndef TIMER_MANAGER_H_
#define TIMER_MANAGER_H_

#include "../../MCAL/timer/timer_types.h"



u8_en_timerErrorsType TIMER_Manager_init (st_timerConfigType* st_config);
u8_en_timerErrorsType TIMER_Manager_start (st_timerConfigType* st_config);
u8_en_timerErrorsType TIMER_Manager_stop (u8_en_timerNumberType u8_en_timerNum);
u8_en_timerErrorsType TIMER_Manager_reset (st_timerConfigType* st_config);

#endif /*	TIMER_MANAGER_H_	*/