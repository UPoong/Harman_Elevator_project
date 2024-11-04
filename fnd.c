/*
 * FND.c
 *
 *  Created on: Jul 26, 2024
 *      Author: Stardust
 */

#include "fnd.h"

// 7세그먼트 디스플레이 각 자리의 값에 대한 세그먼트 설정
const uint8_t FND_SEGMENTS[10] = {
    0b00111111,  // 0
    0b00000110,  // 1
    0b01011011,  // 2
    0b01001111,  // 3
    0b01100110,  // 4
    0b01101101,  // 5
    0b01111101,  // 6
    0b00000111,  // 7
    0b01111111,  // 8
    0b01101111   // 9
};

// 특정 디지트를 표시하는 함수
void FND_DisplayDigit(uint8_t digit) {

    uint8_t segments = FND_SEGMENTS[digit];

    // 각 세그먼트 핀 설정
    HAL_GPIO_WritePin(FND_D_PORT, FND_D_PIN, (segments & 0b00001000)? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(FND_A_PORT, FND_A_PIN, (segments & 0b00000001)? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(FND_B_PORT, FND_B_PIN, (segments & 0b00000010)? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(FND_C_PORT, FND_C_PIN, (segments & 0b00000100)? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(FND_E_PORT, FND_E_PIN, (segments & 0b00010000)? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(FND_F_PORT, FND_F_PIN, (segments & 0b00100000)? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(FND_G_PORT, FND_G_PIN, (segments & 0b01000000)? GPIO_PIN_SET : GPIO_PIN_RESET);
//    HAL_GPIO_WritePin(FND_DP_PORT, FND_DP_PIN, GPIO_PIN_RESET);	// Dot Point disable
}

// 모든 세그먼트를 OFF로 설정하는 함수
void FND_Clear(void) {
    HAL_GPIO_WritePin(FND_A_PORT, FND_A_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(FND_B_PORT, FND_B_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(FND_C_PORT, FND_C_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(FND_D_PORT, FND_D_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(FND_E_PORT, FND_E_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(FND_F_PORT, FND_F_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(FND_G_PORT, FND_G_PIN, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(FND_DP_PORT, FND_DP_PIN, GPIO_PIN_RESET);
}

void FND_Init(){
	FND_DisplayDigit(currentFloor);
}
