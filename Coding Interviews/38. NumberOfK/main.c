#include <stdio.h>
#include <stdlib.h>

int numberOfK(int *, int, int);
int findLeftest(int *, int, int, int);
int findRightest(int *, int, int, int);
int findK(int *, int, int, int);

int main(void) {
	int nums1[] = {1, 2, 3, 3, 3, 3, 4, 5};
	int nums2[] = {2};
	int nums3[] = {2, 2, 2, 2, 2, 2, 2, 2};
	int count;
	count = numberOfK(nums1, 8, 3);
	printf("count = %d\n", count);
	count = numberOfK(nums2, 1, 2);
	printf("count = %d\n", count);
	count = numberOfK(nums3, 8, 2);
	printf("count = %d\n", count);

	return 0;
}

int numberOfK(int nums[], int len, int k) {
	int low = 0, high = len - 1;
	int mid, leftest, rightest;
	mid = findK(nums, low, high, k);
	if(mid == -1) {
		return -1;
	}

	leftest = findLeftest(nums, low, mid, k);
	rightest = findRightest(nums, mid, high, k);

	return rightest - leftest + 1;
}

int findLeftest(int nums[], int low, int high, int k) {
	int mid, leftest;
	mid = findK(nums, low, high, k);
	while(mid != -1) {
		leftest = mid;
		high = mid - 1;
		mid = findK(nums, low, high, k);
	}
	return leftest;
}

int findRightest(int nums[], int low, int high, int k) {
	int mid, rightest;
	mid = findK(nums, low, high, k);
	while(mid != -1) {
		rightest = mid;
		low = mid + 1;
		mid = findK(nums, low, high, k);
	}
	return rightest;
}

int findK(int nums[], int low, int high, int k) {
	while(low <= high) {
		int mid = (low + high) / 2;
		if(nums[mid] == k) {
			return mid;
		}
		if(k < nums[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	
	return -1;
}

