/********************************************/
/*     Authors: Omar, Mariam & Anwar		*/
/********************************************/

/******************* LIB **********************/
#include <LIB/BIT_MATH.h>
#include <LIB/STD_Types.h>

/****************** MCAL **********************/
#include <MCAL/EXTI/MEXTI_Interface.h>
#include <MCAL/GPIO/MGPIO_Interface.h>
#include <MCAL/NVIC/MNVIC_Interface.h>
#include <MCAL/RCC/MRCC_Interface.h>
#include <MCAL/SPI/MSPI_Interface.h>
#include <MCAL/STK/MSTK_Interface.h>
#include <MCAL/USART/MUSART_Interface.h>

/******************* HAL **********************/
#include <HAL/LCD/HLCD_Interface.h>
#include <HAL/TFT/HTFT_Interface.h>
<<<<<<< HEAD:Code/AlQuranCast_Project_TX_Final/src/main.c
#include <HAL/TFT/TFT_arrays.h>
=======
#include "HAL/TFT/TFT_arrays.h"
>>>>>>> 207dc3583d5fab31f1f2dae0123f204331335697:AlQuranCast_Project_TX/src/main.c


void handler_USART(void);

u8 u8_channelNumber = 0;
u8 u8_Button1State;
u8 u8_Button2State;
u8 u8_Button3State;
u8 u8_Button4State;

u8 Global_u8RX ;

int main(void){
	MRCC_voidInit();
	MSTK_voidInit();
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOB);
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOC);
	MRCC_voidEnablePeripheral(RCC_APB2 , RCC_APB2_SYSCFG);
	MRCC_voidEnablePeripheral(RCC_APB2,RCC_APB2_USART1);
	MRCC_voidEnablePeripheral(RCC_APB1,RCC_APB1_SPI2);

	// Channel Buttons Configuration
	MGPIO_voidSetPinMode(GPIO_PORTB , GPIO_PIN0 , GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTB , GPIO_PIN0 , GPIO_PULLUP);
	MGPIO_voidSetPinMode(GPIO_PORTB , GPIO_PIN1 , GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTB , GPIO_PIN1 , GPIO_PULLUP);
	MGPIO_voidSetPinMode(GPIO_PORTB , GPIO_PIN2 , GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTB , GPIO_PIN2 , GPIO_PULLUP);
<<<<<<< HEAD:Code/AlQuranCast_Project_TX_Final/src/main.c
	MGPIO_voidSetPinMode(GPIO_PORTB , GPIO_PIN3 , GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTB , GPIO_PIN3 , GPIO_PULLUP);
=======
>>>>>>> 207dc3583d5fab31f1f2dae0123f204331335697:AlQuranCast_Project_TX/src/main.c
	// UART Configuration
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN9,GPIO_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN10,GPIO_ALT_FUNC);


	/*Setup the pins of the alternative functions*/
	MGPIO_voidSetAltFunction(GPIO_PORTA,GPIO_PIN9,0b0111);
	MGPIO_voidSetAltFunction(GPIO_PORTA,GPIO_PIN10,0b0111);

	MNVIC_voidEnablePeripheralInterrupt(6); 	// EXTI0
	MNVIC_voidEnablePeripheralInterrupt(7);		// EXTI1
	MNVIC_voidEnablePeripheralInterrupt(8);		// EXTI2
	MNVIC_voidEnablePeripheralInterrupt(37);	// USART1

	MSUART_voidSetCallBack(handler_USART);
	MUSART_voidInit();
	MUSART_EnableUSART(MUSART_USART1);

	LCD_voidInit();

	LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN2);
	LCD_voidSendString(	(const u8*)"Welcome To");
	LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN2);
	LCD_voidSendString((const u8*)"AlQuranCast");
	MSTK_voidDelayms(500);

	LCD_voidClearScreen();
	LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN0);
	LCD_voidSendString((const u8*)"Choose a Channel:");
	LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN2);
	LCD_voidSendString((const u8*)"(1) (2) (3)");

	HTFT_voidInit();


	while(1)
	{
		MGPIO_voidGetPinValue(GPIO_PORTB, GPIO_PIN0, &u8_Button1State);
		if(u8_Button1State == 0){
			MUSART_voidTransmit(MUSART_USART1,(u8*)"a",1);
			MUSART_voidTransmit(MUSART_USART1,(u8*)"d",1);
			MUSART_voidTransmit(MUSART_USART1,(u8*)"f",1);
			LCD_voidClearScreen();
			LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN0);
			LCD_voidSendString((const u8*)"1.Mohamed Seddik");
			LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN2);
			LCD_voidSendString((const u8*)"El-Menshawy");
