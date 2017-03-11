#include <stdio.h>

#define VECTORSIZE 9

#define BLANK 2 // 2 represents blank space
#define SYM_X 3 // symbol for x - for human
#define SYM_O 5 // symbol for 0 - for cpu

#define POSWIN_X 18    // X can win in next move, human
#define POSWIN_O 50    // O can win in next move, cpu
#define WIN_X 27		// for human
#define WIN_O 125		// for cpu

#define PLAYERHUMAN 0
#define PLAYERCPU 1

#define PLACE(x) ((board[x]==BLANK)?' ':((board[x]==SYM_X)?'X':'O'))

// game board
int board[VECTORSIZE] = {2,2,2,2,2,2,2,2,2};
int turncount; // from 1 to 9, total moves in game
int playerturn; // 0 - human, 1 - computer

void print_board() {
    printf("\n\n");
    printf("      |      |      \n");
    printf("   %c  |   %c  |  %c  \n", PLACE(0),  PLACE(1), PLACE(2));
    printf("      |      |      \n");
    printf("--------------------\n");
    printf("      |      |      \n");
    printf("   %c  |   %c  |  %c  \n", PLACE(3),  PLACE(4), PLACE(5));
    printf("      |      |      \n");
    printf("--------------------\n");
    printf("      |      |      \n");
    printf("   %c  |   %c  |  %c  \n", PLACE(6),  PLACE(7), PLACE(8));
    printf("      |      |      \n");    
    printf("\n\n");   
}

int move2()
{
	if(board[4] == BLANK)	// if center blank then return center
		return 4;
	else {
		if(board[1] == BLANK)
			return 1;
		else if(board[3] == BLANK)
			return 3;
		else if(board[5] == BLANK)
			return 5;
		else
			return 7;
	}
}

int poswin(int player)
{
	if(player == PLAYERHUMAN) {
		if(board[0] * board[1] * board[2] == POSWIN_X)
			return ((board[0] == BLANK)? 0: (board[1] == BLANK)? 1 : 2);
			
		if(board[3] * board[4] * board[5] == POSWIN_X)
			return ((board[3] == BLANK)? 3: (board[4] == BLANK)? 4 : 5);
			
		if(board[6] * board[7] * board[8] == POSWIN_X)
			return ((board[6] == BLANK)? 6: (board[7] == BLANK)? 7 : 8);
			
		if(board[0] * board[3] * board[6] == POSWIN_X)
			return ((board[0] == BLANK)? 0: (board[3] == BLANK)? 3 : 6);
			
		if(board[1] * board[4] * board[7] == POSWIN_X)
			return ((board[1] == BLANK)? 1: (board[4] == BLANK)? 4 : 7);
			
		if(board[2] * board[5] * board[8] == POSWIN_X)
			return ((board[2] == BLANK)? 2: (board[5] == BLANK)? 5 : 8);
			
		if(board[0] * board[4] * board[8] == POSWIN_X)
			return ((board[0] == BLANK)? 0: (board[4] == BLANK)? 4 : 8);
			
		if(board[2] * board[4] * board[6] == POSWIN_X)
			return ((board[2] == BLANK)? 2: (board[4] == BLANK)? 4 : 6);																		
	} else {
		if(board[0] * board[1] * board[2] == POSWIN_O)
			return ((board[0] == BLANK)? 0: (board[1] == BLANK)? 1 : 2);
			
		if(board[3] * board[4] * board[5] == POSWIN_O)
			return ((board[3] == BLANK)? 3: (board[4] == BLANK)? 4 : 5);
			
		if(board[6] * board[7] * board[8] == POSWIN_O)
			return ((board[6] == BLANK)? 6: (board[7] == BLANK)? 7 : 8);
			
		if(board[0] * board[3] * board[6] == POSWIN_O)
			return ((board[0] == BLANK)? 0: (board[3] == BLANK)? 3 : 6);
			
		if(board[1] * board[4] * board[7] == POSWIN_O)
			return ((board[1] == BLANK)? 1: (board[4] == BLANK)? 4 : 7);
			
		if(board[2] * board[5] * board[8] == POSWIN_O)
			return ((board[2] == BLANK)? 2: (board[5] == BLANK)? 5 : 8);
			
		if(board[0] * board[4] * board[8] == POSWIN_O)
			return ((board[0] == BLANK)? 0: (board[4] == BLANK)? 4 : 8);
			
		if(board[2] * board[4] * board[6] == POSWIN_O)
			return ((board[2] == BLANK)? 2: (board[4] == BLANK)? 4 : 6);	
	}
	return -1;
}

