#include <stdio.h>
#include <limits.h>
float rnd();

int main() 
{
	int comp, k, you;
	char  x[2];
	static char move[4] = "gyp";
	
	printf("３桁の整数を入れよ");
	scanf("%d", &k);
	
	while ( k>0 ) 
	{
		rnd();
		k--;
	}
	while (printf("ジャンケン(g, y, p) "), scanf("%1s", x) != EOF) 
	{
		for ( you = 0; you < 3; you ++) 
		{
			if ( x[0] == move[you] ) 
			{
				comp = rnd()*3;
				printf("貴方= %s   サイコロ= %c\n", x, move[comp]);
				if ( you == comp ) printf("あいこでしょ\n");
				else if ( you-comp == -1 || you-comp == 2 )printf("貴方の勝ち\n");
				else printf("貴方の負け\n");
				break;
			}
		}
		if ( you >= 3 ) printf("タイプミス\n");
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