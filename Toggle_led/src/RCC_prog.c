/*
 * main.c
 *
 *  Created on: May 7, 2023
 *      Author: Hager Badr
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_int.h"
#include "RCC_priv.h"
#include "RCC_config.h"


void MRCC_voidInitSysClock(void)
{
    #if RCC_CLK_SOURCE == RCC_HSE_CRYSTAL
        /*HSE ENABLE.*/
        RCC_CR = 0x00010000;
        /*Select HSE as system CLK */
        SET_BIT(RCC_CFGR , 0);
        CLR_BIT(RCC_CFGR , 1);
       /*Busy wait until HSE be Ready*/
        while(GET_BIT(RCC_CR , 17) == 0);
    #elif RCC_CLK_SOURCE == RCC_HSE_RC
        /*Enable HSE with bypass */
        RCC_CR = 0x00050000;
        /*Select HSE as system CLK */
        SET_BIT(RCC_CFGR , 0);
        CLR_BIT(RCC_CFGR , 1);

        /*Busy wait until HSE be Ready*/
        while(GET_BIT(RCC_CR , 17) == 0);
    #elif RCC_CLK_SOURCE == RCC_HSI
        /*Enable HSI with Trimming = 0 */
        RCC_CR = 0x00000001;
        /*Select HSI as system CLK */
        CLR_BIT(RCC_CFGR , 0);
        CLR_BIT(RCC_CFGR , 1);
        /*Busy wait until HSI be Ready*/
        while(GET_BIT(RCC_CR , 1) == 0);
    #elif RCC_CLK_SOURCE == RCC_PLL
        #if PLL_SOURCE == PLL_HSE
        /*Enable PLL with HSE crystal*/
        RCC_CR = 0x01010000;

        RCC_PLLCFGR = 0X00400000;
        #elif PLL_SOURCE == PLL_HSI
        /*Enable PLL with HSI*/
        RCC_CR = 0x01000001;

        RCC_PLLCFGR = 0X00000000;

        #else
            #error
        #endif // PLL_SOURCE\
        SET_BIT(RCC_CFGR , 1);
        CLR_BIT(RCC_CFGR , 0);
        /*Busy wait until PLL be Ready*/
        while(GET_BIT(RCC_CR , 25) == 0);
    #else
        #error
    #endif // RCC_CLK_SOURCE


        RCC_CFGR |=AHP_PRESCALER;

}

void MRCC_voidEnableClock(u8 Copy_u8BusID , u8 Copy_u8PeriphralID)
{
        if(Copy_u8PeriphralID <= 31)
        {
            switch (Copy_u8BusID)
            {
            case RCC_AHP1 :
                SET_BIT(RCC_AHB1ENR , Copy_u8PeriphralID);
                break;
            case RCC_AHP2 :
                SET_BIT(RCC_AHB2ENR , Copy_u8PeriphralID);
                break;
            case RCC_APB1:
                SET_BIT(RCC_APB1ENR , Copy_u8PeriphralID);
                break;
            case RCC_APB2 :
                SET_BIT(RCC_APB2ENR , Copy_u8PeriphralID);
            break;
            default :   /*return error*/  break;
            }
        }
        else
        {
              /*Return error*/
        }
}
void MRCC_voidDisableClock(u8 Copy_u8BusID , u8 Copy_u8PeriphralID)
{
        if(Copy_u8PeriphralID <= 31)
        {
            switch (Copy_u8BusID)
            {
            case RCC_AHP1 :
                CLR_BIT(RCC_AHB1ENR , Copy_u8PeriphralID);
                break;
            case RCC_AHP2 :
                CLR_BIT(RCC_AHB2ENR , Copy_u8PeriphralID);
                break;
            case RCC_APB1:
                CLR_BIT(RCC_APB1ENR , Copy_u8PeriphralID);
                break;
            case RCC_APB2 :
                CLR_BIT(RCC_APB2ENR , Copy_u8PeriphralID);
            break;
            default :   /*return error*/  break;
            }
        }
        else
        {
            /*Return error*/
        }
}

