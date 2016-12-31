#include <stdio.h>

#define MAXLEN 100

char line[MAXLEN];
char longest[MAXLEN];

int _getline(char line[], int lim);
void copy(char line[], char longest[]);
void printline(int len);

int main(void) {
	printline(10);
	return 0;
}

int _getline(char line[], int lim) {
	int c;
	int i = 0;
	while(i < lim - 1 && (c = getchar()) != EOF && c != '\n') {
		line[i++] = c;
	}
	if(c == '\n') {
		line[i] = '\n';
	}
	line[++i] = '\0';
	return i - 1;
}

void copy(char line[], char longest[]) {
	int i;
	for(i = 0; line[i] != '\0'; i++) {
		longest[i] = line[i];
	}
	longest[i] = '\0';
}

void printline(int len) {
	int i;
	while((i = _getline(line, MAXLEN)) != 0) {
		if(i == len) {
			printf("%s", line);
		}
	}
}
