///*
// * uart.c
// *
// *  Created on: Jul 25, 2024
// *      Author: Stardust
// */
//
//// uart 통신
//// 비상 정지 버튼이 눌렸을 때, 터미널로 기능 실행
//
//#include "uart.h"
//
//// flag
//bool forcedMove = 0;
//bool restart = 0;
//
//uint8_t ACK1[] = "Continue...\r\n\r\n";
//uint8_t ACK2[] = "Going to nearest Floor...\r\n\r\n";
//uint8_t ACK3[] = "Choose floor to go:\r\n\r\n";
//uint8_t ACK4[] = "Going to Floor 1...\r\n\r\n";
//uint8_t ACK5[] = "Going to Floor 2...\r\n\r\n";
//uint8_t ACK6[] = "Going to Floor 3...\r\n\r\n";
//
//uint8_t Warn[] = "!Invalid Input \r\n";
//
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
//    if (huart->Instance == USART2){
//    	// Continue
//        if (rxData == '1') {
//        	HAL_UART_Transmit_IT(&huart2, ACK1, sizeof(ACK1));
//            restart = true;
//        }
//        // 가장 가까운 층으로 이동
//        else if (rxData == '2') {
//        	HAL_UART_Transmit_IT(&huart2, ACK2, sizeof(ACK2));
//        	switch(state){
//				case 1:
//					infiniteRotation(DIR_CCW, 1); break;
//				case 2:
//					infiniteRotation(DIR_CW, 2); break;
//				case 3:
//					infiniteRotation(DIR_CCW, 2); break;
//				case 4:
//					infiniteRotation(DIR_CW, 3); break;
//        	}
//			forcedMove = true;
//        }
//        // 1층으로 이동
//        else if (rxData == '3') {
//        	HAL_UART_Transmit_IT(&huart2, ACK3, sizeof(ACK3));
//        	rxData = 0;
//        	// 다시 UART 수신 인터럽트 활성화
//        	HAL_UART_Receive_IT(&huart2, &rxData, sizeof(rxData));
//        	while(1){
//				if (rxData == '1') {
//					HAL_UART_Transmit_IT(&huart2, ACK4, sizeof(ACK4));
//					infiniteRotation(DIR_CW, 1);
//					forcedMove = true;
//					break;
//				}
//				// 2층으로 이동
//				else if (rxData == '2') {
//					HAL_UART_Transmit_IT(&huart2, ACK5, sizeof(ACK5));
//					// 현재 엘리베이터가 2층보다 아래에 있으면
//					if(state == 1 || state == 2)
//						infiniteRotation(DIR_CW, 2);
//					// 현재 엘리베이터가 2층보다 위에 있으면
//					else
//						infiniteRotation(DIR_CCW, 2);
//					forcedMove = true;
//					break;
//				}
//				// 3층으로 이동
//				else if (rxData == '3') {
//					HAL_UART_Transmit_IT(&huart2, ACK6, sizeof(ACK6));
//					infiniteRotation(DIR_CW, 3);
//					forcedMove = true;
//					break;
//				}
//				// 에러 메시지(1~3 이외의 입력)
//				else {
//					HAL_UART_Transmit_IT(&huart2, Warn, sizeof(Warn));
//				}
//        	}
//        }
//        // 다시 UART 수신 인터럽트 활성화
//        HAL_UART_Receive_IT(&huart2, &rxData, sizeof(rxData));
//    }
//}

#include "uart.h"

// flag
bool forcedMove = 0;
bool restart = 0;
bool choosingFloor = 0;

uint8_t ACK1[] = "Continue...\r\n\r\n";
uint8_t ACK2[] = "Going to nearest Floor...\r\n\r\n";
uint8_t ACK3[] = "Choose floor to go:\r\n\r\n";
uint8_t ACK4[] = "Going to Floor 1...\r\n\r\n";
uint8_t ACK5[] = "Going to Floor 2...\r\n\r\n";
uint8_t ACK6[] = "Going to Floor 3...\r\n\r\n";

uint8_t Warn[] = "!Invalid Input \r\n";

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance == USART2) {
//        if (choosingFloor) {
//            // 층 선택 처리
//            switch (rxData) {
//                case '1':
//                    HAL_UART_Transmit_IT(&huart2, ACK4, sizeof(ACK4));
//                    infiniteRotation(DIR_CCW, 1);
//                    forcedMove = true;
//                    choosingFloor = false;  // 선택 종료
//                    break;
//                case '2':
//                    HAL_UART_Transmit_IT(&huart2, ACK5, sizeof(ACK5));
//                    if (state == 1 || state == 2)
//                        infiniteRotation(DIR_CW, 2);
//                    else
//                        infiniteRotation(DIR_CCW, 2);
//                    forcedMove = true;
//                    choosingFloor = false;  // 선택 종료
//                    break;
//                case '3':
//                    HAL_UART_Transmit_IT(&huart2, ACK6, sizeof(ACK6));
//                    infiniteRotation(DIR_CW, 3);
//                    forcedMove = true;
//                    choosingFloor = false;  // 선택 종료
//                    break;
//                default:
//                	// 에러 메시지(1~3 이외의 입력)
//                    HAL_UART_Transmit_IT(&huart2, Warn, sizeof(Warn));
//                    break;
//            }
//        }
        if(choosingFloor){
            // 층 선택 처리
            if(rxData == '1'){
				HAL_UART_Transmit_IT(&huart2, ACK4, sizeof(ACK4));
				infiniteRotation(DIR_CCW, 1);
				forcedMove = true;
				choosingFloor = false;  // 선택 종료
            }
			else if(rxData == '2'){
				HAL_UART_Transmit_IT(&huart2, ACK5, sizeof(ACK5));
				if (state == 1 || state == 2)
					infiniteRotation(DIR_CW, 2);
				else
					infiniteRotation(DIR_CCW, 2);
				forcedMove = true;
				choosingFloor = false;  // 선택 종료
            }
            else if(rxData == '3'){
                HAL_UART_Transmit_IT(&huart2, ACK6, sizeof(ACK6));
                infiniteRotation(DIR_CW, 3);
                forcedMove = true;
                choosingFloor = false;  // 선택 종료
            }
            else{
            	// 에러 메시지(1~3 이외의 입력)
                HAL_UART_Transmit_IT(&huart2, Warn, sizeof(Warn));
            }
        }
        else {
            // Continue
            if (rxData == '1') {
                HAL_UART_Transmit_IT(&huart2, ACK1, sizeof(ACK1));
                restart = true;
            }
            // 가장 가까운 층으로 이동
            else if (rxData == '2') {
                HAL_UART_Transmit_IT(&huart2, ACK2, sizeof(ACK2));
                switch(state){
                    case 1:
                        infiniteRotation(DIR_CCW, 1); break;
                    case 2:
                        infiniteRotation(DIR_CW, 2); break;
                    case 3:
                        infiniteRotation(DIR_CCW, 2); break;
                    case 4:
                        infiniteRotation(DIR_CW, 3); break;
                }
                forcedMove = true;
            }
            else if (rxData == '3') {
                HAL_UART_Transmit_IT(&huart2, ACK3, sizeof(ACK3));
                choosingFloor = true;  // 상태 변경: 층 선택 중
            }
            // 에러 메시지(1~3 이외의 입력)
            else {
                HAL_UART_Transmit_IT(&huart2, Warn, sizeof(Warn));
            }
        }

        // 다시 UART 수신 인터럽트 활성화
        HAL_UART_Receive_IT(&huart2, &rxData, sizeof(rxData));
    }
}
