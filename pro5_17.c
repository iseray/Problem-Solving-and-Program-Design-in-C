#include <stdio.h>
#include <math.h>

/**
*   计算直线x=a和x=b之间的曲线 y=f(x) ,与x轴围起来的面积,
*   参数a,b为 截取曲线y的两条直线在x轴的交点
*   参数n为在a和b之间将曲线分成n份
*   参数f为函数指针 
*   求近似面积的一种方法是, 将曲线在a,b间分成n个近似梯形, n的值越大, 所分的梯形与实际曲线越贴合
*   算出所有梯形的面积和, 就是对实际面积的近似 
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
