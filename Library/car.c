#include "car.h"
#include "motor_driver.h"

motor_typedef motor_left;
motor_typedef motor_right;

void car_control(car_state car_state, uint8_t speed)
{
	switch(car_state)
	{
		case CAR_STOP:
			motor_control(&motor_left, MOTOR_STOP, 0);
			motor_control(&motor_right, MOTOR_STOP, 0);
			break;
		case CAR_FORWARD:
			motor_control(&motor_left, MOTOR_CW, speed);
			motor_control(&motor_right, MOTOR_CW, speed);
			break;
		case CAR_BACKWARD:
			motor_control(&motor_left, MOTOR_CCW, speed);
			motor_control(&motor_right, MOTOR_CCW, speed);			
			break;
		
		case CAR_LEFT:
			motor_control(&motor_left, MOTOR_STOP, 0);
			motor_control(&motor_right, MOTOR_CW, speed);			
			break;
		
		case CAR_RIGHT:
			motor_control(&motor_left, MOTOR_CW, speed);
			motor_control(&motor_right, MOTOR_STOP, 0);			
			break;
		
		default:
			break;
	}
}

void car_init(TIM_HandleTypeDef *htim)
{
	motor_init(&motor_left, GPIOA, GPIO_PIN_10, htim, TIM_CHANNEL_1);
	motor_init(&motor_right, GPIOA, GPIO_PIN_11, htim, TIM_CHANNEL_2);
	car_control(CAR_STOP, 0 );
}


