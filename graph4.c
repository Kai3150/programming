#include <stdio.h>
#include <math.h>

int nizi(int);
int main() {
	int i, j, n;
	
	for (i=-10; i<=10; i++) 
	{
		n=nizi(i);
		printf("%3d ",i);
		printf("%*s",n,"*");
		printf("\n");
		
	}
	
	return 0;
}


/* ƒOƒ‰ƒt‚ð•`‚­ŠÖ”*/

int nizi(int x) {
	return (20*sin(0.314*x)+20);
}