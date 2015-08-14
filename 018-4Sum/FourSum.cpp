/*
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
 * Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note:
 *   Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 *   The solution set must not contain duplicate quadruplets.
 *
 *   For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *
 *   A solution set is:
 *   (-1,  0, 0, 1)
 *   (-2, -1, 1, 2)
 *   (-2,  0, 0, 2)
 *
 */

 /* 思想：利用之前计算过的TwoSum，个人觉得这道题目最需要注意的就是去重了。
  * 一部分体现在3Sum这道题目中的情况，另一部分在于双重循环时的去重，比如：
  * 当前序列为[-4,-4,-1,-1,0]，第一重循环当i指向为-4，j也指向-4，循环n次
  * 后，当i指向第二个-4，这个时候i应该跳过这个-4指向第一个-1，因为这时所有的情况第一次都
  * 以及遍历过了。
  *
  *  -4 -4 -1 -1 0
  *   i  j
  *
  *   -4 -4 -1 -1 0                                                                     -4 -4 -1 -1 0
  *       i  j      =>就是这种情况下，i应该跳过-4，因为在i=0的时候有一种情况是这样的：   i     j
  *
  */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > twoSum(vector<int> &nums,int target,int low,int high){
        vector<vector<int> > result;
        result.clear();
        vector<int> current;
        while(low<high){
            if(nums[low]+nums[high]==target){
                current.push_back(nums[low]);
                current.push_back(nums[high]);
                result.push_back(current);
                current.clear();
                while(nums[low+1]==nums[low]){
                    low++;
                }
                low++;
                while(nums[high-1]==nums[high]){
                    high--;
                }
                high--;
            }else if(nums[low]+nums[high]<target){
                low++;
            }else{
                high--;
            }
        }
        return result;
    }

    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        bool flag=false;
        unsigned int index=0;
        result.clear();
        if(nums.size()<4){
            return result;
        }
        sort(nums.begin(),nums.end());
        for(unsigned int i=0;i<nums.size()-3;i++){
            flag=false;
            for(index=0;index<i;index++){
                if(nums[index]==nums[i]){
                    flag=true;
                    break;
                }
            }
            if(flag){
                continue;
            }
            for(unsigned int j=i+1;j<nums.size()-2;j++){
                flag=false;
                for(index=i+1;index<j;index++){ //要注意是从i+1开始
                    if(nums[index]==nums[j]){
                        flag=true;
                        break;
                    }
                }
                if(flag){
                    continue;
                }
                vector<vector<int> > two=twoSum(nums,target-nums[i]-nums[j],j+1,nums.size()-1);
                if(two.size()==0){
                    continue;
                }else{
                    for(unsigned int k=0;k<two.size();k++){
                        vector<int> current;
                        current.push_back(nums[i]);
                        current.push_back(nums[j]);
                        current.push_back(two[k][0]);
                        current.push_back(two[k][1]);
                        result.push_back(current);
                        current.clear();
                    }
                    two.clear();
                }
            }
        }
        return result;
    }
};
int main()
{
    vector<int> nums;
    nums.push_back(-4);
    nums.push_back(-1);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    Solution object;
    vector<vector<int> > result=object.fourSum(nums,-1);
    for(unsigned int i=0;i<result.size();i++){
        for(unsigned int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
