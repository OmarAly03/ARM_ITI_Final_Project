/*
 * HLEDMATRIX_Interface.h
 *
 *  Created on: Feb 18, 2024
 *      Author: Omar
 */

#ifndef HLEDMATRIX_INTERFACE_H_
#define HLEDMATRIX_INTERFACE_H_

#include <LIB/STD_Types.h>

/*********************** Functions Prototypes ******************************/
void HLEDMATRIX_voidInit(void);
void HLEDMATRIX_voidDisableColumns(void);
void HLEDMATRIX_voidSetRowValue(u8 copy_u8RowValue);
void HLEDMATRIX_voidDisplay(u8 *copy_u8Array);




#endif /* HLEDMATRIX_INTERFACE_H_ */
