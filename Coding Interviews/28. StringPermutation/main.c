#include <stdio.h>
#include <stdlib.h>

void permutation(char str[], int left, int right);
void swap(char *str, int left, int right);

int main() {
    char str[] = "abb";
    permutation(str, 0, 2);
    return 0;
}

void permutation(char str[], int left, int right) {
    if(str == NULL) {
        return;
    }
    if(left == right) {
        printf("%s\n", str);
        return;
    }

    int i, j, duplicate;
    for(i = left; i <= right; i++) {
        duplicate = 0;
        for(j = left; j < i; j++) {
            if(str[j] == str[i]) {
                duplicate = 1;
                break;
            }
        }
        if(duplicate == 1) {
            continue;
        }
        swap(str, left, i);
        permutation(str, left + 1, right);
        swap(str, left, i);
    }
    return;
}

void swap(char *str, int left, int right) {
    char temp = str[left];
    str[left] = str[right];
    str[right] = temp;
}
