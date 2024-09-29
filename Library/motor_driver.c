#include "motor_driver.h"
#include "pwm.h"
//speed = 0 - 100
void motor_control(motor_typedef *motor, motor_state motor_state, uint8_t speed)
{
	motor->motor_state = motor_state;
	switch(motor->motor_state)
	{
		case MOTOR_STOP:
			HAL_GPIO_WritePin(motor->GPIOx, motor->GPIO_Pin, GPIO_PIN_RESET);
			pwm_set_duty(motor->htim, motor->channel, 0);
			break;
		case MOTOR_CW:
			HAL_GPIO_WritePin(motor->GPIOx, motor->GPIO_Pin, GPIO_PIN_RESET);
			pwm_set_duty(motor->htim, motor->channel, speed);
			break;
		case MOTOR_CCW:
			HAL_GPIO_WritePin(motor->GPIOx, motor->GPIO_Pin, GPIO_PIN_SET);
			pwm_set_duty(motor->htim, motor->channel, 100 - speed);
			break;
		default:
			break;
	}
}

void motor_init(motor_typedef *motor, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin,
								TIM_HandleTypeDef *htim, uint32_t channel)
{
	motor->GPIOx = GPIOx;
	motor->GPIO_Pin = GPIO_Pin;
	motor->htim = htim;
	motor->channel = channel;
	motor->motor_state = MOTOR_STOP;
	HAL_TIM_PWM_Start(motor->htim, motor->channel);
}

