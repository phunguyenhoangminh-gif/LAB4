/*
 * led_display.h
 *
 *  Created on: Oct 11, 2025
 *      Author: minhp
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

#include "main.h"

void setRed(int road);
void setYellow(int road);
void setGreen(int road);
void turnOffAllLEDs(void);

void update7SEG(int index);
void updateLEDBuffer(int num1, int num2);

void scanLED(void);

#endif /* INC_LED_DISPLAY_H_ */
