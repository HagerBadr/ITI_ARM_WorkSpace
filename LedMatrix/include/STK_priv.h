#ifndef _STK_PRIV_H_
#define _STK_PRIV_H_


typedef	struct
{
	volatile	u32		CTRL;
	volatile	u32		LOAD;
	volatile	u32		VAL;
	volatile	u32		CALIB;
}STK_Type;

#define		STK_AHB_DIV_8			0
#define		STK_AHB					1

#define		STK_SINGLE_INTERVAL		2
#define		STK_PERIOD_INTERVAL		4

#define		STK	((STK_Type *)0xE000E010)

#endif
