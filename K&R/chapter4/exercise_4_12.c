#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100

char s[MAXLEN];
int i = 0;

void itoa_reverse(int);

int main(void) {
	memset(s, '\0', MAXLEN);
	itoa_reverse(1234);
	printf("%s\n", s);

	return 0;
}

void itoa_reverse(int x) {
	if(x < 0) {
		s[i++] = '-';
		x = -x;
	}
	if(x / 10 > 0) {
		itoa_reverse(x / 10);
	}
	s[i++] = x % 10 + '0';
}
