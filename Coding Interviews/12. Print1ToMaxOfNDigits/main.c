#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void print1ToMaxOfNDigits(int n);
int increment(char num[], int n);
void printNum(char num[], int n);

/*
 * 使用一个数组来表示大数，在数组上模拟加1运算。对于要显示的n位数字，开辟n+1个空间，第1~n位用来存储具体的数字，
 * 第0位用来判断是否还要继续增加下去（当第0位为1时，说明上一个数就是0999...999，也就是要显示的最后一个数）。
 */
int main() {
    print1ToMaxOfNDigits(5);
    return 0;
}

void print1ToMaxOfNDigits(int n) {
    if(n <= 0) {
        return;
    }
    char *num = (char *)malloc(sizeof(char) * (n + 1));
    memset(num, '0', n + 1);

    while(increment(num, n) == TRUE) {
        printNum(num, n);
    }

	free(num);
}

/*
 * 对最低位（第n位）做单独的计算，因为1加在这一位上。
 * 其它位和进位相加，当进位为0时，结束计算。
 */
int increment(char num[], int n) {
    int i, overflow = 0, sum = 0;
    sum = num[n] - '0' + 1;
    num[n] = sum % 10 + '0';
    overflow = sum / 10;
    i = n - 1;
    while(overflow > 0) {
        sum = num[i] - '0' + overflow;
        num[i] = sum % 10 + '0';
        overflow = sum / 10;
        i--;
    }
    if(num[0] == '1') {
        return FALSE;
    }
    return TRUE;
}

void printNum(char num[], int n) {
    int i, flag = 0;
    for(i = 1; i <= n; i++) {
        if(flag == 0) {
            if(num[i] != '0') {
                printf("%c", num[i]);
                flag = 1;
            }
        }else {
            printf("%c", num[i]);
        }
    }
    printf("\n");
}
