#include "ADC.h"
void Peripheral_ADC_Init(void)
{       
      GPIO_Init(Power_DETEC_PORT, Power_DETEC_GPIO_PIN, GPIO_MODE_IN_FL_NO_IT);
      ADC1_DeInit();
      ADC1_Init(ADC1_CONVERSIONMODE_CONTINUOUS,ADC1_CHANNEL_4,ADC1_PRESSEL_FCPU_D2,\
	  ADC1_EXTTRIG_TIM,DISABLE,ADC1_ALIGN_RIGHT,ADC1_SCHMITTTRIG_CHANNEL9,\
	  DISABLE);  
      //ADC1_StartConversion();
      /* Enable EOC interrupt */
      //ADC1_ITConfig(ADC1_IT_EOCIE,ENABLE);
      /* Enable general interrupts */  
      //enableInterrupts();
}
u16 ADC_Concersion(ADC1_Channel_TypeDef ADC_Channels)
{
      u16 data;
      ADC1_ConversionConfig(ADC1_CONVERSIONMODE_SINGLE,ADC_Channels,ADC1_ALIGN_RIGHT);
      ADC1_StartConversion();
      while(!ADC1_GetFlagStatus(ADC1_FLAG_EOC));//等待转换结束
      ADC1_ClearFlag(ADC1_FLAG_EOC);//清除相关标识
      data = ADC1_GetConversionValue();
      return data;
}