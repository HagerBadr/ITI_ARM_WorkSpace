/**
 * @file GPIO_int.h
 * @author Doaa Hagag (doaahagag128@gmail.com)
 * @version 1.2
 * @brief Add MGPIO_voidSetPin and MGPIO_voidResetPin functions
 * @compiler:   GNU ARM-GCC
 * @controller: STM32F40ICCU6
 * @layer:      MCAL 
 * @date 2023-05-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef _GPIO_INT_H_
#define _GPIO_INT_H_

#define MGPIO_PORTA 					0
#define MGPIO_PORTB						1
#define MGPIO_PORTC						2

#define MGPIO_OUTPUT					1
#define MGPIO_INPUT						0
#define MGPIO_ALTERNATIVE_FUNCTION		2
#define MGPIO_ANALOG					3

#define HIGH							1
#define LOW								0

#define MGPIO_AF05					0b0101

#define OUTPUT_PUSH_PULL				0
#define OUTPUT_OPEN_DRAIN				1

#define NO_PULLUP_NO_PULLDOWN	0
#define PULLDOWN				2
#define PULLUP					1

#define  MGPIO_LOW_SPEED				0
#define  MEDIUM_SPEED_UP_TO_10MHZ		1
#define  HIGH_SPEED_UP_TO_50MHZ			2
#define  VERY_HIGH_SPEED_UP_TO_100MHZ	3


void MGPIO_voidSetPinOutputType(u8 Copy_u8PortName ,u8 Copy_u8PinNumber, u8 Copy_u8OutputType);
void MGPIO_voidSetPinMode(u8 Copy_u8PortName ,u8 Copy_u8PinNumber, u8 Copy_u8Mode);
void MGPIO_voidSetPinOutPutSpeed(u8 Copy_u8PortName ,u8 Copy_u8PinNumber, u8 Copy_u8OutputSpeed);
void MGPIO_voidSetPinValue(u8 Copy_u8PortName ,u8 Copy_u8PinNumber, u8 Copy_u8PinValue);
void MGPIO_voidSetPinInputType(u8 Copy_u8PortName ,u8 Copy_u8PinNumber, u8 Copy_u8InputType);
void MGPIO_voidSetAlternativeFunctio(u8 Copy_u8PortName,u8 Copy_u8PinName,u8 Copy_u8AlternativeNumber);


#define MGPIO_PIN0		0
#define MGPIO_PIN1		1
#define MGPIO_PIN2		2
#define MGPIO_PIN3		3
#define MGPIO_PIN4		4
#define MGPIO_PIN5		5
#define MGPIO_PIN6		6
#define MGPIO_PIN7		7
#define MGPIO_PIN8		8
#define MGPIO_PIN9		9
#define MGPIO_PIN10		10
#define MGPIO_PIN11		11
#define MGPIO_PIN12		12
#define MGPIO_PIN13		13
#define MGPIO_PIN14		14
#define MGPIO_PIN15		15


#if 0
typedef enum {
    GPIOA_PORT,
    GPIOB_PORT,
    GPIOC_PORT
}GPIO_NUM_t;

typedef enum {
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15,
    PIN16
}PIN_NUM_t;

typedef enum {
    INPUT =0,                          /*Input (reset state)*/
    OUTPUT=1,                          /*General purpose output mode*/
    ALTERNATIVE_FUNCTION,              /*Alternate function mode*/
    ANALOG                            /*Analog mode*/
}PIN_MODE_t;

typedef enum {
    OUTPUT_PUSH_PULL,
    OUTPUT_OPEN_DRAIN
}OUTPUT_t;

typedef enum {
    LOW_SPEED_2MHZ,
    MEDIUM_SPEED_UP_TO_10MHZ,
    HIGH_SPEED_UP_TO_50MHZ,
    VERY_HIGH_SPEED_UP_TO_100MHZ
}OUTPUT_SPEED_t;

typedef enum {
    NO_PULL_UP_NO_PULL_DOWN,
    PULL_UP,
    PULL_DOWN
}OUTPUT_MODE_t;

void MGPIO_voidSetPinDirection(GPIO_NUM_t GPIO_N , PIN_NUM_t PIN_NUMBER , PIN_MODE_t PinMode); /*Done*/
void MGPIO_voidSetPinOutputType(GPIO_NUM_t GPIO_N ,PIN_NUM_t PIN_NUMBER , OUTPUT_t Output_Type); /*Done*/
void MGPIO_voidSetPinOutputSpeed(GPIO_NUM_t GPIO_N ,PIN_NUM_t PIN_NUMBER , OUTPUT_SPEED_t Output_Speed);/*Done*/
void MGPIO_voidSetPinOutputMode(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER , OUTPUT_MODE_t Mode); /*Done*/
void MGPIO_voidGetInputPinValue(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER , u8 *Local_pu8Value);  /*Done*/ //Read IDR
void MGPIO_voidGetOutputPinValue(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER , u8 *Local_pu8Value); /*Done*/  //Read ORD
void MGPIO_voidSetPin(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER);    /*Done*/
void MGPIO_voidResetPin(GPIO_NUM_t GPIO_N  ,PIN_NUM_t PIN_NUMBER);  /*Done*/


#endif


#endif /*_GPIO_INT_H_*/
