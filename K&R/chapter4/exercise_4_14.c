#include <stdio.h>

#define swap(t,x,y) (t)=(x);(x)=(y);(y)=(t)

int main(void) {
	int a = 1;
	int b = 2;
	int t;
	swap(t,a,b);

	printf("a = %d, b = %d\n", a, b);

	return 0;
}
