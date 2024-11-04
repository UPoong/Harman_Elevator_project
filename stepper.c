/*
 * stepper.c
 *
 *  Created on: Jul 23, 2024
 *      Author: Stardust
 */

#include "stepper.h"

uint8_t state = 1;

extern uint8_t currentFloor;

void stepMotor(uint8_t step){
	HAL_GPIO_WritePin(IN1_Port, IN1_Pin, HALF_STEP_SEQ[step][0]);
	HAL_GPIO_WritePin(IN2_Port, IN2_Pin, HALF_STEP_SEQ[step][1]);
	HAL_GPIO_WritePin(IN3_Port, IN3_Pin, HALF_STEP_SEQ[step][2]);
	HAL_GPIO_WritePin(IN4_Port, IN4_Pin, HALF_STEP_SEQ[step][3]);
}

void rotateSteps(uint16_t steps, uint8_t direction){
	for(uint16_t i=0; i<steps; i++){
		uint8_t step;
		// 회전 방향에 맞춰서 스텝 패턴 설정
		if(direction == DIR_CW){
			step = i % 8;
		}
		else{
			step = 7 - (i % 8);
		}
		stepMotor(step);
		delay_us(1000);	// 각 스텝간의 지연
	}
}

void rotateDegrees(uint16_t degrees, uint8_t direction){
	uint16_t steps = (uint16_t)(((uint32_t)degrees * STEPS_PER_REVOLATION) / 360);
	rotateSteps(steps, direction);
}

void infiniteRotation(uint8_t direction, uint8_t targetFloor){
	uint32_t i = 0;
	while(currentFloor != targetFloor){
		if (interruptFlag) {
			// 플래그가 설정되면 함수 실행 중단
			break;
		}
		uint8_t step;
		i++;
		if(direction == DIR_CW){
			step = i % 8;
		}
		else{
			step = 7 - (i % 8);
		}
		stepMotor(step);
		findCurrentState(direction, i);
		delay_us(STEP_DELAY_US);
	}
}

void findCurrentState(uint8_t direction, uint32_t steps){
	uint8_t nextFloor;
	steps = steps % (UNIT_STEPS * 2);
	if(direction == DIR_CW){
		nextFloor = currentFloor + 1;
	}
	else if(direction == DIR_CCW){
		nextFloor = currentFloor - 1;
	}
	if(currentFloor == 1 && nextFloor == 2){
		if(steps < UNIT_STEPS)
			state = 1;
		else
			state = 2;
	}
	else if(currentFloor == 2 && nextFloor == 3){
		if(steps < UNIT_STEPS)
			state = 3;
		else
			state = 4;
	}
	else if(currentFloor == 3 && nextFloor == 2){
		if(steps < UNIT_STEPS)
			state = 4;
		else
			state = 3;
	}
	else if(currentFloor == 2 && nextFloor == 1){
		if(steps < UNIT_STEPS)
			state = 2;
		else
			state = 1;
	}
}
