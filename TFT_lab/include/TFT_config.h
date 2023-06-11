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
#ifndef TFT_CONFIG_H
#define TFT_CONFIG_H

#define HTFT_A0_PORT_PIN		MGPIO_PORTA, MGPIO_PIN0
#define HTFT_CS_PORT_PIN		MGPIO_PORTA, MGPIO_PIN1
#define HTFT_RST_PORT_PIN		MGPIO_PORTA, MGPIO_PIN1

#endif
