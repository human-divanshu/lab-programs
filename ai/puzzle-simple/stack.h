#include "state.h"

#ifndef STATESTACK
#define STATESTACK 1

#define STACKSIZE 100000

state* stack[STACKSIZE];
int stacktop;

state* visited[STACKSIZE]; // to save states which have been visited
int visitcount; 

void initstack();
state* pop();
void push(state* s);
int isstackempty();
int isvisited(state *s);
void emptystack();
void emptyvisited();

#endif