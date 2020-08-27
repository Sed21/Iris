#ifndef PROJECT_CLOCK_H
#define PROJECT_CLOCK_H

#include <stdint.h>
#include "../macro.h"

/*  Timer using inner Sys clock */
void Timer(uint16_t exec_time);


/*  Timer using PIOSC clock  */
void Timer_PIOSC(uint16_t exec_time);

/*  Seconds counter Timer   */
//void Time_Seconds(uint16_t time);


#endif
