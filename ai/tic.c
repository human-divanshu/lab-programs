#include <stdio.h>
#include <stdlib.h>

#define PLACE(x) ((board[x]==2)?' ':((board[x]==3)?'X':'O'))
#define EXPAND_ROW(x) ((board[x] == board[x+1]) && (board[x+1] == board[x+2]))
#define EXPAND_COL(x) ((board[x] == board[x+3]) && (board[x+3] == board[x+6]))

// game board
int board[9] = {2,2,2,2,2,2,2,2,2};
// 2 - empty 
// 3 - X
// 5 - O
int cpu_symbol;
int human_symbol;
int turn; // 0 for human's turn, 1 for cpu's turn
int turn_count = 1; // max value 9



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
    printf("Human symbol : %d\n", human_symbol);
    printf("CPU symbol : %d\n", cpu_symbol); 
}

void go(int n)
{
    printf("Marking box %d\n", n); 
    board[n] = (turn == 0) ? human_symbol : cpu_symbol;
}

int make_two()
{
    // if center is empty return it, else return any non-corner blank square
    if(board[4] == 2)
        return 4;
    else if(board[1] == 2)
        return 1;
    else if(board[3] == 2)
        return 3;
    else if(board[5] == 2)
        return 5;
    else if(board[7] == 2)
        return 7;
}

int win_pos(int key)
{
    int winning_pos = -1; // no winning position
    int win_value = (key == 3) ? 18 : 50;
    
    if(board[0] * board[1] * board[2] == win_value)
        return (board[0] == 2) ? 0 : ((board[1] == 2 ? 1 : 2));
        
    if(board[3] * board[4] * board[5] == win_value)
        return (board[3] == 2) ? 0 : ((board[4] == 2 ? 1 : 2));
        
    if(board[6] * board[7] * board[8] == win_value)
        return (board[6] == 2) ? 0 : ((board[7] == 2 ? 1 : 2));
        
    if(board[0] * board[3] * board[6] == win_value)
        return (board[0] == 2) ? 0 : ((board[3] == 2 ? 1 : 2));
        
    if(board[1] * board[4] * board[7] == win_value)
        return (board[1] == 2) ? 0 : ((board[4] == 2 ? 1 : 2));
        
    if(board[2] * board[5] * board[8] == win_value)
        return (board[2] == 2) ? 0 : ((board[5] == 2 ? 1 : 2));
        
    if(board[0] * board[4] * board[8] == win_value)
        return (board[0] == 2) ? 0 : ((board[4] == 2 ? 1 : 2));
        
    if(board[2] * board[4] * board[6] == win_value)
        return (board[2] == 2) ? 0 : ((board[4] == 2 ? 1 : 2));
    
}

int give_turn()
{
    int move;
    //0 for human, 1 for cpu
    printf("\nTurn count : %d\n", turn_count);
    if(turn == 0) {
        printf("Human's turn : Please choose a box to move (0 - 8):");
        scanf("%d", &move);
        go(move);
        turn = 1;
    } else {
        printf("Computer's turn : ");
        move = win_pos(cpu_symbol); // find if cpu can win in next move
        // if yes then move to win
        if(move != -1)
            go(move);
        else {
            // if move is -1 then check if cpu needs to block human
            move = win_pos(human_symbol);
            if(move != -1)
                go(move);
            else
                go(make_two());
        }
        turn = 0;
    }
}

int check_win()
{
    int win = -1;
    // return 0 - if human won, 1 - cpu won, -1 no one won
    if(EXPAND_ROW(0))
        win = board[0];
    else if(EXPAND_ROW(3))
        win = board[3];
    else if(EXPAND_ROW(6))
        win = board[6];
    else if(EXPAND_COL(0))
        win = board[0];
    else if(EXPAND_COL(1))
        win = board[1];
    else if(EXPAND_COL(2))
        win = board[2];
    else if((board[0] == board[4]) && (board[4] == board[8]))
        win = board[0];
    else if((board[2] == board[4]) && (board[4] == board[6]))
        win = board[2];
    return win;
}

int main(void)
{
    int temp;
    int winner = -1;
    
    do {
        system("clear");
        printf("Please choose your symbol:\nPress 1 for X\nPress 2 for 0\nPress 3 to exit\n:");
        scanf("%d", &temp);
           
        if(temp == 3) {
            printf("Exiting ...\n");
            exit(0);    
        }
            
        if(temp == 1) {
            // human chose X
            cpu_symbol = 3;
            human_symbol = 5;
            turn = 0; // first chance human
        } else {
            cpu_symbol = 5;
            human_symbol = 3;
            turn = 1; // first chance cpu
        }
        
        while(turn_count <= 9) {
            print_board();
            give_turn();
            // check win if turn_count > 4
            if(turn_count > 4) {
                winner = check_win(); // return 0 - if human won, 1 - cpu won, -1 no one won
                if(winner == 0) {
                    printf("\nHUMAN WON\n");
                    continue;
                } else if(winner == 1) {
                    printf("\nCOMPUTER WON\n");
                    continue;
                }
            }
            turn_count++;            
        }
        if(winner == -1) {
            printf("\nGAME DRAW\n");
        }
        
    } while(temp != 3);
    
        
    return 0;
}
