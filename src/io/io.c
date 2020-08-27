#include "io.h"
#include "led.h"
#include "button.h"
#include "../macro.h"

void INIT_PERIF(void){
    SYSCTL_RCGCGPIO_R  |= PORT_A | PORT_D | PORT_E;
    SYSCTL_GPIOHBCTL_R |= PORT_A | PORT_D | PORT_E;

    GPIO_PORTA_AHB_AFSEL_R = 0;
    GPIO_PORTD_AHB_AFSEL_R = 0;
    GPIO_PORTE_AHB_AFSEL_R = 0;

    GPIO_PORTA_AHB_AMSEL_R = 0;
    GPIO_PORTD_AHB_AMSEL_R = 0;
    GPIO_PORTE_AHB_AMSEL_R = 0; 
    
    //Outputs PD1, PD2, PD3
    //Outputs PA5, PA6, PA7
    //Inputs  PE1, PE2, PE3
    GPIO_PORTA_AHB_DIR_R |= PIN_PA5 | PIN_PA6 | PIN_PA7;
    GPIO_PORTD_AHB_DIR_R |= PIN_PD1 | PIN_PD2 | PIN_PD3;
    GPIO_PORTE_AHB_DIR_R = 0;

    //Set up PA5, PA6, PA7 pins as output
    GPIO_PORTA_AHB_DEN_R |= PIN_PA5 | PIN_PA6 | PIN_PA7;
    //Set up PD1, PD2, PD3 pins as output
    GPIO_PORTD_AHB_DEN_R |= PIN_PD1 | PIN_PD2 | PIN_PD3;
    //Set up PE1, PE2, PE3 pins as input
    GPIO_PORTE_AHB_DEN_R |= PIN_PE1 | PIN_PE2 | PIN_PE3;

    GPIO_PORTA_AHB_PCTL_R = 0;
    GPIO_PORTD_AHB_PCTL_R = 0;
    GPIO_PORTE_AHB_PCTL_R = 0;
}


void INIT_IO (void) {
    INIT_LED();
    INIT_BUTTON();
    INIT_PERIF();
}