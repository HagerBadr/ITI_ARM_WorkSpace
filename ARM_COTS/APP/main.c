/*
 * main.c
 *
 *  Created on: May 21, 2023
 *      Author: Hager Badr
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_int.h"
#include "GPIO_int.h"
#include "NVIC_interface.h"
#include "EXTI_int.h"

void Toggle_Led(void);

void main()
{
	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_AHP1, RCC_GPIOA);
	MGPIO_voidSetPinMode(MGPIO_PORTA,MGPIO_PIN0,MGPIO_INPUT);
	MGPIO_voidSetPinOutputType(MGPIO_PORTA,0,0);
	MGPIO_voidSetPinOutPutSpeed(MGPIO_PORTA,0,0);
	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN0,1);

	MGPIO_voidSetPinMode(MGPIO_PORTA,MGPIO_PIN1,MGPIO_OUTPUT);
	MGPIO_voidSetPinOutputType(MGPIO_PORTA,1,0);
	MGPIO_voidSetPinOutPutSpeed(MGPIO_PORTA,1,0);

	//MNVIC_voidInit();
	//MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);
	NVIC_voidInit();
	NVIC_voidEnableInt(MNVIC_EXTI0);

	MEXTI_voidChangeSenseEnable(0,MEXTI_FALLING_EDGE);
	MEXTI_voidSetCallBack(0,&Toggle_Led);
	MEXTI_voidEnableInterrupt(0);
	while(1)
	{

	}

}
void Toggle_Led(void)
{
	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN1,1);
}
