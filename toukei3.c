#include <stdio.h>
#define LOW -10
#define HIGH 110
int main()
{
	int max, ten, n, min;
	max = LOW;
	min = HIGH;
	n = 0;
	while(printf("���_\n"),scanf("%d",&ten)!=EOF){
		if (max < ten)max=ten;
		if (min > ten)min=ten;
		n++;
	}	
	printf("�ō��_ �� %d �Œ�_ �� %d �l�� �� %d\n",max,min,n);
	return 0;
}