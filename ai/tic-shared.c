#include <stdio.h>

int board[9] = {2,2,2,2,2,2,2,2,2};
int turncount;
int playerturn;

void print_board() {
    printf("\n\n");
    printf("      |      |      \n");
    printf("   %c  |   %c  |  %c  \n", ((board[0]==2)?' ':((board[0]==3)?'X':'O')), ((board[1]==2)?' ':((board[1]==3)?'X':'O')), ((board[2]==2)?' ':((board[2]==3)?'X':'O')));
    printf("      |      |      \n");
    printf("--------------------\n");
    printf("      |      |      \n");
    printf("   %c  |   %c  |  %c  \n", ((board[3]==2)?' ':((board[3]==3)?'X':'O')), ((board[4]==2)?' ':((board[4]==3)?'X':'O')), ((board[5]==2)?' ':((board[5]==3)?'X':'O')));
    printf("      |      |      \n");
    printf("--------------------\n");
    printf("      |      |      \n");
    printf("   %c  |   %c  |  %c  \n", ((board[6]==2)?' ':((board[6]==3)?'X':'O')), ((board[7]==2)?' ':((board[7]==3)?'X':'O')), ((board[8]==2)?' ':((board[8]==3)?'X':'O')));
    printf("      |      |      \n");
    printf("\n\n");
}

int move2()
{
 if(board[4] == 2)
  return 4;
 else {
  if(board[1] == 2)
   return 1;
  else if(board[3] == 2)
   return 3;
  else if(board[5] == 2)
   return 5;
  else
   return 7;
 }
}

int poswin(int player)
{
 if(player == 0) {
  if(board[0] * board[1] * board[2] == 18)
   return ((board[0] == 2)? 0: (board[1] == 2)? 1 : 2);

  if(board[3] * board[4] * board[5] == 18)
   return ((board[3] == 2)? 3: (board[4] == 2)? 4 : 5);

  if(board[6] * board[7] * board[8] == 18)
   return ((board[6] == 2)? 6: (board[7] == 2)? 7 : 8);

  if(board[0] * board[3] * board[6] == 18)
   return ((board[0] == 2)? 0: (board[3] == 2)? 3 : 6);

  if(board[1] * board[4] * board[7] == 18)
   return ((board[1] == 2)? 1: (board[4] == 2)? 4 : 7);

  if(board[2] * board[5] * board[8] == 18)
   return ((board[2] == 2)? 2: (board[5] == 2)? 5 : 8);

  if(board[0] * board[4] * board[8] == 18)
   return ((board[0] == 2)? 0: (board[4] == 2)? 4 : 8);

  if(board[2] * board[4] * board[6] == 18)
   return ((board[2] == 2)? 2: (board[4] == 2)? 4 : 6);
 } else {
  if(board[0] * board[1] * board[2] == 50)
   return ((board[0] == 2)? 0: (board[1] == 2)? 1 : 2);

  if(board[3] * board[4] * board[5] == 50)
   return ((board[3] == 2)? 3: (board[4] == 2)? 4 : 5);

  if(board[6] * board[7] * board[8] == 50)
   return ((board[6] == 2)? 6: (board[7] == 2)? 7 : 8);

  if(board[0] * board[3] * board[6] == 50)
   return ((board[0] == 2)? 0: (board[3] == 2)? 3 : 6);

  if(board[1] * board[4] * board[7] == 50)
   return ((board[1] == 2)? 1: (board[4] == 2)? 4 : 7);

  if(board[2] * board[5] * board[8] == 50)
   return ((board[2] == 2)? 2: (board[5] == 2)? 5 : 8);

  if(board[0] * board[4] * board[8] == 50)
   return ((board[0] == 2)? 0: (board[4] == 2)? 4 : 8);

  if(board[2] * board[4] * board[6] == 50)
   return ((board[2] == 2)? 2: (board[4] == 2)? 4 : 6);
 }
 return -1;
}

int checkwin()
{
  if(board[0] * board[1] * board[2] == 125)
   return 1;

  if(board[3] * board[4] * board[5] == 125)
   return 1;

  if(board[6] * board[7] * board[8] == 125)
   return 1;

  if(board[0] * board[3] * board[6] == 125)
   return 1;

  if(board[1] * board[4] * board[7] == 125)
   return 1;

  if(board[2] * board[5] * board[8] == 125)
   return 1;

  if(board[0] * board[4] * board[8] == 125)
   return 1;

  if(board[2] * board[4] * board[6] == 125)
   return 1;

  if(board[0] * board[1] * board[2] == 27)
   return 0;

  if(board[3] * board[4] * board[5] == 27)
   return 0;

  if(board[6] * board[7] * board[8] == 27)
   return 0;

  if(board[0] * board[3] * board[6] == 27)
   return 0;

  if(board[1] * board[4] * board[7] == 27)
   return 0;

  if(board[2] * board[5] * board[8] == 27)
   return 0;

  if(board[0] * board[4] * board[8] == 27)
   return 0;

  if(board[2] * board[4] * board[6] == 27)
   return 0;

  return -1;
}


void go(int n)
{
 printf("Marking box : %d\n", n + 1);
 if(playerturn == 0)
  board[n] = 3;
 else
  board[n] = 5;
}

int human_turn()
{
 int pos;

 printf("Human turn \n");
 do {
  printf("Enter a number (1 to 9) to mark your box :");
  scanf("%d", &pos);
 } while (board[pos - 1] != 2);

 go(pos - 1);
 playerturn = 1;
 turncount++;
}

int cpu_turn()
{
 int pos = -1;

 printf("CPU turn\n");
 pos = poswin(1);

 if(pos != -1) {
  go(pos);
 } else {
  pos = poswin(0);

  if(pos != -1) {
   go(pos);
  } else {
   pos = move2();
   go(pos);
  }
 }
 playerturn = 0;
 turncount++;
}


int main(void)
{
 turncount = 1;
 int win = -1;
 playerturn = 0;

 print_board();
 printf("First turn given to human\n");

 while(turncount <= 9) {
  if(playerturn == 0)
   human_turn();
  else
   cpu_turn();

  print_board();

  win = checkwin();

  if(win != -1) {
   if(win == 0)
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
