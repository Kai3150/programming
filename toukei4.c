#include <stdio.h>
#define YUU 80
#define FUKA 60

int main()
{
	int ten, n, yuu, fuka;

	yuu = 0;
	fuka = 0;

	while(printf("特典\n"),scanf("%d",&ten)!=EOF){
		if (ten >= YUU)yuu++;
		if (ten < FUKA)fuka++;
		n++;
	}
	printf("優 %d 不可 %d\n",yuu,fuka);
	return 0;
}
