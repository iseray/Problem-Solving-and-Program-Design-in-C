#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* һ��ʼһ��bug�����˺þ�, ��¼����, 
 * ����scanf���������� "%c%lf", ������ " %c%lf", �������ֶ�ȡchar�ַ�ʱ���ֻ���
 * scanf�Ὣ��һ��Ϊ������Ļس�����ȡ��char�ַ���, ��һ���ո�Ὣ�س������Ե�
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
