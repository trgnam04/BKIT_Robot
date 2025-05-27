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

extern uint8_t button_count[4];
extern uint8_t switch_count[4];

void button_init(void);
void button_scan();
void is_button_press(uint8_t idx);
void get_switch_state(uint8_t idx);


#endif /* INC_BUTTON_SCAN_H_ */
