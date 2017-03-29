#include <stdio.h>
#include "stack.h"

void initstack(intstack *s)
{
	s->top = -1;
}

void push(intstack *s, int item)
{
	(s->top)++;
	s->arr[s->top] = item;
}

int pop(intstack *s)
{
	if(stackempty(s)) {
		printf("Underflow\n");
		return -1;
	} else {
		(s->top)--;
		return s->arr[s->top + 1];
	}
}

int stackempty(intstack *s)
{
	return (s->top == -1);
}