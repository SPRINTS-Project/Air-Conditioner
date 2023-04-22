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
st_lcdConfigType st_gs_lcdConfig;
 st_keypadConfigType st_gs_keypadConfig;
static st_buzzerConfigType st_gs_buzzerConfig;
static u8_programStateType u8_en_gs_programState = APP_WELCOME;
static uint8_t u8_delay = 0;
const uint8_t u8_gc_defaultTemp = 20;
static uint8_t u8_gs_curTemp = 0;
static uint8_t u8_gs_programTemp = 0;


void APP_init(void);
void APP_welcome(void);
void APP_set(void);
void APP_working(void);
void APP_timer0OvfHandeler(void);


void APP_start(void)
{
	APP_init();
	while(1)
	{
		while(u8_en_gs_programState == APP_WELCOME)
		{
			APP_welcome();
		}
		while(u8_en_gs_programState == APP_SET_TEMP)
		{
			APP_set();
		}
		while(u8_en_gs_programState == APP_WORKING)
		{
			APP_working();
		}
	}
}


void APP_init(void)
{
	// Initialize timer 0 in Normal mode with OVF interrupt enabled and interrupt period every 0.5 ms
	st_gs_timer_0_config.u8_timerNum = TIMER_0;
	st_gs_timer_0_config.u8_timer_ovf_int_enable = 1;
	st_gs_timer_0_config.u16_timer_InitialValue = APP_TIMER_0_INIT_VALUE;
	st_gs_timer_0_config.callBackFunction =  APP_timer0OvfHandeler;
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
	st_gs_lcdConfig.u8_RSpin[0]=porta;
	st_gs_lcdConfig.u8_RSpin[1]=pin4;
	st_gs_lcdConfig.u8_RWpin[0]=porta;
	st_gs_lcdConfig.u8_RWpin[1]=pin5;
	st_gs_lcdConfig.u8_Epin[0]=porta;
	st_gs_lcdConfig.u8_Epin[1]=pin6;
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


void APP_welcome(void)
{
	LCD_clear();
	LCD_setCursor(1,1);
	LCD_writeString((uint8_t*)"Welcome");
	u8_delay = 0 ;
	while(u8_delay <= 2);
	LCD_clear();
	LCD_setCursor(1,1);
	LCD_writeString((uint8_t*)"default Temp is");
	LCD_setCursor(2,1);
	LCD_writeString((uint8_t*)"20");
	u8_delay = 0;
	while(u8_delay <= 2);
	LCD_clear();
	LCD_setCursor(1,1);
	LCD_writeString((uint8_t*)"Set Initial Temp");
	u8_delay = 0;
	while(u8_delay <= 1);
	u8_gs_programTemp = u8_gc_defaultTemp;
	u8_en_gs_programState = APP_SET_TEMP;
}




void APP_set(void)
{
	uint8_t u8_keypadData = 0;
	char ch_arrs_curTempToString[2];
	itoa(u8_gs_programTemp,ch_arrs_curTempToString,10);
	LCD_clear();
	LCD_setCursor(1,1);
	LCD_writeString((uint8_t*)"Min=18");
	LCD_setCursor(1,8);
	LCD_writeString((uint8_t*)ch_arrs_curTempToString);
	LCD_setCursor(1,11);
	LCD_writeString((uint8_t*)"Min=18");
	
	
	KEYPAD_read(&u8_keypadData);
	if (u8_keypadData == '1')
	{
		// Increment
		if (u8_gs_programTemp < 35)
		{
			u8_gs_programTemp++;
		}
	}
	else if (u8_keypadData == '2')
	{
		// Decrement
		if (u8_gs_programTemp >18)
		{
			u8_gs_programTemp--;
		}
	}
	else if (u8_keypadData == '3')
	{
		// Set
		u8_en_gs_programState = APP_WORKING;
	}
	else{
		// do nothing
	}
}



void APP_working(void)
{
	uint8_t u8_keypadData = 0;
	char ch_arrs_curTempToString[2];
	
	// convert int to string
	itoa(u8_gs_curTemp,ch_arrs_curTempToString,10);
	
	// print current temp
	LCD_clear();
	LCD_setCursor(1,1);
	LCD_writeString((uint8_t*)"Current Temp = ");
	LCD_setCursor(2,1);
	LCD_writeString((uint8_t*)ch_arrs_curTempToString);
	

	if (u8_gs_curTemp > u8_gs_programTemp)
	{
		// print the bell shape 
		LCD_writeSpChar(LCD_BELL);
		
		
		// start the BUZZER
		BUZZER_start();
	}
	KEYPAD_read(&u8_keypadData);
	if (u8_keypadData == '5')
	{
		// reset
		
		// Stop the BUZZER
		BUZZER_stop();
		
		// Set the program temp with the default temp
		u8_gs_programTemp = u8_gc_defaultTemp;
		
		// clear LCD and print Temp value is resettled to 20
		LCD_clear();
		LCD_setCursor(1,1);
		LCD_writeString((uint8_t*)"Temp value is resettled to 20");
		
		// 1s timeout
		u8_delay = 0;
		while(u8_delay <= 2);
		
		// change the program state
		u8_en_gs_programState = APP_SET_TEMP;
	}
	else if (u8_keypadData == '4')
	{
		// adjust
		
		// Stop the BUZZER
		BUZZER_stop();
		
		// change the program state
		u8_en_gs_programState = APP_SET_TEMP;
	}
	else{
		
		// Invalid button
		LCD_clear();
		LCD_setCursor(1,1);
		LCD_writeString((uint8_t*)"the operation is not allowed");
		
		// 1s timeout
		u8_delay = 0;
		while(u8_delay <= 2);
	}
}


void APP_timer0OvfHandeler(void)
{
	u8_delay++;
	TIMER_Manager_reset(&st_gs_timer_0_config);
}
