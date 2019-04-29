#ifndef	_P_IRQ_H
#define	_P_IRQ_H

#include "peripherals/base.h"

// Documented at https://embedded-xinu.readthedocs.io/en/latest/arm/rpi/BCM2835-Interrupt-Controller.html
// Also on page 112 of the BCM2837 peripherals specification	
#define IRQ_BASIC_PENDING	(ARM_IC_BASE+0x00)
#define IRQ_PENDING_1		(ARM_IC_BASE+0x04)
#define IRQ_PENDING_2		(ARM_IC_BASE+0x08)
#define FIQ_CONTROL		    (ARM_IC_BASE+0x0C)
#define ENABLE_IRQS_1		(ARM_IC_BASE+0x10)
#define ENABLE_IRQS_2		(ARM_IC_BASE+0x14)
#define ENABLE_BASIC_IRQS	(ARM_IC_BASE+0x18)
#define DISABLE_IRQS_1		(ARM_IC_BASE+0x1C)
#define DISABLE_IRQS_2		(ARM_IC_BASE+0x20)
#define DISABLE_BASIC_IRQS	(ARM_IC_BASE+0x24)

#define SYSTEM_TIMER_IRQ_0	(1 << 0)
#define SYSTEM_TIMER_IRQ_1	(1 << 1)
#define SYSTEM_TIMER_IRQ_2	(1 << 2)
#define SYSTEM_TIMER_IRQ_3	(1 << 3)

#define ARM_TIMER_IRQ_ENABLE        (1 << 0)
#define ARM_MAILBOX_IRQ_ENABLE      (1 << 1)
#define ARM_DOORBELL_0_IRQ_ENABLE 	(1 << 2)
#define ARM_DOORBELL_1_IRQ_ENABLE   (1 << 3)
#define GPU_0_HALTED_IRQ_ENABLE     (1 << 4)
#define GPU_1_HALTED_IRQ_ENABLE     (1 << 5)
#define ACCESS_ERROR_1_IRQ_ENABLE   (1 << 6)
#define ACCESS_ERROR_0_IRQ_ENABLE   (1 << 7)

// Read the IRQ_BASIC_PENDING to see which events are pending
#define ARM_TIMER_IRQ 			(1 << 0)
#define ARM_MAILBOX_IRQ      	(1 << 1)
#define ARM_DOORBELL_0_IRQ 		(1 << 2)
#define ARM_DOORBELL_1_IRQ   	(1 << 3)
#define GPU_0_HALTED_IRQ     	(1 << 4)
#define GPU_1_HALTED_IRQ     	(1 << 5)
#define ACCESS_ERROR_1_IRQ   	(1 << 6)
#define ACCESS_ERROR_0_IRQ  	(1 << 7)

#endif  /*_P_IRQ_H */
