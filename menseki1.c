/* モンテカルロ法*/
#include <stdio.h>
#include <limits.h>

float rnd();
float fan(float, float);

int main()
{
  int n, i;
  float b, s;

  printf("まく砂の数");
  scanf("%d", &n);
  b = 0;

  for ( i = 1; i <= n; i++ )
  {
    if ( fan( rnd(), rnd() ) <= 1 ) b = b + 1.0;
  }

  s = b / n;
  printf( "まいた砂の数\t\t= %d\n", n );
  printf( "扇形内の砂の数\t\t= %f\n", b );
  printf( "円の面積\t\t\t= %f\n", 4.0*s );
  return 0;
}

/* 扇形関数*/
float fan(float x, float y)
{
  return x * x + y * y;
}

/* 乱数関数*/
float rnd()
{
  static long ix = 1643;
  long ia = 1664525;
  float r;
  ix = ia * ix + 37313;
  r = ix / (double)LONG_MAX;
  if (ix < 0)
    r = r + 1.0;
  return r;
}
