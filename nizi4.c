/* nizi4.c */
#include <stdio.h>
#include <math.h>
int main() {
	float a,b,c,s,menseki;
	
	printf("a: ");
	scanf("%f",&a);
	
	printf("b: ");
	scanf("%f",&b);

	printf("c: ");
	scanf("%f",&c);
		
	if ((a+b>c && c>fabs((double)a-(double)b)) || (a+c>b && b>fabs((double)a-(double)c)) || (b+c>a && a>fabs((double)b-(double)c))){
		s=(a+b+c)/2;
		menseki = sqrt(s*(s-a)*(s-b)*(s-c));
		printf("–ÊÏ = %f",menseki);
	}
	else {
		printf("OŠpŒ`‚ª‚Å‚«‚È‚¢");
	}
	return 0;
	
}