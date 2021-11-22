/*sort5.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct kamoku
{
  char mei[20];
  char kana[10];
  int ei;
  int koku;
  int su;
  int sha;
  int ri;
  int goukei;
};
#define SIZE 30

int main()
{
  struct kamoku seiseki[SIZE], min;
  int i, j, n, m;
  FILE *input;
  char infname[16];
  printf("入力ファイル名：");
  scanf("%s", infname);

  if ((input = fopen(infname, "r")) == NULL)
  {
    printf("入力ファイルがありません\n");
    exit(1);
  }

  n = SIZE - 1;
  for (i = 0; i < SIZE; i++)
  {
    if (fscanf(input, "%s %s %d %d %d %d %d %d", seiseki[i].mei, seiseki[i].kana, &seiseki[i].ei, &seiseki[i].koku, &seiseki[i].su, &seiseki[i].sha, &seiseki[i].ri, &seiseki[i].goukei) == EOF)
    {
      n = i - 1;
      break;
    }
    if (seiseki[i].goukei < 300)
    {
      i--;
    }
  }

  for (i = 0; i <= n - 1; i++)
  {
    min = seiseki[i];
    m = i;
    for (j = i + 1; j <= n; j++)
    {
      if (strcmp(min.kana, seiseki[j].kana) > 0)
      {
        min = seiseki[j];
        m = j;
      }
    }
    seiseki[m] = seiseki[i];
    seiseki[i] = min;
  }
  printf("\t名前\t\tフリガナ\t英\t国\t数\t社\t理\t合計\n");
  for (i = 0; i <= n; i++)
  {
    printf("\t%-10s\t%-10s\t%d\t%d\t%d\t%d\t%d\t%d\n", seiseki[i].mei, seiseki[i].kana, seiseki[i].ei, seiseki[i].koku, seiseki[i].su, seiseki[i].sha, seiseki[i].ri, seiseki[i].goukei);
  }

  fclose(input);

  return 0;
}
