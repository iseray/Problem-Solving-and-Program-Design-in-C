#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int a, b;
	char op;
	printf("������������: \n");
	scanf("%c%d", &op, &b);
	printf("%c %d\n", op, b);
	while(1) {
		scanf("%c%d", &op, &b);
		printf("%c %d\n", op, b);
	}
}
