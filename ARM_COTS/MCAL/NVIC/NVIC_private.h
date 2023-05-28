/*
 * INVIC_private.h
 *
 *  Created on: Mar 5, 2023
 *      Author: Delta Store
 */

#ifndef INVIC_INVIC_PRIVATE_H_
#define INVIC_INVIC_PRIVATE_H_

#define		NVIC_16GRB_0SUB			(0x5FA00300)
#define		NVIC_8GRB_2SUB			(0x5FA00400)
#define		NVIC_4GRB_4SUB			(0x5FA00500)
#define		NVIC_2GRB_8SUB			(0x5FA00600)
#define		NVIC_0GRB_16SUB			(0x5FA00700)


#define		NVIC_BASE_ADD			(0xE000E100)

#define		NVIC_ISER0				*((u32 *)(NVIC_BASE_ADD+0x000))
#define		NVIC_ISER1				*((u32 *)(NVIC_BASE_ADD+0x004))

#define		NVIC_ICER0				*((u32 *)(NVIC_BASE_ADD+0x080))
#define		NVIC_ICER1				*((u32 *)(NVIC_BASE_ADD+0x084))

#define		NVIC_ISPR0				*((u32 *)(NVIC_BASE_ADD+0x100))
#define		NVIC_ISPR1				*((u32 *)(NVIC_BASE_ADD+0x104))

#define		NVIC_ICPR0				*((u32 *)(NVIC_BASE_ADD+0x180))
#define		NVIC_ICPR1				*((u32 *)(NVIC_BASE_ADD+0x184))

#define		NVIC_IABR0				*((u32 *)(NVIC_BASE_ADD+0x200))
#define		NVIC_IABR1				*((u32 *)(NVIC_BASE_ADD+0x204))

#define		NVIC_IPR				((u8 *)(NVIC_BASE_ADD+0x300))

#endif /* INVIC_INVIC_PRIVATE_H_ */
