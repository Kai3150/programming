#include <stdio.h>

int nizi(int);
int main() {
	int i, j, n;
	
	for (i=-7; i<=7; i++) 
	{
		n=nizi(i);
		printf("%2d ",i);
		printf("%*s",n,"*");
		printf("\n");
		
	}
	
	return 0;
}


/* ƒOƒ‰ƒt‚ð•`‚­ŠÖ”*/

int nizi(int x) {
	return (x*x+4);
}