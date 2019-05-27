#include "utils.h"
#include "printf.h"
#include "timer.h"
#include "entry.h"
#include "peripherals/irq.h"

int irq_1_enabled, irq_2_enabled, irq_basic_enabled;

const char *entry_error_messages[] = {
	"SYNC_INVALID_EL1t",
	"IRQ_INVALID_EL1t",		
	"FIQ_INVALID_EL1t",		
	"ERROR_INVALID_EL1T",		

	"SYNC_INVALID_EL1h",		
	"IRQ_INVALID_EL1h",		
	"FIQ_INVALID_EL1h",		
	"ERROR_INVALID_EL1h",		

	"SYNC_INVALID_EL0_64",		
	"IRQ_INVALID_EL0_64",		
	"FIQ_INVALID_EL0_64",		
	"ERROR_INVALID_EL0_64",	

	"SYNC_INVALID_EL0_32",		
	"IRQ_INVALID_EL0_32",		
	"FIQ_INVALID_EL0_32",		
	"ERROR_INVALID_EL0_32"	
};

void enable_interrupt_controller()
{
}

void show_invalid_entry_message(int type, unsigned long esr, unsigned long address)
{
	printf("%s, ESR: %x, address: %x\r\n", entry_error_messages[type], esr, address);
}

void disable_interupts() {
    // Disable all basic IRQs
    irq_basic_enabled = get32(ENABLE_BASIC_IRQS);
    put32(DISABLE_BASIC_IRQS, 127);
    
    // Disable IRQ 1
    irq_1_enabled = get32(ENABLE_IRQS_1);
    put32(DISABLE_IRQS_1, (1 << 1) | (1 << 3) | (1 << 9) | (1 << 29));
    
    // Disable IRQ 2
    irq_2_enabled = get32(ENABLE_IRQS_2);
    put32(DISABLE_IRQS_1, (1 << 11) | (1 << 13) | (1 << 14) | (1 << 16) | (1 << 17) | (1 << 18) | (1 << 19) | (1 << 20) | (1 << 21) | (1 << 22) | (1 << 23) | (1 << 25));
}

void enable_interupts() {
    // Enable all basic IRQs
    put32(ENABLE_BASIC_IRQS, irq_basic_enabled);
    
    // Enable IRQ 1
    put32(ENABLE_IRQS_1, irq_1_enabled);
    
    // Enable IRQ 2
    put32(ENABLE_IRQS_2, irq_1_enabled);
}

void handle_irq(void) {
	unsigned int irq = get32(IRQ_BASIC_PENDING);
	if (irq & ARM_TIMER_IRQ) {
		handle_timer_irq();
        disable_interupts();
    }
	else if(irq & 127) {
		printf("Unknown pending basic irq: %d\r\n", irq);
    } else {
        printf("Unknown . . .\r\n");
    }
}
