/********************************************/
/*     Authors: Omar, Mariam & Anwar		*/
/********************************************/

/****************** LIB **********************/
#include <LIB/BIT_MATH.h>
#include <LIB/STD_Types.h>

/****************** MCAL **********************/
#include <MCAL/GPIO/MGPIO_Interface.h>
#include <MCAL/STK/MSTK_Interface.h>

/****************** HAL **********************/
#include <HAL/LEDMATRIX/HLEDMATRIX_Config.h>
#include <HAL/LEDMATRIX/HLEDMATRIX_Private.h>
#include <HAL/LEDMATRIX/HLEDMATRIX_Interface.h>

void HLED_MATRIX_void_Init(void) {
	// Set Row port mode
	MGPIO_voidSetPinMode(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW0_PIN, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW0_PIN, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW1_PIN, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW1_PIN, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW2_PIN, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW2_PIN, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW3_PIN, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW3_PIN, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW4_PIN, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW4_PIN, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW5_PIN, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW5_PIN, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW6_PIN, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW6_PIN, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW7_PIN, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW7_PIN, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);


	// Set columns port mode
	MGPIO_voidSetPinMode(LED_MATRIX_COL_PORT, LED_MATRIX_COL0_PIN, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LED_MATRIX_COL_PORT, LED_MATRIX_COL0_PIN, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(LED_MATRIX_COL_PORT, LED_MATRIX_COL1_PIN, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LED_MATRIX_COL_PORT, LED_MATRIX_COL1_PIN, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(LED_MATRIX_COL_PORT, LED_MATRIX_COL2_PIN, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LED_MATRIX_COL_PORT, LED_MATRIX_COL2_PIN, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(LED_MATRIX_COL_PORT, LED_MATRIX_COL3_PIN, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LED_MATRIX_COL_PORT, LED_MATRIX_COL3_PIN, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(LED_MATRIX_COL_PORT, LED_MATRIX_COL4_PIN, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LED_MATRIX_COL_PORT, LED_MATRIX_COL4_PIN, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(LED_MATRIX_COL_PORT, LED_MATRIX_COL5_PIN, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LED_MATRIX_COL_PORT, LED_MATRIX_COL5_PIN, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(LED_MATRIX_COL_PORT, LED_MATRIX_COL6_PIN, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LED_MATRIX_COL_PORT, LED_MATRIX_COL6_PIN, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(LED_MATRIX_COL_PORT, LED_MATRIX_COL7_PIN, GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LED_MATRIX_COL_PORT, LED_MATRIX_COL7_PIN, GPIO_PUSH_PULL, GPIO_MEDIUM_SPEED);
}

void HLED_MATRIX_void_Reset(void) {
    // Turn off all column pins
	MGPIO_voidSetPinValue(LED_MATRIX_COL_PORT, GPIO_PIN0, GPIO_RESET);
    MGPIO_voidSetPinValue(LED_MATRIX_COL_PORT, GPIO_PIN1, GPIO_RESET);
    MGPIO_voidSetPinValue(LED_MATRIX_COL_PORT, GPIO_PIN2, GPIO_RESET);
    MGPIO_voidSetPinValue(LED_MATRIX_COL_PORT, GPIO_PIN5, GPIO_RESET);
    MGPIO_voidSetPinValue(LED_MATRIX_COL_PORT, GPIO_PIN6, GPIO_RESET);
    MGPIO_voidSetPinValue(LED_MATRIX_COL_PORT, GPIO_PIN7, GPIO_RESET);
    MGPIO_voidSetPinValue(LED_MATRIX_COL_PORT, GPIO_PIN8, GPIO_RESET);
    MGPIO_voidSetPinValue(LED_MATRIX_COL_PORT, GPIO_PIN9, GPIO_RESET);

    // Turn off all row pins
    MGPIO_voidSetPinValue(LED_MATRIX_ROWS_PORT, GPIO_PIN0, GPIO_RESET);
    MGPIO_voidSetPinValue(LED_MATRIX_ROWS_PORT, GPIO_PIN1, GPIO_RESET);
    MGPIO_voidSetPinValue(LED_MATRIX_ROWS_PORT, GPIO_PIN2, GPIO_RESET);
    MGPIO_voidSetPinValue(LED_MATRIX_ROWS_PORT, GPIO_PIN3, GPIO_RESET);
    MGPIO_voidSetPinValue(LED_MATRIX_ROWS_PORT, GPIO_PIN4, GPIO_RESET);
    MGPIO_voidSetPinValue(LED_MATRIX_ROWS_PORT, GPIO_PIN5, GPIO_RESET);
    MGPIO_voidSetPinValue(LED_MATRIX_ROWS_PORT, GPIO_PIN6, GPIO_RESET);
    MGPIO_voidSetPinValue(LED_MATRIX_ROWS_PORT, GPIO_PIN7, GPIO_RESET);
}

void HLED_MATRIX_void_DisableColumns(void) {
	MGPIO_voidSetPinValue(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW0_PIN, GPIO_RESET);
	MGPIO_voidSetPinValue(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW1_PIN, GPIO_RESET);
	MGPIO_voidSetPinValue(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW2_PIN, GPIO_RESET);
	MGPIO_voidSetPinValue(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW3_PIN, GPIO_RESET);
	MGPIO_voidSetPinValue(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW4_PIN, GPIO_RESET);
	MGPIO_voidSetPinValue(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW5_PIN, GPIO_RESET);
	MGPIO_voidSetPinValue(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW6_PIN, GPIO_RESET);
	MGPIO_voidSetPinValue(LED_MATRIX_ROWS_PORT, LED_MATRIX_ROW7_PIN, GPIO_RESET);
}

void HLED_MATRIX_void_SetRowValue(u8 copyu8_RowValue) {
	MGPIO_voidSetPinValue(LED_MATRIX_COL_PORT, LED_MATRIX_COL0_PIN, !GET_BIT(copyu8_RowValue, 0));
	MGPIO_voidSetPinValue(LED_MATRIX_COL_PORT, LED_MATRIX_COL1_PIN, !GET_BIT(copyu8_RowValue, 1));
	MGPIO_voidSetPinValue(LED_MATRIX_COL_PORT, LED_MATRIX_COL2_PIN, !GET_BIT(copyu8_RowValue, 2));
	MGPIO_voidSetPinValue(LED_MATRIX_COL_PORT, LED_MATRIX_COL3_PIN, !GET_BIT(copyu8_RowValue, 3));
	MGPIO_voidSetPinValue(LED_MATRIX_COL_PORT, LED_MATRIX_COL4_PIN, !GET_BIT(copyu8_RowValue, 4));
	MGPIO_voidSetPinValue(LED_MATRIX_COL_PORT, LED_MATRIX_COL5_PIN, !GET_BIT(copyu8_RowValue, 5));
	MGPIO_voidSetPinValue(LED_MATRIX_COL_PORT, LED_MATRIX_COL6_PIN, !GET_BIT(copyu8_RowValue, 6));
	MGPIO_voidSetPinValue(LED_MATRIX_COL_PORT, LED_MATRIX_COL7_PIN, !GET_BIT(copyu8_RowValue, 7));

}

void HLED_MATRIX_void_DisplayChar(u8 *ptru8_arr) {
	u8 localu8_Iterator = 0;
	for(localu8_Iterator = 0; localu8_Iterator < NUM_OF_COLS; localu8_Iterator++){
		HLED_MATRIX_void_DisableColumns();
		HLED_MATRIX_void_SetRowValue(ptru8_arr[localu8_Iterator]);
		MGPIO_voidSetPinValue(LED_MATRIX_ROWS_PORT, localu8_Iterator, GPIO_PIN_HIGH);
		MSTK_voidDelayus(500);
	}

}

void HLED_MATRIX_void_DisplayString(u8 *ptru8_str, u8 localu8_ArrSize) {

    u8 localu8_Counter = 0;
    Chars_t local_Character;
    u8 localu8_CharArr[(localu8_ArrSize + 1) * NUM_OF_COLS];
    u8 localu8_Frame[NUM_OF_COLS];

    // Get the corresponding char values for the whole string
    // Then, copy the values array in one 1D array
    for(localu8_Counter = 0; localu8_Counter < localu8_ArrSize; localu8_Counter++){
        local_Character = *(ptru8_str + localu8_Counter);

        u8 localu8_i = 0;
        if((local_Character >= 'A' && local_Character <= 'Z') || (local_Character >= '0' && local_Character <= '9')){
            // For letters and numbers, handle them in a similar way
            for(localu8_i = 0; localu8_i < NUM_OF_COLS; localu8_i++){
                if(local_Character >= 'A' && local_Character <= 'Z'){
                    localu8_CharArr[localu8_Counter * NUM_OF_COLS + localu8_i] = Char_Pixels[local_Character - 'A' + 1][localu8_i];
                }
                else {
                    // Handle numbers by shifting the ASCII value
                    localu8_CharArr[localu8_Counter * NUM_OF_COLS + localu8_i] = Char_Pixels[local_Character - '0' + 27][localu8_i];
                }
            }
        }
        else if(local_Character == SPACE){
            for(localu8_i = 0; localu8_i < NUM_OF_COLS; localu8_i++){
                localu8_CharArr[localu8_Counter * NUM_OF_COLS + localu8_i] = 0;
            }
        }
    }

    // Add space at the end of the string
    for(localu8_Counter = 0; localu8_Counter < NUM_OF_COLS; localu8_Counter++){
        localu8_CharArr[localu8_ArrSize * NUM_OF_COLS + localu8_Counter] = 0;
    }

    // Create frames by shifting elements
    for(localu8_Counter = 0; localu8_Counter <= localu8_ArrSize * NUM_OF_COLS; localu8_Counter++) {
        localu8_Frame[0] = localu8_CharArr[localu8_Counter + 0];
        localu8_Frame[1] = localu8_CharArr[localu8_Counter + 1];
        localu8_Frame[2] = localu8_CharArr[localu8_Counter + 2];
        localu8_Frame[3] = localu8_CharArr[localu8_Counter + 3];
        localu8_Frame[4] = localu8_CharArr[localu8_Counter + 4];
        localu8_Frame[5] = localu8_CharArr[localu8_Counter + 5];
        localu8_Frame[6] = localu8_CharArr[localu8_Counter + 6];
        localu8_Frame[7] = localu8_CharArr[localu8_Counter + 7];

        // Display with delay
        u16 localu8_DelayIterator = 0;
        for(localu8_DelayIterator = 0; localu8_DelayIterator < 15; localu8_DelayIterator++) {
            HLED_MATRIX_void_DisplayChar(localu8_Frame);
        }

    }
}
