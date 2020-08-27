#include <stdint.h>
#include "clock.h"
#include "../macro.h"


void Timer(uint16_t exec_time)
{
    if(exec_time <= 0 || exec_time > 1000) exec_time = 1000U;

    NVIC_ST_CTRL_R = 0;
    NVIC_ST_RELOAD_R = (SYS_CLOCK / 1000U) * exec_time - 1U;
    NVIC_ST_CTRL_R |= (1U << 2) | (1U << 1) | 1U;
}


void Timer_PIOSC(uint16_t exec_time)
{
    if(exec_time <= 0 || exec_time > 1000) exec_time = 1000U;

    NVIC_ST_CTRL_R = 0;
    NVIC_ST_RELOAD_R = (PIOSC_CLOCK / 1000U) * exec_time - 1U;
    NVIC_ST_CTRL_R |=  1U;  //(1U << 1) | 1U


    while (((NVIC_ST_CTRL_R) & (1U << 16)) == 0 )
        ;
    NVIC_ST_CTRL_R = 0;
}
/*
void Time_Seconds(uint16_t time){
    uint16_t volatile counter = 0;
    while(counter < time){
        Timer_PIOSC(1000);
        counter++;
    }
}
*/