<<<<<<< HEAD:Code/AlQuranCast_Project_TX_Final/src/main.c

			HTFT_voidSendPicture(TFT_ElMenshawy);
=======
			//MSTK_voidDelayms(2000);
			HTFT_voidSendPicture(TFT_ElMenshawy);

			MSTK_voidDelayms(2000);
			MUSART_voidTransmit(MUSART_USART1,(u8*)'0',1);
			u8_channelNumber = 0;

			HTFT_voidReset();
			LCD_voidClearScreen();
			LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN0);
			LCD_voidSendString((const u8*)"Choose a Channel:");
			LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN2);
			LCD_voidSendString((const u8*)"(1) (2) (3)");
			break;
>>>>>>> 207dc3583d5fab31f1f2dae0123f204331335697:AlQuranCast_Project_TX/src/main.c
		}


		MGPIO_voidGetPinValue(GPIO_PORTB, GPIO_PIN1, &u8_Button2State);
		if(u8_Button2State == 0){
			MUSART_voidTransmit(MUSART_USART1,(u8*)"c",1);
			MUSART_voidTransmit(MUSART_USART1,(u8*)"b",1);
			MUSART_voidTransmit(MUSART_USART1,(u8*)"f",1);
			LCD_voidClearScreen();
			LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN0);
			LCD_voidSendString((const u8*)"2.Mahmoud Khalil");
			LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN2);
			LCD_voidSendString((const u8*)"El-Hussary");
<<<<<<< HEAD:Code/AlQuranCast_Project_TX_Final/src/main.c

			HTFT_voidSendPicture(TFT_ElHussary);
=======

			HTFT_voidSendPicture(TFT_ElHussary);

			MSTK_voidDelayms(2000);
			MUSART_voidTransmit(MUSART_USART1,(u8*)'0',1);
			u8_channelNumber = 0;

			HTFT_voidReset();
			LCD_voidClearScreen();
			LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN0);
			LCD_voidSendString((const u8*)"Choose a Channel:");
			LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN2);
			LCD_voidSendString((const u8*)"(1) (2) (3)");
			break;
>>>>>>> 207dc3583d5fab31f1f2dae0123f204331335697:AlQuranCast_Project_TX/src/main.c
		}

		MGPIO_voidGetPinValue(GPIO_PORTB, GPIO_PIN2, &u8_Button3State);
		if(u8_Button3State == 0){
			MUSART_voidTransmit(MUSART_USART1,(u8*)"e",1);
			MUSART_voidTransmit(MUSART_USART1,(u8*)"b",1);
			MUSART_voidTransmit(MUSART_USART1,(u8*)"d",1);
			LCD_voidClearScreen();
			LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN1);
			LCD_voidSendString((const u8*)"3.AbdelBaset");
			LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN2);
			LCD_voidSendString((const u8*)"AbdelSamad");
<<<<<<< HEAD:Code/AlQuranCast_Project_TX_Final/src/main.c

			HTFT_voidSendPicture(TFT_AbdElBasset);
		}

		MGPIO_voidGetPinValue(GPIO_PORTB, GPIO_PIN3, &u8_Button4State);
		if(u8_Button4State == 0){
			MUSART_voidTransmit(MUSART_USART1,(u8*)"b",1);
			MUSART_voidTransmit(MUSART_USART1,(u8*)"d",1);
			MUSART_voidTransmit(MUSART_USART1,(u8*)"f",1);
=======

			HTFT_voidSendPicture(TFT_AbdElBasset);

			MSTK_voidDelayms(2000);
			MUSART_voidTransmit(MUSART_USART1,(u8*)'0',1);
			u8_channelNumber = 0;

			HTFT_voidReset();
>>>>>>> 207dc3583d5fab31f1f2dae0123f204331335697:AlQuranCast_Project_TX/src/main.c
			LCD_voidClearScreen();
			LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN0);
			LCD_voidSendString((const u8*)"Choose a Channel:");
			LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN2);
			LCD_voidSendString((const u8*)"(1) (2) (3)");

		}
	}
	return 0;
}


void handler_USART(void){

}

