/* kizitu1.c */
#include <stdio.h>
typedef struct { long year, month, day;} DATE;    /* 日付DATEの型定義*/

DATE todate( long );        /*関数プロトタイプ*/

long today( DATE );

int main() 
{
	DATE karibi, hensaibi;      /* DATE型変数の定義*/
	long dday, n, eof;char tegata[11];
	
	while (1) {
		printf( "手形名\t借入年\t月\t日\t借入日数\n" );
		eof = scanf( "%s%d%d%d%d", tegata,&karibi.year, &karibi.month, &karibi.day, &n );
		if ( eof == EOF ) break;
		dday = today( karibi ) + n;hensaibi = todate( dday );
		printf( "%-10s返済日：%4d年%2d月%2d日\n", tegata,hensaibi.year, hensaibi.month, hensaibi.day );
	}
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