/*****************************************************************************************
 * Author:				Abdullah M. Abdullah
 * Creation Data:		30 May, 2023
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				HAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				  Description
 * v1.0		  30 May, 2023	Abdullah M. Abdullah		  Initial Creation
*****************************************************************************************/
#ifndef TFT_PRIVATE_H
#define TFT_PRIVATE_H

#define SLPOUT_CMD      0x11
#define COLMOD_CMD      0x3A
#define DISPON_CMD      0x29

static void HTFT_voidSendCommand(u8 Copy_u8Command);
static void HTFT_voidSendData(u8 Copy_u8Data);

#endif
