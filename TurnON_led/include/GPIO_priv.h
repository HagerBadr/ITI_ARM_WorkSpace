/*
 * main.c
 *
 *  Created on: May 8, 2023
 *      Author: Hager Badr
 */
#ifndef _GPIO_PRIV_H_
#define _GPIO_PRIV_H_

#define GPIO_OUTPUT_MODE		0b01



#define	GPIOA_BASE_ADDRESS			*((volatile u32 *)0x40020000)

#define	GPIOA_MODER			*((volatile u32 *)0x40020000)
#define GPIOA_OTYPER		*((volatile u32 *)0x40020004)
#define GPIOA_OSPEEDR		*((volatile u32 *)0x40020008)
#define GPIOA_PUPDR			*((volatile u32 *)0x4002000C)
#define GPIOA_ODR			*((volatile u32 *)0x40020014)
/*******************GPIO_B********************/
#define	GPIOB_MODER			*((volatile u32 *)0x40020400)
#define GPIOB_OTYPER		*((volatile u32 *)0x40020404)
#define GPIOB_OSPEEDR		*((volatile u32 *)0x40020408)
#define GPIOB_PUPDR			*((volatile u32 *)0x4002040C)
#define GPIOB_ODR			*((volatile u32 *)0x40020414)
/*******************GPIO_C********************/
#define	GPIOC_MODER			*((volatile u32 *)0x40020800)
#define GPIOC_OTYPER		*((volatile u32 *)0x40020804)
#define GPIOC_OSPEEDR		*((volatile u32 *)0x40020808)
#define GPIOC_PUPDR			*((volatile u32 *)0x4002080C)
#define GPIOC_ODR			*((volatile u32 *)0x40020814)



#endif /*_GPIO_PRIV_H_*/
