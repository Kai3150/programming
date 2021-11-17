#include <stdio.h>

int nizi(int);
int main() {
	int i, j, n;
	
	for (i=-10; i<=10; i++) 
	{
		n=nizi(i);
		printf("%3d ",i);
		for (j=1; j<=n; j++ ) printf("*");
		printf("\n");
		
	}
	
	return 0;
}


/* ƒOƒ‰ƒt‚ð•`‚­ŠÖ”*/

int nizi(int x) {
	if(-10 <= x && x <= 0)
	{
		return (4 * x + 60);
	}
	else if(0 <= x && x <= 10)
	{
		return (-4 * x + 60);
	}
}