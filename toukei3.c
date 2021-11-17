#include <stdio.h>
#define LOW -10
#define HIGH 110
int main()
{
	int max, ten, n, min;
	max = LOW;
	min = HIGH;
	n = 0;
	while(printf("得点\n"),scanf("%d",&ten)!=EOF){
		if (max < ten)max=ten;
		if (min > ten)min=ten;
		n++;
	}	
	printf("最高点 ＝ %d 最低点 ＝ %d 人数 ＝ %d\n",max,min,n);
	return 0;
}