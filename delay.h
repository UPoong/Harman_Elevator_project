/*
 * delay.h
 *
 *  Created on: Jul 23, 2024
 *      Author: Stardust
 */

#ifndef INC_DELAY_H_
#define INC_DELAY_H_

#include "top.h"
#include "led.h"

// timer/counter 10번은 16-bit
void delay_us(uint16_t us);
void wait();

#endif /* INC_DELAY_H_ */
