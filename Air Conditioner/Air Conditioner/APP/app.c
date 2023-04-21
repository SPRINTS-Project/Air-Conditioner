/*
 * app.c
 *
 * Created: 4/21/2023 12:27:22 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 

#include "app.h"


static st_timerConfigType st_gs_timer_0_config;
static st_tempSensorConfigType st_gs_tempSensorConfig;
static st_lcdConfigType st_gs_lcdConfig;
static st_keypadConfigType st_gs_keypadConfig;
static st_buzzerConfigType st_gs_buzzerConfig;





void APP_init(void);


void APP_start(void)
{
	APP_init();
	while(1)
	{
		
	}
}


void APP_init(void)
{
	// Initialize timer 0 in Normal mode with OVF interrupt enabled and interrupt period every 0.5 ms
	st_gs_timer_0_config.u8_timerNum = TIMER_0;
	st_gs_timer_0_config.u8_timer_ovf_int_enable = 1;
	st_gs_timer_0_config.u16_timer_InitialValue = APP_TIMER_0_INIT_VALUE;
	TIMER_Manager_init(&st_gs_timer_0_config);
	
	// Initialize The Temp. sensor 
	st_gs_tempSensorConfig.u8_channel = ADC_CHANNEL_7;
	st_gs_tempSensorConfig.u8_ref_selection = ADC_AVCC;
	st_gs_tempSensorConfig.u8_prescaler_selection = ADC_PRESCALER_2;
	TEMP_SENSOR_init(&st_gs_tempSensorConfig);
	
	// Initialize the LCD
	st_gs_lcdConfig.u8_mode = LCD_4_BIT_MODE;
	st_gs_lcdConfig.u8_d4Pin[0] = porta;
	st_gs_lcdConfig.u8_d4Pin[1] = pin0;
	st_gs_lcdConfig.u8_d5Pin[0] = porta;
	st_gs_lcdConfig.u8_d5Pin[1] = pin1;
	st_gs_lcdConfig.u8_d6Pin[0] = porta;
	st_gs_lcdConfig.u8_d6Pin[1] = pin2;
	st_gs_lcdConfig.u8_d7Pin[0] = porta;
	st_gs_lcdConfig.u8_d7Pin[1] = pin3;
	LCD_init(&st_gs_lcdConfig);
	
	// Initialize the keypad
	st_gs_keypadConfig.u8_col1Pin[0] = portc;
	st_gs_keypadConfig.u8_col1Pin[1] = pin3;
	st_gs_keypadConfig.u8_col2Pin[0] = portc;
	st_gs_keypadConfig.u8_col2Pin[1] = pin4;
	st_gs_keypadConfig.u8_col3Pin[0] = portc;
	st_gs_keypadConfig.u8_col3Pin[1] = pin5;
	st_gs_keypadConfig.u8_col4Pin[0] = portc;
	st_gs_keypadConfig.u8_col4Pin[1] = pin6;
	st_gs_keypadConfig.u8_row1Pin[0] = portc;
	st_gs_keypadConfig.u8_row1Pin[1] = pin0 ;
	st_gs_keypadConfig.u8_row2Pin[0] = portc;
	st_gs_keypadConfig.u8_row2Pin[1] = pin1 ;
	st_gs_keypadConfig.u8_row3Pin[0] = portc;
	st_gs_keypadConfig.u8_row3Pin[1] = pin2 ;
	KEYPAD_init(&st_gs_keypadConfig);
	
	
	// Initialize Buzzer
	st_gs_buzzerConfig.u8_port = portb;
	st_gs_buzzerConfig.u8_pin = pin0;
	BUZZER_init(&st_gs_buzzerConfig);
}