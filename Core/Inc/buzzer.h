/*
 * buzzer.h
 *
 *  Created on: May 27, 2025
 *      Author: ADMIN
 */

#ifndef INC_BUZZER_H_
#define INC_BUZZER_H_

#include "tim.h"
#include "gpio.h"

#define TIMER_CLOCK 64000000

void beep(uint32_t freq, uint32_t duration_ms, float duty_cycle);
void play_startup_sound();
void mario_startup_melody();

#endif /* INC_BUZZER_H_ */
