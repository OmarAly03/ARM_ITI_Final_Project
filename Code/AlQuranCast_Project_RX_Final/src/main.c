/********************************************/
/*     Authors: Omar, Mariam & Anwar		*/
/********************************************/

/********************LIB****************************/
#include <LIB/BIT_MATH.h>
#include <LIB/STD_Types.h>

/*******************MCAL****************************/
#include <MCAL/RCC/MRCC_Interface.h>
#include <MCAL/GPIO/MGPIO_Interface.h>
#include <MCAL/NVIC/MNVIC_Interface.h>
#include <MCAL/USART/MUSART_Interface.h>


/*************CallBack functions********************/
void handler_USART(void);

/*****************Variable**************************/
u8 Global_u8RX ;
u8 LED_str1[] = "1 MOHAMED SEDDIK EL MENSHAWY";
u8 LED_str2[] = "2 MAHMOUD KHALIL EL HUSSARY";
u8 LED_str3[] = "3 ABDELBASET ABDELSAMAD";

u8 ArrSize1 = sizeof(LED_str1) / sizeof(u8);
u8 ArrSize2 = sizeof(LED_str2) / sizeof(u8);
u8 ArrSize3 = sizeof(LED_str3) / sizeof(u8);

void main(void)
{
	/****************************************************************/
	/*             		  1- CLOCK GATING							*/
	/****************************************************************/
	/*Initialize RCC module*/
	MRCC_voidInit();

	/*Enable clock to GPIOA*/
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOA);
	MRCC_voidEnablePeripheral(RCC_AHB1,RCC_AHB1_GPIOB);

	/*Enable clock to USART1*/
	MRCC_voidEnablePeripheral(RCC_APB2,RCC_APB2_USART1);

	HLED_MATRIX_void_Init();

	/****************************************************************/
	/*             		  2- PINS SETUP 							*/
	/****************************************************************/
	/*Configure Pins 9 & 10 as alternative function -> USART1*/
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN9,GPIO_ALT_FUNC);
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN10,GPIO_ALT_FUNC);

	/*Setup the pins of the alternative functions*/
	MGPIO_voidSetAltFunction(GPIO_PORTA,GPIO_PIN9,0b0111);
	MGPIO_voidSetAltFunction(GPIO_PORTA,GPIO_PIN10,0b0111);

	/*Configure pin0 as output*/
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUT);

	/*Setup pin0 with the suitable setting*/
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN0,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);

	/*Configure pin1 as output*/
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_OUTPUT);

	/*Setup pin1 with the suitable setting*/
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN1,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);

	/*Configure pin0 as output*/
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUT);

	/*Setup pin0 with the suitable setting*/
	MGPIO_voidSetPinOutputMode(GPIO_PORTA,GPIO_PIN2,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);


	/****************************************************************/
	/*         	   3- ENABLE USART INTERRUPT						*/
	/****************************************************************/
	/*Enable Peripheral number of USART1*/
	MNVIC_voidEnablePeripheralInterrupt(37);

	/*callBack function when the interrupt fires goes to*/
	MSUART_voidSetCallBack(handler_USART);

	/****************************************************************/
	/*             	 4- USART INITIALIZATION						*/
	/****************************************************************/
	MUSART_voidInit();
	MUSART_EnableUSART(MUSART_USART1);


	while(1);
}


void handler_USART(void)
{
	MUSART_voidReceive(MUSART_USART1 ,&Global_u8RX);
	if(Global_u8RX == 'a'){
		HLED_MATRIX_void_Reset();
		HLED_MATRIX_void_Init();
		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_PIN_HIGH);
		HLED_MATRIX_void_DisplayString(LED_str1, ArrSize1);
	}
	if(Global_u8RX == 'b'){
		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_PIN_LOW);
	}
	if(Global_u8RX == 'c'){
		HLED_MATRIX_void_Reset();
		HLED_MATRIX_void_Init();
		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_PIN_LOW);
        HLED_MATRIX_void_DisplayString(LED_str2, ArrSize2);
	}
	if(Global_u8RX == 'd'){
		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_PIN_LOW);
	}
	if(Global_u8RX == 'e'){
		HLED_MATRIX_void_Reset();
		HLED_MATRIX_void_Init();
		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_PIN_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_PIN_LOW);
		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_PIN_LOW);
		HLED_MATRIX_void_DisplayString(LED_str3, ArrSize3);
	}
	if(Global_u8RX == 'f'){
		MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_PIN_LOW);
	}

}





