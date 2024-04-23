/*
 * MSPI_Configurations.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Ibrahim Refaey
 */

#ifndef MSPI_CONFIG_H_
#define MSPI_CONFIG_H_

/******************SPI1 Configuration**************/

/*
 * MSPI1_STATE :-
 	 * MSPI_ENABLED
 	 * MSPI_DISABLED
 */
#define MSPI2_STATE				MSPI_ENABLED

/*
 * MSPI1_CLK_MODE :-
 	 * MSPI_CLK_MODE_0
 	 * MSPI_CLK_MODE_1
 	 * MSPI_CLK_MODE_2
 	 * MSPI_CLK_MODE_3
 */
#define MSPI2_CLK_MODE			MSPI_CLK_MODE_3

/*
 * MSPI1_MASTER_SLAVE :-
 	 * MSPI_MASTER
 	 * MSPI_SLAVE
 */
#define MSPI2_MASTER_SLAVE		MSPI_MASTER

/*
 * MSPI1_PRESCALER :-
 	 * MSPI_PRESCALER_BY2
 	 * MSPI_PRESCALER_BY4
 	 * MSPI_PRESCALER_BY8
 	 * MSPI_PRESCALER_BY16
 	 * MSPI_PRESCALER_BY32
 	 * MSPI_PRESCALER_BY64
 	 * MSPI_PRESCALER_BY128
 	 * MSPI_PRESCALER_BY256
 */
#define MSPI2_PRESCALER		MSPI_PRESCALER_BY2

/*
 * MSPI1_DATA_ORDER :-
 	 * MSPI_MSB_FIRST
 	 * MSPI_LSB_FIRST
 */
#define MSPI2_DATA_ORDER	MSPI_MSB_FIRST

/*
 * MSPI1_SS_MANAGE :-
 	 * MSPI_HW_SLAVE_MANAGEMENT
 	 * MSPI_SW_SLAVE_MANAGEMENT
 */
#define MSPI2_SS_MANAGE		MSPI_SW_SLAVE_MANAGEMENT

/*
 * MSPI1_DATA_SIZE :-
 	 * MSPI_8BIT_DATA
 	 * MSPI_16BIT_DATA
 */
#define MSPI2_DATA_SIZE		MSPI_8BIT_DATA

/*
 * MSPI1_TX_INTERRUPT_STATE :-
 	 * MSPI_INTERRUPT_ENABLE
 	 * MSPI_INTERRUPT_DISABLE
 */
#define MSPI2_TX_INTERRUPT_STATE	MSPI_INTERRUPT_DISABLE

/*
 * MSPI1_RX_INTERRUPT_STATE :-
 	 * MSPI_INTERRUPT_ENABLE
 	 * MSPI_INTERRUPT_DISABLE
 */
#define MSPI2_RX_INTERRUPT_STATE	MSPI_INTERRUPT_DISABLE



#endif /* MSPI_CONFIG_H_ */
