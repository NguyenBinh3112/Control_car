#include "pwm.h"

void pwm_set_duty(TIM_HandleTypeDef *htim, uint32_t channel, uint8_t duty)
{
	switch(channel)
	{
		case TIM_CHANNEL_1:
			htim->Instance->CCR1 = (htim->Instance->ARR * duty)/100;
			break;
		case TIM_CHANNEL_2:
			htim->Instance->CCR2 = (htim->Instance->ARR * duty)/100;
			break;
	}
}