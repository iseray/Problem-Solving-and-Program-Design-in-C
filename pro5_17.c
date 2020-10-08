#include <stdio.h>
#include <math.h>

/**
*   ����ֱ��x=a��x=b֮������� y=f(x) ,��x��Χ���������,
*   ����a,bΪ ��ȡ����y������ֱ����x��Ľ���
*   ����nΪ��a��b֮�佫���߷ֳ�n��
*   ����fΪ����ָ�� 
*   ����������һ�ַ�����, ��������a,b��ֳ�n����������, n��ֵԽ��, ���ֵ�������ʵ������Խ����
*   ����������ε������, ���Ƕ�ʵ������Ľ��� 
**/

double trap(double a, double b, int n, double f(double farg))
{
	double h = (b -a)/n;
	double sum = 0.0;
	for (int i = 0; i < n; i++)
	{
		sum += f(a + h*i);
	}
	
	return  h * (f(a) + f(b) + 2 * sum) / 2;
}

double g(double x) {
	return pow(x, 2) * sin(x);
}

double h(double x) {
	return sqrt(4 - pow(x, 2));
}


int main()
{
	double a = 1.5;
	
	
	double T = trap(0, 3.14159, 128, g);
	
	printf("the result is: %f \n", T);
	
//	printf("the result is: %f \n", g(a));
//	printf("the result is: %f \n", h(a));
	return 0;
}
