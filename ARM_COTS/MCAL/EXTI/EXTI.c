/*
 * EXTI.c
 *
 *  Created on: May 22, 2023
 *      Author: Delta Store
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_int.h"
#include "EXTI_priv.h"
#include "EXTI_config.h"

static void (*pvCallBack[16])(void) = {{NULL}};

void MEXTI_voidInit(void)
{

}
void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTILine)
{
	if(Copy_u8EXTILine > 15)
	{
		return;
	}
	SET_BIT(MEXTI->IMR ,Copy_u8EXTILine);
}
void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTILine)
{
	if(Copy_u8EXTILine > 15)
	{
		return;
	}
	CLR_BIT(MEXTI->IMR ,Copy_u8EXTILine);

}
void MEXTI_voidChangeSenseEnable(u8 Copy_u8EXTILine , u8 Copy_u8SenseSignal)
{
	switch(Copy_u8SenseSignal)
	{
	case MEXTI_RISING_EDGE:
		CLR_BIT(MEXTI->FTSR ,Copy_u8EXTILine);
		SET_BIT(MEXTI->RTSR ,Copy_u8EXTILine);
		break;
	case MEXTI_FALLING_EDGE:
		CLR_BIT(MEXTI->RTSR ,Copy_u8EXTILine);
		SET_BIT(MEXTI->FTSR ,Copy_u8EXTILine);
		break;
	case MEXTI_ON_CHANGE:
		SET_BIT(MEXTI->FTSR ,Copy_u8EXTILine);
		SET_BIT(MEXTI->RTSR ,Copy_u8EXTILine);
		break;
	}
}
void MEXTI_voidSetCallBack(u8 Copy_u8EXTILine, void (*pvNotificationFunction)(void))
{
	pvCallBack[Copy_u8EXTILine] = pvNotificationFunction;
	void EXTI0_IRQHandler(void)
	{
		if(pvCallBack[0] != NULL)
		{
			pvCallBack[0]();
			SET_BIT( MEXTI->PR , 0 );
		}
	}
//	void EXTI1_IRQHandler(void)
//	{
//		if(pvCallBack[1] != NULL)
//		{
//			pvCallBack[1]();
//			SET_BIT( MEXTI->PR , 1 );
//
//		}
//	}
//	void EXTI2_IRQHandler(void)
//	{
//		if(pvCallBack[2] != NULL)
//		{
//			pvCallBack[2]();
//		}
//	}
//	void EXTI3_IRQHandler(void)
//	{
//		if(pvCallBack[3] != NULL)
//		{
//			pvCallBack[3]();
//		}
//	}
//	void EXTI4_IRQHandler(void)
//	{
//		if(pvCallBack[4] != NULL)
//		{
//			pvCallBack[4]();
//		}
//	}

}


