/**
 * @file RCC_config.h
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

#ifndef _RCC_CONFIG_H_
#define _RCC_CONFIG_H_


/*CHOOSE RCC_CLK_SOURCE:
* RCC_HSE_RC
* RCC_HSE_CRYSTAL
* RCC_HSI
* RCC_PLL
*/
#define RCC_CLK_SOURCE      RCC_HSI

/*CHOOSE PLL_SOURCE
* PLL_HSI
* PLL_HSE
*/
#if RCC_CLK_SOURCE == RCC_PLL
#define PLL_SOURCE          PLL_HSE
#endif // RCC_CLK_SOURCE

/* CHOOSE AHP_PRESCALER
* system_clock_not_divided
* system_clock_divided_by_2
* system_clock_divided_by_4
* system_clock_divided_by_8
* system_clock_divided_by_16
* system_clock_divided_by_64
* system_clock_divided_by_128
* system_clock_divided_by_256
* system_clock_divided_by_512
*/
#define AHP_PRESCALER       system_clock_not_divided

/* CHOOSE APB1_PRESCALER and APB2_PRESCALER
* AHB_clock_not_divided
* AHB_clock_divided_by_2
* AHB_clock_divided_by_4
* AHB_clock_divided_by_8
* AHB_clock_divided_by_16
*/
#define APB1_PRESCALER      AHB_clock_not_divided
#define APB2_PRESCALER      AHB_clock_not_divided

//#define RTC_PRESCALER

/* CHOOSE MICROCONTROLLER_CLOCK_OUTPUT_1
   &      MICROCONTROLLER_CLOCK_OUTPUT_2
*HSI - HSE - LSE - PLL
*/
#define  MCO_1
#define  MCO_2

/* CHOOSE PRESCALER FOR MCO1 and MCO2
* NO_DIVISION
* DIVISION_BY_2
* DIVISION_BY_3
* DIVISION_BY_4
* DIVISION_BY_5
*/
#define MCO_1_PRESCALER
#define MCO_2_PRESCALER


#endif /*_RCC_CONFIG_H_*/
