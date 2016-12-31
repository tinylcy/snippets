#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int verifySequence(int[], int, int);

int main() {
    int num1[] = {5, 7, 6, 9, 11, 10, 8};
    printf("result: %d\n", verifySequence(num1, 0, 6));
    int num2[] = {25, 33, 45, 40, 30, 65, 82, 83, 90, 88, 85, 80, 50};
    printf("result: %d\n", verifySequence(num2, 0, 12));
    int num3[] = {6, 7, 8, 9};
    printf("result: %d\n", verifySequence(num3, 0, 3));
    return 0;
}

int verifySequence(int num[], int left, int right) {
    if(left == right || left + 1 == right) {
        return TRUE;
    }
    int index = left;
    int pivot, i;
    while(index <= right && num[index] < num[right]) {
        index++;
    }
    pivot = index;
    for(i = index; i < right; i++) {
        if(num[i] < num[right]) {
            return FALSE;
        }
    }

    int verifyLeft = TRUE;
    if(left <= pivot - 1) {
        verifyLeft = verifySequence(num, left, pivot - 1);
    }
    int verifyRight = TRUE;
    if(pivot <= right - 1) {
        verifyRight = verifySequence(num, pivot, right - 1);
    }

    return verifyLeft && verifyRight;
}


