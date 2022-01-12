#include <stdio.h>
#include <math.h>

double f(double);
double df(double);
double newton(double(*)(double), double(*)(double), double);
static double a, b;

int main(){
	printf("a:");
	scanf("%lf", &a);
	printf("b:");
	scanf("%lf", &b);
	printf("%f.\n", newton(f, df, 3.0));
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
	return exp(a*x) - b*x;
}

double df(double x){
	return a * exp(a*x) - b;
}