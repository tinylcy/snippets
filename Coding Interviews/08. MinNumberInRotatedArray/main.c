#include <stdio.h>

int findMin(int*, int);
int findMinSequential(int*, int);

/*
 * 考虑3种情况：
 *    1. 旋转数组本身就是有序数组，如[1, 2, 3, 4, 5]
 *    2. 旋转数组为常规的旋转数组，如[3, 4, 5, 1, 2]
 *    3. 旋转数组中相等的元素，以至于无法区分最小的元素是在左还是右，如[1, 0, 1, 1, 1]和[1, 1, 1, 0, 1]
 */

int main(void) {
	int number1[] = {3, 4, 5, 1, 2};
	printf("%d\n", findMin(number1, 5));

	int number2[] = {1, 2, 3, 4, 5};
	printf("%d\n", findMin(number2, 5));

	int number3[] = {3, 4, 5, 1, 2, 3};
	printf("%d\n", findMin(number3, 6));

	int number4[] = {1, 0, 1, 1, 1};
	printf("%d\n", findMin(number4, 5));

	int number5[] = {1, 1, 1, 0, 1};
	printf("%d\n", findMin(number5, 5));
}

int findMin(int *number, int length) {
	int start = 0;
	int end = length - 1;

	if(number[start] < number[end]) {
		return number[start];
	}

	while(start <= end) {
		if(start + 1 == end) {
			break;
		}

		int mid = (start + end) / 2;
		
		if(number[start] == number[mid] && number[mid] == number[end]) {
			return findMinSequential(number, length);
		}

		if(number[mid] >= number[start]) {
			start = mid;
		}else {
			end = mid;
		}
	}

	return number[end];
}

/*
 * 顺序查找
 */
int findMinSequential(int *number, int length) {
	int min = number[0];
	for(int i = 0; i < length; i++) {
		if(number[i] < min) {
			min = number[i];
		}
	}
	return min;
}