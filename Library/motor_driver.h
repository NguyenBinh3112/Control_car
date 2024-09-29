#ifndef BUTTON_DRIVER_H
#define BUTTON_DRIVER_H

#include "main.h"

typedef enum
{
	MOTOR_STOP,
	MOTOR_CW,
	MOTOR_CCW
}motor_state;

typedef struct
{
	motor_state motor_state;
	GPIO_TypeDef *GPIOx; 
	uint16_t GPIO_Pin;
	TIM_HandleTypeDef *htim;
	uint32_t channel;
}motor_typedef;

void motor_control(motor_typedef *motor, motor_state motor_state, uint8_t speed);
void motor_init(motor_typedef *motor, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin,
								TIM_HandleTypeDef *htim, uint32_t channel);
#endif

