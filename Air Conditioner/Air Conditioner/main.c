/*
 * Air Conditioner.c
 *
 * Created: 4/18/2023 11:34:59 PM
 * Author : Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 
/*#define F_CPU 8000000UL


#include "APP/app.h"

#include "MCAL/adc/adc.h"
st_adcConfigType adc_config;
double data;
int main(void)
{
	adc_config.u8_prescaler_selection = ADC_PRESCALER_16;
	adc_config.u8_ref_selection = ADC_AVCC;
	ADC_init (&adc_config);
	
	while(1){
	ADC_read (ADC_CHANNEL_0,&data);	
	for(uint64_t i=0; i<1000;i++);
	}
	//APP_start();
}*/

