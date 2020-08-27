#ifndef PROJECT_PINS_H
#define PROJECT_PINS_H

#include <stdint.h>

//Also contains counter that powers leds in the following sequence
/*
 * RED - 1 CAR
 * YELLOW - 2 CARS
 * GREEN - 3 CARS
 * Max car number = 3
 */
void Read_Input(uint8_t *input_data_array);

void Turn_ON_RED_OX(void);
void Turn_ON_YELLOW_OX(void);
void Turn_ON_GREEN_OX(void);

void Turn_OFF_RED_OX(void);
void Turn_OFF_YELLOW_OX(void);
void Turn_OFF_GREEN_OX(void);


void Turn_ON_RED_OY(void);
void Turn_ON_YELLOW_OY(void);
void Turn_ON_GREEN_OY(void);

void Turn_OFF_RED_OY(void);
void Turn_OFF_YELLOW_OY(void);
void Turn_OFF_GREEN_OY(void);

void Reset_OX(void);
void Reset_OY(void);


#endif //PROJECT_PINS_H
