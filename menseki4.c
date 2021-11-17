/* シンプソン公式*/
#include <stdio.h>
#include <math.h>
#define LOW 0.0
#define HIGH 1.0
float simpson(float, float, int);

double f(double x)
{
  double t;
  t = 1 + x * x;
  return 4 / t;
}

int main()
{
  int m;
  while (printf("分割数=  "), scanf("%d", &m) != EOF)
  {
    printf("積分の面積= %f\n", simpson(LOW, HIGH, m));
  }
  return 0;
}

/* Simpson 関数*/
float simpson(float a, float b, int m)
{
  int i, n;
  double s1 = 0.0, s2 = 0.0, h, x;
  n = 2 * m;
  h = (b - a) / n;
  for (i = 1; i < n; i += 2)
  {
    x = a + h * i;
    s2 += f(x);
    s1 += f(x - h) + f(x + h);
  }
  return (s1 + 4.0 * s2) * h / 3.0;
}
