/*
 * SSD_prg.c
 *
 *  Created on: Feb 1, 2023
 *  Author: Hager Badr
 */

#include"STD_TYPES.h"
#include"GPIO_int.h"

#include"SSD_pri.h"
#include"SSD_config.h"
#include"SSD_int.h"

static void	_delay_ms(u32 _ms)
{
	for(u32 i = 0; i < (_ms * 500) ; i++)
	{
		asm("NOP");
	}
}

void H_SSD_Void_init(void)
{
	//set all SSD pins as output
	MGPIO_voidSetPinMode(SSD_LED_A_PORT, SSD_LED_A_PIN, MGPIO_OUTPUT) ;
	MGPIO_voidSetPinMode(SSD_LED_B_PORT, SSD_LED_B_PIN, MGPIO_OUTPUT) ;
	MGPIO_voidSetPinMode(SSD_LED_C_PORT, SSD_LED_C_PIN, MGPIO_OUTPUT) ;
	MGPIO_voidSetPinMode(SSD_LED_D_PORT, SSD_LED_D_PIN, MGPIO_OUTPUT) ;
	MGPIO_voidSetPinMode(SSD_LED_E_PORT, SSD_LED_E_PIN, MGPIO_OUTPUT) ;
	MGPIO_voidSetPinMode(SSD_LED_F_PORT, SSD_LED_F_PIN, MGPIO_OUTPUT) ;
	MGPIO_voidSetPinMode(SSD_LED_G_PORT, SSD_LED_G_PIN, MGPIO_OUTPUT) ;
	MGPIO_voidSetPinMode(SSD_LED_DOT_PORT, SSD_LED_DOT_PIN, MGPIO_OUTPUT) ;

	//set enable pins at output
	MGPIO_voidSetPinMode(SSD_DIG_1_EN_PORT, SSD_DIG_1_EN_PIN, MGPIO_OUTPUT) ;
	MGPIO_voidSetPinMode(SSD_DIG_2_EN_PORT, SSD_DIG_2_EN_PIN, MGPIO_OUTPUT) ;

}


void H_SSD_Void_DisplayNumber(u8 number)
{
	if(number>99)
	{
		return ;
	}

	u8 uints = number % 10 ;
	u8 tens = number / 10 ;
	u32 i ;

	for(i=0;i<SSD_DISPLAY_TIME;i++)
	{
		switch(uints)
		{
		case 0:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, LOW) ;
			break ;
		case 1:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, LOW) ;
			break ;
		case 2:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH) ;
			break ;
		case 3:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH) ;
			break ;
		case 4:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH) ;
			break ;
		case 5:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH) ;
			break ;
		case 6:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH) ;
			break ;
		case 7:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, LOW) ;
			break ;
		case 8:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH) ;
			break ;
		case 9:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH) ;
			break ;
		}

		// enable DIG 1 (units)
		MGPIO_voidSetPinValue(SSD_DIG_1_EN_PORT, SSD_DIG_1_EN_PIN,LOW  ) ;
		// disable DIG 2 (tens)
		MGPIO_voidSetPinValue(SSD_DIG_2_EN_PORT, SSD_DIG_2_EN_PIN,HIGH ) ;
		//delay
		_delay_ms(10) ;
		// disable DIG 1 (units)

		switch(tens)
		{
		case 0:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, LOW) ;
			break ;
		case 1:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, LOW) ;
			break ;
		case 2:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH) ;
			break ;
		case 3:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH) ;
			break ;
		case 4:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH) ;
			break ;
		case 5:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH) ;
			break ;
		case 6:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH) ;
			break ;
		case 7:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, LOW) ;
			break ;
		case 8:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH) ;
			break ;
		case 9:
			MGPIO_voidSetPinValue(SSD_LED_A_PORT, SSD_LED_A_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_B_PORT, SSD_LED_B_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_C_PORT, SSD_LED_C_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_D_PORT, SSD_LED_D_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_E_PORT, SSD_LED_E_PIN, LOW) ;
			MGPIO_voidSetPinValue(SSD_LED_F_PORT, SSD_LED_F_PIN, HIGH) ;
			MGPIO_voidSetPinValue(SSD_LED_G_PORT, SSD_LED_G_PIN, HIGH) ;
			break ;
		}
		// enable DIG 2 (tens)
		MGPIO_voidSetPinValue(SSD_DIG_1_EN_PORT, SSD_DIG_1_EN_PIN,HIGH) ;
		MGPIO_voidSetPinValue(SSD_DIG_2_EN_PORT, SSD_DIG_2_EN_PIN,LOW ) ;
		_delay_ms(10) ;
		// disable DIG 2 (tens)
		MGPIO_voidSetPinValue(SSD_DIG_2_EN_PORT, SSD_DIG_2_EN_PIN,HIGH) ;
	}
}

void H_SSD_Void_DisplayOFF(void)
{
	// disable DIG 1 (units)
	MGPIO_voidSetPinValue(SSD_DIG_1_EN_PORT, SSD_DIG_1_EN_PIN,HIGH) ;
	// disable DIG 2 (tens)
	MGPIO_voidSetPinValue(SSD_DIG_2_EN_PORT, SSD_DIG_2_EN_PIN,HIGH) ;
}
