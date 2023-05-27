/*
 * main.c
 *
 *  Created on: May 8, 2023
 *      Author: Hager Badr
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_int.h"
#include "GPIO_int.h"


void main()
{

	MRCC_voidInitSysClock();

	MRCC_voidEnableClock(RCC_AHP1,0);

	MGPIO_voidSetPinMode(MGPIO_PORTA,MGPIO_PIN0,MGPIO_OUTPUT);

	MGPIO_voidSetPinOutputType(MGPIO_PORTA,MGPIO_PIN0,OUTPUT_PUSH_PULL);
	//MGPIO_voidSetPinOutPutSpeed(MGPIO_PORTA,MGPIO_PIN0,);

	while(1)
	{
		MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN0,HIGH);

	}
}

