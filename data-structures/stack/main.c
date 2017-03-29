#include <stdio.h>
#include "stack.h"

int main(void)
{
	intstack s1;
	initstack(&s1);

	push(&s1, 10);
	push(&s1, 20);
	push(&s1, 30);

	printf("Pop : %d\n", pop(&s1));
	printf("Pop : %d\n", pop(&s1));
	printf("Pop : %d\n", pop(&s1));
	printf("Pop : %d\n", pop(&s1));
	return 0;
}