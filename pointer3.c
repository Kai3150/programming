#include <stdio.h>

int main( ){
	int d, *pointer;
	pointer = &d;
	printf("��������͂��Ă��������F");
	scanf("%d", pointer);

	printf("���͂��������́A%d �ł��B\n", *pointer);
}