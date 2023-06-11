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

//#include "STD_TYPES.h"

#define     RCC_AHB1        0
#define     RCC_AHB2        1
#define     RCC_APB1        2
#define     RCC_APB2        3

#define     RCC_GPIOA       0
#define     RCC_GPIOB       1
#define     RCC_GPIOC       2


/**
 * @brief Function to Initialize The System Clock Source
 *          prebuild Configuration
 * @return ** void
 */
void MRCC_voidInit(void);

/**
 * @brief Function To Enable Peripheral Clock
 *
 * @param Copy_u8PeripheralBus
 *          Choose From : RCC_AHB1, RCC_AHB2, RCC_APB1, RCC_APB2
 * @param Copy_u8PeripheralID
 *          choose From : RCC_GPIOA, RCC_GPIOB, RCC_GPIOC
 * @return ** void
 */
void MRCC_voidEnablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeriperhalID);

/**
 * @brief Function To Disable Peripheral Clock
 *
 * @param Copy_u8PeripheralBus
 *          Choose From : RCC_AHB1, RCC_AHB2, RCC_APB1, RCC_APB2
 * @param Copy_u8PeripheralID
 *          choose From : RCC_GPIOA, RCC_GPIOB, RCC_GPIOC
 * @return ** void
 */
void MRCC_voidDisablePeripheralClock(u8 Copy_u8PeripheralBus, u8 Copy_u8PeriperhalID);


#endif /*_RCC_INT_H_*/
