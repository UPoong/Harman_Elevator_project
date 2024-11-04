/*
 * led.h
 *
 *  Created on: Jul 22, 2024
 *      Author: Stardust
 */

#ifndef HW_DEVICE_LED_H_
#define HW_DEVICE_LED_H_

#include "top.h"

typedef struct{
	GPIO_TypeDef 	*port;
	uint16_t		pinNumber;
	GPIO_PinState	on;
	GPIO_PinState	off;
}LED_TBL;	// table

extern uint8_t currentFloor;

void LEDInit();
void ledOn(uint8_t ch);
void ledOff(uint8_t ch);
void currentFloorLED(uint8_t ch);
void ledToggle(uint8_t ch);

#endif /* HW_DEVICE_LED_H_ */
