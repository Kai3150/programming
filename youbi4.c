#include <stdio.h>
#include <stdlib.h>

long nday(int, int, int);

int main()
{
  int y, m, d, y2, d2, m2;
  long n, n2;

  while (printf("年月日"), scanf("%d%d%d", &y, &m, &d),
  printf("②年月日"), scanf("%d%d%d", &y2, &m2, &d2) != EOF)
  {
    n = nday(y, m, d);
    n2 = nday(y2, m2, d2);

    printf("間の日数 = %ld\n", labs(n2 - n));
  }
  return 0;
}

long nday(int iy, int im, int id)
{
  long ny, nm;
  ny = iy;
  nm = im;
  if (im <= 2)
  {
    ny--;
    nm += 12;
  }
  return (365 * ny + ny / 4 - ny / 100 + ny / 400 + 306 * (nm + 1) / 10 + id - 428);
}
