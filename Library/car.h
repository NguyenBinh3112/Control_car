#ifndef CAR_H
#define CAR_H
#include "main.h"

typedef enum
{
	CAR_STOP,
	CAR_FORWARD,
	CAR_BACKWARD,
	CAR_LEFT,
	CAR_RIGHT
}car_state;

void car_control(car_state car_state, uint8_t speed);
void car_init(TIM_HandleTypeDef *htim);
#endif