int checkwin()
{
		if(board[0] * board[1] * board[2] == WIN_O)
			return PLAYERCPU;
			
		if(board[3] * board[4] * board[5] == WIN_O)
			return PLAYERCPU; 
			
		if(board[6] * board[7] * board[8] == WIN_O)
			return PLAYERCPU; 
			
		if(board[0] * board[3] * board[6] == WIN_O)
			return PLAYERCPU; 
			
		if(board[1] * board[4] * board[7] == WIN_O)
			return PLAYERCPU; 
			
		if(board[2] * board[5] * board[8] == WIN_O)
			return PLAYERCPU; 
			
		if(board[0] * board[4] * board[8] == WIN_O)
			return PLAYERCPU; 
			
		if(board[2] * board[4] * board[6] == WIN_O)
			return PLAYERCPU; 

		if(board[0] * board[1] * board[2] == WIN_X)
			return PLAYERHUMAN;
			
		if(board[3] * board[4] * board[5] == WIN_X)
			return PLAYERHUMAN; 
			
		if(board[6] * board[7] * board[8] == WIN_X)
			return PLAYERHUMAN; 
			
		if(board[0] * board[3] * board[6] == WIN_X)
			return PLAYERHUMAN; 
			
		if(board[1] * board[4] * board[7] == WIN_X)
			return PLAYERHUMAN; 
			
		if(board[2] * board[5] * board[8] == WIN_X)
			return PLAYERHUMAN; 
			
		if(board[0] * board[4] * board[8] == WIN_X)
			return PLAYERHUMAN; 
			
		if(board[2] * board[4] * board[6] == WIN_X)
			return PLAYERHUMAN; 
			
		return -1;
}


void go(int n)
{
	printf("Marking box : %d\n", n + 1); 
	if(playerturn == PLAYERHUMAN)
		board[n] = SYM_X;
	else
		board[n] = SYM_O;
}

int human_turn()
{
	int pos;
	
	printf("Human turn \n");
	do {
		printf("Enter a number (1 to 9) to mark your box :");
		scanf("%d", &pos);
	} while (board[pos - 1] != BLANK);	// given pos should be blank
	
	go(pos - 1);	// mark the given pos
	playerturn = PLAYERCPU;		// give turn to cpu
	turncount++;
}

int cpu_turn()
{
	int pos = -1;	// not possible position
	
	printf("CPU turn\n");
	pos = poswin(PLAYERCPU); // should return pos or -1
	
	if(pos != -1) {
		go(pos);	// mark the win position
	} else {
		pos = poswin(PLAYERHUMAN);
		
		if(pos != -1) {
			go(pos);	// counter the human win
		} else {
			pos = move2();
			go(pos);
		}
	}	
	playerturn = PLAYERHUMAN;	// give turn to human
	turncount++;
}


int main(void)
{
	turncount = 1; // set turn value to 1
	int win = -1;	// who has won, -1 = no one, else playercpu or playerhuman
	playerturn = PLAYERHUMAN;	// give first chance to human
	
	print_board();
	printf("First turn given to human\n");
		
	while(turncount <= 9) {
		if(playerturn == PLAYERHUMAN)
			human_turn();
		else
			cpu_turn();
		
		print_board();
		
		win = checkwin();
		
		if(win != -1) {
			if(win == PLAYERHUMAN)
				printf("HUMAN WINs\n");
			else
				printf("CPU WINS\n");
			break;
		}
	}
	
	if(win == -1 && turncount > 9)
		printf("GAME DRAW\n");
	
	
	return 0;
}
