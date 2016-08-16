#include <stdio.h>

int numberOf_1(int);

int main(void) {

	printf("%d\n", numberOf_1(-1));
}

int numberOf_1(int n) {
	int flag = 1;
	int count = 0;
	while(flag != 0) {
		if(n & flag) {        /*如果要写成 if((n & flag) != 0)，必须要在 n & flag 两边加上括号*/
			count++;
		}
		flag = flag << 1;
	}
	return count;
}