
#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

#define     TCCR0		      *((volatile u8 *)(0x53))		// Timer/Counter0 Control Register
#define     TCCR0_FOC0        7								// Force On Compare
#define     TCCR0_WGM00       6                             // Wave Generation Mode 0
#define     TCCR0_COM01       5                             // Compare match output mode 1
#define     TCCR0_COM00       4                             // Compare match output mode 0
#define     TCCR0_WGM01       3                             // Wave Generation Mode 1
#define     TCCR0_CS02        2                             // Clock Select 02
#define     TCCR0_CS01        1                             // Clock Select 01
#define     TCCR0_CS00        0                             // Clock Select 00

#define     TCNT0		      *((volatile u8 *)(0x52))		// Timer/Counter0 Register

#define     OCR0		      *((volatile u8 *)(0x5C))		// Output Compare0 Register

#define     TIMSK		      *((volatile u8 *)(0x59))		// Timer0 Mask Register
#define     TIMSK_TOIE0       0								// Timer Overflow Interrupt Enable
#define     TIMSK_OCIE0       1                             // Timer On Compare Interrupt Enable

#define     TIFR              *((volatile u8 *)(0x58))		// Timer/Counter0 Interrupt Flag
#define     TIFR_TOV0         0								// Timer/Counter0 Overflow flag
#define     TIFR_OCF0         1                             // Timer/Counter0 Output Compare flag

#define     NULL_POINTER      (void *)0						// NULL_POINTER Definition

#endif
