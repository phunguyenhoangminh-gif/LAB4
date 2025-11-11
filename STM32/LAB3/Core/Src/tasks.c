/*
 * tasks.c
 *
 *  Created on: Nov 11, 2025
 *      Author: minhp
 */

#include "tasks.h"

void task_led_blinky(void)
{
	if (isTimerExpired(4)) {
		setTimer(4, 1000);
		HAL_GPIO_TogglePin(LBLINKY_GPIO_Port, LBLINKY_Pin);
	}
}
