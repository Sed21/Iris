#include <stdint.h>
#include "pins.h"
#include "functionality.h"
#include "../../macro.h"
#include "../../io/led.h"
#include "../../io/button.h"
#include "../../system/clock.h"

void Read_Input(uint8_t *input_data_array){
    uint8_t volatile flag_ox = 0;
    uint8_t volatile flag_oy = 0;

    uint8_t volatile NCars_oX = 0;
    uint8_t volatile NCars_oY = 0;

    //Indicator that controller is in set mod
    Switch_LED_GREEN();

    while(!SW1_is_pressed()) {
        if(GPIO_PORTE_AHB_DATA_R_PE1 == 0)
        {
            Timer_PIOSC(10);
            if(GPIO_PORTE_AHB_DATA_R_PE1 == SET_PIN && flag_ox == 0)
            {
                if(NCars_oX < MAX_CARS){
                    NCars_oX++;
                    Cars_Count_LED(SIDE_OX, NCars_oX);
                }
                flag_ox = 1U;
            } else {
                flag_ox = 0;
            }
        }

        if(GPIO_PORTE_AHB_DATA_R_PE2 == 0)
        {
            Timer_PIOSC(10);
            if(GPIO_PORTE_AHB_DATA_R_PE2 == SET_PIN && flag_oy == 0)
            {
                if(NCars_oY < MAX_CARS){
                    NCars_oY++;
                    Cars_Count_LED(SIDE_OY, NCars_oY);
                    flag_oy = 1U;
                }
            } else {
                flag_oy = 0;
            }
        }
    }
    input_data_array[0] = NCars_oX;
    input_data_array[1] = NCars_oY;
    Switch_LED_RED();
}


void Turn_ON_RED_OX(void){
    GPIO_PORTD_AHB_DATA_W_PD1 |= SET_PIN;
}

void Turn_ON_YELLOW_OX(void){
    GPIO_PORTD_AHB_DATA_W_PD2 |= SET_PIN;
}

void Turn_ON_GREEN_OX(void){
    GPIO_PORTD_AHB_DATA_W_PD3 |= SET_PIN;
}

void Turn_OFF_RED_OX(void){
    GPIO_PORTD_AHB_DATA_W_PD1 = UNSET_PIN;
}

void Turn_OFF_YELLOW_OX(void){
    GPIO_PORTD_AHB_DATA_W_PD2 = UNSET_PIN;
}

void Turn_OFF_GREEN_OX(void){
    GPIO_PORTD_AHB_DATA_W_PD3 = UNSET_PIN;
}




void Turn_ON_RED_OY(void){
    GPIO_PORTA_AHB_DATA_W_PA5 |= SET_PIN;
}

void Turn_ON_YELLOW_OY(void){
    GPIO_PORTA_AHB_DATA_W_PA6 |= SET_PIN;
}

void Turn_ON_GREEN_OY(void){
    GPIO_PORTA_AHB_DATA_W_PA7 |= SET_PIN;
}

void Turn_OFF_RED_OY(void){
    GPIO_PORTA_AHB_DATA_W_PA5 = UNSET_PIN;
}

void Turn_OFF_YELLOW_OY(void){
    GPIO_PORTA_AHB_DATA_W_PA6 = UNSET_PIN;
}

void Turn_OFF_GREEN_OY(void){
    GPIO_PORTA_AHB_DATA_W_PA7 = UNSET_PIN;
}


void Reset_OX(void){
    Turn_OFF_RED_OX();
    Turn_OFF_YELLOW_OX();
    Turn_OFF_GREEN_OX();
}

void Reset_OY(void){
    Turn_OFF_RED_OY();
    Turn_OFF_YELLOW_OY();
    Turn_OFF_GREEN_OY();
}
