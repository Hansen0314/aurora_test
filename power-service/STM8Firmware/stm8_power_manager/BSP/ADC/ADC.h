#ifndef ADC_H
#define ADC_H
#include "stm8s_adc1.h"
/*---------------------------ADC-----------------------------------------------*/
#define Power_DETEC_PORT (GPIOD)
#define Power_DETEC_GPIO_PIN GPIO_PIN_3
#define Power_DETEC_ADC_CHANNEL ADC1_CHANNEL_4 
void Peripheral_ADC_Init(void);
u16 ADC_Concersion(ADC1_Channel_TypeDef ADC_Channels);
#endif