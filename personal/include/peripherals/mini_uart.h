#ifndef	_P_MINI_UART_H
#define	_P_MINI_UART_H

#include "peripherals/base.h"

#define AUX_ENABLES     (MU_BASE+0x04)
#define AUX_MU_IO_REG   (MU_BASE+0x40)
#define AUX_MU_IER_REG  (MU_BASE+0x44)
#define AUX_MU_IIR_REG  (MU_BASE+0x48)
#define AUX_MU_LCR_REG  (MU_BASE+0x4C)
#define AUX_MU_MCR_REG  (MU_BASE+0x50)
#define AUX_MU_LSR_REG  (MU_BASE+0x54)
#define AUX_MU_MSR_REG  (MU_BASE+0x58)
#define AUX_MU_SCRATCH  (MU_BASE+0x5C)
#define AUX_MU_CNTL_REG (MU_BASE+0x60)
#define AUX_MU_STAT_REG (MU_BASE+0x64)
#define AUX_MU_BAUD_REG (MU_BASE+0x68)

// Used to enable interupts by setting the AUX_MU_IER_REG register
#define MU_TRANS_INT_ENABLE 	(1 << 0)
#define MU_RECV_INT_ENABLE 		(1 << 1)

#endif  /*_P_MINI_UART_H */
