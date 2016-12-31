#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if(bufp < BUFSIZE) {
		buf[bufp++] = c;
	} else {
		printf("ungetch: top many characters\n");
	}
}