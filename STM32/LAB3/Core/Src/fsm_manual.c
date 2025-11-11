/*
 * fsm_manual.c
 *
 *  Created on: Oct 12, 2025
 *      Author: minhp
 */

#include "fsm_manual.h"

void fsm_manual_run(void) {
    switch (status) {
        case MAN_RED:
            updateLEDBuffer(2, temp_red);

            if (isTimerExpired(2) == 1) {
                HAL_GPIO_TogglePin(LR1_GPIO_Port, LR1_Pin);
                HAL_GPIO_TogglePin(LR2_GPIO_Port, LR2_Pin);
                setTimer(2, 500);
            }

            if (isButtonPressed(1) == 1) {
                temp_red++;
                if (temp_red > 99) temp_red = 1;
            }

            if (isButtonPressed(2) == 1) {
				time_red = temp_red;
			}
            break;

        case MAN_AMBER:
            updateLEDBuffer(3, temp_amber);

            if (isTimerExpired(2) == 1) {
                HAL_GPIO_TogglePin(LY1_GPIO_Port, LY1_Pin);
                HAL_GPIO_TogglePin(LY2_GPIO_Port, LY2_Pin);
                setTimer(2, 500);
            }

            if (isButtonPressed(1) == 1) {
                temp_amber++;
                if (temp_amber > 99) temp_amber = 1;
            }

            if (isButtonPressed(2) == 1) {
				time_amber = temp_amber;
			}
            break;

        case MAN_GREEN:
            updateLEDBuffer(4, temp_green);

            if (isTimerExpired(2) == 1) {
                HAL_GPIO_TogglePin(LG1_GPIO_Port, LG1_Pin);
                HAL_GPIO_TogglePin(LG2_GPIO_Port, LG2_Pin);
                setTimer(2, 500);
            }

            if (isButtonPressed(1) == 1) {
                temp_green++;
                if (temp_green > 99) temp_green = 1;
            }

            if (isButtonPressed(2) == 1) {
				time_green = temp_green;
			}
            break;

        default:
            break;
    }
}
