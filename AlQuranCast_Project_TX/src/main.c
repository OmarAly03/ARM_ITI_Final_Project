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
#include <HAL/LEDMATRIX/HLEDMATRIX_Interface.h>
#include <HAL/TFT/HTFT_Interface.h>

void Handler0(void);
void Handler1(void);
void Handler2(void);

void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void handler_USART(void);

u8 u8_channelNumber = 0;
u8 Global_u8RX ;

int main(void){
	MRCC_voidInit();
	MSTK_voidInit();
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOB);
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOC);
	MRCC_voidEnablePeripheral(RCC_APB2 , RCC_APB2_SYSCFG);
	MRCC_voidEnablePeripheral(RCC_APB2,RCC_APB2_USART1);

	// Channel Buttons Configuration
	MGPIO_voidSetPinMode(GPIO_PORTB , GPIO_PIN0 , GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTB , GPIO_PIN0 , GPIO_PULLUP);
	MGPIO_voidSetPinMode(GPIO_PORTB , GPIO_PIN1 , GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTB , GPIO_PIN1 , GPIO_PULLUP);
	MGPIO_voidSetPinMode(GPIO_PORTB , GPIO_PIN2 , GPIO_INPUT);
	MGPIO_voidSetPinInputMode(GPIO_PORTB , GPIO_PIN2 , GPIO_PULLUP);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN9,GPIO_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN10,GPIO_ALT_FUNC);

	/*Setup the pins of the alternative functions*/
	MGPIO_voidSetAltFunction(GPIO_PORTA,GPIO_PIN9,0b0111);
	MGPIO_voidSetAltFunction(GPIO_PORTA,GPIO_PIN10,0b0111);

	// External Interrupt Initiation & Enable
	MEXTI_voidInit();
	MEXTI_voidSetCallBack(MEXTI_LINE0 , Handler0);
	MEXTI_voidSetCallBack(MEXTI_LINE1 , Handler1);
	MEXTI_voidSetCallBack(MEXTI_LINE2 , Handler2);

	MNVIC_voidEnablePeripheralInterrupt(6); 	// EXTI0
	MNVIC_voidEnablePeripheralInterrupt(7);		// EXTI1
	MNVIC_voidEnablePeripheralInterrupt(8);		// EXTI2
	MNVIC_voidEnablePeripheralInterrupt(37);	// USART1

	MSUART_voidSetCallBack(handler_USART);
	MUSART_voidInit();
	MUSART_EnableUSART(MUSART_USART1);

	MEXTI_voidEnableEXTILine(MEXTI_LINE0); // <------------------
	MEXTI_voidEnableEXTILine(MEXTI_LINE1); // <------------------
	MEXTI_voidEnableEXTILine(MEXTI_LINE2); // <------------------



	LCD_voidInit();

	LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN2);
	LCD_voidSendString((const u8*)"Welcome To");
	LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN2);
	LCD_voidSendString((const u8*)"AlQuranCast");
	MSTK_voidDelayms(500);

	LCD_voidClearScreen();
	LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN0);
	LCD_voidSendString((const u8*)"Choose a Channel:");
	LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN2);
	LCD_voidSendString((const u8*)"(1) (2) (3)");

	while(1)
	{
		switch(u8_channelNumber){
		case 0:{
			break;
		}

		case 1:{
			MUSART_voidTransmit(MUSART_USART1,(u8*)'1',1);
			LCD_voidClearScreen();
			LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN0);
			LCD_voidSendString((const u8*)"1.Mohamed Seddik");
			LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN2);
			LCD_voidSendString((const u8*)"El-Menshawy");
			MSTK_voidDelayms(2000);
			MUSART_voidTransmit(MUSART_USART1,(u8*)'0',1);
			u8_channelNumber = 0;

			LCD_voidClearScreen();
			LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN0);
			LCD_voidSendString((const u8*)"Choose a Channel:");
			LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN2);
			LCD_voidSendString((const u8*)"(1) (2) (3)");
			break;
		}

		case 2:{
			MUSART_voidTransmit(MUSART_USART1,(u8*)'2',1);
			LCD_voidClearScreen();
			LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN0);
			LCD_voidSendString((const u8*)"2.Mahmoud Khalil");
			LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN2);
			LCD_voidSendString((const u8*)"El-Hussary");
			MSTK_voidDelayms(2000);
			MUSART_voidTransmit(MUSART_USART1,(u8*)'0',1);
			u8_channelNumber = 0;

			LCD_voidClearScreen();
			LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN0);
			LCD_voidSendString((const u8*)"Choose a Channel:");
			LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN2);
			LCD_voidSendString((const u8*)"(1) (2) (3)");
			break;
		}

		case 3:{
			MUSART_voidTransmit(MUSART_USART1,(u8*)'3',1);
			LCD_voidClearScreen();
			LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN1);
			LCD_voidSendString((const u8*)"3.AbdelBaset");
			LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN2);
			LCD_voidSendString((const u8*)"AbdelSamad");
			MSTK_voidDelayms(2000);
			MUSART_voidTransmit(MUSART_USART1,(u8*)'0',1);
			u8_channelNumber = 0;

			LCD_voidClearScreen();
			LCD_voidSetPosition(LCD_ROW0,LCD_COLUMN0);
			LCD_voidSendString((const u8*)"Choose a Channel:");
			LCD_voidSetPosition(LCD_ROW1,LCD_COLUMN2);
			LCD_voidSendString((const u8*)"(1) (2) (3)");
			break;
		}

		default:{
			/* Do Nothing */
		}
		}
	}
	return 0;
}

void Handler0(void){
	u8_channelNumber = 1;
}
void Handler1(void){
	u8_channelNumber = 2;
}
void Handler2(void){
	u8_channelNumber = 3;
}

void EXTI0_IRQHandler(void){
	Handler0();
}
void EXTI1_IRQHandler(void){
	Handler1();
}
void EXTI2_IRQHandler(void){
	Handler2();
}

void handler_USART(void){
	MUSART_voidReceive(MUSART_USART1 ,&Global_u8RX);
}
