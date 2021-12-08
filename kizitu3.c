/* kizitu3.c */
#include <stdio.h>
typedef struct { long year, month, day;} DATE;    /* ���tDATE�̌^��`*/

DATE todate( long );        /*�֐��v���g�^�C�v*/

long today( DATE );

int main() 
{
	DATE firstday, lastday, taihuu;      /* DATE�^�ϐ��̒�`*/
	long dday, n1, n2, eof;
	int youbi;
	
	/*�����̓��t�̓���*/
	firstday.year = 2021; 
	firstday.month = 9;
	firstday.day = 15;
	//�Z�[���̓���
	n1 = 80;
	
	dday = today( firstday ) + n1;
	lastday = todate( dday );
	youbi = nweek(lastday);
	
	
	if (0 != youbi && 6 != youbi){
		dday = dday + 7 - youbi;
		lastday = todate(dday);
	}
	printf( "�ŏI���F%4d�N%2d��%2d��\n",lastday.year, lastday.month, lastday.day );
	

	return 0;
}

/* �����֐�Fairfield ����*/
long today( DATE datex ) {    /* today�֐��̒�`�\���̂̈���*/
	
	long y, m, d;
	y = datex.year;
	m = datex.month;
	d = datex.day;
	if( m <= 2 ) { m += 12; y--; }
	d = y*365 + y/4 -y/100 + y/400 + 306*(m+1)/10 + d -428;
	return d;
}

/* ���t�֐�Inverse Fairfield ����*/
DATE todate( long nday ) {    /* todate�\���̊֐��̒�`*/
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

//Zeller
int nweek( int iy, int im, int id) 
{
	long ny,nm;
	ny = iy;
	nm=im;
	if ( im <= 2 ) {
		ny--;
		nm+= 12;
	}
	return ((ny+ny/4-ny/100+ny/400+26*(nm+1)/10+id-1)%7);
}