/*
 Given an unsorted integer array, find the first missing positive integer.

 For example,
 Given [1,2,0] return 3,
 and [3,4,-1,1] return 2.

 Your algorithm should run in O(n) time and uses constant space.
*/

/* 思想：哈希*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> hashTable;
        int maxValue=0;
        for(unsigned int i=0;i<nums.size();i++){
            if(nums[i]>maxValue){
                maxValue=nums[i];
            }
        }
        hashTable.clear();
        for(int i=0;i<=maxValue;i++){
            hashTable.push_back(0);
        }
        for(unsigned int i=0;i<nums.size();i++){
            if(nums[i]>0){
                hashTable[nums[i]]=1;
            }
        }
        for(int i=1;i<=maxValue;i++){
            if(hashTable[i]==0){
                return i;
            }
        }
        return maxValue+1;
    }
};

int main()
{
    Solution object;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    cout<<object.firstMissingPositive(nums)<<endl;
    return 0;
}
