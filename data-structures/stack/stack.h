#ifndef INTSTACK
#define INTSTACK 1

#define STACKSIZE 100

struct s {
	int arr[STACKSIZE];
	int top;
};
typedef struct s intstack;

void initstack(intstack *s);
void push(intstack *s, int item);
int pop(intstack *s);
int stackempty(intstack *s);

#endif