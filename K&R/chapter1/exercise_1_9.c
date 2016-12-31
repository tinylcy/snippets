#include <stdio.h>

int main(void) {
	int ch;
	int isSpace = 0;
	for( ; (ch = getchar()) != EOF; ) {
		if(ch == ' ' ) {
		  if(isSpace == 0) {
		      putchar(ch);
			  isSpace = 1;
		  } else if(isSpace == 1) {
			continue;
		  }
		} else {
			putchar(ch);
			isSpace = 0;
		}
	}

	return 0;
}
