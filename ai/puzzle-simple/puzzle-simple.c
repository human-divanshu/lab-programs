#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "stack.h"
#include "state.h"

state initial;
state final;

int isfinalstate(state *s)
{
	int i, j;
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			if(s->box[i][j] != final.box[i][j])
				return FALSE;
	return TRUE;
}


void printstate(state *s)
{
	int i, j;

	printf("\n");
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			printf(" %d ",(s->box[i][j]));
		}
		printf("\n");
	}
	printf("\n");
}

int manvalue(int value, int x, int y)
{
	//printf("Got %d with x as %d and y as %d\n", value, x, y);
	switch(value) {
		case 1:
				return abs(x - 0) + abs(y - 0);
		case 2:
				return abs(x - 1) + abs(y - 0);
		case 3:
				return abs(x - 2) + abs(y - 0);
		case 4:
				return abs(x - 2) + abs(y - 1);
		case 5:
				return abs(x - 2) + abs(y - 2);
		case 6:
				return abs(x - 1) + abs(y - 2);
		case 7:
				return abs(x - 0) + abs(y - 2);
		case 8:
				return abs(x - 0) + abs(y - 1);
		default:
			return 0;
	}
}

int misplace(state *s)
{
	int mis = 0;
	(s->box[0][0] != 1) ? mis++ : FALSE;
	(s->box[0][1] != 2) ? mis++ : FALSE;
	(s->box[0][2] != 3) ? mis++ : FALSE;
	(s->box[1][2] != 4) ? mis++ : FALSE;
	(s->box[2][2] != 5) ? mis++ : FALSE;
	(s->box[2][1] != 6) ? mis++ : FALSE;
	(s->box[2][0] != 7) ? mis++ : FALSE;
	(s->box[1][0] != 8) ? mis++ : FALSE;
	return mis;
}

int cost(state *s)
{
	int cost = 0;
	int temp;
	int i, j;
	for(i = 0; i < 3; i++) {
		for(j = 0; j < 3; j++) {
			cost = cost + manvalue(s->box[i][j], j, i);
		}
	}
	return cost + misplace(s);
}

void backtrack(state *s)
{

}

// find next state and push it onto the stack
int findnextstate(state *s)
{
	int posx, posy;
	int i, j;
	int val;
	int posfound = FALSE;
	state *new;
	int pushdone = FALSE;

	// find pos of blank
	for(i = 0; i < 3; i++) {
		if(posfound == TRUE)
			break;

		for(j = 0; j < 3; j++) {
			val = s->box[i][j];
			if(val == 0) {
				posx = i;
				posy = j;
				posfound = TRUE;
				break;
			}
		}
	}

	//printf("Position of blank is : %d %d\n", posx, posy);

	// move blank up
	if(posx > 0) {
		//printf("Moving blank up\n");
		new = (state*) malloc(sizeof(state));
		memcpy(new, s, sizeof(state));
		new->parent = s;
		new->box[posx][posy] = new->box[posx - 1][posy];
		new->box[posx - 1][posy] = 0;
		//printstate(new);
		new->cost = cost(new);
		
		printf("Moving blank up\n");
		printstate(new);
		push(new);

	}

	// move blank down
	if(posx < 2) {
		//printf("Moving blank down\n");
		new = (state*) malloc(sizeof(state));
		memcpy(new, s, sizeof(state));
		new->parent = s;
		new->box[posx][posy] = new->box[posx + 1][posy];
		new->box[posx + 1][posy] = 0;
		//printstate(new);
		new->cost = cost(new);		
		printf("Moving blank down\n");
		printstate(new);
		push(new);
		
	}

	// move blank left
	if(posy > 0) {
		//printf("Moving blank left\n");
		new = (state*) malloc(sizeof(state));
		memcpy(new, s, sizeof(state));
		new->parent = s;
		new->box[posx][posy] = new->box[posx][posy - 1];
		new->box[posx][posy - 1] = 0;
		//printstate(new);
		new->cost = cost(new);	
		printf("Moving blank left\n");
		printstate(new);
		push(new);
	}

	// move blank right
	if(posy < 2) {
		//printf("Moving blank right\n");
		new = (state*) malloc(sizeof(state));
		memcpy(new, s, sizeof(state));
		new->parent = s;
		new->box[posx][posy] = new->box[posx][posy + 1];
		new->box[posx][posy + 1] = 0;
		//printstate(new);
		new->cost = cost(new);	

		printf("Moving blank right\n");
		printstate(new);
		push(new);			
	}

}

void search()
{
	state *temp;
	static int count = 0;

	temp = pop();

	printstate(temp);

	while(TRUE) {
		count++;

		if(!isfinalstate(temp)) {
			findnextstate(temp);
		} else {
			printf("Final state found\n");
			//backtrack(temp);
			printf("Total iterations are : %d\n", count);
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
}

int main(void)
{
	int i, j;
	initstack();

	// set final state
	final.box[0][0] = 1; final.box[0][1] = 2; final.box[0][2] = 3; final.box[1][0] = 8; final.box[1][1] = 0; 
	final.box[1][2] = 4; final.box[2][0] = 7; final.box[2][1] = 6; final.box[2][2] = 5;

	// set initial state
	printf("Enter the initial state for the board (use 0 for blank) : ");
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			scanf("%d", &(initial.box[i][j]));
	initial.cost = cost(&initial);
	initial.parent = NULL;

	printf("Searching for solutions :");

	push(&initial);
	
//	printf("Check isvisited : %d\n", isvisited(&initial));
//	printf("Check isvisited : %d\n", isvisited(&final));
	search();

	return 0;
}