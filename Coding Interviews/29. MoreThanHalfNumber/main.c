#include <stdio.h>
#include <stdlib.h>

int moreThanHalfNum(int num[], int size);
int partition(int num[], int low, int high);
void swap(int num[], int i, int j);

void show(int num[], int N) {
    int i;
    for(i = 0; i < N; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");
}

int main() {
    // int num[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    int num[] = {2, 5, 1, 4, 7, 7, 9, 7, 2, 7, 7, 7, 7};
    int ret = moreThanHalfNum(num, 13);
    printf("ret = %d\n", ret);
    return 0;
}

int moreThanHalfNum(int num[], int size) {
    int low = 0, high = size - 1;
    int index = partition(num, low, high);

    int mid = size / 2;
    while(index != mid) {
        printf("index = %d\n", index);
        if(index > mid) {
            high = index - 1;
            index = partition(num, low, high);
        } else if(index < mid){
            low = index + 1;
            index = partition(num, low, high);
        }
    }
    return num[index];
}

int partition(int num[], int low, int high) {
    int i = low, j = high + 1;
    int pivot = num[low];
    while(1) {
        while(num[++i] < pivot) {
            if(i == high) {
                break;
            }
        }
        while(num[--j] > pivot) {
            if(j == low) {
                break;
            }
        }
        if(i >= j) {
            break;
        }
        swap(num, i, j);
    }
    swap(num, low, j);
    return j;
}

void swap(int num[], int i, int j) {
    int tmp = num[i];
    num[i] = num[j];
    num[j] = tmp;
}
