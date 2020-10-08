#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * 出了一个小bug, 一开始diff = abs(NG - LG), 后来发现abs只接受int参数, 并返回int, 导致abs(2.5 - 1)的得数为1 . 
 */

double square_root(double N)
{
	double LG = 1.0;
	double NG;
	NG = 0.5 * (LG + N / LG);
	double diff = NG - LG;	
	
	while(diff > 0.005 || diff < -0.005) {
		LG = NG;
		NG = 0.5 * (LG + N / LG);
		diff = NG - LG;
	}
	
	return NG;
}

int main()
{
	double N = 10000;
	double sr = square_root(N);
	printf("The square root of %lf is %lf.\n", N, sr);
	
}

/*
	if (NG == LG)
	{
		return NG;
	} else {
		while(abs(NG-LG) >= 0.005) {
			LG = NG;
			NG = 0.5 * (LG + N / LG);
			if (NG == LG) {
				return NG;
			}
		}
	}
*/
