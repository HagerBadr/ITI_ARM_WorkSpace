#ifndef _EXTI_INT_H_
#define _EXTI_INT_H_

void MEXTI_voidInit(void);
void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTILine);
void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTILine);
void MEXTI_voidChangeSenseEnable(u8 Copy_u8EXTILine , u8 Copy_u8SenseSignal);
void MEXTI_voidSetCallBack(u8 Copy_u8EXTILine, void (*pvNotificationFunction)(void));

#define		MEXTI_RISING_EDGE		0
#define 	MEXTI_FALLING_EDGE		1
#define 	MEXTI_ON_CHANGE			2

#endif
