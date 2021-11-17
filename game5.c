#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

float rnd();

int main()
{
	int comp, k, you, ten;
	char x[2];
	static char move[4] = "gyp";

	printf("三桁の整数を入れよ ");
	scanf("%d", &k);

	while (k > 0)
	{
		rnd();
		k--;
	}

	while (1)
	{
		printf("new game start\n");
		ten = 0;

		while (printf("ジャンケン(g, y, p) "), scanf("%1s", x), abs(ten) != 2)
		{
			if (x[0] != move[0] && x[0] != move[1] && x[0] != move[2])
			{
				printf("タイプミス\n");
			}

				for (you = 0; you < 3; you++)
				{
					if (x[0] == move[you])
					{
						comp = rnd() * 3;
						printf("あなた = %s   サイコロ = %c\n", x, move[comp]);

						if (you == comp)
						{
							ten = 0;
							printf("あいこ: あなたの点は%dです\n", ten);
						}
						else if (you - comp == -1 || you - comp == 2)
						{
							if (ten == -1)
							{
								ten = 0;
							}
							ten++;
							printf("勝ち: あなたの点は%dです\n", ten);
						}
						else
						{
							if (ten == 1)
							{
								ten = 0;
							}
							ten--;
							printf("負け: あなたの点は%dです\n", ten);
						}
						printf("\n");
					}
				}

			if (ten == 2)
			{
				printf("あなたの勝ち");
				break;
			}
			else if (ten == -2)
			{
				printf("あなたの負け");
				break;
			}
		}
	}
	return 0;
}

float rnd()
{
	static unsigned long ix = 1643;
	long ia = 1664525;
	long ic = 37313;
	float r;
	ix = (ia * ix + ic) & LONG_MAX;
	r = ix / (float)(LONG_MAX);
	return r;
}
