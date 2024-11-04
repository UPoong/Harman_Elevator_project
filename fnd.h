/*
 * FND.h
 *
 *  Created on: Jul 26, 2024
 *      Author: Stardust
 */

#ifndef INC_FND_H_
#define INC_FND_H_

#include "top.h"

#define FND_A_PIN    GPIO_PIN_5
#define FND_A_PORT   GPIOA
#define FND_B_PIN    GPIO_PIN_6
#define FND_B_PORT   GPIOA
#define FND_C_PIN    GPIO_PIN_7
#define FND_C_PORT   GPIOA
#define FND_D_PIN    GPIO_PIN_6
#define FND_D_PORT   GPIOB
#define FND_E_PIN    GPIO_PIN_7
#define FND_E_PORT   GPIOC
#define FND_F_PIN    GPIO_PIN_9
#define FND_F_PORT   GPIOA
#define FND_G_PIN    GPIO_PIN_8
#define FND_G_PORT   GPIOA
#define FND_DP_PIN   GPIO_PIN_10
#define FND_DP_PORT  GPIOB

extern uint8_t currentFloor;

//void FND_Init(void);
void FND_DisplayDigit(uint8_t digit);
void FND_Clear(void);
void FND_Init();

#endif /* INC_FND_H_ */
