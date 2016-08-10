/*
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 *You are given a target value to search. If found in the array return its index, otherwise return -1.
 *
 *You may assume no duplicate exists in the array.
 */

 /*
  * 思想：取得mid值后，做判断：
  * 1. 如果nums[mid]比nums[left]大，那么说明left到mid一定是递增的，然后判断target是否在[left,mid]区间内
  *    如果是的话就修改right；否则，target在mid右边，修改left。
  * 2. 如果nums[mid]比nums[left]小，如果这个时候nums[mid]<nums[right]，那么[mid,right]一定是递增的，
  *    判断target是否在该区间内，如果是，修改left，否则修改right
  * 要注意的是值不存在的情况，如果区间长度缩小到了2，这个时候nums[left]==nums[mid],说明可以返回-1了，因为如果
  * 要判断的话在比较前已经判断出来了。
  *
  */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[left]==target){
                return left;
            }
            if(nums[right]==target){
                return right;
            }
            if(nums[mid]>nums[left]){
                if(nums[left]<target&&target<nums[mid]){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }else if(nums[mid]<nums[left]){
                if(nums[mid]<target&&target<nums[right]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }else if(nums[mid]==nums[left]){
                return -1;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(5);
    nums.push_back(1);
    nums.push_back(3);
    Solution object;
    cout<<object.search(nums,0)<<endl;
    return 0;
}
