#include <stdio.h>
#include <limits.h>

float rnd();

int main() 
{
	int c, dice, k;
	char  x[2];
	static char move[3] = "th";
	
	printf("�R���̐���������");
	
	scanf("%d", &k);
	
	while ( k>0 ) 
	{
		rnd();
		k--;
	}
	
	while (printf("���A��(t/h) "), scanf("%1s", x) != EOF) 
	{
		if ( x[0] == move[0] || x[0] == move[1] )
		 {
			dice = rnd()*6 + 1;
			c = dice%2;
			printf("�M��= %s   �T�C�R��= %c (%d)\n", x, move[c], dice);
			if ( x[0] == move[c] ) printf("�M���̏���\n");
			else printf("�M���̕���\n");
		}
		else printf("�^�C�v�~�X\n");
	}
	return 0;
}

/* �����֐�*/
float rnd() 
{
	static unsigned long ix = 1643;
	long ia = 1664525;
	long ic = 37313;
	float r;
	ix = (ia * ix + ic)&LONG_MAX;
	r = ix / (float)(LONG_MAX);
	return r;
}