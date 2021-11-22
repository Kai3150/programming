/*sort5.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30

int main()
{
  char mei[20];
  char kana[10];
  int ei;
  int koku;
  int su;
  int sha;
  int ri;
  int goukei;

  int i, j, n, m;
  FILE *input, *output;
  char infname[16], outfname[16];

  printf("入力ファイル名：");
  // scanf("%s", infname);
  strcpy(infname, "seiseki.d");

  if ((input = fopen(infname, "r")) == NULL)
  {
    printf("入力ファイルがありません\n");
    exit(1);
  }
  n = SIZE - 1;
  for (i = 0; i < SIZE; i++)
  {

    if (fscanf(input, "%s %s %d %d %d %d %d", mei, kana, &ei, &koku, &su, &sha, &ri) == EOF)
    {
      goukei = ei + koku + su + sha + ri;
      n = i - 1;
      break;
    }
    printf("%s, %s, %d, %d, %d, %d, %d, %3d\n", mei, kana, ei, koku, su, sha, ri, goukei);
  }
  fclose(input);

  return 0;
}
