#include "klib.h"

void kernel_main(void)
{
	unsigned long id = getCPUId();
	init_printf(0, putc);
	
	if(id == 0) {
		uart_init();
		printf("Hello, world from %d!\r\n", id);
		printf("We are in privilege level %d.\r\n", get_el());
	} else {
		delay(300000000 * id);
	}
}