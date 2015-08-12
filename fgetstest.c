/* getstest.c */
#include <stdio.h>

int main(void){
	int a;
	char c[100];

	fgets(c, 10, stdin);
	printf("%c, %d", c[0], c[0]);

	return 0;
}



