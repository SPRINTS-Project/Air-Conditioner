/*
 * temp_sensor.h
 *
 * Created: 4/21/2023 12:27:22 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 


#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "../../MCAL/adc/adc_types.h"


typedef struct
{
	uint8_t u8_ref_selection;
	uint8_t u8_prescaler_selection;
	uint8_t u8_channel;
}st_tempSensorConfigType;

typedef uint8_t u8_en_tempSensorErrorsType;

#define TEMP_E_OK				((u8_en_tempSensorErrorsType)0x00)
#define TEMP_E_NOT_OK			((u8_en_tempSensorErrorsType)0x08)



u8_en_tempSensorErrorsType TEMP_SENSOR_init (st_tempSensorConfigType* st_config);

u8_en_tempSensorErrorsType TEMP_SENSOR_read (uint8_t * u8_data);

#endif /*	TEMP_SENSOR_H	*/