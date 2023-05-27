/*
 * main.c
 *
 *  Created on: May 8, 2023
 *      Author: Hager Badr
 */

#if 1

#include <GPIO_CONFIG.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_int.h"
#include "GPIO_priv.h"




void MGPIO_voidSetPinMode(u8 Copy_u8PortName ,u8 Copy_u8PinNumber, u8 Copy_u8Mode)
{
	switch(Copy_u8PortName)
	{
	case MGPIO_PORTA:
		switch(Copy_u8Mode)
		{
		case MGPIO_INPUT:
			CLR_BIT(GPIOA_MODER,(Copy_u8PinNumber*2));
			CLR_BIT(GPIOA_MODER,((Copy_u8PinNumber*2)+1));
			break;
		case MGPIO_OUTPUT:
			SET_BIT(GPIOA_MODER,(Copy_u8PinNumber*2));
			CLR_BIT(GPIOA_MODER,((Copy_u8PinNumber*2)+1));
			break;
		case MGPIO_ALTERNATIVE_FUNCTION:
			CLR_BIT(GPIOA_MODER,(Copy_u8PinNumber*2));
			SET_BIT(GPIOA_MODER,((Copy_u8PinNumber*2)+1));
			break;
		case MGPIO_ANALOG:
			SET_BIT(GPIOA_MODER,(Copy_u8PinNumber*2));
			SET_BIT(GPIOA_MODER,((Copy_u8PinNumber*2)+1));
			break;
		default :	break;

		}
		//GPIOA_MODER |= GPIO_OUTPUT_MODE << (Copy_u8PinNumber * 2);
		break;
		case MGPIO_PORTB:
			switch(Copy_u8Mode)
			{
			case MGPIO_INPUT:
				CLR_BIT(GPIOB_MODER,(Copy_u8PinNumber*2));
				CLR_BIT(GPIOB_MODER,((Copy_u8PinNumber*2)+1));
				break;
			case MGPIO_OUTPUT:
				SET_BIT(GPIOB_MODER,(Copy_u8PinNumber*2));
				CLR_BIT(GPIOB_MODER,((Copy_u8PinNumber*2)+1));
				break;
			case MGPIO_ALTERNATIVE_FUNCTION:
				CLR_BIT(GPIOB_MODER,(Copy_u8PinNumber*2));
				SET_BIT(GPIOB_MODER,((Copy_u8PinNumber*2)+1));
				break;
			case MGPIO_ANALOG:
				SET_BIT(GPIOB_MODER,(Copy_u8PinNumber*2));
				SET_BIT(GPIOB_MODER,((Copy_u8PinNumber*2)+1));
				break;
			default :	break;
			}

			//GPIOB_MODER |= GPIO_OUTPUT_MODE << (Copy_u8PinNumber * 2);
			break;

			case MGPIO_PORTC:
				switch(Copy_u8Mode)
				{
				case MGPIO_INPUT:
					CLR_BIT(GPIOC_MODER,(Copy_u8PinNumber*2));
					CLR_BIT(GPIOC_MODER,((Copy_u8PinNumber*2)+1));
					break;
				case MGPIO_OUTPUT:
					SET_BIT(GPIOC_MODER,(Copy_u8PinNumber*2));
					CLR_BIT(GPIOC_MODER,((Copy_u8PinNumber*2)+1));
					break;
				case MGPIO_ALTERNATIVE_FUNCTION:
					CLR_BIT(GPIOC_MODER,(Copy_u8PinNumber*2));
					SET_BIT(GPIOC_MODER,((Copy_u8PinNumber*2)+1));
					break;
				case MGPIO_ANALOG:
					SET_BIT(GPIOC_MODER,(Copy_u8PinNumber*2));
					SET_BIT(GPIOC_MODER,((Copy_u8PinNumber*2)+1));
					break;
				default :	break;
				}
				//GPIOC_MODER |= GPIO_OUTPUT_MODE << (Copy_u8PinNumber * 2);
				break;
				default :	break;
	}
}

void MGPIO_voidSetPinOutputType(u8 Copy_u8PortName ,u8 Copy_u8PinNumber, u8 Copy_u8OutputType)
{
	switch(Copy_u8PortName)
	{
	case MGPIO_PORTA:
		switch(Copy_u8OutputType)
		{
		case OUTPUT_PUSH_PULL:
			CLR_BIT(GPIOA_OTYPER,Copy_u8PinNumber);
			break;
		case OUTPUT_OPEN_DRAIN:
			SET_BIT(GPIOA_OTYPER,Copy_u8PinNumber);
			break;
		default :	break;
		}
		//CLR_BIT(GPIOA_OTYPER ,Copy_u8PinNumber);
		break;

		case MGPIO_PORTB:
			switch(Copy_u8OutputType)
			{
			case OUTPUT_PUSH_PULL:
				CLR_BIT(GPIOB_OTYPER,Copy_u8PinNumber);
				break;
			case OUTPUT_OPEN_DRAIN:
				SET_BIT(GPIOB_OTYPER,Copy_u8PinNumber);
				break;
			default :	break;
			}
			//CLR_BIT(GPIOB_OTYPER ,Copy_u8PinNumber);
			break;

			case MGPIO_PORTC:
				switch(Copy_u8OutputType)
				{
				case OUTPUT_PUSH_PULL:
					CLR_BIT(GPIOC_OTYPER,Copy_u8PinNumber);
					break;
				case OUTPUT_OPEN_DRAIN:
					SET_BIT(GPIOC_OTYPER,Copy_u8PinNumber);
					break;
				default :	break;
				}
				//CLR_BIT(GPIOC_OTYPER ,Copy_u8PinNumber);
				break;
				default :	break;
	}
}
void MGPIO_voidSetPinOutPutSpeed(u8 Copy_u8PortName ,u8 Copy_u8PinNumber, u8 Copy_u8OutputSpeed)
{
	switch(Copy_u8PortName)
	{
	case MGPIO_PORTA:
		GPIOA_OSPEEDR |= 0b00 << (Copy_u8PinNumber * 2);
		break;

	case MGPIO_PORTB:
		GPIOB_OSPEEDR |= 0b00 << (Copy_u8PinNumber * 2);
		break;

	case MGPIO_PORTC:
		GPIOC_OSPEEDR |= 0b00 << (Copy_u8PinNumber * 2);
		break;

	}
}

void MGPIO_voidSetPinValue(u8 Copy_u8PortName ,u8 Copy_u8PinNumber, u8 Copy_u8PinValue)
{
	switch(Copy_u8PortName)
	{
	case MGPIO_PORTA:
		switch(Copy_u8PinValue)
		{
		case HIGH:
			SET_BIT(GPIOA_ODR, Copy_u8PinNumber);
			break;
		case LOW:
			CLR_BIT(GPIOA_ODR, Copy_u8PinNumber);

			break;
		}
		break;

		case MGPIO_PORTB:
			switch(Copy_u8PinValue)
			{
			case HIGH:
				SET_BIT(GPIOB_ODR, Copy_u8PinNumber);
				break;
			case LOW:
				CLR_BIT(GPIOB_ODR, Copy_u8PinNumber);

				break;
			}
			break;

			case MGPIO_PORTC:
				switch(Copy_u8PinValue)
				{
				case HIGH:
					SET_BIT(GPIOC_ODR, Copy_u8PinNumber);
					break;
				case LOW:
					CLR_BIT(GPIOC_ODR, Copy_u8PinNumber);

					break;
				}
				break;

	}
}
#endif
