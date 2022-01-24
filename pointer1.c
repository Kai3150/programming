#include <stdio.h>
int main(){
	char str[] = "Hello World", *strp;
	strp = str;
	
	while(*strp != '\0'){
		putchar(*strp);
		strp++;
	}
	
	putchar('\n');
	return 0;
}