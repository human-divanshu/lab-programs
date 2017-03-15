#include <stdio.h>
#include "stack.h"

void emptystack()
{
	stacktop = -1;
}

void emptyvisited()
{
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
	int i, j;
	int same;
	for(ctr = 0; ctr < visitcount; ctr++) {
		same = 0;
		// check if the state has been visited here
		for(i = 0; i < 3; i++) {
			for(j = 0; j < 3; j++) {
				if(visited[ctr]->box[i][j] == s->box[i][j])
					same++;
			}
		}
		if(same == 9)
			return 1;
	}
	return 0;
}

void push(state* s)
{
	if(!isvisited(s)) {
		visited[visitcount++] = s;
		stack[++stacktop] = s;
	}
}

int isstackempty()
{
	return (stacktop == -1);
}