
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "TIMER_interface.h"
#include "Timer_private.h"
#include "Timer_config.h"


void (* TIMER_pvTimer0NotificationFunction)(void) = NULL_POINTER; 

void TIMER_voidInit(void)
{
	/*Set Timer 0 in CTC Mode*/
	CLR_BIT(TCCR0, TCCR0_WGM00);
	SET_BIT(TCCR0, TCCR0_WGM01);
	
	/*Set The Prescaler to be 8*/
	CLR_BIT(TCCR0, TCCR0_CS00);
	SET_BIT(TCCR0, TCCR0_CS01);
	CLR_BIT(TCCR0, TCCR0_CS02);
	
	/*Enable Output Compare Interrupt*/
	SET_BIT(TIMSK, TIMSK_OCIE0);
}

void TIMER_voidSetPreLoadValue0(u8 Copy_u8PreLoadValue)
{
	TCNT0 = Copy_u8PreLoadValue;
}


void TIMER_voidSetCompareValue0(u8 Copy_u8CompareValue)
{
	/*Set The Compare Value to the OCR0 Register*/
	OCR0 = Copy_u8CompareValue;
}

void TIMER_voidTimer0SetCallBack(void (*Copy_pvNotificationFunction)(void))
{
	/*Assign the function address to the global pointer to function*/
	TIMER_pvTimer0NotificationFunction = Copy_pvNotificationFunction;
}


void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	/*Check if the global pointer to function is changed or not*/
	if(TIMER_pvTimer0NotificationFunction != NULL_POINTER)
	{
		/*Execute the global pointer to function*/
		TIMER_pvTimer0NotificationFunction();
	}
}



