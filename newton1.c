#include <stdio.h>
double f(double, double);
double df(double);
int main(){
	double a, x0, x1, e = 10.0;
	printf("input non-negative number:");
	scanf("%lf", &a);x0 = a;
	while((e < -0.001) || (e > 0.001)){
		x1 = x0 -f(x0, a) / df(x0);
		e = x1 -x0;
		x0 = x1;
	}
	printf("square root of %f is %f.\n", a, x1);
}

double f(double x, double a){
	return x * x -a;
}

double df(double x){
	return 2 * x;
}