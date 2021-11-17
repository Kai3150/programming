#include <stdio.h>
#include <stdlib.h>

long nday(int, int, int);
int leap(int);

int main()
{
  int y, m, d, y2, d2, m2, days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
  long n, n2, days_3m;
  float r, b, risoku;

  while (printf("\n日歩: "), scanf("%f", &r),
         printf("何万円: "), scanf("%f", &b),
         printf("年月日"), scanf("%d%d%d", &y, &m, &d) != EOF)
  {
    m2 = (m + 3) % 12;

    if (m < m2) {
      y2 = y;
    }
    else
    {
      y2 = y + 1;
    }

    if (leap(y2)) {
      days[1] = 29;
    }
    d2 = days[m2 - 1];

    n = nday(y, m, d);
    n2 = nday(y2, m2, d2);
    days_3m = labs(n2 - n);
    printf("3ヶ月日数 = %ld\n", days_3m);

    risoku = days_3m * r * b;
    printf("三ヶ月後の利息は%f円", risoku);
  }
  return 0;
}

int leap(int y)
{
  if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
    return 1;
  else
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
