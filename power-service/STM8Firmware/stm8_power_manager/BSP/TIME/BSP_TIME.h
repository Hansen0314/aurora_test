#ifndef __BSP_TIME_H
#define __BSP_TIME_H
#include "stm8s_tim4.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define TIM4_PERIOD       124
void CLK_Config(void);
void Peripheral_Time_Init(void);
void TimingDelay_Decrement(void);
void Delay(__IO uint32_t nTime);
extern __IO uint32_t TimingDelay;
#endif