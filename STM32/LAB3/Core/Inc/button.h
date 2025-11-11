/*
 * button.h
 *
 *  Created on: Oct 11, 2025
 *      Author: minhp
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define MAX_BUTTON 5
#define NORMAL_STATE	SET
#define PRESSED_STATE	RESET

int isButtonPressed (int index);
int isButtonLongPressed (int index);

void getKeyInput();

#endif /* INC_BUTTON_H_ */
