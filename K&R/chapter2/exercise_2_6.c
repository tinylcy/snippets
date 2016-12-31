#include <stdio.h>

int setbits(int x, int p, int n, int y);

int main(void) {
	int result = setbits(47, 4, 3, 11);
	printf("result = %d\n", result);

	return 0;
}

int setbits(int x, int p, int n, int y) {
	return x & ((0xFF << (p + 1)) | ~(0xFF << (p - n + 1))) | ((y & ~(0xFF << n)) << (p - n + 1));
}
