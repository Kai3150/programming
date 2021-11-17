#include <stdio.h>
#include <limits.h>

float rnd();

int main() 
{
	int c, dice1, dice2, k, c1, c2;
	char  x[2];
	static char move[3] = "th";
	
	printf("３桁の整数を入れよ");
	
	scanf("%d", &k);
	
	while ( k>0 ) 
	{
		rnd();
		k--;
	}
	
	while (printf("丁、半(t/h) "), scanf("%1s", x) != EOF) 
	{
		if ( x[0] == move[0] || x[0] == move[1] )
		 {
			dice1 = rnd()*6 + 1;
			dice2 = rnd()*6 + 1;
			
			c1 = dice1%2;
			c2 = dice2%2;
			c = (dice1 + dice2)%2;
			
			printf("貴方= %s   サイコロ1= %c (%d)   サイコロ2= %c (%d)\n", x, move[c1], dice1, move[c2], dice2);
			if ( x[0] == move[c] ) printf("貴方の勝ち\n");
			else printf("貴方の負け\n");
		}
		else printf("タイプミス\n");
	}
	return 0;
}

/* 乱数関数*/
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