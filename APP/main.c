
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KPD/KPD_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"

#include "../MCAL/DIO/DIO_interface.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#define MAX_TRIES 2

void stop_door(){
	DIO_voidSetPinValue(PORTA,PIN3,DIO_LOW);
	DIO_voidSetPinValue(PORTA,PIN4,DIO_LOW);
}

void open_door(){
	DIO_voidSetPinValue(PORTA,PIN3,DIO_HIGH);
	DIO_voidSetPinValue(PORTA,PIN4,DIO_LOW);
	DIO_voidSetPinValue(PORTA,PIN7,DIO_HIGH);
	DIO_voidSetPinValue(PORTA,PIN5,DIO_HIGH); //buzzer
	_delay_ms(100);
	DIO_voidSetPinValue(PORTA,PIN5,DIO_LOW);
	_delay_ms(2000-100);
	stop_door();
}

void close_door(){
	DIO_voidSetPinValue(PORTA,PIN3,DIO_LOW);
	DIO_voidSetPinValue(PORTA,PIN4,DIO_HIGH);
	_delay_ms(2000);
	stop_door();
	DIO_voidSetPinValue(PORTA,PIN7,DIO_LOW);
}



void main(void)
{
	LCD_voidInit();
	KPD_voidInit();

	u8 Local_u8Key;

	u8 Flag=0;
	u8 arr[3];
	u8 arr2[3]={4,5,6};
	u8 Counter=0;
	DIO_voidSetPinDirection(PORTA,PIN3,DIO_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN4,DIO_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN5,DIO_OUTPUT);
	DIO_voidSetPinDirection(PORTA,PIN7,DIO_OUTPUT);
	DIO_voidSetPinDirection(PORTD,PIN0,DIO_INPUT);
	u8 px=0, pcounter=0, ptries=0;
	while(1)
	{

		if(DIO_u8GetPinValue(PORTD,PIN0)==DIO_LOW){
			LCD_voidClearDisplay();
			px=0;
			pcounter=0;
			ptries=0;
			continue;
		}

		LCD_voidGoToXY(0,0);
		LCD_voidSendString("enter pass code: ");
		do
		{
			Local_u8Key = KPD_u8GetPressedKey();
		}while(Local_u8Key == 0xFF);

		pcounter++;
		arr[px] = Local_u8Key;
		LCD_voidGoToXY(1,px+3);
		LCD_voidSendData(Local_u8Key + '0');
		px++;



		if(pcounter == 3){

			Flag = 1;
			for(int i=0; i<3;i++){
				if(arr[i]!=arr2[i])
					Flag = 0;
			}

			if(Flag == 1){
				LCD_voidClearDisplay();
				LCD_voidSendString("Welcome Home");
				LCD_voidGoToXY(1,0);
				LCD_voidSendString("Door Is Open");
				ptries=0;
				open_door();
				while((DIO_u8GetPinValue(PORTD,PIN0)==DIO_HIGH));
				close_door();
			}
			else{
				ptries++;
				LCD_voidClearDisplay();
				LCD_voidGoToXY(0,0);
				LCD_voidSendString("Wrong pass code ");
				px=0;
				pcounter=0;
//				DIO_voidSetPinValue(PORTA,PIN3,DIO_LOW);
				_delay_ms(1000);
				LCD_voidClearDisplay();
			}


		}

		if(ptries == MAX_TRIES){
			LCD_voidClearDisplay();
			LCD_voidGoToXY(0,0);
			LCD_voidSendString("LOCKING DOOR!");
			break;
		}

	}

	while(1){
		DIO_voidSetPinValue(PORTA,PIN5,DIO_HIGH); //buzzer
		_delay_ms(100);
		DIO_voidSetPinValue(PORTA,PIN5,DIO_LOW);
		_delay_ms(100);
	}
}




