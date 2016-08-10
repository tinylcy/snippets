#include <iostream> 
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int N = nums.size();
        int aux[N];
        for(int i = 0; i < N; i++) {
        	aux[i] = nums[i];
        }
        k = k % N;
        for(int i = N - k, j = 0; j < N; i++, j++) {
        	nums[j] = aux[i % N];
        }
    }
};


int main() {
	Solution solution;
	int a[2] = {1, 2};
	vector<int> nums(a, a+2);
	solution.rotate(nums, 3); 
	for(int i = 0; i < nums.size(); i++) {
		cout << nums[i] << " ";
	}
}