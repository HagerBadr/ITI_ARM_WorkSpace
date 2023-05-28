#ifndef _EXTI_PRIV_H_
#define _EXTI_PRIV_H_


typedef struct
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
}EXTI_t;

#define MEXTI			((volatile EXTI_t *)0x40013C00)
#define SYSCFG_CR1		((volatile EXTI_t *)0x40013808)

#endif
