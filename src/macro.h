#ifndef PROJECT_MACRO_H
#define PROJECT_MACRO_H

/*
 *   CPU Clock Registers (SysTic)
 */
#define NVIC_ST_CTRL_R             (*(unsigned volatile long*)0xE000E010U)
#define NVIC_ST_RELOAD_R           (*(unsigned volatile long*)0xE000E014U)
#define NVIC_ST_CURRENT_R          (*(unsigned volatile long*)0xE000E018U)
#define NVIC_EN0_R                 (*((volatile unsigned long*)0xE000E100))
//=========================================================================
/*
 *   GPIO (GENERAL PURPOSE INPUT OUTPUT)
 */
#define GPIO_PORTF_AHB_DATA_SW1     (*((volatile unsigned long*)(0x4005D000 + (1U << 6))))
#define GPIO_PORTF_AHB_PUR_R        (*((volatile unsigned long*)0x4005D510))
#define GPIO_PORTF_AHB_LOCK_R       (*((volatile unsigned long*)0x4005D520))
#define GPIO_PORTF_AHB_CR_R         (*((volatile unsigned long*)0x4005D524))
#define GPIO_PORTF_AHB_IEV_R        (*((volatile unsigned long*)0x4005D40C))

#define GPIO_PORTA_AHB_AFSEL_R      (*((volatile unsigned long*)0x40058420))
#define GPIO_PORTD_AHB_AFSEL_R      (*((volatile unsigned long*)0x4005B420))
#define GPIO_PORTE_AHB_AFSEL_R      (*((volatile unsigned long*)0x4005C420))

#define GPIO_PORTA_AHB_PCTL_R       (*((volatile unsigned long*)0x4005852C))
#define GPIO_PORTD_AHB_PCTL_R       (*((volatile unsigned long*)0x4005B52C))
#define GPIO_PORTE_AHB_PCTL_R       (*((volatile unsigned long*)0x4005C52C))

#define GPIO_PORTA_AHB_DEN_R        (*((volatile unsigned long*)0x4005851C))
#define GPIO_PORTD_AHB_DEN_R        (*((volatile unsigned long*)0x4005B51C))
#define GPIO_PORTE_AHB_DEN_R        (*((volatile unsigned long*)0x4005C51C))
#define GPIO_PORTF_AHB_DEN_R        (*((volatile unsigned long*)0x4005D51C))

#define GPIO_PORTA_AHB_AMSEL_R      (*((volatile unsigned long*)0x40058528))
#define GPIO_PORTD_AHB_AMSEL_R      (*((volatile unsigned long*)0x4005B528))
#define GPIO_PORTE_AHB_AMSEL_R      (*((volatile unsigned long*)0x4005C528))

#define GPIO_PORTA_AHB_DIR_R        (*((volatile unsigned long*)0x40058400))
#define GPIO_PORTD_AHB_DIR_R        (*((volatile unsigned long*)0x4005B400))
#define GPIO_PORTE_AHB_DIR_R        (*((volatile unsigned long*)0x4005C400))
#define GPIO_PORTF_AHB_DIR_R        (*((volatile unsigned long*)0x4005D400))

#define GPIO_PORTA_AHB_DATA_R       (*((volatile unsigned long*)0x400583FC))
#define GPIO_PORTD_AHB_DATA_R       (*((volatile unsigned long*)0x4005B3FC))
#define GPIO_PORTE_AHB_DATA_R       (*((volatile unsigned long*)0x4005C3FC))
#define GPIO_PORTF_AHB_DATA_R       (*((volatile unsigned long*)0x4005D3FC))

#define GPIO_PORTA_AHB_DATA_BITS_R    ((volatile unsigned long*)0x40058000)
#define GPIO_PORTD_AHB_DATA_BITS_R    ((volatile unsigned long*)0x4005B000)
#define GPIO_PORTE_AHB_DATA_BITS_R    ((volatile unsigned long*)0x4005C000)
#define GPIO_PORTF_AHB_DATA_BITS_R    ((volatile unsigned long*)0x4005D000)

