#include <stdio.h>
#include <string.h>
#define SIZE 30      /* ���ѕ\�̒���*/

typedef struct {    
	char mei[20];    /* KAMOKU�^�̌^��`*/
	char kana[10];
	int ei;
	int koku;
	int su;
	int sha;
	int ri;
	int sogo; } KAMOKU;
	

int sogofind(KAMOKU *, int);

int main() {
	KAMOKU seiseki[SIZE], tmp;
	int i, n, m, j, max;
	FILE *input;      /* ���̓t�@�C���̃|�C���^*/
	char infname[16];    /* ���̓t�@�C����*/
	char kanamei[10];    /* ��������J�i��*/
	printf( "���ѕ�t�@�C�����F" );
	scanf( "%s", infname );
	input = fopen( infname, "r" );
	n = SIZE -1;
	for ( i = 0; i < SIZE; i++ ) 
	{
		if ( fscanf( input, "%s%s%d%d%d%d%d",
		 seiseki[i].mei, seiseki[i].kana, &seiseki[i].ei, &seiseki[i].koku, 
		 &seiseki[i].su, &seiseki[i].sha, &seiseki[i].ri ) == EOF ) {
			n = i -1;
			break;
		}
		seiseki[i].sogo = seiseki[i].ei + seiseki[i].koku + seiseki[i].su + seiseki[i].sha + seiseki[i].ri; 
	}
	
	//sort
	 for (i = 0; i <= n - 1; i++)
	  {
	    max = seiseki[i].sogo;
	    m = i;
	    for (j = i + 1; j <= n; j++)
	    {
	      if (max < seiseki[j].sogo)
	      {
	        max = seiseki[j].sogo;
	        m = j;
	      }
	    }
	    //swap
	    tmp = seiseki[m];
	    seiseki[m] = seiseki[i];
	    seiseki[i] = tmp;
	  }


		m = sogofind( seiseki, n );

		printf( "%-12s\t%-10s\t%4d\n\n",seiseki[m].mei, seiseki[m].kana, seiseki[m].sogo );
	
	fclose( input );
	return 0;
}

/* �����񌟍��֐�*/
int sogofind( KAMOKU *d, int n ) {
	int i, k, m;
	i = 0;
	k = n;
	m = n / 2;
	
	//400�_����̐l��񕪒T��
	while ( i < k ) {
		if( (d+m)->sogo > 400  ) i = m+1;
		else k = m;
		m = (i+k)/2;
	}
	if ((d+m)->sogo < 400) m = m - 1;
	return m;
}
