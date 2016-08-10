#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 100

bool find(int matrix[][MAXSIZE], int rows, int columns, int key);

int main(void) {
    int matrix[][MAXSIZE] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    int key = 8;
    printf("%d\n", find(matrix, 4, 4, key));
    return 0;
}

bool find(int matrix[][MAXSIZE], int rows, int columns, int key) {
    bool found = false;
    if(matrix != NULL && rows > 0 && columns > 0) {
        int row = 0, column = columns - 1;
        while(row >= 0 && column >= 0) {
            if(matrix[row][column] > key) {
                column--;
            }else if(matrix[row][column] < key) {
                row++;
            }else {
                found = true;
                break;
            }
        }
    }
    return found;
}
