#include <stdio.h>
#include <stdlib.h>

void reorderArray(int*, int);
void swap(int*, int, int);

int main() {
    int num[] = {1, 1, 2, 3};
    reorderArray(num, 4);

    int i;
    for(i = 0; i < 4; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}

void reorderArray(int num[], int length) {
    int first, last;
    first = 0;
    last = length - 1;
    while(first <= last) {
        while(first <= last && num[first] % 2 == 1) {
            first++;
        }
        while(first <= last && num[last] % 2 == 0) {
            last--;
        }
        if(first < last) {
            swap(num, first, last);
        }
    }
}

void swap(int num[], int x, int y) {
    int tmp = num[x];
    num[x] = num[y];
    num[y] = tmp;
}
