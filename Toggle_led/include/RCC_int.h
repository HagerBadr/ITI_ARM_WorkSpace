/**
 * @file RCC_int.h
 * @author Doaa Hagag (doaahagag128@gmail.com)
 * @brief
 * @compiler:   GNU ARM-GCC
 * @controller: STM32F40ICCU6
 * @layer:      MCAL
 * @version 0.1
 * @date 2023-05-01
 *
 * @copyright Copyright (c) 2023
 *
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
