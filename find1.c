#include <stdio.h>
#include <string.h>
#define SIZE 30      /* 成績表の長さ*/

typedef struct {    
	char mei[20];    /* KAMOKU型の型定義*/
	char kana[10];
	int ei;
	int koku;
	int su;
	int sha;
	int ri; } KAMOKU;
	

int charfind(KAMOKU *, int, char *);

int main() {
	KAMOKU seiseki[SIZE];
	int i, n, m;
	FILE *input;      /* 入力ファイルのポインタ*/
	char infname[16];    /* 入力ファイル名*/
	char kanamei[10];    /* 検索するカナ名*/
	printf( "成績簿ファイル名：" );
	scanf( "%s", infname );
	input = fopen( infname, "r" );
	n = SIZE -1;
	for ( i = 0; i < SIZE; i++ ) 
	{
		if ( fscanf( input, "%s%s%d%d%d%d%d",
		 seiseki[i].mei, seiseki[i].kana,
		 &seiseki[i].ei, &seiseki[i].koku, 
		 &seiseki[i].su, &seiseki[i].sha,
		  &seiseki[i].ri ) == EOF ) {
			n = i -1;
			break;
		}
	}
	while ( printf( "探したい人の名前(フリガナ)：" ),scanf( "%s",kanamei ) != EOF ) {
		m = charfind( seiseki, n, kanamei );
		if ( m < 0 ) {
			printf( "%s の名前はありません。\n\n", kanamei );
			continue;
		}
		printf( "名前フリガナ英国数社理\n" );
		printf( "%-12s\t%-10s\t%4d\t%4d\t%4d\t%4d\t%4d\n\n",
		seiseki[m].mei, seiseki[m].kana, 
		seiseki[m].ei,seiseki[m].koku, 
		seiseki[m].su, seiseki[m].sha, 
		seiseki[m].ri );
	}
	fclose( input );
	return 0;
}

/* 文字列検索関数*/
int charfind( KAMOKU *d, int n, char *x ) {
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