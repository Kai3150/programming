/* nizi2.c */
#include <stdio.h>
#include <math.h>
int main() {
	char mei[6];
	float a,b,c,x,x1,x2;
	double d;
	
	while(printf("式名a  b  c  "),scanf("%s%f%f%f",mei,&a,&b,&c)!=EOF)
	{
		if ( a==0 ) {
			printf("%s a が0です。\n",mei);
			continue;
		}
		d=b*b-4*a*c;
		if( d>0) {
			x1=(fabs((double)b)+sqrt(d))/(2*a);
			if ( b>0 ) x1 = -x1;
			x2=c/(a*x1);
			printf("%s x1=%f x2=%f\n",mei,x1,x2);
		}
		else if ( d== 0) {
			x = -b/(2*a);
			printf("%s 重解= %f\n",mei,x);
		}
		else printf("%s 実数解無し\n",mei);
	}
	return 0;
}