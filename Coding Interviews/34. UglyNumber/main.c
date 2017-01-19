#include <stdio.h>
#include <stdlib.h>

int findUglyNumber(int n);
int minNum(int x, int y, int z);

int main() {
    printf("%d\n", findUglyNumber(1500));
    printf("%d\n", findUglyNumber(3));

    return 0;
}

int findUglyNumber(int n) {
    int ugly[1600];
    ugly[1] = 1;
    ugly[2] = 2;
    ugly[3] = 3;
    ugly[4] = 4;
    ugly[5] = 5;

    int i = 3, j = 3, k = 5, cnt = 5; // 以2位基数从3开始，因为 2 * 2 = 4 已经被包括了。
    while(cnt <= n) {
        int twoBased = 2 * ugly[i];
        int threeBased = 3 * ugly[j];
        int fiveBased = 5 * ugly[k];
        int min = minNum(twoBased, threeBased, fiveBased);
        if(min > ugly[cnt]) {
            ugly[++cnt] = min;
        }
        if(min == twoBased) {
            i++;
        }
        if(min == threeBased) {
            j++;
        }
        if(min == fiveBased) {
            k++;
        }
    }

    return ugly[n];
}

int minNum(int x, int y, int z) {
    return (x < y ? x : y) < z ? (x < y ? x : y) : z;
}

