/**
 * @file GPIO_prog.c
 * @author Doaa Hagag (doaahagag128@gmail.com)
 * @compiler:   GNU ARM-GCC
 * @controller: STM32F40ICCU6
 * @layer:      MCAL 
 * @version 1.2
 * @brief Add MGPIO_voidSetPin and MGPIO_voidResetPin functions
 * @date 2023-05-04
 * 
 * @copyright Copyright (c) 2023
 * 
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

void MGPIO_voidSetPinInputType(u8 Copy_u8PortName ,u8 Copy_u8PinNumber, u8 Copy_u8InputType)
{
	switch(Copy_u8PortName)
	{
	case MGPIO_PORTA:
		switch(Copy_u8InputType)
		{
		case NO_PULLUP_NO_PULLDOWN:
			/*00*/
			CLR_BIT( GPIOA_PUPDR , (2*Copy_u8PinNumber));
			CLR_BIT( GPIOA_PUPDR , ((2*Copy_u8PinNumber)+1));
			break;
		case PULLUP:
			SET_BIT( GPIOA_PUPDR , (2*Copy_u8PinNumber));
			CLR_BIT( GPIOA_PUPDR , ((2*Copy_u8PinNumber)+1));
			break;
		case PULLDOWN:
			CLR_BIT( GPIOA_PUPDR , (2*Copy_u8PinNumber));
			SET_BIT( GPIOA_PUPDR , ((2*Copy_u8PinNumber)+1));
			break;
		default :	break;
		}
		//CLR_BIT(GPIOA_OTYPER ,Copy_u8PinNumber);
		break;

		case MGPIO_PORTB:
			switch(Copy_u8InputType)
			{
			case NO_PULLUP_NO_PULLDOWN:
				/*00*/
				CLR_BIT( GPIOB_PUPDR , (2*Copy_u8PinNumber));
				CLR_BIT( GPIOB_PUPDR , ((2*Copy_u8PinNumber)+1));
				break;
			case PULLUP:
				SET_BIT( GPIOB_PUPDR , (2*Copy_u8PinNumber));
				CLR_BIT( GPIOB_PUPDR , ((2*Copy_u8PinNumber)+1));
				break;
			case PULLDOWN:
				CLR_BIT( GPIOB_PUPDR , (2*Copy_u8PinNumber));
				SET_BIT( GPIOB_PUPDR , ((2*Copy_u8PinNumber)+1));
				break;
				default :	break;
			}
			//CLR_BIT(GPIOB_OTYPER ,Copy_u8PinNumber);
			break;

			case MGPIO_PORTC:
				switch(Copy_u8InputType)
				{
				case OUTPUT_PUSH_PULL:
					CLR_BIT(GPIOC_PUPDR,Copy_u8PinNumber);
					break;
				case OUTPUT_OPEN_DRAIN:
					SET_BIT(GPIOC_PUPDR,Copy_u8PinNumber);
					break;
				default :	break;
				}
				//CLR_BIT(GPIOC_OTYPER ,Copy_u8PinNumber);
				break;
				default :	break;
	}
}

void MGPIO_voidSetAlternativeFunctio(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8AlternativeNumber)
{
	switch(Copy_u8PortName)
	{
	case MGPIO_PORTA:
		if(Copy_u8PinName <= 7)
		{
			GPIOA_AFRL &= ~(0b1111 << (Copy_u8PinName*4));
			GPIOA_AFRL |= (Copy_u8AlternativeNumber << (Copy_u8PinName*4));
		}
		else if(Copy_u8PinName <= 15)
		{
			GPIOA_AFRH &= ~(0b1111 << (Copy_u8PinName*4));
			GPIOA_AFRH |= (Copy_u8AlternativeNumber << ((Copy_u8PinName-8)*4));
		}
	}
}







