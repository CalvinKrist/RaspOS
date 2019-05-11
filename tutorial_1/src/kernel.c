#include "mini_uart.h"

void kernel_main(void)
{
	uart_init();
	uart_send_string("Hello, world!\r\n");

    char c;
	while (1) {
        c = uart_recv();
        if(c == '\r')
            uart_send_string("\r\n");
        else
            uart_send(c);
	}
}
