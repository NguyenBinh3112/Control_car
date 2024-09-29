#ifndef PWM_H
#define PWM_H

#include "main.h"

void pwm_set_duty(TIM_HandleTypeDef *htim, uint32_t channel, uint8_t duty);

#endif

