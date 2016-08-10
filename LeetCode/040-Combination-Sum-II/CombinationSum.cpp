/*
 * Given a collection of candidate numbers (C) and a target number (T),
 * find all unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 *  All numbers (including target) will be positive integers.
 *  Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 *  The solution set must not contain duplicate combinations.
 *
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 * A solution set is:
 * [1, 7]
 * [1, 2, 5]
 * [2, 6]
 * [1, 1, 6]
 */

/*
 * 在最原始的全排列的基础上，再设置两个规则来解决问题：
 * 如何避免由于重复数字导致的重复：如果存在相同的数，那么必须先使用前面的数再使用后面的数字；
 * 如何避免出现1,2,5和1,5,2的情况：先将所有的数字排序。在构建所有可能的序列中，要求所有的数字都是递增的。
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int> > result;

    int currentSum(vector<int> &current){
        int sum=0;
        for(unsigned int i=0;i<current.size();i++){
            sum+=current[i];
        }
        return sum;
    }

    void DFS(vector<int> &nums,vector<int> &current,int target,vector<bool> &visited){
        if(currentSum(current)>target){
            return;
        }
        if(currentSum(current)==target){
            result.push_back(current);
            return;
        }
        for(unsigned int i=0;i<nums.size();i++){
            if(visited[i]==true){
                continue;
            }else{
                bool flag=false;
                for(unsigned int j=0;j<i;j++){
                    if(nums[j]==nums[i]&&visited[j]==false){
                        flag=true;
                        break;
                    }
                }
                for(unsigned int k=0;k<current.size();k++){
                    if(current[k]>nums[i]){
                        flag=true;
                        break;
                    }
                }
                if(flag){
                    continue;
                }else{
                    current.push_back(nums[i]);
                    visited[i]=true;
                    DFS(nums,current,target,visited);
                    current.pop_back();
                    visited[i]=false;
                }
            }
        }
        return;
    }

    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        vector<int> current;
        vector<bool> visited;
        for(unsigned int i=0;i<candidates.size();i++){
            visited.push_back(false);
        }
        result.clear();
        sort(candidates.begin(),candidates.end());
        DFS(candidates,current,target,visited);
        return result;
    }
};

int main()
{
    vector<int> candidates;
    candidates.push_back(10);
    candidates.push_back(1);
    candidates.push_back(2);
    candidates.push_back(7);
    candidates.push_back(6);
    candidates.push_back(1);
    candidates.push_back(5);
    Solution object;
    vector<vector<int> > result=object.combinationSum2(candidates,8);
    for(unsigned int i=0;i<result.size();i++){
        for(unsigned int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
