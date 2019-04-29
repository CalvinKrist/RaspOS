#include "utils.h"
#include "printf.h"
#include "peripherals/timer.h"
#include "peripherals/mini_uart.h"

const unsigned int interval = 200000;
unsigned int ticks = 0;

void timer_init ( void )
{	
	/* Timer frequency = Clk/256 * 0x400 */
	put32(ARM_TIMER_LOAD, 0x400);
	
	put32(ARM_TIMER_CTRL, ARM_TIMER_CTRL_23BIT |
						  ARM_TIMER_CTRL_ENABLE |
						  ARM_TIMER_CTRL_INT_ENABLE |
						  ARM_TIMER_CTRL_PRESCALE_256);
}

void handle_timer_irq( void ) 
{
	ticks++;
	put32(ARM_TIMER_CLEAR, 1);
	//printf("Timer interrupt received from CPU %d with ticks %d\n\r", getCPU(), ticks);
	
	//printf("IIR_REG: %d", get32(AUX_MU_IIR_REG));
}
