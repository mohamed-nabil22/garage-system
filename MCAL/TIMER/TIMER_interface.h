
#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

void TIMER_voidInit(void);
void TIMER_voidSetCompareValue0(u8 Copy_u8CompareValue);
void TIMER_voidTimer0SetCallBack(void (*Copy_pvNotificationFunction)(void));
void TIMER_voidSetPreLoadValue0(u8 Copy_u8PreLoadValue);

#endif
