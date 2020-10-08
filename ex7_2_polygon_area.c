#include <stdio.h> 
#include <stdlib.h>
double xarray[20];
double yarray[20];

/* ����һ���ļ�ָ��, ��������, ���������󳤶� */ 
int get_corners(FILE *inp, double xarr[], double yarr[], int n)
{
	int input_status; /* �����Ƿ��Ѿ������ļ�ĩβ */ 
	double item;      /* ��ʱ������ı��ļ���ȡ��ֵ */ 
	int i = 0;
	int flag = 0;     /*  ���ڿ��������������䵽xarr����yarr */ 
	
	input_status = fscanf(inp, "%lf", &item);         /* �����ȡ�ɹ��᷵��1, ��ʾ��ȡ��1��������, ���򷵻ظ���(EOF) */ 
	while (input_status == 1) {
		if (flag == 0) {
			xarr[i] = item;	
			flag = 1;
		} else {
			yarr[i] = item;
			flag = 0;
			++i;              /* ÿ����������, i��1  */ 
		}
		input_status = fscanf(inp, "%lf", &item);
	}
	return --i;  /* ����ʵ���������ĳ��� */ 
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
	int n = get_corners(inp, xarray, yarray, 20);  /* ��������������� */ 
	int i;
	for(i = 0; i < 7; ++i) {
		printf("%.2lf, %.2lf\n",xarray[i], yarray[i]);
	}
	double area = polygon_area(xarray, yarray, n);
	printf("the area is : %.2lf", area);
}
