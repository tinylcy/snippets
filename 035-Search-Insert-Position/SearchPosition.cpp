/*
 * Given a sorted array and a target value, return the index if the target is found.
 * If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target>nums[nums.size()-1]){
            return nums.size();
        }
        if(target<nums[0])
            return 0;
        int index=0;
        while(nums[index]<target){
            ++index;
        }
        return index;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(5);
    nums.push_back(6);
    Solution object;
    cout<<object.searchInsert(nums,0)<<endl;
    return 0;
}
