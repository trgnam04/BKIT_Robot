/*
 * button_scan.h
 *
 *  Created on: May 27, 2025
 *      Author: ADMIN
 */

#ifndef INC_BUTTON_SCAN_H_
#define INC_BUTTON_SCAN_H_

#include "spi.h"
#include "gpio.h"


void button_init(void);
void button_scan();
uint8_t is_button_press(uint8_t idx);
uint8_t get_switch_state(uint8_t idx);


#endif /* INC_BUTTON_SCAN_H_ */
