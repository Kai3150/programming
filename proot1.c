/* proot1.c 内部利益率の計算*/
#include <stdio.h>
#define SIZE 30      /* 多項式の最大次数*/
#define ERR 0.000001    /* 精度*/
#define LOW 1.0      /* 初期区間の左端*/
#define HIGH 3.0    /* 右端*/

float proot( float *, int, float, float, float );
float polyf( float *, int, float );

int main(){
	float a[SIZE], rir;
	int i, n;
	printf( "多項式の係数のデータを入れて下さい。\n" );
	n = SIZE -1;
	for ( i = 0; i < SIZE; i++ ) {
		printf( "a[%2d]=", i);
		if ( scanf( "%f", &a[i] ) == EOF ) { 
			n = i -1;
			break; 
		}
	}
	rir = proot( a, n, ERR, LOW, HIGH );
	if ( rir < LOW ) printf( "\n区間内に解はありません。\n" );
	else printf( "\n内部利益率：%f\n", rir -1.0 );
	return 0;
}

/* 多項式の実数解を求める関数*/
float proot( float *a, int n, float err, float xa, float xb ) {
	float x1, x2, x;
	x1 = xa;
	x2 = xb;
	if ( polyf( a, n, x1 ) * polyf( a, n, x2 ) > 0.0 )return ( xa -1.0 );
	while ( x2 -x1 >= err ) {
		x = ( x1 + x2 )/2.0;
		if ( polyf( a, n, x ) * polyf( a, n, x2 ) > 0.0 ) x2 = x;
		else x1 = x;
	}
	return x2;
}

/* 多項式の値を求める関数*/
float polyf( float *a, int n, float x ) {
	int i;
	float y;
	y = *a;
	for ( i = 1; i <= n; i++ ) y = y*x + (*(a+i));
	return y;
}