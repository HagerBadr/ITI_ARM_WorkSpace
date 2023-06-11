/*
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
|________________________________________________________________________________|
| ~ Author:          Hesham Abdallah NourEldeen                                  |
| ~ Creation Data:   24 May 2023                                                 |
| ~ Version:         v1.0                                                        |
| ~ Compiler:        GNU ARM-GCC                                                 |
| ~ Controller:      STM32F401CCU6                                               |
|________________________________________________________________________________|
| ~ Version     Date                  Author                  Description        |
| ~ v1.0        24 May, 2023    Hesham Abdallah NourEldeen    Initial Creation   |
|________________________________________________________________________________|
|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
*/
#ifndef IR_INTERFACE_H_
#define IR_INTERFACE_H_

void HIR_voidInit();
void HIR_voidGetFrame(void);
void HIR_voidTakeAction(void);
void HIR_voidPlay(void);

#endif /* IR_INTERFACE_H_ */
