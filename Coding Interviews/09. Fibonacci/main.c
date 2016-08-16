#include <stdio.h>

int fibonacci(int);

int main(void) {
	for(int i = 0; i < 10; i++) {
		printf("%d\n", fibonacci(i));
	}
}

int fibonacci(int n) {
	if(n == 0 || n == 1) {
		return n;
	}
	int first = 0;
	int second = 1;
	int third = 0;
	for(int i = 2; i <= n; i++) {
		third = first + second;
		first = second;
		second = third;
	}
	return third; 
}