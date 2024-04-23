/********************************************/
/*     Authors: Omar, Mariam & Anwar		*/
/********************************************/

/************ LIB **************/
#include <LIB/BIT_MATH.h>
#include <LIB/STD_Types.h>

/************ MCAL **************/
#include <MCAL/STK/MSTK_Config.h>
#include <MCAL/STK/MSTK_Interface.h>
#include <MCAL/STK/MSTK_Private.h>

void MSTK_voidInit(void){
	/* Select Clock Source */
#if MSTK_CLK_SOURCE == MSTK_AHB_BY_8
	CLR_BIT(STK -> CTRL, CLKSOURCE);
#elif MSTK_CLK_SOURCE == MSTK_AHB
	SET_BIT(STK -> CTRL, CLKSOURCE);
#else
#error "Wrong MSTK CLK Source Configuration Parameter"
#endif
}

void MSTK_voidClearCurrentValue(void){
	STK -> VAL = 0;
}

void MSTK_voidSetPreloadValue(u32 copy_u32PreloadValue){
	STK -> LOAD = copy_u32PreloadValue & STK_RES;
}

void MSTK_voidGetFlagValue(u8 *p_Read){
	*p_Read = GET_BIT(STK -> CTRL, COUNTFLAG);
}

void MSTK_voidEnableSTK(void){
	SET_BIT(STK -> CTRL, ENABLE);
}

void MSTK_voidDisableSTK(void){
	CLR_BIT(STK -> CTRL, ENABLE);
}

void MSTK_voidGetElapsedTime(u8 *p_Read){
	*p_Read = (STK -> LOAD) - (STK -> VAL);
}

void MSTK_voidGetRemainingTime(u8 *p_Read){
	*p_Read = STK -> VAL;
}

void MSTK_voidEnableInterrupt(void){
	SET_BIT(STK -> CTRL, TICKINT);
}
void MSTK_voidDisableInterrupt(void){
	CLR_BIT(STK -> CTRL, TICKINT);
}

void MSTK_voidDelayms(u32 copy_u32Delayms){
	/* Calculate the needed preload value */
	u32 local_u32PreloadValue = copy_u32Delayms * (STK_FREQ / 1000);
	STK -> LOAD = local_u32PreloadValue;

	/* Reset the current value register */
	MSTK_voidClearCurrentValue();

	/* Enable SYSTICK */
	MSTK_voidEnableSTK();

	while(GET_BIT(STK -> CTRL, COUNTFLAG) == 0);

	/* Disable SYSTICK */
	MSTK_voidDisableSTK();
}

void MSTK_voidDelayus(u32 copy_u32Delayus){
	/* Calculate the needed preload value */
		u32 local_u32PreloadValue = copy_u32Delayus * (STK_FREQ / 1000000);
		STK -> LOAD = local_u32PreloadValue;

		/* Reset the current value register */
		MSTK_voidClearCurrentValue();

		/* Enable SYSTICK */
		MSTK_voidEnableSTK();

		while(GET_BIT(STK -> CTRL, COUNTFLAG) == 0);

		/* Disable SYSTICK */
		MSTK_voidDisableSTK();
}
