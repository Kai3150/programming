/* proot3.c*/
#include <stdio.h>
#define SIZE 7      /* 多項式の最大次数*/
#define ERR 0.000001    /* 精度*/
#define LOW 1.0      /* 初期区間の左端*/
#define HIGH 3.0    /* 右端*/

float proot( float *, int, float, float, float );
float polyf( float *, int, float );

int main(){
	float a[SIZE], sisu, rir, sougaku=0;
	int i, n;
	printf( "預金利率を入力してください。（％）\n" );	
	printf( "rir=");
	scanf( "%f", &rir );
	printf( "多項式の係数のデータを入れて下さい。\n" );
	n = SIZE -1;
	for ( i = 0; i < SIZE; i++ ) {
		printf( "a[%2d]=", i);
		if ( scanf( "%f", &a[i] ) == EOF ) { 
			n = i -1;
			break; 
		}
	}
	
	
	rir = 1 + rir/100;
	sisu = rir;
	for ( i = -1; i < n; n-- ) {
		sisu = sisu*rir;
		sougaku = sougaku + a[n]*sisu;
	}

	printf( "\n総額：%f\n", sougaku );
	return 0;
}
