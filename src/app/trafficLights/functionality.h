#ifndef PROJECT_FUNCTIONALITY_H
#define PROJECT_FUNCTIONALITY_H

#include <stdint.h>

void LED_Sequence_OX(uint8_t pos);

void LED_Sequence_OY(uint8_t pos);

void Cars_Count_LED(uint8_t side, uint8_t NCars);

void Reset_PINS(void);

void Await(void);

#endif //PROJECT_FUNCTIONALITY_H
