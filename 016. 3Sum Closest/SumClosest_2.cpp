/*
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
 * Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *
 *  For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 *  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

/*
 * 思想：对于nums中每个数i，找到剩余数中的两个数字，它们的和最接近target-nums[i]，
 * 所以把找3个数的问题转化成找2个数的问题。把所有数字排序，然后由两边向中间收缩。但是
 * 并不是说是收缩到最后的结果就是答案，收缩归收缩，更新归更新。比如：nums=1,2,3,4,5,100; target=99
 * 我一开始就是犯了这个错误。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int abs(int x){
        return x>0?x:-x;
    }

    int twoSumClosest(vector<int> &nums,int low,int high,int target){
        int currentSum=0;
        int closestRange=0;
        int closestSum=0;
        bool isFirst=true;
        while(low<high){
            currentSum=nums[low]+nums[high];
            if(isFirst){
                closestSum=currentSum;
                closestRange=abs(currentSum-target);
                isFirst=false;
            }else{
                if(abs(currentSum-target)<closestRange){
                    closestSum=currentSum;
                    closestRange=currentSum-target;
                }
            }
            if(currentSum==target){
                return currentSum;
            }else if(currentSum<target){
                low++;
            }else if(currentSum>target){
                high--;
            }
        }
        return closestSum;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        bool isFirst=true;
        int closestRange=0;
        int closestSum=0;
        sort(nums.begin(),nums.end());
        for(unsigned int i=0;i<nums.size()-2;i++){
            int twoClosest=twoSumClosest(nums,i+1,nums.size()-1,target-nums[i]);
            if(isFirst){
                closestRange=abs(nums[i]+twoClosest-target);
                closestSum=nums[i]+twoClosest;
                isFirst=false;
            }else{
                if(abs(nums[i]+twoClosest-target)<=closestRange){
                    closestRange=abs(nums[i]+twoClosest-target);
                    closestSum=nums[i]+twoClosest;
                }
            }
        }
        return closestSum;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    Solution object;
    cout<<object.threeSumClosest(nums,1)<<endl;
    return 0;
}
