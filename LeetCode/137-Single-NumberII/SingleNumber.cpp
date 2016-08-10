#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int N=nums.size();
        int singleNum=0;
        for(int i=0;i<N;i++){
        	singleNum=singleNum^nums[i];
        }
        return singleNum;
    }
};

int main() {
	Solution object;
	int a[5] = {5, 1, 2, 1, 5};
	vector<int> nums(a,a+5);
	cout<<object.singleNumber(nums)<<endl;
	return 0;
}