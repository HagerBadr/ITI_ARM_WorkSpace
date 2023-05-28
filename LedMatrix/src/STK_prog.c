/*
 * main.c
 *
 *  Created on: May 15, 2023
 *      Author: Hager Badr
 */

#include	"STD_TYPES.h"
#include	"BIT_Math.h"

#include	"STK_int.h"
#include	"STK_priv.h"
#include	"STK_config.h"


#ifndef		NULL
#define		NULL	(void *)0
#endif

static void (*SysTick_CallBack) (void) = NULL;
static u8	STK_u8ModeOfInterval;
void	STK_voidInit(void)
{

	#if		STK_CLK_SRC		==		STK_AHB_DIV_8
				STK -> CTRL = 0x00000000 ;
	#elif	STK_CLK_SRC		==		STK_AHB
				STK -> CTRL = 0x00000004 ;
	#else
		#error	"Wrong choice of SysTick Prescaler"
	#endif

}

void	STK_voidBusyWait(u32 Ticks)
{
	/*		Load Ticks to Load Register		*/
	STK -> LOAD	= Ticks;
	/*		Start Timer 					*/
	SET_BIT(STK -> CTRL , 0);
	/*		Wait till the flag raised 		*/
	while((GET_BIT(STK -> CTRL , 16))== 0)
	{
		asm("NOP");
	}
	/*		Stop Timer 						*/
	CLR_BIT(STK -> CTRL , 0);
	STK -> LOAD	= 0;
	STK -> VAL	= 0;

}

void	STK_voidSetIntervalSingle(u32 Ticks,void (*Pf)(void))
{
	/*		Load Ticks to Load Register		*/
	STK -> LOAD	= Ticks;
	/*		Start Timer 					*/
	SET_BIT(STK -> CTRL , 0);
	/*		Save CallBack					*/
	SysTick_CallBack = Pf;
	/*		Software Flage to indicate which callback will execute	*/
	STK_u8ModeOfInterval = STK_SINGLE_INTERVAL;
	/*		SysTick Interrupt Enable PIE	*/
	SET_BIT(STK -> CTRL , 1);

}

void	STK_voidSetIntervalPeriodic(u32 Ticks,void (*Pf)(void))
{
	/*		Load Ticks to Load Register		*/
	STK -> LOAD	= Ticks;
	/*		Start Timer 					*/
	SET_BIT(STK -> CTRL , 0);
	/*		Save CallBack					*/
	SysTick_CallBack = Pf;
	/*		Software Flage to indicate which callback will execute	*/
	STK_u8ModeOfInterval = STK_PERIOD_INTERVAL;
	/*		SysTick Interrupt Enable PIE	*/
	SET_BIT(STK -> CTRL , 1);

}

void	STK_voidStopInterval(void)
{
	/*		Stop Timer 						*/
	CLR_BIT(STK -> CTRL , 0);
	STK -> LOAD	= 0;
	STK -> VAL	= 0;
}

u32		STK_u32GetElapsedTime(void)
{
	u32	Local_u32ElapsedTime;
	//LOAD REG - VAR REG
	Local_u32ElapsedTime = ((STK -> LOAD) - (STK -> VAL));
	return Local_u32ElapsedTime;
}
u32		STK_u32GetRemainingTime(void)
{
	//B2Y 2D 2EEH
	u32	Local_u32RemainingTime;
	Local_u32RemainingTime =  (STK -> VAL);
	return Local_u32RemainingTime;
}
//Core Peripheral
void	SysTick_Handler(void)
{
	u8 Local_u8Temp = 0;
	if(STK_u8ModeOfInterval == STK_SINGLE_INTERVAL)
	{
		/*	1- Disable the Interrupt 	*/
			CLR_BIT(STK -> CTRL , 1);
		/*	2- Stop the timer			*/
			CLR_BIT(STK -> CTRL , 0);
			STK -> LOAD	= 0;
			STK -> VAL	= 0;
	}
	SysTick_CallBack();
	/*	Clear Interrupt Flag by reading the Flag */
	Local_u8Temp	=	GET_BIT(STK -> CTRL , 16);
}

