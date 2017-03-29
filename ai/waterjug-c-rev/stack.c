#include <stdio.h>
#include "stack.h"

void emptystack()
{
	stacktop = -1;
	visitcount = 0;
}

void initstack()
{
	stacktop = -1;
	visitcount = 0;
}

state* pop()
{
	return stack[stacktop--];
}

int isvisited(state *s)
{
	int ctr;
	for(ctr = 0; ctr < visitcount; ctr++)
		if(s->j1 == visited[ctr]->j1 && s->j2 == visited[ctr]->j2)
			return 1;
	return 0;
}

void push(state* s)
{
	if(!isvisited(s)) {
		//printf("Pushing : [ %d , %d ]\n", s->j1, s->j2);
		visited[visitcount++] = s;
		stack[++stacktop] = s;
	}
}



int isstackempty()
{
	return (stacktop == -1);
}