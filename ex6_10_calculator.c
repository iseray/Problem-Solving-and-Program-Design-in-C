#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* 一开始一个bug调试了好久, 记录下来, 
 * 这里scanf函数不能用 "%c%lf", 而是用 " %c%lf", 否则会出现读取char字符时出现混乱
 * scanf会将第一次为了输入的回车键读取到char字符中, 加一个空格会将回车键忽略掉
 */ 
void scan_data(char *operator, double *operand)
{
	//printf("Please input a operator followed by a number. eg: + 5.0 \n");
	scanf(" %c%lf", operator, operand);
	
}

void do_next_op(char *operator, double *operand, double *result)
{
	switch(*operator) {
		case '+': *result += *operand; break;
		case '-': *result -= *operand; break;
		case '*': *result *= *operand; break;
		case '/': *result /= *operand; break;
		case '^': *result = pow(*result, *operand); break;
		case 'q':  break;
	}
}

int main()
{
	double result = 0;
	double num;
	char op;
	
	scan_data(&op, &num);
	while (op != 'q') {
	//printf("%c %lf", op, num);
	do_next_op(&op, &num, &result);
	printf("Result so far is %lf \n", result);
	scan_data(&op, &num);	
	} 
	printf("final result is %lf\n", result);
	
} 
