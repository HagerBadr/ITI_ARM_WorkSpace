/*
 * INVIC_init.h
 *
 *  Created on: Mar 5, 2023
 *      Author: Delta Store
 */

#ifndef INVIC_INVIC_INIT_H_
#define INVIC_INVIC_INIT_H_

#define     MNVIC_EXTI0     6
#define     MNVIC_EXTI1     7

void	NVIC_voidInit(void);

void	NVIC_voidEnableInt(u8 IntNum);
void	NVIC_voidDisableInt(u8 IntNum);

void	NVIC_voidSetPendingFlag(u8 IntNum);
void	NVIC_voidClrPendingFlag(u8 IntNum);

u8	NVIC_u8GetActiveFlag(u8 IntNum);
void	NVIC_voidSetPriority(u8 IntNum,u8 Priority);
void	EXTI0_IRQHandler(void);
void	SysTick_Handler(void) ;
void	NVIC_voidEXTI0SetCallBack(void (*Pf) (void));
void	NVIC_voidEXTI1SetCallBack(void (*Pf) (void));
#endif /* INVIC_INVIC_INIT_H_ */
