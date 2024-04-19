/*
 * EXTI_Program.c
 *
 *  Created on: Sep 12, 2023
 *      Author: Ibrahim Refaey
 */

/************ LIB ****************/
#include <LIB/BIT_MATH.h>
#include <LIB/STD_Types.h>

/************ MCAL ****************/
#include <MCAL/EXTI/MEXTI_Config.h>
#include <MCAL/EXTI/MEXTI_Interface.h>
#include <MCAL/EXTI/MEXTI_Private.h>

extern MEXTI_Configurations MEXTI_Config[MEXTI_NUMBER];

static PtrToFunc_void MEXTI_CallBack[MEXTI_TOTAL_NUMBER];

void MEXTI_voidInit(void){
	u8 local_u8Iterator = 0;
	for(local_u8Iterator = 0 ; local_u8Iterator < MEXTI_NUMBER ; local_u8Iterator++){
		MEXTI_voidSelectPort(MEXTI_Config[local_u8Iterator].Line , MEXTI_Config[local_u8Iterator].Port);
		MEXTI_voidSetMode(MEXTI_Config[local_u8Iterator].Line ,MEXTI_Config[local_u8Iterator].Mode);
		switch (MEXTI_Config[local_u8Iterator].State) {
			case MEXTI_ENABLED:
				MEXTI_voidEnableEXTILine(MEXTI_Config[local_u8Iterator].Line);
				break;
			case MEXTI_DISABLED:
				MEXTI_voidDisableEXTILine(MEXTI_Config[local_u8Iterator].Line);
				break;
			default:
				break;
		}
	}
}
void MEXTI_voidEnableEXTILine (MEXTI_Line A_MEXTI_Line)
{

	SET_BIT(EXTI->IMR , A_MEXTI_Line);
}

void MEXTI_voidDisableEXTILine (MEXTI_Line A_MEXTI_Line)
{

	CLR_BIT(EXTI->IMR , A_MEXTI_Line);
}

void MEXTI_voidSetCallBack (MEXTI_Line A_MEXTI_Line , PtrToFunc_void A_CallBackFunc)
{

	MEXTI_CallBack[A_MEXTI_Line] = A_CallBackFunc;
}

void MEXTI_voidSoftwareInterrputRequest (MEXTI_Line A_MEXTI_Line)
{

	SET_BIT(EXTI->SWIER , A_MEXTI_Line);
}

void MEXTI_voidClearPendingFlag (MEXTI_Line A_MEXTI_Line)
{

	SET_BIT(EXTI->PR , A_MEXTI_Line);
}

void MEXTI_voidSelectPort (MEXTI_Line A_MEXTI_Line , MEXTI_Port A_MEXTI_Port)
{

	SYSCFG->EXTICR[(A_MEXTI_Line/4)] &= ~(FOUR_BIT_MASK << ((A_MEXTI_Line%4)*4));
	SYSCFG->EXTICR[(A_MEXTI_Line/4)] |=  (A_MEXTI_Port << ((A_MEXTI_Line%4)*4));
}

void MEXTI_voidSetMode (MEXTI_Line A_MEXTI_Line , MEXTI_Mode A_MEXTI_Mode)
{

	if (A_MEXTI_Mode == MEXTI_FALLING_EDGE)
	{
		SET_BIT(EXTI->FTSR , A_MEXTI_Line);
	}
	else if (A_MEXTI_Mode == MEXTI_RISING_EDGE)
	{
		SET_BIT(EXTI->RTSR , A_MEXTI_Line);
	}
	else
	{
		SET_BIT(EXTI->FTSR , A_MEXTI_Line);
		SET_BIT(EXTI->RTSR , A_MEXTI_Line);
	}
}
