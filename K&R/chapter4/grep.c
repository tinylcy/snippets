#include <stdio.h>
#define MAXLEN 1000

int mygetline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(void) {
	char line[MAXLEN];
	while(mygetline(line, MAXLEN) > 0) {
		if(strindex(line, pattern) != -1) {
			printf("%s", line);
		}
	}

	return 0;
}

int mygetline(char line[], int lim) {
	int c;
	int i = 0;
	while(i++ < lim - 1 && (c = getchar()) != EOF && c != '\n') {
		line[i] = c;
	}
	if(c == '\n') {
		line[i++] = '\n';
	}
	line[i] = '\0';
	return i;
}

int strindex(char s[], char t[]) {
	int i, j, k;
	for(i = 0; s[i] != '\0'; i++) {
		for(j = i, k = 0; t[k] == s[j] && t[k] != '\0'; j++, k++) {
			;
		}
		if(k > 0 && t[k] == '\0') {
			return i;
		}
	}
	return -1;
}
