#include <stdio.h>
#include <stdint.h>
#include "sched.h"
#include "handler/bsp.h"
#include "../macro.h"

uint8_t flag_task_prior;

Task* Select_Task(Task *task_array, uint8_t priority) {
    uint8_t volatile index = 0;
    for (; index < ARRAY_SIZE; index++) {
        if (task_array[index].priority == priority && task_array[index].exec_state == IDLE) {
            task_array[index].exec_state = RUNNING;
            return &task_array[index];
        }
    }
    return NULL;
}

void Exec_Task(Task *task_array) {
    Task* current_task = NULL;
    if(flag_task_prior == RESET) {
        current_task = Select_Task(task_array, RESET);
        Run_Task(current_task);
        Reset_Task_Array(task_array);
        return;
    } else {
        while(1){ // exec all tasks of same priority
            current_task = Select_Task(task_array, flag_task_prior);
            if(current_task == NULL || flag_task_prior == 0){
                return;
            } else {
                Run_Task(current_task);
            }
        }
    }
}


void Run_Task(Task *task){
    (task->func)();
    task->exec_state = FINISHED;
}

void Reset_Task_Array(Task *task_array){
    for(uint8_t volatile index = 0; index < ARRAY_SIZE; index++){
        task_array[index].exec_state = IDLE;
    }
}


void Get_Priority(void){
    //tick_counter
    switch(tick_counter) {
        case TRIGGER_0:
            //Red color ON
            flag_task_prior = RED_ON;
            break;

        case TRIGGER_3:
            //Red color OFF
            //Yellow color ON
            flag_task_prior = RED_OFF_YELL_ON;
            break;

        case TRIGGER_4:
            //Yellow color OFF
            //Green Color ON
            flag_task_prior = YELL_OFF_GREEN_ON;
            break;

        case TRIGGER_7:
            //Green Color OFF
            //Yellow Color ON
            flag_task_prior = GREEN_OFF_YELL_ON;
            break;

        case FINISH_CYCLE:
            //Yellow OFF
            //RESET
            flag_task_prior = RESET;
            break;

        default:
            flag_task_prior = 0;
            break;
    }
}



