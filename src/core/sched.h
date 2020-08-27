#ifndef PROJECT_SCHED_H
#define PROJECT_SCHED_H

#include <stdint.h>

//Change the function type for different input
typedef void (Function)(void);

typedef struct _Task
{
    uint8_t priority;
    Function *func;
    uint8_t exec_state;
}Task;

Task* Select_Task(Task *task_array, uint8_t priority);

void Run_Task(Task *task);

void Exec_Task(Task *task_array);

void Get_Priority(void);

void Reset_Task_Array(Task *task_array);

#endif //PROJECT_SCHED_H
