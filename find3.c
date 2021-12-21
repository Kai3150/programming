#include <stdio.h>
#include <string.h>
#define SIZE 30      /* 成績表の長さ*/

typedef struct {    
	char mei[20];    /* KAMOKU型の型定義*/
	char kana[10];
	char number[15];
	 } TELBOOK;
	

int charfind(TELBOOK *, int, char *);

int main() {
	TELBOOK telbook[SIZE];
	int i, n, m;
	FILE *input;      /* 入力ファイルのポインタ*/
	char infname[16];    /* 入力ファイル名*/
	char kanamei[10];    /* 検索するカナ名*/
	printf( "電話帳ファイル名：" );
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
	
	
	while ( printf( "探したい人の名前(フリガナ)：" ),scanf( "%s",kanamei ) != EOF ) {
		m = charfind( telbook, n, kanamei );
		if ( m < 0 ) {
			printf( "%s の名前はありません。\n\n", kanamei );
			continue;
		}
		printf( "%-12s\t%-10s\t%-15s\n\n",
		telbook[m].mei, telbook[m].kana, telbook[m].number);
	}
	fclose( input );
	return 0;
}

/* 文字列検索関数*/
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