#include <stdio.h>

long nday(int, int, int);

int main() {
  int y,m,d;
  long n;

  while(printf("年月日"), scanf("%d%d%d",&y,&m,&d)!=EOF) {
    n = nday(y,m,d);
    printf("西暦元年１月１日からの日数＝%ld\n",n);
    }
    return 0;
}

long nday( int iy, int im, int id) {
  long ny,nm;ny = iy;
  nm=im;
  if ( im <= 2 ) {
    ny--;
    nm += 12;
    }
  return (365*ny+ny/4-ny/100+ny/400+306*(nm+1)/10+id-428);
}
