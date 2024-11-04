/*
 * btn.c
 *
 *  Created on: Jul 22, 2024
 *      Author: Stardust
 */

#include <button.h>

BTN_TBL btn_tbl[_BTN_MAX_CH] ={
		{GPIOB, GPIO_PIN_5, GPIO_PIN_RESET},	// 1층 버튼
		{GPIOB, GPIO_PIN_3, GPIO_PIN_RESET},	// 2층 버튼 - 미사용(외부 인터럽트 GPIO로 사용)
		{GPIOA, GPIO_PIN_10, GPIO_PIN_RESET}	// 3층 버튼
};

// 버튼 입력 디바운싱 및 엣지 검출
// 계속 누르고 있을 필요 없이, 한 번 누르면 기능이 실행되도록
bool btnPress(uint8_t ch){
    static bool btnState[_BTN_MAX_CH] = {false};  // 버튼 상태 저장 배열
    bool currentState;

    if(ch >= _BTN_MAX_CH){
        return false;
    }

    currentState = !HAL_GPIO_ReadPin(btn_tbl[ch].port, btn_tbl[ch].pinNumber);

    if(currentState && !btnState[ch]) {
        HAL_Delay(100);  // Debounce delay
        currentState = !HAL_GPIO_ReadPin(btn_tbl[ch].port, btn_tbl[ch].pinNumber);
        if(currentState) {
            btnState[ch] = true;  // 버튼 상태 업데이트
            return true;  // 버튼이 눌렸음을 반환
        }
    } else if(!currentState) {
        btnState[ch] = false;  // 버튼이 떼어졌음을 업데이트
    }

    return false;
}
