#include "mini_uart.h"

void kernel_main(char * args)
{
	uart_init();
	uart_send_string("Hello, world from processor ");
	uart_send(args[0]);

	while (1) {
		uart_send(uart_recv());
	}
}
