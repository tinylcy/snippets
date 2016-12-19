#include <stdio.h>
#include <stdlib.h>

void printMatrix(int arr[10][10], int x, int y);

int main() {
    int arr1[10][10] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    printMatrix(arr1, 4, 4);
    int arr2[10][10] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    printMatrix(arr2, 3, 4);
    int arr3[10][10] = {{1, 2, 3}, {4, 5, 6}};
    printMatrix(arr3, 2, 3);
    int arr4[10][10] = {{1}};
    printMatrix(arr4, 1, 1);
    return 0;
}

void printMatrix(int arr[10][10], int x, int y) {
    int i, j, k;
    k = 0;
    while(x >= 0 && y >= 0 && k < x && k < y) {
        for(i = k, j = k; j < y; j++) {
            //printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
            printf("%d ", arr[i][j]);
        }
        j--;
        if(x - 1 - k > 0) {
            for(i = k + 1; i < x; i++) {
                //printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
                printf("%d ", arr[i][j]);
            }
            i--;
        }
        if(x - 1 - k > 0 && y - 1 - k > 0) {
            for(j = j - 1; j >= k; j--) {
                //printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
                printf("%d ", arr[i][j]);
            }
            j++;
        }

        if(x - 1 - k > 1 && y - 1 - k > 0) {
            for(i = i - 1; i > k; i--) {
                //printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
                printf("%d ", arr[i][j]);
            }
            i++;
        }

        k++;
        x--;
        y--;
    }
    printf("\n");
}
