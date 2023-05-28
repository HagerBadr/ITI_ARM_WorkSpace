/*
 * main.c
 *
 *  Created on: May 8, 2023
 *      Author: Hager Badr
 */
#ifndef _GPIO_PRIV_H_
#define _GPIO_PRIV_H_

/**
 * @brief GPIOx REGISTERS
 *          x refers to A, B OR C
 * 
 */
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




#if 0

typedef struct GPIO_priv
{
    /* Registers As Members */
    volatile u32 MODER;     /*port mode register*/
    volatile u32 OTYPER;    /*GPIO port output type register*/
    volatile u32 OSPEEDR;   /*GPIO port output speed register*/
    volatile u32 PUPDR;     /*GPIO port pull-up/pull-down register*/
    volatile u32 IDR;       /*GPIO port input data register*/
    volatile u32 ODR;       /*GPIO port output data register*/
    volatile u32 BSRR;      /*GPIO port bit set/reset register*/
    volatile u32 LCKR;      /*GPIO port configuration lock register*/
    volatile u32 AFRL;      /*GPIO alternate function low register*/
    volatile u32 AFRH;      /*GPIO alternate function high register*/
}GPIO_t;

/**
 * @brief Registers Base Address
 * 
 */
#define GPIOA ((volatile GPIO_t*)0x40020000)
#define GPIOB ((volatile GPIO_t*)0x40020400)
#define GPIOC ((volatile GPIO_t*)0x40020800)


/***************************************************************************************************
 **********************                         BITS                       *************************
 ***************************************************************************************************/
#define     BIT_0           0 
#define     BIT_1           1

#define     BIT_2           2
#define     BIT_3           3

#define     BIT_4           4 
#define     BIT_5           5

#define     BIT_6           6 
#define     BIT_7           7

#define     BIT_8           8 
#define     BIT_9           9

#define     BIT_10          10 
#define     BIT_11          11

#define     BIT6_12         12
#define     BIT6_13         13

#define     BIT7_14         14
#define     BIT7_15         15

#define     BIT8_16         16 
#define     BIT8_17         17

#define     BIT9_18         18 
#define     BIT9_19         19

#define     BIT10_20        20 
#define     BIT10_21        21

#define     BIT11_22        22 
#define     BIT11_23        23

#define     BIT12_24        24 
#define     BIT12_25        25

#define     BIT13_26        26 
#define     BIT13_27        27

#define     BIT14_28        28
#define     BIT14_29        29

#define     BIT15_30        30
#define     BIT15_31        31

#endif

#endif /*_GPIO_PRIV_H_*/
