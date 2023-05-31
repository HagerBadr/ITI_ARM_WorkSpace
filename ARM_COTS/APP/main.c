/*
 * main.c
 *
 *  Created on: May 21, 2023
 *      Author: Hager Badr
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/RCC/RCC_int.h"
#include "../MCAL/GPIO/GPIO_int.h"
#include "../HAL/SSD/SSD_int.h"

void main()
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_AHP1, RCC_GPIOA);
	H_SSD_Void_init();

	//	MGPIO_voidSetPinMode(MGPIO_PORTA,MGPIO_PIN0,MGPIO_INPUT);
//	MGPIO_voidSetPinOutputType(MGPIO_PORTA,0,0);
//	MGPIO_voidSetPinOutPutSpeed(MGPIO_PORTA,0,0);
//	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN0,1);
//
//	MGPIO_voidSetPinMode(MGPIO_PORTA,MGPIO_PIN1,MGPIO_OUTPUT);
//	MGPIO_voidSetPinOutputType(MGPIO_PORTA,1,0);
//	MGPIO_voidSetPinOutPutSpeed(MGPIO_PORTA,1,0);

	//MNVIC_voidInit();
	//MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);

	while(1)
	{
		H_SSD_Void_DisplayNumber(10);
	}

}
