#ifndef KPD_INTERFACE_H
#define KPD_INTERFACE_H

#define   correct         1
#define   wrong           0

#define  Enable           1
#define  Disable          0

#define  EN               1
#define  DIS              0

       /*Functions Prototypes*/
void KPD_voidInit(void);
u8 KPD_u8GetPressedKey(void);
void KPD_voidPW(void);
u8 KPD_voidLockEnable(void);
u8 KPD_SetPW(void);
#endif
