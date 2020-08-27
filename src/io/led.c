#include <stdint.h>
#include "led.h"
#include "../macro.h"


void INIT_LED(void){
    SYSCTL_RCGCGPIO_R |= (1U << 5);  /* enable clock for GPIOF */
    SYSCTL_GPIOHBCTL_R |= (1U << 5); /* enable AHB for GPIOF   */

    GPIO_PORTF_AHB_DIR_R |= (LED_RED | LED_BLUE | LED_GREEN);
    GPIO_PORTF_AHB_DEN_R |= (LED_RED | LED_BLUE | LED_GREEN);
}

void Switch_LED_RED(void){
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] ^= LED_RED;
}

void Switch_LED_BLUE(void){
    GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] ^= LED_BLUE;
}

void Switch_LED_GREEN(void){
    GPIO_PORTF_AHB_DATA_BITS_R[LED_GREEN] ^= LED_GREEN;
}

void Reset_LED(void){
    GPIO_PORTF_AHB_DATA_BITS_R[LED_RED] = 0;
    GPIO_PORTF_AHB_DATA_BITS_R[LED_BLUE] = 0;
    GPIO_PORTF_AHB_DATA_BITS_R[LED_GREEN] = 0;
}

