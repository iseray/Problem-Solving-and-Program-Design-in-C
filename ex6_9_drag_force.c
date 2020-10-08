#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 计算汽车的空气阻力, 参数:阻力系数    汽车受力的投影面积   气体密度    速度 */
double drag_force(double drag_coefficient, double area, double density, double V)
{
	/*  F = 1/2 * CD * A * ρ* V^2 */
	double F = 1.0/2 * drag_coefficient * area * density * V * V;
	return F;
}

int main()
{
	double A, CD;
	double density = 1.23;
	double F;
	printf("Please input the projected area of the vehicle perpendicular to the velocity vector (in m2) \n ");
	printf(" and input the drag coefficient(0.2~0.5), seperate by a blank > ");
	scanf("%lf%lf", &A, &CD);
	/*printf("%lf %lf", A, CD); */
	
	double V = 0.0;
	for (V = 0.0; V <= 40.0; V += 5.0) {
		F = drag_force(CD, A, density, V);
		printf("%lf\t\t%lf\n", V, F);
	}
}
