#include <stdio.h>
#include <string.h>
#define SIZE 30      /* ���ѕ\�̒���*/

typedef struct {    
	char mei[20];    /* KAMOKU�^�̌^��`*/
	char kana[10];
	char number[15];
	 } TELBOOK;
	

int charfind(TELBOOK *, int, char *);

int main() {
	TELBOOK telbook[SIZE];
	int i, n, m;
	FILE *input;      /* ���̓t�@�C���̃|�C���^*/
	char infname[16];    /* ���̓t�@�C����*/
	char kanamei[10];    /* ��������J�i��*/
	printf( "�d�b���t�@�C�����F" );
	scanf( "%s", infname );
	input = fopen( infname, "r" );
	n = SIZE -1;
	for ( i = 0; i < SIZE; i++ ) 
	{
		if ( fscanf( input, "%s%s%s", telbook[i].mei, telbook[i].kana, telbook[i].number	) == EOF ) {
			n = i -1;
			break;
		}
	}
	
	
	while ( printf( "�T�������l�̖��O(�t���K�i)�F" ),scanf( "%s",kanamei ) != EOF ) {
		m = charfind( telbook, n, kanamei );
		if ( m < 0 ) {
			printf( "%s �̖��O�͂���܂���B\n\n", kanamei );
			continue;
		}
		printf( "%-12s\t%-10s\t%-15s\n\n",
		telbook[m].mei, telbook[m].kana, telbook[m].number);
	}
	fclose( input );
	return 0;
}

/* �����񌟍��֐�*/
int charfind( TELBOOK *d, int n, char *x ) {
	int i, k, m;
	i = 0;
	k = n;
	m = n / 2;
	while ( i < k ) {
		if( strcmp( x, (d+m)->kana ) > 0 ) i = m+1; 
		else k = m;
		m = (i+k)/2;
	}
	if ( strcmp( x, (d+m)->kana ) == 0 ) return m;
	else return -1;
}