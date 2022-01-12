#include <stdio.h>
double f(double);
double df(double);
double newton(double(*)(double), double(*)(double), double);
static double a;

int main(){
	printf("input non-negative number:");
	scanf("%lf", &a);printf("cube root of %f is %f.\n", a, newton(f, df, a));
}

double newton(double(*pf)(double), double(*pdf)(double), double app){
	double x0, x1, e;
	e = 10.0;
	x0 = app;
	while((e < -0.001) || (e > 0.001)){
		x1 = x0 -pf(x0) / pdf(x0);
		e = x1 -x0;
		x0 = x1;
	}
	return x1;
}

double f(double x){
	return x * x * x -a;
}

double df(double x){
	return 3 * x * x;
}