/* proot1.c �������v���̌v�Z*/
#include <stdio.h>
#define SIZE 30      /* �������̍ő原��*/
#define ERR 0.000001    /* ���x*/
#define LOW 1.0      /* ������Ԃ̍��[*/
#define HIGH 3.0    /* �E�[*/

float proot( float *, int, float, float, float );
float polyf( float *, int, float );

int main(){
	float a[SIZE], rir;
	int i, n;
	printf( "�������̌W���̃f�[�^�����ĉ������B\n" );
	n = SIZE -1;
	for ( i = 0; i < SIZE; i++ ) {
		printf( "a[%2d]=", i);
		if ( scanf( "%f", &a[i] ) == EOF ) { 
			n = i -1;
			break; 
		}
	}
	rir = proot( a, n, ERR, LOW, HIGH );
	if ( rir < LOW ) printf( "\n��ԓ��ɉ��͂���܂���B\n" );
	else printf( "\n�������v���F%f\n", rir -1.0 );
	return 0;
}

/* �������̎����������߂�֐�*/
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

/* �������̒l�����߂�֐�*/
float polyf( float *a, int n, float x ) {
	int i;
	float y;
	y = *a;
	for ( i = 1; i <= n; i++ ) y = y*x + (*(a+i));
	return y;
}