#include <stdio.h>
#define IN 1
#define OUT 0

int main(void) {
	int len[100];
	int maxLen = 0;
	int ch;
	int state;
	int currentLen = 0;
	
	int i, j;
	for(i = 0; i < 100; i++) {
		len[i] = 0;
	}

	while((ch = getchar()) != EOF) {
		if(ch == ' ' || ch == '\t' || ch == '\n') {
			if(state == IN) {
				if(currentLen > maxLen) {
					maxLen = currentLen;
				}
				len[currentLen]++;
				currentLen = 0;
			}
			state = OUT;
		} else {
			currentLen++;
			state = IN;
		}                                
	}

	//for(i = 0; i <= maxLen; i++) {
	//	printf("len = %d, count = %d\n", i, len[i]);
	//}

	int maxCount = 0;
	for(i = 0; i < maxLen; i++) {
		if(len[i] > maxCount) {
			maxCount = len[i];
		}
	}

	for(i = maxCount; i > 0; i--) {
		for(j = 0; j <= maxLen; j++) {
			if(len[j] >= i) {
				printf("%3s", "#");
			} else {
				printf("%3s", " ");
			}
		}
		printf("\n");
	}
	for(i = 0; i <= maxLen; i++) {
		printf("%3d", i);
	}
	printf("\n");

	return 0;
}
