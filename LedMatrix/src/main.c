/*
 * main.c
 *
 *  Created on: May 14, 2023
 *      Author: Hager Badr
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "RCC_int.h"
#include "GPIO_int.h"
#include "STK_int.h"
#include "led_matrix_int.h"




#if 1
void main()
{
	u8 ARRAY[8] ={0, 62, 8, 8, 8, 62, 0, 0};

	MRCC_voidInitSysClock();
	MRCC_voidEnableClock(RCC_AHP1,0);
	MRCC_voidEnableClock(RCC_AHP1,1);

	HLEDMAT_voidInit();
	while(1)
	{
		HLEDMAT_voidDisplay(&ARRAY);

	}
}
#endif
