/*
 * led.c
 *
 *  Created on: Jul 22, 2024
 *      Author: Stardust
 */

#include "led.h"

LED_TBL led_tbl[_LED_MAX_CH] = 	{
						{GPIOA, GPIO_PIN_5, GPIO_PIN_SET, GPIO_PIN_RESET},
						{GPIOA, GPIO_PIN_6, GPIO_PIN_SET, GPIO_PIN_RESET},
						{GPIOA, GPIO_PIN_7, GPIO_PIN_SET, GPIO_PIN_RESET},
						{GPIOB, GPIO_PIN_6, GPIO_PIN_SET, GPIO_PIN_RESET}
//						{GPIOC, GPIO_PIN_7, GPIO_PIN_SET, GPIO_PIN_RESET},
//						{GPIOA, GPIO_PIN_9, GPIO_PIN_SET, GPIO_PIN_RESET},
//						{GPIOA, GPIO_PIN_8, GPIO_PIN_SET, GPIO_PIN_RESET},
//						{GPIOB, GPIO_PIN_10, GPIO_PIN_SET, GPIO_PIN_RESET}
						};

void LEDInit(){
	currentFloorLED(currentFloor-1);
}

void ledOn(uint8_t ch){
	HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pinNumber, led_tbl[ch].on);
}

void ledOff(uint8_t ch){
	HAL_GPIO_WritePin(led_tbl[ch].port, led_tbl[ch].pinNumber, led_tbl[ch].off);
}

void currentFloorLED(uint8_t ch){
	for(uint8_t i=0; i<3; i++){
		ledOff(i);
	}
	ledOn(ch);
}

void ledToggle(uint8_t ch){
	if(ch >= _LED_MAX_CH) return;
		for(uint8_t i=0; i<=ch; i++)
			HAL_GPIO_TogglePin(led_tbl[i].port, led_tbl[i].pinNumber);
}
