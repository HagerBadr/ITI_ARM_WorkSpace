/*
 * main.c
 *
 *  Created on: May 7, 2023
 *      Author: Hager Badr
 */
#include "BIT_MATH.H"
#include "STD_TYPES.H"
#include "RCC_int.h"
#include "GPIO_int.h"
#include "SPI_interface.h"
#include "TFT_interface.h"
#include "image.h"

//void play();
void main()
{
MRCC_voidInit();
MRCC_voidEnablePeripheralClock(RCC_AHB1,0);
MRCC_voidEnablePeripheralClock(RCC_APB2,12);

//MGPIO_voidSetPinMode(MGPIO_PORTA,MGPIO_PIN5,MGPIO_ALTERNATIVE_FUNCTION);
//MGPIO_voidSetPinMode(MGPIO_PORTA,MGPIO_PIN6,MGPIO_ALTERNATIVE_FUNCTION);
//
//MGPIO_voidSetAlternativeFunctio(MGPIO_PORTA,MGPIO_PIN5,MGPIO_AF05);
//MGPIO_voidSetAlternativeFunctio(MGPIO_PORTA,MGPIO_PIN6,MGPIO_AF05);

STK_voidInit();
MSPI1_voidInit();
HTFT_voidInit();
HTFT_voidDisplayImage(arr);

	while(1)
	{

	//	 play();


	}
}
//void play()





#if 0
#include "BIT_MATH.H"
#include "STD_TYPES.H"

#include "RCC_int.h"
#include "GPIO_int.h"
#include "STK_int.h"
#include "NVIC_interface.h"
#include "EXTI_int.h"


#include "IR_int.h"


void main(void)
{
	HIR_voidInit();


	while(1)
	{
		HIR_voidPlay();
	}
}
#endif
#if 0
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "Delay.h"
#include "RCC_int.h"
#include "GPIO_int.h"
#include "STK_int.h"
#include "NVIC_interface.h"
#include "EXTI_int.h"

void APP_GETFRAME();
void APP_TakeAction();
void APP_voidPlay(void);

u8 APP_u8StartEdgeFlag = 0;
u32 APP_u32ReceiveFrame[50] = {0};
u8 APP_u8EdgeCounter = 0;
u8 Local_u8LoopCounter = 0;
u8 APP_u8ButtonData = 0;

void main()
{

	MRCC_voidInit();


	MRCC_voidEnablePeripheralClock(RCC_AHB1,0);

	MGPIO_voidSetPinMode(MGPIO_PORTA,MGPIO_PIN8,MGPIO_INPUT);
	MGPIO_voidSetPinOutputType(MGPIO_PORTA,MGPIO_PIN8,OUTPUT_PUSH_PULL);

	MGPIO_voidSetPinMode(MGPIO_PORTA,MGPIO_PIN9,MGPIO_INPUT);
	MGPIO_voidSetPinOutputType(MGPIO_PORTA,MGPIO_PIN9,OUTPUT_PUSH_PULL);

	STK_voidInit();


	MEXTI_voidInit();
	MEXTI_voidChangeSenseEnable(0,MEXTI_FALLING_EDGE);
	MEXTI_voidSetCallBack(0,&APP_GETFRAME);
	MEXTI_voidEnableInterrupt(0);

	//MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);
	NVIC_voidInit();
	NVIC_voidEnableInt(6);

	while(1)
	{
		APP_voidPlay();
	}
}


void APP_GETFRAME()
{
	if(APP_u8StartEdgeFlag == 0)
	{
		STK_voidSetIntervalSingle(1000000,&APP_TakeAction);
		APP_u8StartEdgeFlag = 1;
	}
	else
	{
		/*Get the Counted Time */
		APP_u32ReceiveFrame[APP_u8EdgeCounter] = STK_u32GetElapsedTime();
		/*Reset the Timer*/
		STK_voidStopInterval();
		/*Set preload Value*/
		STK_voidSetIntervalSingle(1000000,&APP_TakeAction);
		/*Increment the Edge Counter*/
		APP_u8EdgeCounter++;
	}
}

void APP_TakeAction()
{
	/*2wl ma 2d5l el function de m3nha 2ny 2stlmt el frame kloh keda*/
	for(Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
	{
		if((APP_u32ReceiveFrame[Local_u8LoopCounter] >= 1000) &&
				(APP_u32ReceiveFrame[Local_u8LoopCounter] <= 1500))
		{
			CLR_BIT(APP_u8ButtonData,Local_u8LoopCounter);
		}
		else
		{
			SET_BIT(APP_u8ButtonData,Local_u8LoopCounter);
		}
	}
APP_u8StartEdgeFlag = 0;
APP_u8EdgeCounter = 0;

}

void APP_voidPlay(void)
{
	switch(APP_u8ButtonData)
	{
	case 22:
		MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN9,HIGH);

		//asm("NOP");
		break;
	case 12:
		MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN9,LOW);

		//		asm("NOP");
		break;
	}
}
#endif
