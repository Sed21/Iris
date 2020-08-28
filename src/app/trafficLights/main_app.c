#include <stdint.h>
#include "main_app.h"
#include "functionality.h"
#include "pins.h"
#include "../../io/io.h"
#include "../../system/clock.h"
#include "../../core/sched.h"

//Global var
uint8_t cars[2] = {0 , 0};

//Extern vars
uint8_t flag_side;
uint8_t run_once;
uint8_t NCycles;

Task TL_OX[ARRAY_SIZE] = {
        {RED_ON , Turn_ON_RED_OX, IDLE},
        {RED_OFF_YELL_ON , Turn_OFF_RED_OX, IDLE},
        {RED_OFF_YELL_ON , Turn_ON_YELLOW_OX, IDLE},
        //{YELL_OFF_GREEN_ON, Turn_ON_RED_OY, IDLE }, // optional
        {YELL_OFF_GREEN_ON, Turn_OFF_YELLOW_OX, IDLE},
        {YELL_OFF_GREEN_ON, Turn_ON_GREEN_OX, IDLE},
        {GREEN_OFF_YELL_ON, Turn_OFF_GREEN_OX, IDLE},
        {RESET, Reset_OX ,IDLE}
} ;
Task TL_OY[ARRAY_SIZE] = {
        {RED_ON , Turn_ON_RED_OY, IDLE},
        {RED_OFF_YELL_ON , Turn_OFF_RED_OY, IDLE},
        {RED_OFF_YELL_ON , Turn_ON_YELLOW_OY, IDLE},
        //{YELL_OFF_GREEN_ON, Turn_ON_RED_OX, IDLE }, // optional
        {YELL_OFF_GREEN_ON, Turn_OFF_YELLOW_OY, IDLE},
        {YELL_OFF_GREEN_ON, Turn_ON_GREEN_OY, IDLE},
        {GREEN_OFF_YELL_ON, Turn_OFF_GREEN_OY, IDLE},
        {RESET, Reset_OY ,IDLE}
};


void main_app(void){
    INIT_IO();
    Read_Input(cars);
    Await();

    if(cars[0] == 1 && cars[1] == 0){
        flag_side = SIDE_OX;
        run_once = 1;
        Exec_Task(TL_OX);
    } else if(cars[1] == 1 && cars[0] == 0){
        flag_side = SIDE_OY;
        run_once = 1;
        Exec_Task(TL_OY);
    } else {
        NCycles = cars[0] + cars[1]; // last car
        run_once = 0;

        //NCycles decrements in bsp.c
        while(NCycles != 0){
            Timer(1000);
            if(NCycles % 2 == 0) {
                flag_side = SIDE_OX;
                Exec_Task(TL_OX);
            } else {
                flag_side = SIDE_OY;
                Exec_Task(TL_OY);
            }
        }
    }
}

