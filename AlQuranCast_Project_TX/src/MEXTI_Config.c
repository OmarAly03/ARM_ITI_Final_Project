#include <LIB/BIT_MATH.h>
#include <LIB/STD_Types.h>

/************ LIB ****************/
#include <LIB/BIT_MATH.h>
#include <LIB/STD_Types.h>

/************ MCAL ****************/
#include <MCAL/EXTI/MEXTI_Config.h>
#include <MCAL/EXTI/MEXTI_Interface.h>
#include <MCAL/EXTI/MEXTI_Private.h>

/*
 * MEXTI_Configuartions {
	 * Line
	 * Port
	 * Mode
	 * Initial Value
 * }
 */


MEXTI_Configurations MEXTI_Config [MEXTI_NUMBER] =
{
		{
				MEXTI_LINE0,
				MEXTI_PORTB,
				MEXTI_FALLING_EDGE,
				MEXTI_ENABLED
		}
		,
		{
				MEXTI_LINE1,
				MEXTI_PORTB,
				MEXTI_FALLING_EDGE,
				MEXTI_ENABLED
		},
		{
				MEXTI_LINE2,
				MEXTI_PORTB,
				MEXTI_FALLING_EDGE,
				MEXTI_ENABLED
		}

};


