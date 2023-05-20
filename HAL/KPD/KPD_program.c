#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_private.h"
#include "KPD_config.h"

void KPD_voidInit(void)
{
	/* Set Row Pins to be input */
	DIO_voidSetPinDirection(KPD_PORT, KPD_ROW0_PIN, DIO_INPUT);
	DIO_voidSetPinDirection(KPD_PORT, KPD_ROW1_PIN, DIO_INPUT);
	DIO_voidSetPinDirection(KPD_PORT, KPD_ROW2_PIN, DIO_INPUT);
	DIO_voidSetPinDirection(KPD_PORT, KPD_ROW3_PIN, DIO_INPUT);
	
	
	/* set Row Pins To Be Pulled Up */
	DIO_voidSetPinValue(KPD_PORT, KPD_ROW0_PIN, DIO_PULLUP);
	DIO_voidSetPinValue(KPD_PORT, KPD_ROW1_PIN, DIO_PULLUP);
	DIO_voidSetPinValue(KPD_PORT, KPD_ROW2_PIN, DIO_PULLUP);
	DIO_voidSetPinValue(KPD_PORT, KPD_ROW3_PIN, DIO_PULLUP);
	
	
	/* Set Column Pins to be output */
	DIO_voidSetPinDirection(KPD_PORT, KPD_COLUMN0_PIN, DIO_OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT, KPD_COLUMN1_PIN, DIO_OUTPUT);
	DIO_voidSetPinDirection(KPD_PORT, KPD_COLUMN2_PIN, DIO_OUTPUT);
	
	
	/* Set Column Pins To Be High */
	DIO_voidSetPinValue(KPD_PORT, KPD_COLUMN0_PIN, DIO_HIGH);
	DIO_voidSetPinValue(KPD_PORT, KPD_COLUMN1_PIN, DIO_HIGH);
	DIO_voidSetPinValue(KPD_PORT, KPD_COLUMN2_PIN, DIO_HIGH);
/*
	//PassWord
		u8 PW_Array[4];
		u8 Counter;
		for(Counter=0 ;Counter<4; Counter++){
		PW_Array[Counter]= 0xFF;
		}
		*/
}


u8 KPD_u8GetPressedKey(void)
{
	static u8 Local_u8KPDArray[KPD_ROW_NUM][KPD_COLUMN_NUM] = KPD_ARR_VAL;
	static u8 Local_u8KPDColumnsArray[KPD_COLUMN_NUM] = {KPD_COLUMN0_PIN, KPD_COLUMN1_PIN, KPD_COLUMN2_PIN};
	static u8 Local_u8KPDRowsArray[KPD_ROW_NUM] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};
	u8 Local_u8ColumnIndex;
	u8 Local_u8RowIndex;
	u8 Local_u8PressedKey = KPD_NO_PRESSED_KEY;
	u8 Local_u8PinState;
	for(Local_u8ColumnIndex = 0; Local_u8ColumnIndex < KPD_COLUMN_NUM; Local_u8ColumnIndex++)
	{
		/* Activate The Column */
		DIO_voidSetPinValue(KPD_PORT, Local_u8KPDColumnsArray[Local_u8ColumnIndex], DIO_LOW);
		/* Loop On The Rows */
		for(Local_u8RowIndex = 0; Local_u8RowIndex < KPD_ROW_NUM; Local_u8RowIndex++)
		{
			/* Get The Row Pin State */
			Local_u8PinState = DIO_u8GetPinValue(KPD_PORT, Local_u8KPDRowsArray[Local_u8RowIndex]);
			/* Check if the Current Row Pin is Low */
			if(Local_u8PinState == DIO_LOW)
			{
				/* Get The Pressed Key */
				Local_u8PressedKey = Local_u8KPDArray[Local_u8RowIndex][Local_u8ColumnIndex];
				
				/* Polling (Busy Wait) until the key is released */
				while(Local_u8PinState == DIO_LOW)
				{
					/* Read The Current Row */
					Local_u8PinState = DIO_u8GetPinValue(KPD_PORT, Local_u8KPDRowsArray[Local_u8RowIndex]);
				}
				
				/* Return the Pressed Key and Exit the function */
				return Local_u8PressedKey;
			}
		}
		
		/* Deactivate The Current Column */
		DIO_voidSetPinValue(KPD_PORT, Local_u8KPDColumnsArray[Local_u8ColumnIndex], DIO_HIGH);
	}
	
	/* No Key Pressed, Then Return The Initial Value */
	return Local_u8PressedKey;
}


u8 KPD_PWEnable(){
#if EnableState == Enable
	return 1;
#elif EnableState == Disable
	return 0;
#endif
}

u8 KPD_SetPW()
{
#define   first_num        4
#define   second_num       5
#define   third_num        6
}
