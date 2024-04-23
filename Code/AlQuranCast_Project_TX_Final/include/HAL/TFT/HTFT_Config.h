/********************************************/
/*     Authors: Omar, Mariam & Anwar		*/
/********************************************/

#ifndef HTFT_CONFIGURATIONS_H_
#define HTFT_CONFIGURATIONS_H_

#define TFT_RESET_PORT					GPIO_PORTB
#define TFT_RESET_PIN					GPIO_PIN9

#define TFT_CS_PORT						GPIO_PORTB
#define TFT_CS_PIN						GPIO_PIN8


#define TFT_CONTROL_PORT				GPIO_PORTB
#define TFT_CONTROL_PIN					GPIO_PIN10

/*
 * TFT_COLOR_MODE :-
 	 * TFT_RGB444
 	 * TFT_RGB565
 	 * TFT_RGB666
 */
#define TFT_COLOR_MODE					TFT_RGB565


#define TFT_PIXELS_X					128

#define TFT_PIXELS_Y					160


#endif /* HTFT_CONFIGURATIONS_H_ */
