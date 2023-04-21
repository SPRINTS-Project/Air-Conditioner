/*
 * adc.h
 *
 * Created: 4/21/2023 12:27:22 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 


#ifndef ADC_H_
#define ADC_H_


#include "adc_types.h"


u8_en_adcErrorsType ADC_init (st_adcConfigType* st_config);
u8_en_adcErrorsType ADC_read (u8_en_adcChannelId u8_channelID,uint16_t * u16_data);


#endif	/*	ADC_H_	*/