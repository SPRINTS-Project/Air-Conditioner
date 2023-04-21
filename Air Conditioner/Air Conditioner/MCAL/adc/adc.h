/*
 * adc.h
 *
 * Created: 4/21/2023 12:27:22 AM
 *  Author: Mahmoud Sarhan
 *	EMAIL : Eng.mahmoud.adel94@gmail.com
 */ 


#ifndef ADC_H_
#define ADC_H_

#include <stdint.h>







typedef uint8_t u8_en_adcErrorsType;
#define ADC_E_OK					((u8_en_adcErrorsType)0x00)
#define ADC_E_NOT_OK				((u8_en_adcErrorsType)0x04)


typedef uint8_t u8_en_adcChannelId;

#define ADC_CHANNEL_0				((u8_en_adcChannelId)0x00)
#define ADC_CHANNEL_1				((u8_en_adcChannelId)0x01)
#define ADC_CHANNEL_2				((u8_en_adcChannelId)0x02)
#define ADC_CHANNEL_3				((u8_en_adcChannelId)0x03)
#define ADC_CHANNEL_4				((u8_en_adcChannelId)0x04)
#define ADC_CHANNEL_5				((u8_en_adcChannelId)0x05)
#define ADC_CHANNEL_6				((u8_en_adcChannelId)0x06)
#define ADC_CHANNEL_7				((u8_en_adcChannelId)0x07)




typedef uint8_t u8_en_adcRefType;
#define ADC_AREF_INTERNAL_VREF_OFF				((u8_en_adcRefType)0x00)
#define ADC_AVCC								((u8_en_adcRefType)0x01)
#define ADC_RESERVED							((u8_en_adcRefType)0x02)
#define ADC_INTERNAL_2_56V_REF					((u8_en_adcRefType)0x03)



typedef uint8_t u8_en_adcPrescalerType;
#define ADC_PRESCALER_2_0					((u8_en_adcPrescalerType)0x00)
#define ADC_PRESCALER_2						((u8_en_adcPrescalerType)0x01)
#define ADC_PRESCALER_4						((u8_en_adcPrescalerType)0x02)
#define ADC_PRESCALER_8						((u8_en_adcPrescalerType)0x03)
#define ADC_PRESCALER_16					((u8_en_adcPrescalerType)0x04)
#define ADC_PRESCALER_32					((u8_en_adcPrescalerType)0x05)
#define ADC_PRESCALER_64					((u8_en_adcPrescalerType)0x06)
#define ADC_PRESCALER_128					((u8_en_adcPrescalerType)0x07)




typedef struct
{
	u8_en_adcRefType u8_ref_selection;
	u8_en_adcPrescalerType u8_prescaler_selection;
}st_adcConfigType;



u8_en_adcErrorsType ADC_init (st_adcConfigType* st_config);
u8_en_adcErrorsType ADC_read (u8_en_adcChannelId u8_channelID,uint16_t * u16_data);


#endif	/*	ADC_H_	*/