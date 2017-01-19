#include <stdio.h>
#include <stdlib.h>

int inversePairs(int num[], int size);
void swap(int num[], int i, int j);

int main() {
    int num[] = {7, 5, 6, 4};
    printf("%d\n", inversePairs(num, 4));
    return 0;
}

int inversePairs(int num[], int size) {
    int i, j, count;
    for(i = 1, count = 0; i < size; i++) {
        for(j = i; num[j] < num[j - 1] && j > 0; j--) {
            swap(num, j - 1, j);
            count++;
        }
    }
    return count;
}

void swap(int num[], int i, int j) {
    int tmp = num[i];
    num[i] = num[j];
    num[j] = tmp;
}
