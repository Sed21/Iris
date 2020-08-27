#include <stdint.h>
#include "bsp.h"
#include "../sched.h"
#include "../../macro.h"
#include "../../io/led.h"

uint8_t tick_counter;

void SysTick_Handler(void)
{
    if(tick_counter == PERIOD_LENGTH){
        tick_counter = 0;
        NCycles--; // change this line
    } else {
        tick_counter++;
    }
}

