#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        return findMin(nums, low, high);
    }

    int findMin(vector<int>& nums, int low, int high) {
    	while(low < high-1) {
    		int mid = (low + high)/2;
    		if(nums[mid] >= nums[low] && nums[mid] <= nums[high]) {
    			high = low;
    		}else if(nums[mid] >= nums[low] && nums[mid] >= nums[high]) {
    			low = mid;
    		}else if(nums[mid] <= nums[low] && nums[mid] <= nums[high]) {
    			high = mid;
    		}
    	}
    	return nums[low] <= nums[high] ? nums[low] : nums[high];
    }
};

int main(){
	int a[] = {1, 2, 3};
	vector<int> nums(a, a+3);
	Solution object;
	cout << object.findMin(nums) << endl;
	return 0;
}