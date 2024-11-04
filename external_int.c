/*
 * interrupt.c
 *
 *  Created on: Jul 25, 2024
 *      Author: Stardust
 */

#include "external_int.h"

uint8_t currentFloor = 1;

// 외부 인터럽트 받으면 infiniteRotation 함수 강제 종료 위해 사용
bool interruptFlag = 0;

// 외부 인터럽트 while문 탈출 조건
extern bool forcedMove;
extern bool restart;

uint8_t Message[] = "Warning!\r\nSelect an Option: \r\n1. Continue\r\n2. Go to nearest Floor\r\n3. Go to specific Floor\r\n\r\n";

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == GPIO_PIN_4){
		// debouncing
		HAL_Delay(100);
		if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)){
			restart = false;
			forcedMove = false;
			HAL_UART_Transmit_IT(&huart2, Message, sizeof(Message));
			while(1){
				HAL_Delay(1000);
				if(restart){
					break;
				}
				else if(forcedMove){
					interruptFlag = true;
					break;
				}
			}
		}
	}
	if(GPIO_Pin == GPIO_PIN_15){
		currentFloor = 1;
		FND_DisplayDigit(currentFloor);
//		currentFloorLED(currentFloor-1);
	}
	if(GPIO_Pin == GPIO_PIN_14){
		currentFloor = 2;
		FND_DisplayDigit(currentFloor);
//		currentFloorLED(currentFloor-1);
	}
	if(GPIO_Pin == GPIO_PIN_13){
		currentFloor = 3;
		FND_DisplayDigit(currentFloor);
//		currentFloorLED(currentFloor-1);
	}
	// floor 2
	else if(GPIO_Pin == GPIO_PIN_3){
		//debouncing
		HAL_Delay(100);
		if(!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3)){

			switch(currentFloor){
				case 1:
					infiniteRotation(DIR_CW, 2);
					wait();
					break;
				case 2:
					break;
				case 3:
					infiniteRotation(DIR_CCW, 2);
					wait();
					break;
			}
		}
	}
}
