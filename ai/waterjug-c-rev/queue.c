#include <stdio.h>
#include "queue.h"
#include "stack.h"

void initqueue()
{
	queuefront = -1;
	queuerear = -1;
}

state* dequeue()
{
	return queue[++queuefront];
}

void enqueue(state* s)
{
	if(!isvisited(s)) {
		// printf("Insert into queue : [ %d , %d ]\n", s->j1, s->j2);
		visited[visitcount++] = s;
		queue[++queuerear] = s;
	}	
}

int isqueueempty()
{
	return (queuefront == queuerear);
}