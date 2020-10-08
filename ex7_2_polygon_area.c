#include <stdio.h> 
#include <stdlib.h>
double xarray[20];
double yarray[20];

/* 接受一个文件指针, 两个数组, 和数组的最大长度 */ 
int get_corners(FILE *inp, double xarr[], double yarr[], int n)
{
	int input_status; /* 检验是否已经读到文件末尾 */ 
	double item;      /* 临时保存从文本文件读取的值 */ 
	int i = 0;
	int flag = 0;     /*  用于控制输入的数是填充到xarr还是yarr */ 
	
	input_status = fscanf(inp, "%lf", &item);         /* 如果读取成功会返回1, 表示读取了1个数据项, 否则返回负数(EOF) */ 
	while (input_status == 1) {
		if (flag == 0) {
			xarr[i] = item;	
			flag = 1;
		} else {
			yarr[i] = item;
			flag = 0;
			++i;              /* 每输入两个数, i加1  */ 
		}
		input_status = fscanf(inp, "%lf", &item);
	}
	return --i;  /* 返回实际填充数组的长度 */ 
} 

double polygon_area(double xarr[], double yarr[], int n)
{
	int i;
	double sum = 0;
	for (i =0; i < n-1; ++i) {
		sum += (xarr[i+1] + xarr[i]) * (yarr[i+1] - yarr[i]);
	} 
	return  0.5 * sum;
}

int main()
{
	FILE *inp = fopen("corners.txt", "r");
	int n = get_corners(inp, xarray, yarray, 20);  /* 返回输入的坐标数 */ 
	int i;
	for(i = 0; i < 7; ++i) {
		printf("%.2lf, %.2lf\n",xarray[i], yarray[i]);
	}
	double area = polygon_area(xarray, yarray, n);
	printf("the area is : %.2lf", area);
}
