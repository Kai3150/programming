/* proot3.c*/
#include <stdio.h>
#define SIZE 7      /* �������̍ő原��*/
#define ERR 0.000001    /* ���x*/
#define LOW 1.0      /* ������Ԃ̍��[*/
#define HIGH 3.0    /* �E�[*/

float proot( float *, int, float, float, float );
float polyf( float *, int, float );

int main(){
	float a[SIZE], sisu, rir, sougaku=0;
	int i, n;
	printf( "�a����������͂��Ă��������B�i���j\n" );	
	printf( "rir=");
	scanf( "%f", &rir );
	printf( "�������̌W���̃f�[�^�����ĉ������B\n" );
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

	printf( "\n���z�F%f\n", sougaku );
	return 0;
}
