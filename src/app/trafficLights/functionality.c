#include <stdint.h>
#include "functionality.h"
#include "pins.h"
#include "../../macro.h"
#include "../../io/led.h"
#include "../../io/button.h"
#include "../../system/clock.h"

void LED_Sequence_OX(uint8_t pos){
    switch(pos){
        case 1U:
            Turn_ON_RED_OX();
            break;
        case 2U:
            Turn_ON_YELLOW_OX();
            break;
        case 3U:
            Turn_ON_GREEN_OX();
            break;
        default:
            Switch_LED_RED();
            break;
    }
}

void LED_Sequence_OY(uint8_t pos){
    switch(pos){
        case 1U:
            Turn_ON_RED_OY();
            break;
        case 2U:
            Turn_ON_YELLOW_OY();
            break;
        case 3U:
            Turn_ON_GREEN_OY();
            break;
        default:
            Switch_LED_BLUE();
            break;
    }
}

void Cars_Count_LED(uint8_t side, uint8_t NCars){
    switch(side){
        case SIDE_OX:
            LED_Sequence_OX(NCars);
            break;
        case SIDE_OY:
            LED_Sequence_OY(NCars);
            break;

        default:
            //Not sure yet
            //Switch_LED_RED();
            break;
    }
}

void Reset_PINS(void){
    Turn_OFF_RED_OX();
    Turn_OFF_YELLOW_OX();
    Turn_OFF_GREEN_OX();

    Turn_OFF_RED_OY();
    Turn_OFF_YELLOW_OY();
    Turn_OFF_GREEN_OY();

    Reset_LED();
}

void Await(void){
    Reset_PINS();
    Reset_LED();

    Switch_LED_RED();
    Timer_PIOSC(300);

    Switch_LED_BLUE();
    Timer_PIOSC(300);

    Switch_LED_GREEN();
    Timer_PIOSC(400);

    Reset_LED();
}

