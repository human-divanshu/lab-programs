#include "state.h"

#ifndef STATEQUEUE
#define STATEQUEUE 1

#define QUEUESIZE 100

state* queue[QUEUESIZE];
int queuefront;
int queuerear;

void initqueue();
state* dequeue();
void enqueue(state* s);
int isqueueempty();

#endif