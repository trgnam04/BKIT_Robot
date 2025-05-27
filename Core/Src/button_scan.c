/*
 * button_scan.c
 *
 *  Created on: May 27, 2025
 *      Author: ADMIN
 */

#include "button_scan.h"

uint8_t spi_data = 0x00;
uint8_t button_count[4];
uint8_t switch_count[4];


/**
  * @brief  Init matrix button
  * @param  None
  * @retval None
  */
void button_init(){
	HAL_GPIO_WritePin(INPUT_LOAD_GPIO_Port, INPUT_LOAD_Pin, 1);
}

/**
  * @brief  Scan matrix button
  * @param  None
  * @note  	Call every 50ms
  * @retval None
  */
void button_scan(){
    HAL_GPIO_WritePin(INPUT_LOAD_GPIO_Port, INPUT_LOAD_Pin, 0);
    HAL_GPIO_WritePin(INPUT_LOAD_GPIO_Port, INPUT_LOAD_Pin, 1);
    HAL_SPI_Receive(&hspi1, (void*)&spi_data, 1, 10);

    uint8_t mask = 0x80;
    for(int i = 0; i < 8; i++){
        uint8_t bit_state = (spi_data & mask) ? 1 : 0;

        if(i < 4){
        	switch_count[3 - i] = bit_state;
        } else {
            if(bit_state)
                button_count[7 - i] = 0;
            else
                button_count[7 - i]++;
        }

        mask >>= 1;
    }
}

uint8_t is_button_press(uint8_t idx){
	return button_count[idx] == 1;
}

uint8_t get_switch_state(uint8_t idx){
	return switch_count[idx] == 1;
}

