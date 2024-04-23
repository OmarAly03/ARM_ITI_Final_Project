/********************************************/
/*     Authors: Omar, Mariam & Anwar		*/
/********************************************/

#ifndef HLED_MATRIX_INTERFACE_H_
#define HLED_MATRIX_INTERFACE_H_

#include <LIB/STD_Types.h>



void HLED_MATRIX_void_Init(void);
void HLED_MATRIX_void_DisableColumns(void);
void HLED_MATRIX_void_SetRowValue(u8 copyu8_RowValue);
void HLED_MATRIX_void_DisplayChar(u8 *ptru8_arr);
void HLED_MATRIX_void_DisplayString(u8 *ptru8_arr, u8 localu8_ArrSize) ;


#endif /* HLED_MATRIX_INTERFACE_H_ */
