/*
|================================================================================|
|________________________________________________________________________________|
| ~ Author:          Hager Badr Eldeen                            		         |
| ~ Creation Data:   1 June 2023                                                 |
| ~ Version:         v1.0                                                        |
| ~ Compiler:        GNU ARM-GCC                                                 |
| ~ Controller:      STM32F401CCU6                                               |
|________________________________________________________________________________|
| ~ Version     Date                  Author                  Description        |
| ~ v1.0        1 June, 2023   Hager Badr Eldeen              Initial Creation   |
|________________________________________________________________________________|
|                                                                                |
|================================================================================|
*/
#include "BIT_MATH.H"
#include "STD_TYPES.H"

#include "RCC_int.h"
#include "GPIO_int.h"
#include "STK_int.h"
#include "NVIC_interface.h"
#include "EXTI_int.h"


#include "IR_int.h"

/*First Edge*/
static u8 Global_u8StartEdgeFlag = 0;

/*Time between every two falling edges*/
static u32 Global_u32ReceivedFrame[50] = {0};

/*Carry Decimal Number*/
static u8 Global_u8ButtonData = 0;

/*Edge Number*/
static u8 Global_u8EdgeCounter = 0;


void HIR_voidInit(void)
{
	/*RCC Init*/
	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA);

	/*Configure PA0*/
	MGPIO_voidSetPinMode	   (MGPIO_PORTA,MGPIO_PIN0,MGPIO_INPUT);
	MGPIO_voidSetPinInputType (MGPIO_PORTA,MGPIO_PIN0,PULLUP);


	/*Configure PA1*/
	MGPIO_voidSetPinMode	   (MGPIO_PORTA,MGPIO_PIN1,MGPIO_OUTPUT);
	/*Configure PA2*/
	MGPIO_voidSetPinMode	   (MGPIO_PORTA,MGPIO_PIN2,MGPIO_OUTPUT);
	/*Configure PA3*/
	MGPIO_voidSetPinMode	   (MGPIO_PORTA,MGPIO_PIN3,MGPIO_OUTPUT);


	/*Init STK*/
	/*On But not counting cuz load = 0 */
	STK_voidInit();


	/*EXTI Init*/
	MEXTI_voidInit();
	/*Falling*/
	MEXTI_voidChangeSenseEnable(MEXTI_LINE0 , MEXTI_FALLING_EDGE);
	/*Pass The Function*/
	MEXTI_voidSetCallBack(MEXTI_LINE0 , &HIR_voidGetFrame);
	/*Enable Interrupt*/
	MEXTI_voidEnableInterrupt(MEXTI_LINE0);


	/*NVIC Init*/
	NVIC_voidInit();
	/*Enable EXT0 Interrupt*/
	NVIC_voidEnableInt(6);
}

void HIR_voidGetFrame(void)
{
	if(Global_u8StartEdgeFlag == 0)
	{
		/*Set timer with Total FrameTime*/
		STK_voidSetIntervalSingle(60000,&HIR_voidTakeAction);

		Global_u8StartEdgeFlag = 1;
	}
	else
	{	/*Get the counted TIME*/
		Global_u32ReceivedFrame[Global_u8EdgeCounter] = STK_u32GetElapsedTime();
		/*Reset Timer*/
		MSTK_voidResetSYSTICK();
		/*Set PreLoad Value*/
		STK_voidSetIntervalSingle(60000,&HIR_voidTakeAction);
		/*Inc Edge Counter*/
		Global_u8EdgeCounter++;


	}
}

void HIR_voidTakeAction(void)
{
	u8 Local_u8LoopCounter = 0;
	for (Local_u8LoopCounter = 0; Local_u8LoopCounter < 8 ; Local_u8LoopCounter ++)
	{
		/*Data From 17 to 24*/
		if ((Global_u32ReceivedFrame[17+Local_u8LoopCounter] >= 1000) &&
				(Global_u32ReceivedFrame[17+Local_u8LoopCounter] <= 1500))
		{
			/*Zero*/
			CLR_BIT(Global_u8ButtonData,Local_u8LoopCounter);
		}

		else
		{
			SET_BIT(Global_u8ButtonData,Local_u8LoopCounter);
		}
	}
	Global_u8StartEdgeFlag = 0;
	Global_u8EdgeCounter = 0;
}

void HIR_voidPlay(void)
{
	switch(Global_u8ButtonData)
	{

	  case 22://0
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN1,HIGH);
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN2,LOW);
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN3,LOW);
	  	break;
	  case 12://1
	    MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN1,LOW);
	    MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN2,HIGH);
	    MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN3,LOW);
	  	break;
	  case 24://2
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN1,LOW);
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN2,LOW);
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN3,HIGH);
	  	break;
	  case 94://3
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN1,HIGH);
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN2,HIGH);
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN3,LOW);
	  	break;
	  case 8://4
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN1,HIGH);
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN2,LOW);
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN3,HIGH);
	  	break;
	  case 28://5
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN1,LOW);
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN2,HIGH);
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN3,HIGH);
	  	break;
	  case 90://6
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN1,HIGH);
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN2,HIGH);
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN3,HIGH);
	  	break;
	  case 69://ON-OFF
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN1,LOW);
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN2,LOW);
	  	MGPIO_voidSetPinValue(MGPIO_PORTA,MGPIO_PIN3,LOW);
	  	break;
	}
}


