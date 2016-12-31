#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b, int n);

int main(void) {

}

void reverse(char s[]) {

}

void reverse_recursive(char s[], int size) {
	if(size % 2 == 0) {
		swap(s, s + size / 2 - 1, size / 2);

	}
}

void swap(char *a, char *b, int n) {
	while(n > 0) {
		char tmp = *a;
		*a = *b;
		*b = tmp;
		a++;
		b++;
		n--;
	}
}
