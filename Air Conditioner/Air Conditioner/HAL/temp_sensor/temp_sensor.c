/*
 * temp_sensor.c
 *
 * Created: 4/21/2023 12:27:22 AM
 *  Author: Mohamed Abdel-Wahab
 *	EMAIL : mohamedhegay22@gmail.com
 */ 



#include "temp_sensor.h"
#include "../../MCAL/adc/adc.h"
#include "../../MCAL/dio/dio.h"

/*static u8_en_adcChannelId u8_sg_channelID;
static u8_en_adcRefType u8_sg_Vref;
static void get_channel(u8_en_adcChannelId u8_a_channelID);
static void get_Vref(u8_en_adcRefType u8_a_Vref);*/

static st_adcConfigType st_sg_adc;

u8_en_tempSensorErrorsType TEMP_SENSOR_init (st_tempSensorConfigType* st_config)
{
	u8_en_tempSensorErrorsType l_TempSensor_ret = TEMP_E_OK;
	u8_en_adcErrorsType l_adc_ret = ADC_E_OK;
	u8_en_dioErrors l_dio_ret = DIO_E_OK;
	
	if(NULL==st_config || st_config->u8_channel >= ADC_INVALID_CHANNEL || st_config->u8_prescaler_selection >= ADC_INVALID_PRESCALER )
	{
		l_TempSensor_ret = TEMP_E_NOT_OK;
	}
	else
	{
		st_sg_adc.u8_prescaler_selection = st_config->u8_prescaler_selection;
		st_sg_adc.u8_ref_selection = st_config->u8_ref_selection;
		l_adc_ret = ADC_init(&st_sg_adc);
		l_dio_ret = DIO_init(porta,st_config->u8_channel,STD_INPUT);
		/*get_channel(st_config->u8_channel);
		get_Vref(st_config->u8_ref_selection);*/
				
	}
	return l_TempSensor_ret;
}

u8_en_tempSensorErrorsType TEMP_SENSOR_read (st_tempSensorConfigType* st_config , uint8_t * u8_data)
{
	u8_en_tempSensorErrorsType l_TempSensor_ret = TEMP_E_OK;
	u8_en_adcErrorsType l_adc_ret = ADC_E_OK;
	double f64_l_readTemp_ADC = 0.0;
	double f64_l_stepSize = 0.0;
	
	if(NULL== u8_data || NULL==st_config || st_config->u8_channel >= ADC_INVALID_CHANNEL || st_config->u8_prescaler_selection >= ADC_INVALID_PRESCALER)
	{
		l_TempSensor_ret = TEMP_E_NOT_OK;
	}
	else
	{
		
		l_adc_ret = ADC_read(st_config->u8_channel,&f64_l_readTemp_ADC);
		if(ADC_E_OK==l_adc_ret)
		{
			if( ADC_INTERNAL_2_56V_REF == st_config->u8_ref_selection)
			{
				f64_l_stepSize = ( INTERNAL_VOLTAGE /ADC_MAX_RESOLUTION);
			}
			else if(ADC_AVCC == st_config->u8_ref_selection)
			{
				f64_l_stepSize = ( AVCC_VOLTAGE /ADC_MAX_RESOLUTION);
			}
			else
			{
				/*l_adc_ret = ADC_E_NOT_OK;*/
				//do nothing
			}			
		}
		else
		{
			//l_adc_ret = ADC_E_NOT_OK;
			return l_adc_ret;
		}
		
		/*get the ADC digital value in analog voltage(DAC) then in temperature degree*/
		if(((uint32_t)l_adc_ret * f64_l_stepSize * VOLTAGE_TO_CELSUIS_FACTOR) >= MAX_TEMPERATURE_SENSOR_VALUE)
		{
			// if temperature more than maximum ,will saturate at maximum possible temperature the sensor can measure 
			*u8_data = MAX_TEMPERATURE_SENSOR_VALUE ;
		}
		else
		{
			*u8_data = (uint8_t)((uint32_t)l_adc_ret * f64_l_stepSize * VOLTAGE_TO_CELSUIS_FACTOR);
		}
		
	}
	return l_TempSensor_ret;
}

/*static void get_channel(u8_en_adcChannelId u8_a_channelID)
{
	u8_sg_channelID = u8_a_channelID;
}
static void get_Vref(u8_en_adcRefType u8_a_Vref)
{
	u8_sg_Vref = u8_a_Vref;
}
*/