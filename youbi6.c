#include <stdio.h>
#include <stdlib.h>

int  nweek(int, int, int);
long nday(int, int, int);
int main()
{
  int y, m, d, y2, d2, m2, n, weeks, end_n, start_n;
  long n1, n2;
  static char *youbi[] = {"日", "月", "火", "水", "木", "金", "土"};

  while (printf("授業開始年月日"), scanf("%d%d%d", &y, &m, &d),
  printf("授業終了年月日"), scanf("%d%d%d", &y2, &m2, &d2),
  printf("授業曜日"), scanf("%d", &n) != EOF)
  {
    start_n = nweek(y, m, d);
    end_n = nweek(y2, m2, d2);

    n1 = nday(y, m, d);
    n2 = nday(y2, m2, d2);

    weeks = labs(n2 - n1) / 7;

    if (!(
      (start_n < n && n < end_n) ||
      (n < start_n && start_n < end_n) ||
      (end_n < n && n < start_n)
      )){
      weeks += 1;
    }

    printf("%d回授業があります\n", weeks);
  }
  return 0;
}

int nweek(int iy, int im, int id)
{
  long ny, nm;
  ny = iy;
  nm = im;
  if (im <= 2)
  {
    ny--;
    nm += 12;
  }
  return ((ny + ny / 4 - ny / 100 + ny / 400 + 26 * (nm + 1) / 10 + id - 1) % 7);
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
