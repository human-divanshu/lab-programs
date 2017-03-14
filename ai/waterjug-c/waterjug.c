#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "state.h"
#include "stack.h"
#include "queue.h"
#define TRUE 1
#define FALSE 0
#define DFS 1
#define BFS 2

// Globals 
int jug1size;
int jug2size;
int finalwater;
int resultfound;
int algo;
state initial;


int min(int a, int b)
{
	return (a < b)? a : b;
}

void printstate(state *s)
{
	printf("[ %d , %d ]\n", s->j1, s->j2);
}

void backtrack(state *s)
{
	emptystack();	// empty the stack for backtracking
	state *temp;
	temp = s;
	while(temp != NULL) {
		push(temp);
		temp = temp->parent;
	}

	printf("Answer sequence is : \n");
	while(TRUE) {
		printstate(pop());

		if(isstackempty())
			break;
	}

}

// generate new states based on the
// given input states
void generatestates(state* s)
{
	state *new;
	int topour;

	// fill jug 1
	if(s->j1 < jug1size) {
		printf("Fill jug 1: ");
		new = (state*) malloc(sizeof(state));
		new->j1 = jug1size;
		new->j2 = s->j2;
		new->parent = s;
		printstate(new);
		(algo == DFS) ? push(new) : enqueue(new);
	}

	// fill jug 2
	if(s->j2 < jug2size) {
		printf("Fill jug 2: ");
		new = (state*) malloc(sizeof(state));
		new->j1 = s->j1;
		new->j2 = jug2size;
		new->parent = s;
		printstate(new);
		(algo == DFS) ? push(new) : enqueue(new);
	}

	// empty jug 1
	if(s->j1 > jug1size) {
		printf("Empty jug 1: ");
		new = (state*) malloc(sizeof(state));
		new->j1 = 0;
		new->j2 = s->j2;
		new->parent = s;
		printstate(new);
		(algo == DFS) ? push(new) : enqueue(new);
	}

	// empty jug 2
	if(s->j2 > jug2size) {
		printf("Empty jug 2: ");
		new = (state*) malloc(sizeof(state));
		new->j1 = s->j1;
		new->j2 = 0;
		new->parent = s;
		printstate(new);
		(algo == DFS) ? push(new) : enqueue(new);
	}

	// pour from jug 1 to jug 2
	if(s->j1 != 0 && s->j2 < jug2size) {
		printf("Pour from jug 1 to jug 2: ");
		topour = min(s->j1, jug2size - s->j2);
		new = (state*) malloc(sizeof(state));
		new->j1 = s->j1 - topour;
		new->j2 = s->j2 + topour;
		new->parent = s;
		printstate(new);
		(algo == DFS) ? push(new) : enqueue(new);
	}

	// pour from jug 2 to jug 1
	if(s->j2 != 0 && s->j1 < jug1size) {
		printf("Pour from jug 2 to jug 1: ");
		topour = min(s->j2, jug1size - s->j1);
		new = (state*) malloc(sizeof(state));
		new->j1 = s->j1 + topour;
		new->j2 = s->j2 - topour;
		new->parent = s;
		printstate(new);
		(algo == DFS) ? push(new) : enqueue(new);
	}
}


void dfs()
{
	state *temp;
	static int count = 1;
	
	temp = pop();
	printf("Processing state : ");
	printstate(temp);

	while(TRUE) {
		count++;

		if(!isfinalstate(temp)) {
			generatestates(temp);
		} else {
			printf("Final state found\n");
			resultfound = TRUE;
			printstate(temp);
			backtrack(temp);
			printf("\nTotal iterations is : %d\n", count);
			break;
		}

		if(!isstackempty()) {
			temp = pop();
			printf("Processing state : ");
			printstate(temp);
		} else {
			break;
		}
	}

	if(!resultfound) {
		printf("No solution exists for this problem\n");
	}
}

void bfs()
{
	state *temp;
	static int count = 1;
	
	temp = dequeue();
	printf("Processing state : ");
	printstate(temp);

	while(TRUE) {
		count++;

		if(!isfinalstate(temp)) {
			generatestates(temp);
		} else {
			printf("Final state found\n");
			resultfound = TRUE;
			printstate(temp);
			backtrack(temp);
			printf("\nTotal iterations is : %d\n", count);
			break;
		}

		if(!isqueueempty()) {
			temp = dequeue();
			printf("Processing state : ");
			printstate(temp);
		} else {
			break;
		}
	}

	if(!resultfound) {
		printf("No solution exists for this problem\n");
	}
}



int isfinalstate(state *s)
{
	return (s->j1 == finalwater || s->j2 == finalwater);
}

int main(void)
{
	int opt;
	resultfound = FALSE;

	initstack();
	initqueue();
	
	printf("Enter the size of the jug 1:");
	scanf("%d", &jug1size);

	printf("Enter the size of the jug 2:");
	scanf("%d", &jug2size);

	printf("Enter the water you want in final state:");
	scanf("%d", &finalwater);

	// set the initial state
	initial.j1 = 0;
	initial.j2 = 0;
	initial.parent = NULL;

	printf("Which algorithm do you want to you ? :\n1 - DFS\n2 - BFS\n:");
	scanf("%d", &opt);

	if(opt == 1) {
		push(&initial);
		algo = DFS;
		dfs();
	} else if (opt == 2) {
		enqueue(&initial);
		algo = BFS;
		bfs();
	} else {
		puts("Invalid input\n");
		exit(0);
	}

	return 0;
}