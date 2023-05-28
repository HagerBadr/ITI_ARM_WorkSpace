/*
 * INVIC_prog.c
 *
 *  Created on: Mar 5, 2023
 *      Author: Delta Store
 */


#include	"STD_Types.h"
#include	"BIT_Math.h"

#include	"NVIC_private.h"
#include	"NVIC_interface.h"
#include	"NVIC_config.h"

#ifndef		NULL
#define		NULL	(void *)0
#endif

static void (* EXTI0_CallBack)(void) =NULL ;
static void (* EXTI1_CallBack)(void) =NULL ;

void	NVIC_voidInit(void)
{
	#ifndef		SCB_AIRCR //Application interrupt and reset control register
	#define		SCB_AIRCR	 *((volatile u32 *)(0xE000ED00+0x0C))
	#endif
	SCB_AIRCR	=	NVIC_GRB_SUB_NUM;
}


void	NVIC_voidEnableInt(u8 IntNum)
{
	if(IntNum<32)
	{
		NVIC_ISER0 = (1<<IntNum) ;
	}
	else if(IntNum<64)
	{
		IntNum -= 32 ;
		NVIC_ISER1 = (1<<IntNum) ;
	}
}


void	NVIC_voidDisableInt(u8 IntNum)
{
	if(IntNum<32)
	{
		NVIC_ICER0 = (1<<IntNum) ;
	}
	else if(IntNum<64)
	{
		IntNum -= 32 ;
		NVIC_ICER1 = (1<<IntNum) ;
	}
}

void	NVIC_voidSetPendingFlag(u8 IntNum)
{
	if(IntNum<32)
	{
		NVIC_ISPR0 = (1<<IntNum) ;
	}
	else if(IntNum<64)
	{
		IntNum -= 32 ;
		NVIC_ISPR1 = (1<<IntNum) ;
	}
}


void	NVIC_voidClrPendingFlag(u8 IntNum)
{
	if(IntNum<32)
	{
		NVIC_ICPR0 = (1<<IntNum) ;
	}
	else if(IntNum<64)
	{
		IntNum -= 32 ;
		NVIC_ICPR1 = (1<<IntNum) ;
	}
}


u8	NVIC_u8GetActiveFlag(u8 IntNum)
{
	u8 Local_Active = 0x22;
	if(IntNum<32)
	{
		Local_Active	=	GET_BIT(NVIC_IABR0,(1<<IntNum));
	}
	else if(IntNum<64)
	{
		IntNum -= 32 ;
		Local_Active	=	GET_BIT(NVIC_IABR1,(1<<IntNum));
	}
	return Local_Active;
}

//NVIC_voidSetPriority(0,0b0111) /*Group 1 Sub 3*/
void	NVIC_voidSetPriority(u8 IntNum,u8 Priority)
{
	NVIC_IPR[IntNum] = (Priority<<4);
}

void	NVIC_voidEXTI0SetCallBack(void (*Pf) (void))
{
	if(Pf != NULL)
	{
		EXTI0_CallBack = Pf; //Ahmed
	}
}
void	NVIC_voidEXTI1SetCallBack(void (*Pf) (void))
{
	if(Pf != NULL)
	{
		EXTI1_CallBack = Pf; //Ahmed
	}
}

/*void	EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
}
void	EXTI1_IRQHandler(void)
{
	EXTI1_CallBack();
}
void	SysTick_Handler(void)
{

}*/