#endif
#if 0
void MGPIO_voidSetPinDirection(GPIO_NUM_t GPIO_N , PIN_NUM_t PIN_NUMBER , PIN_MODE_t PinMode)
{
	switch (GPIO_N)
	{
	case GPIOA_PORT:
		switch (PinMode)
		{
		case INPUT:
			CLR_BIT(GPIOA->MODER , 1<<(PIN_NUMBER*2));
			CLR_BIT(GPIOA->MODER , 1<<((PIN_NUMBER*2)+1));
			break;
		case OUTPUT:
			SET_BIT(GPIOA->MODER , 1<<(PIN_NUMBER*2));
			CLR_BIT(GPIOA->MODER , 1<<((PIN_NUMBER*2)+1));
			break;
		case ALTERNATIVE_FUNCTION:
			CLR_BIT(GPIOA->MODER , 1<<(PIN_NUMBER*2));
			SET_BIT(GPIOA->MODER , 1<<((PIN_NUMBER*2)+1));
			break;
		case ANALOG:
			SET_BIT(GPIOA->MODER , 1<<(PIN_NUMBER*2));
			SET_BIT(GPIOA->MODER , 1<<((PIN_NUMBER*2)+1));
			break;
		default:
			break;
		}

		break;
		case GPIOB_PORT:
			switch (PinMode)
			{
			case INPUT:
				CLR_BIT(GPIOB->MODER , 1<<(PIN_NUMBER*2));
				CLR_BIT(GPIOB->MODER , 1<<((PIN_NUMBER*2)+1));
				break;
			case OUTPUT:
				SET_BIT(GPIOB->MODER , 1<<(PIN_NUMBER*2));
				CLR_BIT(GPIOB->MODER , 1<<((PIN_NUMBER*2)+1));
				break;
			case ALTERNATIVE_FUNCTION:
				CLR_BIT(GPIOB->MODER , 1<<(PIN_NUMBER*2));
				SET_BIT(GPIOB->MODER , 1<<((PIN_NUMBER*2)+1));
				break;
			case ANALOG:
				SET_BIT(GPIOB->MODER , 1<<(PIN_NUMBER*2));
				SET_BIT(GPIOB->MODER , 1<<((PIN_NUMBER*2)+1));
				break;
			default:
				break;
			}
			break;
			case GPIOC_PORT:
				switch (PinMode)
				{
				case INPUT:
					CLR_BIT(GPIOC->MODER , 1<<(PIN_NUMBER*2));
					CLR_BIT(GPIOC->MODER , 1<<((PIN_NUMBER*2)+1));
					break;
				case OUTPUT:
					SET_BIT(GPIOC->MODER , 1<<(PIN_NUMBER*2));
					CLR_BIT(GPIOC->MODER , 1<<((PIN_NUMBER*2)+1));
					break;
				case ALTERNATIVE_FUNCTION:
					CLR_BIT(GPIOC->MODER , 1<<(PIN_NUMBER*2));
					SET_BIT(GPIOC->MODER , 1<<((PIN_NUMBER*2)+1));
					break;
				case ANALOG:
					SET_BIT(GPIOC->MODER , 1<<(PIN_NUMBER*2));
					SET_BIT(GPIOC->MODER , 1<<((PIN_NUMBER*2)+1));
					break;
				default:
					break;
				}
				break;

				default:
					break;
	}

}
void MGPIO_voidSetPinOutputType(GPIO_NUM_t GPIO_N ,PIN_NUM_t PIN_NUMBER , OUTPUT_t Output_Type)
{
	switch (GPIO_N)
	{
	case GPIOA_PORT:
		switch (Output_Type)
		{
		case OUTPUT_PUSH_PULL:
			CLR_BIT(GPIOA->OTYPER , PIN_NUMBER);
			break;
		case OUTPUT_OPEN_DRAIN:
			SET_BIT(GPIOA->OTYPER , PIN_NUMBER);
			break;
		default:
			/*Do Nothing*/
			break;
		}
		break;
		case GPIOB_PORT:
			switch (Output_Type)
			{
			case OUTPUT_PUSH_PULL:
				CLR_BIT(GPIOB->OTYPER , PIN_NUMBER);
				break;
			case OUTPUT_OPEN_DRAIN:
				SET_BIT(GPIOB->OTYPER , PIN_NUMBER);
				break;
			default:
				/*Do Nothing*/
				break;
			}
			break;
			case GPIOC_PORT:
				switch (Output_Type)
				{
				case OUTPUT_PUSH_PULL:
					CLR_BIT(GPIOC->OTYPER , PIN_NUMBER);
					break;
				case OUTPUT_OPEN_DRAIN:
					SET_BIT(GPIOC->OTYPER , PIN_NUMBER);
					break;
				default:
					/*Do Nothing*/
					break;
				}
				break;

				default:
					/*Do Nothing*/
					break;
	}

}
void MGPIO_voidSetPinOutputSpeed(GPIO_NUM_t GPIO_N ,PIN_NUM_t PIN_NUMBER , OUTPUT_SPEED_t Output_Speed)
{
	switch (GPIO_N)
	{
	case GPIOA_PORT:
		switch (Output_Speed)
		{
		case LOW_SPEED_2MHZ:
			CLR_BIT(GPIOA->OSPEEDR , 1<<(PIN_NUMBER*2));
			CLR_BIT(GPIOA->OSPEEDR , 1<<((PIN_NUMBER*2)+1));
			break;
		case MEDIUM_SPEED_UP_TO_10MHZ:
			SET_BIT(GPIOA->OSPEEDR , 1<<(PIN_NUMBER*2));
			CLR_BIT(GPIOA->OSPEEDR , 1<<((PIN_NUMBER*2)+1));
			break;
		case HIGH_SPEED_UP_TO_50MHZ:
			CLR_BIT(GPIOA->OSPEEDR , 1<<(PIN_NUMBER*2));
			SET_BIT(GPIOA->OSPEEDR , 1<<((PIN_NUMBER*2)+1));
			break;
		case VERY_HIGH_SPEED_UP_TO_100MHZ:
			SET_BIT(GPIOA->OSPEEDR , 1<<(PIN_NUMBER*2));
			SET_BIT(GPIOA->OSPEEDR , 1<<((PIN_NUMBER*2)+1));
			break;
		default:
			break;
		}

		break;
		case GPIOB_PORT:
			switch (Output_Speed)
			{
			case LOW_SPEED_2MHZ:
				CLR_BIT(GPIOB->OSPEEDR , 1<<(PIN_NUMBER*2));
				CLR_BIT(GPIOB->OSPEEDR , 1<<((PIN_NUMBER*2)+1));
				break;
			case MEDIUM_SPEED_UP_TO_10MHZ:
				SET_BIT(GPIOB->OSPEEDR , 1<<(PIN_NUMBER*2));
				CLR_BIT(GPIOB->OSPEEDR , 1<<((PIN_NUMBER*2)+1));
				break;
			case HIGH_SPEED_UP_TO_50MHZ:
				CLR_BIT(GPIOB->OSPEEDR , 1<<(PIN_NUMBER*2));
				SET_BIT(GPIOB->OSPEEDR , 1<<((PIN_NUMBER*2)+1));
				break;
			case VERY_HIGH_SPEED_UP_TO_100MHZ:
				SET_BIT(GPIOB->OSPEEDR , 1<<(PIN_NUMBER*2));
				SET_BIT(GPIOB->OSPEEDR , 1<<((PIN_NUMBER*2)+1));
				break;
			default:
				break;
			}
			break;
			case GPIOC_PORT:
				switch (Output_Speed)
				{
				case LOW_SPEED_2MHZ:
					CLR_BIT(GPIOC->OSPEEDR , 1<<(PIN_NUMBER*2));
					CLR_BIT(GPIOC->OSPEEDR , 1<<((PIN_NUMBER*2)+1));
					break;
				case MEDIUM_SPEED_UP_TO_10MHZ:
					SET_BIT(GPIOC->OSPEEDR , 1<<(PIN_NUMBER*2));
					CLR_BIT(GPIOC->OSPEEDR , 1<<((PIN_NUMBER*2)+1));
					break;
				case HIGH_SPEED_UP_TO_50MHZ:
					CLR_BIT(GPIOC->OSPEEDR , 1<<(PIN_NUMBER*2));
					SET_BIT(GPIOC->OSPEEDR , 1<<((PIN_NUMBER*2)+1));
					break;
				case VERY_HIGH_SPEED_UP_TO_100MHZ:
					SET_BIT(GPIOC->OSPEEDR , 1<<(PIN_NUMBER*2));
					SET_BIT(GPIOC->OSPEEDR , 1<<((PIN_NUMBER*2)+1));
					break;
				default:
					break;
				}
				break;

				default:
					break;
	}
}
void MGPIO_voidSetPinOutputMode(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER , OUTPUT_MODE_t Mode)
{
	switch (GPIO_N)
	{
	case GPIOA_PORT:
		switch (Mode)
		{
		case NO_PULL_UP_NO_PULL_DOWN:
			CLR_BIT(GPIOA->PUPDR , 1<<(PIN_NUMBER*2));
			CLR_BIT(GPIOA->PUPDR , 1<<((PIN_NUMBER*2)+1));
			break;
		case PULL_UP:
			SET_BIT(GPIOA->PUPDR , 1<<(PIN_NUMBER*2));
			CLR_BIT(GPIOA->PUPDR , 1<<((PIN_NUMBER*2)+1));
			break;
		case PULL_DOWN:
			CLR_BIT(GPIOA->PUPDR , 1<<(PIN_NUMBER*2));
			SET_BIT(GPIOA->PUPDR , 1<<((PIN_NUMBER*2)+1));
			break;
		default:
			break;
		}

		break;
		case GPIOB_PORT:
			switch (Mode)
			{
			case NO_PULL_UP_NO_PULL_DOWN:
				CLR_BIT(GPIOB->PUPDR , 1<<(PIN_NUMBER*2));
				CLR_BIT(GPIOB->PUPDR , 1<<((PIN_NUMBER*2)+1));
				break;
			case PULL_UP:
				SET_BIT(GPIOB->PUPDR , 1<<(PIN_NUMBER*2));
				CLR_BIT(GPIOB->PUPDR , 1<<((PIN_NUMBER*2)+1));
				break;
			case PULL_DOWN:
				CLR_BIT(GPIOB->PUPDR , 1<<(PIN_NUMBER*2));
				SET_BIT(GPIOB->PUPDR , 1<<((PIN_NUMBER*2)+1));
				break;
			default:
				break;
			}
			break;
			case GPIOC_PORT:
				switch (Mode)
				{
				case NO_PULL_UP_NO_PULL_DOWN:
					CLR_BIT(GPIOC->PUPDR , 1<<(PIN_NUMBER*2));
					CLR_BIT(GPIOC->PUPDR , 1<<((PIN_NUMBER*2)+1));
					break;
				case PULL_UP:
					SET_BIT(GPIOC->PUPDR , 1<<(PIN_NUMBER*2));
					CLR_BIT(GPIOC->PUPDR , 1<<((PIN_NUMBER*2)+1));
					break;
				case PULL_DOWN:
					CLR_BIT(GPIOC->PUPDR , 1<<(PIN_NUMBER*2));
					SET_BIT(GPIOC->PUPDR , 1<<((PIN_NUMBER*2)+1));
					break;
				default:
					break;
				}
				break;

				default:
					break;
	}
}
void MGPIO_voidGetInputPinValue(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER , u8 *Local_pu8Value)    //Read IDR)
{
	switch (GPIO_N)
	{
	case GPIOA_PORT:
		Local_pu8Value = GET_BIT (GPIOA->IDR ,PIN_NUMBER);
		break;
	case GPIOB_PORT:
		Local_pu8Value = GET_BIT (GPIOB->IDR ,PIN_NUMBER);
		break;
	case GPIOC_PORT:
		Local_pu8Value = GET_BIT (GPIOC->IDR ,PIN_NUMBER);
		break;
	default:
		/*Do Nothing*/
		break;
	}
}
void MGPIO_voidGetOutputPinValue(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER , u8 *Local_pu8Value)   //Read ORD
{
	switch (GPIO_N)
	{
	case GPIOA_PORT:
		Local_pu8Value = GET_BIT (GPIOA->ODR ,PIN_NUMBER);
		break;
	case GPIOB_PORT:
		Local_pu8Value = GET_BIT (GPIOB->ODR ,PIN_NUMBER);
		break;
	case GPIOC_PORT:
		Local_pu8Value = GET_BIT (GPIOC->ODR ,PIN_NUMBER);
		break;
	default:
		/*Do Nothing*/
		break;
	}

}

void MGPIO_voidSetPin(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER)    //BSRR
{
	switch (GPIO_N)
	{
	case GPIOA_PORT:
		GPIOA->BSRR = (1 << PIN_NUMBER);
		break;
	case GPIOB_PORT:
		GPIOB->BSRR = (1 << PIN_NUMBER);
		break;
	case GPIOC_PORT:
		GPIOB->BSRR = (1 << PIN_NUMBER);
		break;
	default:
		/*Do Nothing*/
		break;
	}
}
void MGPIO_voidResetPin(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER)
{
	switch (GPIO_N)
	{
	case GPIOA_PORT:
		GPIOA->BSRR = (0x10000<< PIN_NUMBER);
		break;
	case GPIOB_PORT:
		GPIOB->BSRR = (0x10000 << PIN_NUMBER);
		break;
	case GPIOC_PORT:
		GPIOB->BSRR = (0x10000 << PIN_NUMBER);
		break;
	default:
		/*Do Nothing*/
		break;
	}
}
#endif
