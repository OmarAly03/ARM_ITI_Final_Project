/*
 * MRCC_Program.c
 *
 *  Created on: Jan 31, 2024
 *      Author: Omar
 */


/************ LIB **************/
#include <LIB/BIT_MATH.h>
#include <LIB/STD_Types.h>

/************ MCAL **************/
#include <MCAL/RCC/MRCC_Interface.h>
#include <MCAL/RCC/MRCC_Private.h>
#include <MCAL/RCC/MRCC_Config.h>

/**********************************Functions Definition ***************************************/
void MRCC_voidInit(void){
#if SYS_CLK == RCC_HSI
	// Enable HSI
	SET_BIT(RCC -> CR, RCC_CR_HSI_ON);

	// Wait till HSI is ready
	while(GET_BIT(RCC -> CR, RCC_CR_HSI_RDY) == RCC_NOT_READY);

	// Masking the switching bits
	RCC -> CFGR &= ~(TWO_BIT_MASK << SW_BIT0);

	// Select HSI as SYS CLK
	RCC -> CFGR |= (SW_HSI << SW_BIT0);


#elif SYS_CLK == RCC_HSE
	// Enable HSE
	SET_BIT(RCC -> CR, RCC_CR_HSE_ON);

	// Wait till HSE is ready
	while(GET_BIT(RCC -> CR, RCC_CR_HSE_RDY) == RCC_NOT_READY);

	// Masking the switching bits
	RCC -> CFGR &= ~(TWO_BIT_MASK << SW_BIT0);

	// Select HSE as SYS CLK
	RCC -> CFGR |= (SW_HSE << SW_BIT0);

#elif SYS_CLK == RCC_PLL
	// Enable PLL
	SET_BIT(RCC -> CR, RCC_CR_PLL_ON);

	// Wait till PLL is ready
	while(GET_BIT(RCC -> CR, RCC_CR_PLL_RDY) == RCC_NOT_READY);

	// Masking the switching bits
	RCC -> CFGR &= ~(TWO_BIT_MASK << SW_BIT0);

	// Select PLL as SYS CLK
	RCC -> CFGR |= (SW_PLL << SW_BIT0);

#else

#error "Wrong SYS_CLK Configuration Parameter"

#endif

}

void MRCC_voidEnablePeripheral(u32 copyu32_BusAddress, u32 copyu32_Peripheral){
	switch(copyu32_BusAddress){
		case RCC_APB1:
			SET_BIT(RCC -> APB1ENR, copyu32_Peripheral);
			break;

		case RCC_APB2:
			SET_BIT(RCC -> APB2ENR, copyu32_Peripheral);
			break;

		case RCC_AHB1:
			SET_BIT(RCC -> AHB1ENR, copyu32_Peripheral);
			break;

		case RCC_AHB2:
			SET_BIT(RCC -> AHB2ENR, copyu32_Peripheral);
			break;

		default:
			break;
	}
}
void MRCC_voidDisablePeripheral(u32 copyu32_BusAddress, u32 copyu32_Peripheral){
	switch(copyu32_BusAddress){
		case RCC_APB1:
			CLR_BIT(RCC -> APB1ENR, copyu32_Peripheral);
			break;

		case RCC_APB2:
			CLR_BIT(RCC -> APB2ENR, copyu32_Peripheral);
			break;

		case RCC_AHB1:
			CLR_BIT(RCC -> AHB1ENR, copyu32_Peripheral);
			break;

		case RCC_AHB2:
			CLR_BIT(RCC -> AHB2ENR, copyu32_Peripheral);
			break;

		default:
			break;
	}
}



void MCRR_voidSetAPB1Prescaler(u8 copyu8APB1Prescaler){
	RCC -> CFGR &= ~(THREE_BIT_MASK << CFGR_PPRE1);

	RCC -> CFGR |= (copyu8APB1Prescaler << CFGR_PPRE1);
}

void MCRR_voidSetAPB2Prescaler(u8 copyu8APB2Prescaler){
	RCC -> CFGR &= ~(THREE_BIT_MASK << CFGR_PPRE1);

	RCC -> CFGR |= (copyu8APB2Prescaler << CFGR_PPRE1);
}

void MCRR_voidSetAHBPrescaler(u8 copyu8AHBPrescaler){
	RCC -> CFGR &= ~(THREE_BIT_MASK << CFGR_PPRE1);

	RCC -> CFGR |= (copyu8AHBPrescaler << CFGR_PPRE1);
}
