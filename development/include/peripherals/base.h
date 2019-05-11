#ifndef	_P_BASE_H
#define	_P_BASE_H

#define PBASE 0x3F000000

#define ST_BASE 		(PBASE + 0x3000)  		/* System Timer */
#define ARM_BASE 		(PBASE + 0xB000) 		/* BCM2708 ARM control block */
#define ARM_IC_BASE 	(ARM_BASE + 0x200) 		/* ARM interrupt controller */
#define ARM_TIMER_BASE 	(ARM_BASE + 0x400) 		/* Timer 0 and 1 */
#define MU_BASE 		(PBASE + 0x215000)  	/* Mini UART */	
#define UART_BASE 		(PBASE + 0x201000)  	/* UART */	

#endif  /*_P_BASE_H */
