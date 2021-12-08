/* kizitu4.c */
#include <stdio.h>
typedef struct { long year, month, day;} DATE;    /* 日付DATEの型定義*/

DATE todate( long );        /*関数プロトタイプ*/

long today( DATE );

int main() 
{
	DATE firstday, travel1, travel2, bon1, bon2, lastday;      /* DATE型変数の定義*/
	long dday, n1;

	
	/*初日の日付の入力*/
	firstday.year = 2021; 
	firstday.month = 7;
	firstday.day = 21;
	
	//旅行初日
	travel1.year = 2021; 
	travel1.month = 7;
	travel1.day = 28;
	
	//旅行最終日
	travel2.year = 2021; 
	travel2.month = 8;
	travel2.day = 2;
	
	//盆休み初日	
	bon1.year = 2021; 
	bon1.month = 8;
	bon1.day = 11;	
	
	//盆休み最終日
	bon2.year = 2021; 
	bon2.month = 8;
	bon2.day = 17;
	
	//必要日数
	n1 = 100 / 2;
	
	dday = today( firstday ) + today(travel2) - today(travel1) + 1 + today(bon2) - today(bon1) + 1 + n1 -1;
	lastday = todate( dday );
	
	
	printf( "最終日：%4d年%2d月%2d日\n",lastday.year, lastday.month, lastday.day );
	

	return 0;
}

/* 日数関数Fairfield 公式*/
long today( DATE datex ) {    /* today関数の定義構造体の引数*/
	
	long y, m, d;
	y = datex.year;
	m = datex.month;
	d = datex.day;
	if( m <= 2 ) { m += 12; y--; }
	d = y*365 + y/4 -y/100 + y/400 + 306*(m+1)/10 + d -428;
	return d;
}

/* 日付関数Inverse Fairfield 公式*/
DATE todate( long nday ) {    /* todate構造体関数の定義*/
	DATE x;
	long y, m, d, l, s;
	y = nday/365;
	while ( 1 ) {
		d = nday -365*y -y/4 + y/100 -y/400;
		l = (y+1)%4 == 0 && (y+1)%100 != 0 || (y+1)%400 == 0;
		s = y;
		if( d-l > 59 ) y++;
		if( d < -305 ) y--;
		if( s==y ) break;
	}
	for( m=5; m <= 16; m++ ) { 
		if( d+428-306*m/10 <= 0 ) break;
	}
	m -= 2;
	d = d+428-306*(m+1)/10;
	if( m >12 ) { m -= 12; y++; }
	x.year = y;
	x.month = m; 
	x.day = d;
	return x;
}
