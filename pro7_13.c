#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 20
#define STACK_EMPTY '@'

char s[STACK_SIZE];
int s_top = -1;

void push(char stack[], 		/* the stack */
		char item,               /* data being pushed onto the stack */
		int *top,				/* pointer to top of the stack */
		int max_size)			/* maximum size of stack */
{
	if (*top < max_size - 1) {
		++(*top);
		stack[*top] = item;
	}
}

char pop(char stack[], int *top)
{
	char item;   /* value poped off the stack */
	
	if (*top >= 0) {
		item = stack[*top];
		--(*top);
	} else {
		item = STACK_EMPTY;
	}
	return item;
}

char retrieve(char stack[], int *top)   /* 仅用来获取栈顶数据, 而不删除 */ 
{
	char item;   /* value poped off the stack */
	
	if (*top >= 0) {
		item = stack[*top];
	} else {
		item = STACK_EMPTY;
	}
	return item;
}

int main()
{
	push(s, '2', &s_top, STACK_SIZE);
	push(s, '+', &s_top, STACK_SIZE);
	push(s, 'C', &s_top, STACK_SIZE);
	printf("the poped item is : %c\n", pop(s, &s_top));
	printf("the poped item is : %c\n", pop(s, &s_top));
	printf("the poped item is : %c\n", pop(s, &s_top));
	printf("the poped item is : %c\n", pop(s, &s_top));
	
}
