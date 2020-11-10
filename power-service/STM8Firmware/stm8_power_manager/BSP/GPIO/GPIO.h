#ifndef __GPIO_H
#define __GPIO_H
#include "stm8s_gpio.h"
#define Power_CTR_GPIO_PORT  (GPIOB)
#define Power_CTR_GPIO_PIN  GPIO_PIN_5

#define BBB_POWER_PORT  (GPIOB)
#define BBB_POWER_GPIO_PIN  GPIO_PIN_4
/*if recive BBB_POWER_PORT restart after 2s*/

#define Watchdog_OUT_PORT (GPIOC)
#define Watchdog_OUT_GPIO_PIN GPIO_PIN_4
#define Watchdog_IN_PORT (GPIOD)
#define Watchdog_IN_GPIO_PIN GPIO_PIN_2
/*software watchdog by using rasing or falling*/

/* Private defines -----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void Peripheral_GPIO_Init();
void Disable_GPIO();
#endif