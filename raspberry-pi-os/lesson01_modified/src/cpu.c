#include "mini_uart.h"

void cpu_main(void)
{
	delay(3000);
	uart_send_string("Hello, world from processor ");
	
	unsigned int cpuId = getCPUId();
	if(cpuId == 0) 
		uart_send('0');
	else
		uart_send('n');
	uart_send('\r\n');
}
