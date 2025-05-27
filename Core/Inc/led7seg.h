/*
 * led7seg.h
 *
 *  Created on: May 27, 2025
 *      Author: ADMIN
 */

#ifndef INC_LED7SEG_H_
#define INC_LED7SEG_H_

#include "main.h"
#include "spi.h"
#include "software_timer.h"

// Some macro
#define LED7SEG_ENABLE_1 HAL_GPIO_WritePin(LED7_EN1_GPIO_Port, LED7_EN1_Pin, GPIO_PIN_RESET);
#define LED7SEG_DISABLE_1 HAL_GPIO_WritePin(LED7_EN1_GPIO_Port, LED7_EN1_Pin, GPIO_PIN_SET);
#define LED7SEG_ENABLE_2 HAL_GPIO_WritePin(LED7_EN2_GPIO_Port, LED7_EN2_Pin, GPIO_PIN_RESET);
#define LED7SEG_DISABLE_2 HAL_GPIO_WritePin(LED7_EN2_GPIO_Port, LED7_EN2_Pin, GPIO_PIN_SET);
#define LED_ENABLE HAL_GPIO_WritePin(LED_EN_GPIO_Port, LED_EN_Pin, GPIO_PIN_RESET);
#define LED_DISABLE HAL_GPIO_WritePin(LED_EN_GPIO_Port, LED_EN_Pin, GPIO_PIN_SET);


void led_init();
void test_led_control();

void set_seg_1(uint8_t data);
void set_seg_2(uint8_t data);
void set_led_array(uint8_t data);
void set_seg_12(uint8_t data);



#endif /* INC_LED7SEG_H_ */
