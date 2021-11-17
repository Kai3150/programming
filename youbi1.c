#include <stdio.h>

int leap(int);

int main() {
  int year;

  while(printf("西暦年"), scanf("%d",&year)!=EOF){
    if ( leap(year) ) printf("うるう年です\n");
    else printf("平年です\n");
    }
    return 0;
}

int leap(int y) {
  if(y%4==0 && y%100!=0 || y%400==0 ) return 1;
  else return 0;
}
