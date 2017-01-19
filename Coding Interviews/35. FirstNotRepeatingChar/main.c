#include <stdio.h>
#include <stdlib.h>

#define CHARNUM 256

char findFirstNotRepeatingChar(char ch[]);

int main() {
    char *str = "abaccdeff";
    printf("%c\n", findFirstNotRepeatingChar(str));
    return 0;
}

char findFirstNotRepeatingChar(char ch[]) {
    int count[CHARNUM];
    int i;

    for(i = 0; i < CHARNUM; i++) {
        count[i] = 0;
    }
    for(i = 0; ch[i] != '\0'; i++) {
        count[ch[i] - 'a']++;
    }
    for(i = 0; i < CHARNUM; i++) {
        if(count[i] == 1) {
            return 'a' + i;
        }
    }
    return '\0';
}
