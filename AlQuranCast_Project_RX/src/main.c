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

void handler_USART(void);
u8 Global_u8RX ;
u8 LED_str1[] = "1 MOHAMED SEDDIK EL MENSHAWY";
u8 LED_str2[] = "2 MAHMOUD KHALIL EL HUSSARY";
u8 LED_str3[] = "3 ABDELBASET ABDELSAMAD";

u8 ArrSize1 = sizeof(LED_str1) / sizeof(u8);
u8 ArrSize2 = sizeof(LED_str2) / sizeof(u8);
u8 ArrSize3 = sizeof(LED_str3) / sizeof(u8);


int main(void){
	MRCC_voidInit();
	MSTK_voidInit();

	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_voidEnablePeripheral(RCC_APB2,RCC_APB2_USART1);
    
	HLED_MATRIX_void_Init();

	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN1, GPIO_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN2, GPIO_OUTPUT);

	MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN0, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN1, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);
	MGPIO_voidSetPinOutputMode(GPIO_PORTA, GPIO_PIN2, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN9,GPIO_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN10,GPIO_ALT_FUNC);

	/*Setup the pins of the alternative functions*/
	MGPIO_voidSetAltFunction(GPIO_PORTA,GPIO_PIN9,0b0111);
	MGPIO_voidSetAltFunction(GPIO_PORTA,GPIO_PIN10,0b0111);

	MNVIC_voidEnablePeripheralInterrupt(37);	// USART1

	MSUART_voidSetCallBack(handler_USART);
	MUSART_voidInit();
	MUSART_EnableUSART(MUSART_USART1);

}


void handler_USART(void){
	MUSART_voidReceive(MUSART_USART1 ,&Global_u8RX);
	if(Global_u8RX == '1'){
		MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_HIGH);
		HLED_MATRIX_void_DisplayString(LED_str1, ArrSize1);

	}
	else if(Global_u8RX == '2'){
		MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_PIN_HIGH);
        HLED_MATRIX_void_DisplayString(LED_str2, ArrSize2);

	}
	else if(Global_u8RX == '3'){
		MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_PIN_HIGH);
		HLED_MATRIX_void_DisplayString(LED_str3, ArrSize3);
	}
	else{
		MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN1, GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTA, GPIO_PIN2, GPIO_PIN_LOW);
	}
}
