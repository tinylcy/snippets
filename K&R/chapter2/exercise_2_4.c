#include <stdio.h>

void squeeze_str(char s[], char t[]);
void squeeze_char(char s[], char c);

int main(void) {

	char s[] = "chenyangli";
	char t[] = "tinylcy";
	squeeze_str(s, t);
	printf("%s\n", s);
	return 0;
}

void squeeze_str(char s[], char t[]) {
	int i;
	for(i = 0; t[i] != '\0'; i++) {
		squeeze_char(s, t[i]);
	}
}

void squeeze_char(char s[], char c) {
	int i, j;
	for(i = 0, j = 0; s[i] != '\0'; i++) {
		if(s[i] != c) {
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}
