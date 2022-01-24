#include <stdio.h>
#include <stdlib.h>
#include <math.h>

FILE *input;

int main(int argc, char *argv[])
{
  int n = 0;
  float sum = 0, f, sqr_sum = 0, m, s;

  if (argc != 2)
  {
    printf("argument must be a file name");
    exit(1);
  }

  if ((input = fopen(argv[1], "r")) == NULL)
  {
    printf("no file");
    exit(1);
  }

  while (fscanf(input, "%f", &f) != EOF)
  {
    sqr_sum += f * f;
    sum += f;
    n++;
  }

  fclose(input);

  m = sum / n;
  s = sqrt(sqr_sum / n - m * m);

  printf("m = %f\n", m);
  printf("s = %f\n", s);
}
