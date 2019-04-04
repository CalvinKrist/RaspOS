#include "mini_uart.h"
#include "utils.h"

void kernel_main(void)
{
	uart_init();
	uart_send_string("Hello, world from processor ");
	
	unsigned int cpuId = getCPUId();
	if(cpuId == 0) 
		uart_send('0');
	else
		uart_send('n');
	uart_send('\r\n');

	while (1) {
		uart_send(uart_recv());
	}
}
