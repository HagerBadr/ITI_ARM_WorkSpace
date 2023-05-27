/*
 * main.c
 *
 *  Created on: May 8, 2023
 *      Author: Hager Badr
 */
#ifndef _RCC_PRIV_H_
#define _RCC_PRIV_H_


#define RCC_BASE_ADD       *((u32*)0x40023800)

#define RCC_CR               *((u32*)0x40023800)
#define RCC_PLLCFGR          *((u32*)0x40023804)
#define RCC_CFGR             *((u32*)0x40023808)
#define RCC_CIR              *((u32*)0x4002380C)
#define RCC_AHB1RSTR         *((u32*)0x40023810)
#define RCC_AHB2RSTR         *((u32*)0x40023814)
#define RCC_APB1RSTR         *((u32*)0x40023820)
#define RCC_APB2RSTR         *((u32*)0x40023824)
#define RCC_AHB1ENR          *((u32*)0x40023830)
#define RCC_AHB2ENR          *((u32*)0x40023834)
#define RCC_APB1ENR          *((u32*)0x40023840)
#define RCC_APB2ENR          *((u32*)0x40023844)
#define RCC_AHB1LPENR        *((u32*)0x40023850)
#define RCC_AHB2LPENR        *((u32*)0x40023854)
#define RCC_APB1LPENR        *((u32*)0x40023860)
#define RCC_APB2LPENR		 *((u32*)0x40023864)
#define RCC_BDCR             *((u32*)0x40023870)
#define RCC_CSR              *((u32*)0x40023874)
#define RCC_SSCGR            *((u32*)0x40023880)
#define RCC_PLLI2SCFGR       *((u32*)0x40023884)
#define RCC_DCKCFGR			 *((u32*)0x4002388C)

#define  RCC_HSE_RC             0
#define  RCC_HSE_CRYSTAL        1
#define  RCC_HSI                2
#define  RCC_PLL                3

#define  PLL_HSE                0
#define  PLL_HSI                1

/*Prescaler for AHB System Clock*/
#define system_clock_not_divided                0000
#define system_clock_divided_by_2               1000
#define system_clock_divided_by_4               1001
#define system_clock_divided_by_8               1010
#define system_clock_divided_by_16              1011
#define system_clock_divided_by_64              1100
#define system_clock_divided_by_128             1101
#define system_clock_divided_by_256             1110
#define system_clock_divided_by_512             1111

/*Prescaler for APB1 System Clock*/
#define AHB_clock_not_divided      000
#define AHB_clock_divided_by_2     100
#define AHB_clock_divided_by_4     101
#define AHB_clock_divided_by_8     110
#define AHB_clock_divided_by_16    111


#endif /*_RCC_PRIV_H_*/
