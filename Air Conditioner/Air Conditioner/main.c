/*
 * Air Conditioner.c
 *
 * Created: 4/18/2023 11:34:59 PM
 * Author : Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>




#include "HAL/buzzer/buzzer.h"
int main(void)
{
	st_buzzerConfigType x;
	x.u8_pin = 0;
	x.u8_port = 0;
	BUZZER_init(&x);
    /* Replace with your application code */
    while (1) 
    {
		BUZZER_start();
		_delay_ms(2000);
		BUZZER_stop();
		_delay_ms(2000);
    }
}

