#include <stdio.h>

int nweek(int, int, int);

int main() {
  int d,m,n,y;
  static char *youbi[]={"日","月", "火", "水", "木", "金", "土"};

  while(printf("年月日"), scanf("%d%d%d",&y,&m,&d)!=EOF) {
    n = nweek(y,m,d);
    printf("%s曜日です\n",youbi[n]);
    }
  return 0;
}

int nweek( int iy, int im, int id) {
  long ny,nm;
  ny = iy;
  nm=im;
  if ( im <= 2 ) {
    ny--;
    nm+= 12;
    }
  return ((ny+ny/4-ny/100+ny/400+26*(nm+1)/10+id-1)%7);
}
