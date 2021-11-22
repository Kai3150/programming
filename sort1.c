/* sort1.c */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 30

int main()
{
  int syu[SIZE];
  int i, j, m, n, max;
  n = SIZE - 1;
  for (i = 0; i < SIZE; i++)
  {
    printf("収入");
    if (scanf("%d", &syu[i]) == EOF)
    {
      n = i - 1;
      break;
    }
  }

  for (i = 0; i <= n - 1; i++)
  {
    max = syu[i];
    m = i;
    for (j = i + 1; j <= n; j++)
    {
      if (max < syu[j])
      {
        max = syu[j];
        m = j;
      }
    }
    syu[m] = syu[i];
    syu[i] = max;
  }
  printf("\n整列の結果\n");
  for (i = 0; i <= n; i++)
  {
    printf("%d\n", syu[i]);
  }
}
