#include <stdio.h>
#define LOW -10
int main()
{
	int max, ten;
	max = LOW;
	while(printf("���_\n"),scanf("%d",&ten)!=EOF){
		if (max < ten)max=ten;
	}	
	printf("�ō��_ �� %d\n",max);
	return 0;
}