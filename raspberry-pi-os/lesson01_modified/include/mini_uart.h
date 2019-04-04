#ifndef	_MINI_UART_H
#define	_MINI_UART_H

#include "utils.h"
#include "peripherals/mini_uart.h"
#include "peripherals/gpio.h"

void uart_init ( void );
char uart_recv ( void );
void uart_send ( char c );
void uart_send_string(char* str);

#endif  /*_MINI_UART_H */
