#include <stdint.h>
#include "button.h"
#include "led.h"
#include "../system/clock.h"
#include "../macro.h"

#define POS ((1U << 6))

void INIT_BUTTON(void){
    GPIO_PORTF_AHB_DEN_R |= GPIO_PORTF_SW1_EN;
    GPIO_PORTF_AHB_DIR_R &= (~GPIO_PORTF_SW1_EN);
    GPIO_PORTF_AHB_PUR_R |= GPIO_PORTF_SW1_EN;
}


void Check_Button(void){
    uint8_t static volatile flag = 0;
    if(GPIO_PORTF_AHB_DATA_SW1 == 0)
    {
        //Timer_PIOSC(10);
        if( flag == 0 && GPIO_PORTF_AHB_DATA_SW1 == 0)
        {
          Switch_LED_GREEN();
          flag = 1U;
        }
     } else
     {
          flag = 0;
     }
}

uint8_t SW1_is_pressed(void){
    if(GPIO_PORTF_AHB_DATA_SW1 == 0){
      Timer_PIOSC(10);
        if(GPIO_PORTF_AHB_DATA_SW1 == 0){
            return 1;
        }
    }
    return 0;
}