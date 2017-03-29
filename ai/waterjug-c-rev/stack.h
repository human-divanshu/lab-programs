#include "state.h"

#ifndef STATESTACK
#define STATESTACK 1

#define STACKSIZE 100

state* stack[STACKSIZE];
state* visited[STACKSIZE]; // to save states which have been visited

int stacktop;
int visitcount;

void initstack();
state* pop();
void push(state* s);
int isstackempty();
int isvisited(state *s);
void emptystack();

#endif