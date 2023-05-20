#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define 	PORTA		 0
#define		PORTB		 1
#define		PORTC		 2
#define		PORTD		 3

#define		DIO_INPUT	 0
#define		DIO_OUTPUT	 1

#define		DIO_HIGH	 1
#define		DIO_PULLUP	 1

#define		DIO_LOW		 0
#define		DIO_NOPULLUP 1

#define		PIN0		 0
#define		PIN1		 1
#define		PIN2		 2
#define		PIN3		 3
#define		PIN4		 4
#define		PIN5		 5
#define		PIN6		 6
#define		PIN7		 7

void DIO_voidSetPinDirection(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinMode);
void DIO_voidSetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber, u8 Copy_u8PinState);
void DIO_voidSetPortDirection(u8 Copy_u8PortName, u8 Copy_u8PortMode);
void DIO_voidSetPortSpecificValue(u8 Copy_u8PortName, u8 Copy_u8Value);
u8 	 DIO_u8GetPinValue(u8 Copy_u8PortName, u8 Copy_u8PinNumber);
#endif
