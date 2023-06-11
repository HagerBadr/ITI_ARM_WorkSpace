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


/**
 * @brief : Select from    :  HSI or HSE  or PLL
 */
#define CPU_CLK_SOURCE      HSI

/**
 * @brief : Select from    :  HSI or HSE
 */
#define PLL_SOURCE          HSE

/**
 * @brief : Select from    :  ENABLE or DISABLE
 */
#define HSI_STATUS          ENABLE

/**
 * @brief : Select from    :  ENABLE or DISABLE
 */
#define HSE_STATUS          ENABLE

/**
 * @brief : Select from    :  ENABLE or DISABLE
 */
#define PLL_STATUS          ENABLE

/**
 * @brief : Select from    :  ENABLE or DISABLE
 */
#define CSS_SYSTEM_STATUS          ENABLE


/**
 * @select: from    : [ 1 : 31 ]
 * @default: 16 = 16 MHZ
 *              + step  .... + 40 MHZ
 *              - step  .... - 40 MHZ
 */
#define HSI_CALIBRATE           16

/**
 * @select: from
 *
 *
 */
#define AHB_PRESCALER  SYS_CLOCK_DIVIDE_BY_2

#define APB1_PRESCALER           APB1_2_DIVIDE_BY_2

#define APB2_PRESCALER           APB1_2_DIVIDE_BY_2
#endif /*_RCC_CONFIG_H_*/
