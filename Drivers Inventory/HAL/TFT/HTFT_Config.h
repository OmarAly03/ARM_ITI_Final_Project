/*
 * HTFT_Configurations.h
 *
 *  Created on: Sep 24, 2023
 *      Author: Ibrahim Refaey
 */

#ifndef HTFT_CONFIGURATIONS_H_
#define HTFT_CONFIGURATIONS_H_

#define TFT_RESET_PORT					GPIO_PORTA
#define TFT_RESET_PIN					GPIO_PIN1

#define TFT_CS_PORT						GPIO_PORTA
#define TFT_CS_PIN						GPIO_PIN0


#define TFT_CONTROL_PORT				GPIO_PORTA
#define TFT_CONTROL_PIN					GPIO_PIN2

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
