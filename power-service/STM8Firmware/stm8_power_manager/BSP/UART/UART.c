#include "UART.h"
void Peripheral_UART_Init()
{
  UART1_DeInit();
  /* UART1 configuration ------------------------------------------------------*/
  /* UART1 configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Receive and transmit enabled
        - UART1 Clock disabled
  */
  UART1_Init((uint32_t)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO,
              UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
}
void UART_Send(const char * msg)
{
    uint16_t  len = strlen(msg);
    while (len--) {
        UART1_SendData8(*msg++);
        while(UART1_GetFlagStatus(UART1_FLAG_TC) == RESET);   
    }

}
