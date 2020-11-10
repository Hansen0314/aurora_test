#include "GPIO.h"
void Peripheral_GPIO_Init()
{
  /* Initialize I/Os in Output Mode */
  GPIO_Init(Power_CTR_GPIO_PORT, (GPIO_Pin_TypeDef)Power_CTR_GPIO_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);   //PB5
  GPIO_Init(Watchdog_OUT_PORT, (GPIO_Pin_TypeDef)Watchdog_OUT_GPIO_PIN, GPIO_MODE_OUT_PP_LOW_SLOW);  
  GPIO_WriteHigh(Power_CTR_GPIO_PORT,(GPIO_Pin_TypeDef)Power_CTR_GPIO_PIN); //power on
  //enable 5V power
  /*  Init GPIO */
  GPIO_Init(Watchdog_IN_PORT, Watchdog_IN_GPIO_PIN, GPIO_MODE_IN_FL_NO_IT);
  GPIO_Init(BBB_POWER_PORT,BBB_POWER_GPIO_PIN,GPIO_MODE_IN_FL_IT);
}
void Disable_GPIO()
{
  GPIO_WriteLow(Watchdog_IN_PORT,Watchdog_IN_GPIO_PIN);
  GPIO_Init(Watchdog_IN_PORT, Watchdog_IN_GPIO_PIN, GPIO_MODE_IN_FL_NO_IT);
  GPIO_Init(BBB_POWER_PORT,BBB_POWER_GPIO_PIN,GPIO_MODE_IN_FL_NO_IT);
  GPIO_WriteLow(Watchdog_OUT_PORT,Watchdog_OUT_GPIO_PIN);
  GPIO_Init(Watchdog_OUT_PORT, Watchdog_OUT_GPIO_PIN, GPIO_MODE_IN_FL_NO_IT);
  GPIO_WriteLow(GPIOD,GPIO_PIN_5);
  GPIO_Init(GPIOD,GPIO_PIN_5,GPIO_MODE_IN_FL_NO_IT);
  GPIO_WriteLow(GPIOD,GPIO_PIN_6);
  GPIO_Init(GPIOD,GPIO_PIN_6, GPIO_MODE_IN_FL_NO_IT);  
}