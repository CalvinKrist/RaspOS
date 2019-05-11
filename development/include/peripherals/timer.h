#ifndef	_P_TIMER_H
#define	_P_TIMER_H

#include "peripherals/base.h"
#include "arm/cpu.h"

// Documented at https://embedded-xinu.readthedocs.io/en/latest/arm/rpi/BCM2835-System-Timer.html
// System Timer Controls
#define ST_CLO       (ST_BASE+0x04)
#define ST_CHI       (ST_BASE+0x08)
#define ST_C0        (ST_BASE+0x0C)
#define ST_C1        (ST_BASE+0x10)
#define ST_C2        (ST_BASE+0x14)
#define ST_C3        (ST_BASE+0x18)

#define ST_CS_M0	(1 << 0)
#define ST_CS_M1	(1 << 1)
#define ST_CS_M2	(1 << 2)
#define ST_CS_M3	(1 << 3)

//ARM Timer Controls (see section 14 of the peripherals spec)
#define ARM_TIMER_LOAD 			(ARM_TIMER_BASE+0x00)
#define ARM_TIMER_VALUE 		(ARM_TIMER_BASE+0x04)
#define ARM_TIMER_CTRL 			(ARM_TIMER_BASE+0x08)
#define ARM_TIMER_CLEAR 		(ARM_TIMER_BASE+0x0C)
#define ARM_TIMER_RAWIRQ 		(ARM_TIMER_BASE+0x10)
#define ARM_TIMER_MASKEDIRQ 	(ARM_TIMER_BASE+0x14)
#define ARM_TIMER_RELOAD		(ARM_TIMER_BASE+0x18)

#define ARM_TIMER_CTRL_23BIT         ( 1 << 1 )

#define ARM_TIMER_CTRL_PRESCALE_1    ( 0 << 2 )
#define ARM_TIMER_CTRL_PRESCALE_16   ( 1 << 2 )
#define ARM_TIMER_CTRL_PRESCALE_256  ( 2 << 2 )

#define ARM_TIMER_CTRL_INT_ENABLE    ( 1 << 5 )
#define ARM_TIMER_CTRL_INT_DISABLE   ( 0 << 5 )

#define ARM_TIMER_CTRL_ENABLE        ( 1 << 7 )
#define ARM_TIMER_CTRL_DISABLE       ( 0 << 7 )

#endif  /*_P_TIMER_H */
