/*
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 *
 *  Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 *  The solution set must not contain duplicate triplets.
 *
 *  For example, given array S = {-1 0 1 2 -1 -4},
 *
 *  A solution set is:
 *  (-1, 0, 1)
 *  (-1, -1, 2)
 */

/*
 * 思想：利用TwoSum的思想，要注意的是去重：第一种情况在注释里面描述了；
 * 第二种情况：考虑序列如：-2,0,0,2,2；当遍历到-2时，一开始low和high分别在0和2，
 * 接下来low加1后依旧指向0，high减1后依旧指向2，所以这是另一种重复的情况。
 * 所以在处理low和high时，如果low和high改变后指向的值和之前指向的值一样，那么继续改变。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> current;
        result.clear();
        if(nums.size()<3){
            return result;
        }
        sort(nums.begin(),nums.end());
        for(unsigned int i=0;i<nums.size()-2;i++){
            bool flag=false;
            for(unsigned int j=0;j<i;j++){
                if(nums[j]==nums[i]){
                    flag=true;
                }
            }
            /*
             * 去掉重复的情况，比如针对序列：-4，-1，-1，0，1，2；第2个-1是用不着遍历了，
             * 因为前一个-1涵盖了第二个的所有可能情况
             */
            if(flag){
                continue;
            }
            int low=i+1;
            int high=nums.size()-1;
            current.clear();
            while(low<high){
                if(nums[low]+nums[high]==-nums[i]){
                    current.push_back(nums[i]);
                    current.push_back(nums[low]);
                    current.push_back(nums[high]);
                    result.push_back(current);
                    current.clear();
                    while(nums[low+1]==nums[low]){
                        low++;
                    }
                    low++; //再往后挪一下，才跳到和上次不一样的值
                    while(nums[high-1]==nums[high]){
                        high--;
                    }
                    high--; //再往前挪一下，才跳到和上次不一样的值
                }else if(nums[low]+nums[high]<-nums[i]){
                    low++;
                }else{
                    high--;
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-1);
    nums.push_back(-4);
    Solution object;
    vector<vector<int> > result=object.threeSum(nums);
    for(unsigned int i=0;i<result.size();i++){
        for(unsigned int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
