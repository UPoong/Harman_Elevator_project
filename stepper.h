/*
 * stepper.h
 *
 *  Created on: Jul 23, 2024
 *      Author: Stardust
 */

#ifndef INC_STEPPER_H_
#define INC_STEPPER_H_

#include "top.h"
#include "delay.h"

#define STEPS_PER_REVOLATION 	4096
#define DIR_CW 					0		// clockwise
#define DIR_CCW					1		// counter-clockwise

#define IN1_Pin					GPIO_PIN_9
#define IN1_Port				GPIOC
#define IN2_Pin					GPIO_PIN_8
#define IN2_Port				GPIOC
#define IN3_Pin					GPIO_PIN_6
#define IN3_Port				GPIOC
#define IN4_Pin					GPIO_PIN_5
#define IN4_Port				GPIOC

static const uint8_t HALF_STEP_SEQ[8][4] = {
		{0,0,0,1},
		{0,0,1,1},
		{0,0,1,0},
		{0,1,1,0},
		{0,1,0,0},
		{1,1,0,0},
		{1,0,0,0},
		{1,0,0,1},
};

extern bool interruptFlag;
extern uint8_t state;

void stepMotor(uint8_t step);
void rotateSteps(uint16_t steps, uint8_t direction);
void rotateDegrees(uint16_t degrees, uint8_t direction);
void infiniteRotation(uint8_t direction, uint8_t targetFloor);
void findCurrentState(uint8_t direction, uint32_t i);

#endif /* INC_STEPPER_H_ */
