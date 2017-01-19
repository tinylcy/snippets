#include <stdio.h>
#include <stdlib.h>

int greatestSum(int arr[], int len);

int main() {
    int arr[] = {1, -2, 3, 10, -4, 7, 2, -5};
    int max = greatestSum(arr, 8);
    printf("%d\n", max);
    return 0;
}

int greatestSum(int arr[], int len) {
    int i, max;
    int *aux = (int *)malloc(sizeof(int) * len);
    for(i = 0; i < len; i++) {
        aux[i] = 0;
    }
    aux[0] = arr[0];
    max = aux[0];
    for(i = 1; i < len; i++) {
        if(arr[i] + aux[i - 1] > arr[i]) {
            aux[i] = arr[i] + aux[i - 1];
        } else {
            aux[i] = arr[i];
        }
        if(aux[i] > max) {
            max = aux[i];
        }
    }
    return max;
}
