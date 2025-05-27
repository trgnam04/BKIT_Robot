/*
 * buzzer.c
 *
 *  Created on: May 27, 2025
 *      Author: ADMIN
 */

#include "buzzer.h"

/*
 * ============================
 *  Passive Buzzer - Programming Notes
 * ============================
 *
 * This project uses a **Passive Buzzer**, which differs from an Active Buzzer in that:
 *  - It does not have a built-in oscillator.
 *  - It requires an external PWM signal to generate sound.
 *
 * ============================
 *  How It Works:
 * ============================
 * - The **PWM frequency** determines the pitch of the sound.
 *     + Example: 440 Hz → A4, 784 Hz → G5
 * - The **duty cycle** affects the volume, but only to a limited extent.
 * - A duty cycle between **40% and 70%** usually provides the clearest sound.
 *
 * ============================
 *  Programming Notes:
 * ============================
 * 1. Use a hardware Timer on the STM32 in **PWM Output Mode**.
 * 2. Calculate **Prescaler (PSC)** and **Auto-Reload Register (ARR)** values to generate the target frequency.
 * 3. Implement a `beep(freq, duration, duty)` function to play individual notes.
 * 4. Chain notes to produce startup tones, error alerts, or simple melodies (e.g., Mario theme).
 *
 * ============================
 *  Limitations:
 * ============================
 * - Volume control is limited; not suitable for high-quality audio output.
 * - Requires careful timing and tuning for melodies.
 *
 * ============================
 *  Advantages:
 * ============================
 * - Low cost and easy to integrate.
 * - Ideal for simple audio feedback in embedded systems.
 */

void buzzer_init(void){

}

/*
 * Parameters:
 *  - freq: Frequency of the sound in Hz (controls the pitch)
 *  - duration_ms: Duration of the sound in milliseconds
 *  - duty_cycle: PWM duty cycle (0–100%), used to control the volume
 */

void beep(uint32_t freq, uint32_t duration_ms, float duty_cycle) {
	if (freq == 0) {
		// rest
		HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
		HAL_Delay(duration_ms);
		return;
	}

    uint32_t timer_clock = 64000000; // Timer clock 64 MHz
    uint32_t arr = 100;
    uint32_t psc = (timer_clock / ((arr + 1) * freq)) - 1;
    uint32_t ccr = duty_cycle * arr;

    __HAL_TIM_SET_PRESCALER(&htim2, psc);
    __HAL_TIM_SET_AUTORELOAD(&htim2, arr);
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, ccr);

    HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
    HAL_Delay(duration_ms);
    HAL_TIM_PWM_Stop(&htim2, TIM_CHANNEL_1);
}

void play_startup_sound() {
    beep(261, 150, 0.5);  // C4
    HAL_Delay(20);
    beep(329, 150, 0.5);  // E4
    HAL_Delay(20);
    beep(392, 200, 0.5);  // G4
    HAL_Delay(20);
    beep(523, 300, 0.5);  // C5
    HAL_Delay(20);
}

void mario_startup_melody() {
    beep(659, 150, 0.5);  // E5
    HAL_Delay(20);
    beep(659, 150, 0.5);  // E5
    HAL_Delay(20);
    beep(0,   150, 0.0);  // rest
    HAL_Delay(20);
    beep(659, 150, 0.5);  // E5
    HAL_Delay(20);
    beep(0,   100, 0.0);  // rest
    HAL_Delay(20);
    beep(523, 150, 0.5);  // C5
    HAL_Delay(20);
    beep(659, 150, 0.5);  // E5
    HAL_Delay(20);
    beep(784, 250, 0.5);  // G5
    HAL_Delay(20);
    beep(0,   250, 0.0);  // rest
    HAL_Delay(20);
}
