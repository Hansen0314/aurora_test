/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "GPIO.h"
#include "UART.h"
#include "BSP_TIME.h"
#include "ADC.h"
#include "stm8s_it.h"
extern u8 BBG_Power_EXTI;
typedef enum {
    PW_ST_STARTUP = 0,
    PW_ST_SOFT_WDOG,
    PW_ST_OFF,
    PW_ST_ON,
    PW_ST_ENABLE,
}PW_STATE;
const char state_list[][20] = {"PW_ST_STARTUP","PW_ST_SOFT_WDOG","PW_ST_OFF","PW_ST_ON","PW_ST_ENABLE"};
PW_STATE pw_state;
#define FEEDBACK_TIME_MS 2000
#define POWER_DETECT_TIME_10MS 100
#define NORMAL_VOlTAGE 450
#define WAIT_POWER_ON_TIME_S 90
#define debug
#define FW_VERSION		"0.2"
/* MPU Power state machine */
u16 Power_DETEC_Voltage;
u8 enable_flag;
PW_STATE Power_State_machine(PW_STATE pw_state)
{
  u16 time_out = 0;
  BitStatus Watchdog_IN_SATE = RESET;
  BitStatus LAST_Watchdog_IN_SATE = RESET;
  u16 wait_power_on_time_s = WAIT_POWER_ON_TIME_S;
  PW_STATE pw_state_next = pw_state;
  bool Watchdog_IN_fall_trig = TRUE;
  switch(pw_state)
  {
    case PW_ST_STARTUP:
      Peripheral_UART_Init(); 
      Peripheral_GPIO_Init();
      Peripheral_ADC_Init();
      BBG_Power_EXTI  = 1;
      enableInterrupts();
      GPIO_WriteHigh(Power_CTR_GPIO_PORT,(GPIO_Pin_TypeDef)Power_CTR_GPIO_PIN); //power on
      pw_state_next = PW_ST_SOFT_WDOG;
      break;
    case PW_ST_SOFT_WDOG:
      GPIO_WriteHigh(Watchdog_OUT_PORT,(GPIO_Pin_TypeDef)Watchdog_OUT_GPIO_PIN);//feed to mcu
//      while(RESET == GPIO_ReadInputPin(Watchdog_IN_PORT,Watchdog_IN_GPIO_PIN))
//      {
//        Delay(1);
//        time_out++;
//        if (time_out > FEEDBACK_TIME_MS)
//        {
//          pw_state_next = PW_ST_OFF;
//          time_out = 0;
//          break;
//        }
//      }   
//      GPIO_WriteLow(Watchdog_OUT_PORT,(GPIO_Pin_TypeDef)Watchdog_OUT_GPIO_PIN);
      while(Watchdog_IN_fall_trig)
      {
        Watchdog_IN_SATE = GPIO_ReadInputPin(Watchdog_IN_PORT,(GPIO_Pin_TypeDef)Watchdog_IN_GPIO_PIN);
        if((RESET != LAST_Watchdog_IN_SATE)&&(RESET == Watchdog_IN_SATE))
        {
          GPIO_WriteLow(Watchdog_OUT_PORT,(GPIO_Pin_TypeDef)Watchdog_OUT_GPIO_PIN);
          Watchdog_IN_fall_trig = FALSE;
        }
        Delay(1);
        time_out++;
        if (time_out > FEEDBACK_TIME_MS)
        {
          pw_state_next = PW_ST_OFF;
          
          return pw_state_next;
        }
        LAST_Watchdog_IN_SATE = Watchdog_IN_SATE;
      }
      break;
    case PW_ST_OFF:
      GPIO_WriteLow(Power_CTR_GPIO_PORT,(GPIO_Pin_TypeDef)Power_CTR_GPIO_PIN);  //Power off after 2s late
      Delay(2000);
      pw_state_next = PW_ST_ON;
      break;
    case PW_ST_ON:
      GPIO_WriteHigh(Power_CTR_GPIO_PORT,(GPIO_Pin_TypeDef)Power_CTR_GPIO_PIN); //power on
      if(enable_flag){
          pw_state_next = PW_ST_ENABLE;
          enable_flag = 0;
          return pw_state_next;
      }
      pw_state_next = PW_ST_SOFT_WDOG;
      Power_DETEC_Voltage = ADC_Concersion(Power_DETEC_ADC_CHANNEL);
      time_out = 0;
      while(Power_DETEC_Voltage < NORMAL_VOlTAGE){
        Power_DETEC_Voltage = ADC_Concersion(Power_DETEC_ADC_CHANNEL);
        Delay(10);
        time_out++;
        if (time_out > POWER_DETECT_TIME_10MS)
        {
          pw_state_next = PW_ST_OFF;
          return pw_state_next;
        }          
      }
      break;
    case PW_ST_ENABLE:
      Delay(200);
      Power_DETEC_Voltage = ADC_Concersion(Power_DETEC_ADC_CHANNEL);
      time_out =0;
      while(Power_DETEC_Voltage < NORMAL_VOlTAGE){
        Power_DETEC_Voltage = ADC_Concersion(Power_DETEC_ADC_CHANNEL);
        Delay(10);
        time_out++;
        if (time_out > POWER_DETECT_TIME_10MS)
        {
          enable_flag = 1;
          pw_state_next = PW_ST_OFF;
          return pw_state_next;
        }          
      }
      while(RESET == GPIO_ReadInputPin(BBB_POWER_PORT,BBB_POWER_GPIO_PIN)) 
      {
        Disable_GPIO();
        Delay(10);
      }
      pw_state_next = PW_ST_STARTUP;
      break;
  }
  if (pw_state_next == PW_ST_SOFT_WDOG)
  {
      while(wait_power_on_time_s -- && BBG_Power_EXTI)
        Delay(1000); 
      if (BBG_Power_EXTI == 0){
        BBG_Power_EXTI  = 1;
        pw_state_next = PW_ST_ENABLE;
      }
  }// waiting for mcu power on 
  
  return pw_state_next;
}

void main(void)
{
  PW_STATE pw_state = PW_ST_ENABLE;
  PW_STATE pw_state_next = PW_ST_STARTUP;
  /* Infinite loop */
  CLK_Config();
  Peripheral_UART_Init();
  Peripheral_Time_Init();
  Peripheral_GPIO_Init();
  Peripheral_ADC_Init();
  EXTI_DeInit();
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOB, EXTI_SENSITIVITY_FALL_ONLY);
  enableInterrupts();
#ifdef debug 
      UART_Send("Power Firmware begin v" FW_VERSION);
      UART_Send("\r\n");
      UART_Send("Date: " __DATE__);
      UART_Send("\r\n");
#endif   
  while (1)
  {
#if 1
    pw_state_next = Power_State_machine(pw_state);
    if (pw_state != pw_state_next) {
        pw_state = pw_state_next;
#ifdef debug 
        UART_Send("New State = ");
        UART_Send(state_list[pw_state]);
        UART_Send("\r\n");
#endif
    } 
#endif
  }

  
}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif