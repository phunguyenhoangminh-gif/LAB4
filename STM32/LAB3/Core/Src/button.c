/*
 * button.c
 *
 *  Created on: Oct 11, 2025
 *      Author: minhp
 */

#include "button.h"

GPIO_TypeDef* ButtonPort[MAX_BUTTON] = {B1_GPIO_Port, B2_GPIO_Port, B3_GPIO_Port};
uint16_t      ButtonPin[MAX_BUTTON]  = {B1_Pin, B2_Pin, B3_Pin};

int KeyReg0[MAX_BUTTON] = {NORMAL_STATE};
int KeyReg1[MAX_BUTTON] = {NORMAL_STATE};
int KeyReg2[MAX_BUTTON] = {NORMAL_STATE};
int KeyReg3[MAX_BUTTON] = {NORMAL_STATE};

int TimeOutForKeyPress[MAX_BUTTON] = {500};

int button_flag[MAX_BUTTON] = {0};
int button_long_flag[MAX_BUTTON] = {0};

int isButtonPressed (int index) {
	if (button_flag[index] == 1) {
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed (int index) {
	if (button_long_flag[index] == 1) {
		button_long_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess (int index) {
	//TODO
	//HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	button_flag[index] = 1;
}

void getKeyInput() {
	for (int i = 0; i < MAX_BUTTON; i++) {
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		KeyReg0[i] = HAL_GPIO_ReadPin(ButtonPort[i], ButtonPin[i]);

		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])) {
			if (KeyReg2[i] != KeyReg3[i]) {
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg3[i] == PRESSED_STATE) {
					TimeOutForKeyPress[i] = 500;
					subKeyProcess(i);
				}
			} else {
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0) {
					TimeOutForKeyPress[i] = 500;
					if (KeyReg3[i] == PRESSED_STATE) {
						subKeyProcess(i);
					}
				}
			}
		}
	}
}
