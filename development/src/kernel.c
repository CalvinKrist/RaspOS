#include "printf.h"
#include "timer.h"
#include "irq.h"
#include "mini_uart.h"
#include "arm/cpu.h"
#include "peripherals/irq.h"
#include "utils.h"

void kernel_main(void)
{
	uart_init();
	init_printf(0, putc);
	

	irq_vector_init();
	timer_init();
	//enable_interrupt_controller();
	put32(ENABLE_BASIC_IRQS, ARM_TIMER_IRQ);
	enable_irq();
	
	printf("Hello from CPU %d!", getCPU());
}
