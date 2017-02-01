#include <stdio.h>

#define PLACE(x) ((board[x]==0?' ':(board[x]==1)?'X':'O'))

// game board
int board[9] = {0,1,1,2,2,1,0,1,0};

// 0 - empty 
// 1 - X
// 2 - O


void printBoard() {
    printf("\n\n");
    printf("      |      |      \n");
    printf("   %c  |   %c  |  %c  \n", PLACE(0),  PLACE(1), PLACE(2);
    printf("      |      |      \n");
    printf("--------------------\n");
    printf("      |      |      \n");
    printf("   %c  |   %c  |  %c  \n", ((board[3] == 0) ? ' ' : (board[3]==1?'X':'O')),  ((board[4] == 0) ? ' ' : (board[4]==1?'X':'O')), ((board[5] == 0) ? ' ' : (board[5]==1?'X':'O')));
    printf("      |      |      \n");
    printf("--------------------\n");
    printf("      |      |      \n");
    printf("   %c  |   %c  |  %c  \n", ((board[6] == 0) ? ' ' : (board[6]==1?'X':'O')),  ((board[7] == 0) ? ' ' : (board[7]==1?'X':'O')), ((board[8] == 0) ? ' ' : (board[8]==1?'X':'O')));
    printf("      |      |      \n");    
    printf("\n\n");    
}

int main(void)
{
    int ctr;
    
    
    // init the board with zeros
 //   for(ctr = 0; ctr <= 9; ctr++)
   //     board[ctr] = 0;
 
    printBoard();
        
    return 0;
}
