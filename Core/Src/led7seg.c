/*
 * led7seg.c
 *
 *  Created on: May 27, 2025
 *      Author: ADMIN
 */


#include "led7seg.h"

uint8_t data_buffer[3] = {0, 0, 0};
uint8_t led_control_state = INIT;

const uint8_t seven_seg_digits[10] = {
  0b00000011, // 0 → reverse of 0b11000000
  0b10011111, // 1 → reverse of 0b11111001
  0b00100101, // 2 → reverse of 0b10100100
  0b00001101, // 3 → reverse of 0b10110000
  0b10011001, // 4 → reverse of 0b10011001
  0b01001001, // 5 → reverse of 0b10010010
  0b01000001, // 6 → reverse of 0b10000010
  0b00011111, // 7 → reverse of 0b11111000
  0b00000001, // 8 → reverse of 0b10000000
  0b00001001  // 9 → reverse of 0b10010000
};


/**
 * @brief  Init for led control
 * @retval None
 */
void led_init()
{
	LED7SEG_DISABLE_1;
	LED7SEG_DISABLE_2;
	LED_DISABLE;
	HAL_GPIO_WritePin(LED_LATCH_GPIO_Port, LED_LATCH_Pin, GPIO_PIN_RESET);
};


/**
 * @brief  Load data from input to output of 595 IC
 * @param data: input
 * @retval None
 */
void latch_data(uint8_t data)
{
  HAL_SPI_Transmit(&hspi1, &data, 1, 1000);
  HAL_GPIO_WritePin(LED_LATCH_GPIO_Port, LED_LATCH_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(LED_LATCH_GPIO_Port, LED_LATCH_Pin, GPIO_PIN_RESET);
};


/**
 * @brief  Convert BCD number to 7 segment LED signal
 * @param digit: number to convert/number for converting
 * @retval Signal to display 7 segment LED
 */
uint8_t digit_to_segment(uint8_t digit)
{
  if (digit > 9) return 0;
  return seven_seg_digits[digit];
};

void set_seg_1(uint8_t data)
{
	LED7SEG_ENABLE_1;
	data_buffer[0] = digit_to_segment(data);
};

void set_seg_2(uint8_t data)
{
	LED7SEG_ENABLE_2;
	data_buffer[1] = digit_to_segment(data);
};

void set_led_array(uint8_t data)
{
	//	LED_ENABLE;
	data_buffer[2] = data;
};

void set_seg_12(uint8_t data)
{
	set_seg_1(data / 10);
	set_seg_2(data % 10);
};


/**
 * @brief  Used to test some functions of this API
 * @retval None
 */
void test_led_control()
{
	set_seg_1(1);
	set_seg_2(5);
	set_led_array(0b10101010);
};
