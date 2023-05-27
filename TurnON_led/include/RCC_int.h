/*
 * main.c
 *
 *  Created on: May 8, 2023
 *      Author: Hager Badr
 */
#ifndef _RCC_INT_H_
#define _RCC_INT_H_

#define  RCC_AHP1     0
#define  RCC_AHP2     1
#define  RCC_APB1     2
#define  RCC_APB2     3

#define     RCC_GPIOA       0
#define     RCC_GPIOB       1
#define     RCC_GPIOC       2

void MRCC_voidInitSysClock(void);
void MRCC_voidEnableClock(u8 Copy_u8BusID , u8 Copy_u8PeriphralID);
void MRCC_voidDisableClock(u8 Copy_u8BusID , u8 Copy_u8PeriphralID);


#endif /*_RCC_INT_H_*/
