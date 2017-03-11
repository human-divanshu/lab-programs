#include <stdio.h>
#include <math.h>



// global varibales
int jug1size;
int jug2size;
int finalwater;

/*
	Function to check if any state is final state
*/
int checkfinastate(state s)
{
	return (s.jug1 == finalwater || s.jug2 == finalwater);
}

int generatestates(int stateid)
{
	int j1 = stateid / (jug2size + 1);
	int j2 = stateid % (jug2size + 1);
	int newj1, newj2;
	int topour;
	
	// empty jug 1 if jug 1 has water
	if(j1 > 0) {
		newj1 = 0;
		newj2 = j2;
		
	}
	
	// empty jug 2 if jug 2 has water
	if(j2 > 0) {
		newj2 = 0;
		newj1 = j1;
	}
	
	// pour jug 1 into jug 2, jitna possible
	topour = min(
	
	
	// pour jug 2 into jug 1 jitna possible
	
	// fill jug 1 if not full
	
	// fill jug 2 if not full
	
	
}


