/*
 * uart.h
 *
 *  Created on: Jul 25, 2024
 *      Author: Stardust
 */

#ifndef INC_UART_H_
#define INC_UART_H_

#include "top.h"
#include "stepper.h"

extern UART_HandleTypeDef huart2;	// uart2 handler

extern uint8_t rxData;

extern bool restart;
extern bool forcedMove;

#endif /* INC_UART_H_ */
