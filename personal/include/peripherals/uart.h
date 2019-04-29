#ifndef	_P_UART_H
#define	_P_UART_H

#include "peripherals/base.h"


#define UART_DR 		(UART_BASE + 0x00)
#define UART_RSRECR 	(UART_BASE + 0x04)
#define UART_FR 		(UART_BASE + 0x18)
#define UART_ILPR 		(UART_BASE + 0x20)
#define UART_IBRD		(UART_BASE + 0x24)
#define UART_FBRD 		(UART_BASE + 0x28)
#define UART_LCRH 		(UART_BASE + 0x2c)
#define UART_CR 		(UART_BASE + 0x30)
#define UART_IFLS 		(UART_BASE + 0x34)
#define UART_IMSC 		(UART_BASE + 0x38)
#define UART_RIS 		(UART_BASE + 0x3c)
#define UART_MIS 		(UART_BASE + 0x40)
#define UART_ICR 		(UART_BASE + 0x44)
#define UART_DMACR 		(UART_BASE + 0x48)
#define UART_ITCR 		(UART_BASE + 0x80)
#define UART_ITIP 		(UART_BASE + 0x84)
#define UART_ITOP 		(UART_BASE + 0x88)
#define UART_TDR 		(UART_BASE + 0x8c)

#define UART_CR_RXE	(1<<9)	/*    9 = RXE = Receive Enable */
#define UART_CR_TXE	(1<<8)	/*    8 = TXE = Transmit Enable */

#define UART_CR_UARTEN	(1<<0)	/*    0 = UARTEN = UART Enable */

#endif //_P_UART_H