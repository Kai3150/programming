//sort6.c
#include <stdio.h>
#include <string.h>
#define SIZE 30      /* ���ѕ\�̒���*/

typedef struct{  
	char mei[20];   
	char kana[10];
	char number[15];
	 } TELBOOK;
	

int charfind(TELBOOK *, int, char *);

int main() {
	TELBOOK telbook[SIZE], tmp;
	int i, n, m, j;
	FILE *input, *output;                    /* ���o�̓t�@�C���̃|�C���^*/
	char infname[16] = "denwa.d";            /* ���̓t�@�C����*/
	char outfname[16] = "telbook.d";         /* �o�̓t�@�C����*/
	char max[10];
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
	fclose( input );
	
	//sort
	for (i = 0; i <= n - 1; i++)
	{
		strcpy(max, telbook[i].kana);
		m = i;
		for (j = i + 1; j <= n; j++)
		{
			if (strcmp(max, telbook[j].kana) >= 0) 
			{
				strcpy(max, telbook[j].kana);
				m = j;
			}
		}
		//swap
		tmp = telbook[i];
		telbook[i] = telbook[m];
		telbook[m] = tmp;
	}
	
	
	output = fopen(outfname, "w");

	for (i = 0; i <= n; i++)
	{
		fprintf(output, "\t%-10s\t%-10s\t%s\n", telbook[i].mei, telbook[i].kana, telbook[i].number);
		printf("\t%-10s\t%-10s\t%s\n", telbook[i].mei, telbook[i].kana, telbook[i].number);
	}
	
	
	fclose(output);
	
	return 0;
}
