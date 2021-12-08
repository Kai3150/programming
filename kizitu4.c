/* kizitu4.c */
#include <stdio.h>
typedef struct { long year, month, day;} DATE;    /* ���tDATE�̌^��`*/

DATE todate( long );        /*�֐��v���g�^�C�v*/

long today( DATE );

int main() 
{
	DATE firstday, travel1, travel2, bon1, bon2, lastday;      /* DATE�^�ϐ��̒�`*/
	long dday, n1;

	
	/*�����̓��t�̓���*/
	firstday.year = 2021; 
	firstday.month = 7;
	firstday.day = 21;
	
	//���s����
	travel1.year = 2021; 
	travel1.month = 7;
	travel1.day = 28;
	
	//���s�ŏI��
	travel2.year = 2021; 
	travel2.month = 8;
	travel2.day = 2;
	
	//�~�x�ݏ���	
	bon1.year = 2021; 
	bon1.month = 8;
	bon1.day = 11;	
	
	//�~�x�ݍŏI��
	bon2.year = 2021; 
	bon2.month = 8;
	bon2.day = 17;
	
	//�K�v����
	n1 = 100 / 2;
	
	dday = today( firstday ) + today(travel2) - today(travel1) + 1 + today(bon2) - today(bon1) + 1 + n1 -1;
	lastday = todate( dday );
	
	
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
