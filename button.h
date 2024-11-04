/*
 * btn.h
 *
 *  Created on: Jul 22, 2024
 *      Author: Stardust
 */

#ifndef HW_DEVICE_BTN_H_
#define HW_DEVICE_BTN_H_

#include "top.h"

typedef struct{
	GPIO_TypeDef	*port;
	uint16_t		pinNumber;
	GPIO_PinState	on;
}BTN_TBL;

bool btnPress(uint8_t ch);

#endif /* HW_DEVICE_BTN_H_ */
