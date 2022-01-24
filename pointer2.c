#include <stdio.h>
#include <string.h>

void sort(int, char**);
int main(){
	char *p[] = {"JANUARY", "FEBRUARY","MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
	int i, n = 12;
	for (i = 0;i < n;i++){
		printf("%s ", p[i]);
	}
	
	printf("\n");
	sort(n, p);
	for (i = 0;i < n;i++){
		printf("%s ", p[i]);
	}
	printf("\n");
}


void sort(int n, char** p){
	int i, j, m;
	char *max;
	for (i = 0;i < n;i++){
		max = p[i];
		m = i;
		for (j = i + 1;j < n;j++){
			if(strcmp(max, p[j]) > 0){
				max = p[j];
				m = j;
			}
		}
		
		p[m] = p[i];
		p[i] = max;
	}
}