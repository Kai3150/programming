#include <stdio.h>
int main()
{
	int c, n, ten;
	float heikin, sum;n=0;
	sum = 0;
	while(1){
		printf("���_%d\n",n);
		c=scanf("%d",&ten);
		if ( c==EOF ) break;
		sum += ten;
		n++;
	}	
	heikin=sum/n;
	printf("�l����%d���v��%f ���ρ�%f\n",n,sum,heikin);
	return 0;
}