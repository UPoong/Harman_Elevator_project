/*
 * delay.c
 *
 *  Created on: Jul 23, 2024
 *      Author: Stardust
 */

#include "delay.h"

extern TIM_HandleTypeDef htim10;

// us delay
// hal 함수에는 ms 단위 딜레이만 있어서 따로 만듬
// 현재 미사용중
void delay_us(uint16_t us){
	__HAL_TIM_SET_COUNTER(&htim10, 0);

	HAL_TIM_Base_Start(&htim10);
	while(__HAL_TIM_GET_COUNTER(&htim10) < us);

	HAL_TIM_Base_Stop(&htim10);
}

// 엘리베이터 대기시간
// 목표 층에 도착 후 2초 대기 및 LED 점멸
void wait(){
	HAL_Delay(2000);
}