#define GPIO_PORTA_AHB_DATA_W_PA5   (*((volatile unsigned long*)(0x40058000 + PIN_PA5)))
#define GPIO_PORTA_AHB_DATA_W_PA6   (*((volatile unsigned long*)(0x40058000 + PIN_PA6)))
#define GPIO_PORTA_AHB_DATA_W_PA7   (*((volatile unsigned long*)(0x40058000 + PIN_PA7)))

#define GPIO_PORTD_AHB_DATA_W_PD1   (*((volatile unsigned long*)(0x4005B000 + PIN_PD1)))
#define GPIO_PORTD_AHB_DATA_W_PD2   (*((volatile unsigned long*)(0x4005B000 + PIN_PD2)))
#define GPIO_PORTD_AHB_DATA_W_PD3   (*((volatile unsigned long*)(0x4005B000 + PIN_PD3)))

#define GPIO_PORTE_AHB_DATA_R_PE1   (*((volatile unsigned long*)(0x4005C000 + PIN_PE1)))
#define GPIO_PORTE_AHB_DATA_R_PE2   (*((volatile unsigned long*)(0x4005C000 + PIN_PE2)))
#define GPIO_PORTE_AHB_DATA_R_PE3   (*((volatile unsigned long*)(0x4005C000 + PIN_PE3)))

//=========================================================================
/*
 *
 */
#define SYSCTL_GPIOHBCTL_R         (*((volatile unsigned long*)0x400FE06C))
#define SYSCTL_RCGCGPIO_R          (*((volatile unsigned long*)0x400FE608))
#define SYSCTL_RCGCTIMER_R         (*((volatile unsigned long*)0x400FE604))

//=========================================================================




/*  Useful macros / consts definition */
/* =================================================*/

/*  System  */
//System/clock.h
#define SYS_CLOCK     16000000U // 16 MHz
#define PIOSC_CLOCK    4000000U //  4 MHz



/*  Core  */
//Core/sched.h
/*  Available states of task  */
#define IDLE     0U
#define RUNNING  1U
#define PAUSED   2U
#define FINISHED 3U

/*  Task's priority  */
#define RED_ON            100U
#define RED_OFF_YELL_ON   101U
#define YELL_OFF_GREEN_ON 102U
#define GREEN_OFF_YELL_ON 103U
#define RESET             104U

#define ARRAY_SIZE 7U // change this val

//Core/handler/bsp.h
#define TRIGGER_0  0
#define TRIGGER_3  3U
#define TRIGGER_4  4U
#define TRIGGER_7  7U
#define FINISH_CYCLE  8U
#define PERIOD_LENGTH 8U
/*
*  as per color -> 3sec Red, 1sec Yellow, 3sec Green, 1sec Yellow
*/



/*  IO  */
//IO/led.h
#define LED_RED   (1U << 1)
#define LED_BLUE  (1U << 2)
#define LED_GREEN (1U << 3)

//IO/io.h
#define PORT_A  ((1U))
#define PORT_D  ((1U << 3))
#define PORT_E  ((1U << 4))

#define PIN_PA5 ((1U << 5))
#define PIN_PA6 ((1U << 6))
#define PIN_PA7 ((1U << 7))

#define PIN_PD1 ((1U << 1))
#define PIN_PD2 ((1U << 2))
#define PIN_PD3 ((1U << 3))
#define PIN_PE1 ((1U << 1))
#define PIN_PE2 ((1U << 2))
#define PIN_PE3 ((1U << 3))



//IO/button.h
#define GPIO_PORTF_SW1_EN (1U << 4)
#define GPIO_PORTF_SW2_EN (1U)


//app/trafficLights/pins.h
#define MAX_CARS 3U
#define SIDE_OX  1U
#define SIDE_OY  2U
#define SET_PIN  1U
#define UNSET_PIN 0


/*________________________________________________________________*/
//Extern variables
#include <stdint.h>
//app/trafficLights/main_app.c
extern uint8_t flag_side;
extern uint8_t run_once;
extern uint8_t NCycles;

extern uint8_t flag_task_prior;

//core/handler/bsp.c
extern uint8_t tick_counter;
/*********************************************************************/
#include "core/sched.h"
extern Task TL_OX[ARRAY_SIZE];
extern Task TL_OY[ARRAY_SIZE];


/*********************************************************************/


#endif //PROJECT_MACRO_H
