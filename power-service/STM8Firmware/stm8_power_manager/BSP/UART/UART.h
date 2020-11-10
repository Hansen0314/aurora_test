#ifndef __UART_H
#define __UART_H
#include "stm8s_uart1.h"
#include "string.h"
void Peripheral_UART_Init();
void UART_Send(const char * msg);
#endif