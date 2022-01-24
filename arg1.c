#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int a, i, flag = 1;

  if (argc != 2)
  {
    printf("put 1 argument");
  }

  a = atoi(argv[1]);

  if (a < 0)
  {
    printf("argument must be natural number");
  }
  else if (a == 1 | a == 0)
  {
    printf("%d is not a prime nmber\n", a);
  }
  else if (a == 2)
  {
    printf("%d is a prime nmber\n", a);
  }
  else
  {
    for (i = 2; i * i <= a; i++)
    {
      if (a % i == 0)
      {
        flag = 0;
      }
    }
    if (flag == 1)
    {
      printf("%d is a prime nmber\n", a);
    }
    else
    {
      printf("%d is not a prime nmber\n", a);
    }
  }
}
