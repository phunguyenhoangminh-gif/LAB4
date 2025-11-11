/*
 * led_display.c
 *
 *  Created on: Oct 11, 2025
 *      Author: minhp
 */

#include "led_display.h"
#include "global.h"

void setRed(int road) {
    if (road == 1) {
        HAL_GPIO_WritePin(LR1_GPIO_Port, LR1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(LY1_GPIO_Port, LY1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(LG1_GPIO_Port, LG1_Pin, GPIO_PIN_SET);
    } else if (road == 2) {
        HAL_GPIO_WritePin(LR2_GPIO_Port, LR2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(LY2_GPIO_Port, LY2_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(LG2_GPIO_Port, LG2_Pin, GPIO_PIN_SET);
    }
}

void setYellow(int road) {
    if (road == 1) {
        HAL_GPIO_WritePin(LR1_GPIO_Port, LR1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(LY1_GPIO_Port, LY1_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(LG1_GPIO_Port, LG1_Pin, GPIO_PIN_SET);
    } else if (road == 2) {
        HAL_GPIO_WritePin(LR2_GPIO_Port, LR2_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(LY2_GPIO_Port, LY2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(LG2_GPIO_Port, LG2_Pin, GPIO_PIN_SET);
    }
}

void setGreen(int road) {
    if (road == 1) {
        HAL_GPIO_WritePin(LR1_GPIO_Port, LR1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(LY1_GPIO_Port, LY1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(LG1_GPIO_Port, LG1_Pin, GPIO_PIN_RESET);
    } else if (road == 2) {
        HAL_GPIO_WritePin(LR2_GPIO_Port, LR2_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(LY2_GPIO_Port, LY2_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(LG2_GPIO_Port, LG2_Pin, GPIO_PIN_RESET);
    }
}

void turnOffAllLEDs(void) {
    HAL_GPIO_WritePin(LR1_GPIO_Port, LR1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LY1_GPIO_Port, LY1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LG1_GPIO_Port, LG1_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LR2_GPIO_Port, LR2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LY2_GPIO_Port, LY2_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(LG2_GPIO_Port, LG2_Pin, GPIO_PIN_SET);
}

const int MAX_LED = 4;
int led_buffer[4] = {0, 0, 0, 0};
int index_led = 0;

void clear7SEG(){
	HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, GPIO_PIN_SET);
}

void display7SEG(int num) {
	clear7SEG();
	switch(num) {
		case 0:
			HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, GPIO_PIN_RESET);
	        break;
	    case 1:
	        HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_RESET);
	        break;
	    case 2:
	        HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, GPIO_PIN_RESET);
	        break;
	    case 3:
	        HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, GPIO_PIN_RESET);
	        break;
	    case 4:
	        HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, GPIO_PIN_RESET);
	        break;
	    case 5:
	        HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, GPIO_PIN_RESET);
	        break;
	    case 6:
	        HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, GPIO_PIN_RESET);
	        break;
	    case 7:
	        HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_RESET);
	        break;
	    case 8:
	        HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_e_GPIO_Port, SEG_e_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, GPIO_PIN_RESET);
	        break;
	    case 9:
	        HAL_GPIO_WritePin(SEG_a_GPIO_Port, SEG_a_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_b_GPIO_Port, SEG_b_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_c_GPIO_Port, SEG_c_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_d_GPIO_Port, SEG_d_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_f_GPIO_Port, SEG_f_Pin, GPIO_PIN_RESET);
	        HAL_GPIO_WritePin(SEG_g_GPIO_Port, SEG_g_Pin, GPIO_PIN_RESET);
	        break;
	    default:
	        break;
	}
}

void update7SEG(int index) {
    switch(index) {
        case 0:
            // Display the first 7 SEG with led_buffer[0]
            display7SEG(led_buffer[0]);
            // Turn off all other displays
            HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
            break;
        case 1:
            // Display the second 7 SEG with led_buffer[1]
            display7SEG(led_buffer[1]);
            HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
            break;
        case 2:
            // Display the third 7 SEG with led_buffer[2]
            display7SEG(led_buffer[2]);
            HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
            HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
            break;
        case 3:
            // Display the fourth 7 SEG with led_buffer[3]
            display7SEG(led_buffer[3]);
            HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
            HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
            break;
        default:
            break;
    }
}

void updateLEDBuffer(int num1, int num2) {
    led_buffer[0] = num1 / 10;
    led_buffer[1] = num1 % 10;
    led_buffer[2] = num2 / 10;
    led_buffer[3] = num2 % 10;
}

void scanLED(void) {
    if (isTimerExpired(3) == 1) {
        update7SEG(index_led);
        setTimer(3, 125);
        index_led++;
		if (index_led >= MAX_LED) index_led = 0;
    }
}
