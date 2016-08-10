/*
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
 * Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *
 *  For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 *  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

/* 思想：DFS */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int result;
    bool isFirst;

    int abs(int x){
        return x>0?x:-x;
    }

    int currentSum(vector<int> &current){
        int sum=0;
        for(unsigned int i=0;i<current.size();i++){
            sum+=current[i];
        }
        return sum;
    }

    void DFS(vector<int> &nums,vector<int> &current,vector<bool> &visited,int target){
        if(current.size()==3){
            int sum=currentSum(current);
            if(isFirst){
                result=sum;
                isFirst=false;
            }else{
                if(abs(sum-target)<result){
                    result=sum;
                }
            }
        }
        for(unsigned int i=0;i<nums.size();i++){
            if(visited[i]==true){
                continue;
            }
            bool flag=false;
            for(unsigned int j=0;j<i;j++){
                if(nums[j]==nums[i]&&visited[j]==false){
                    flag=true;
                    break;
                }
            }
            if(flag){
                continue;
            }
            current.push_back(nums[i]);
            visited[i]=true;
            DFS(nums,current,visited,target);
            visited[i]=false;
            current.pop_back();
        }
    }

    int threeSumClosest(vector<int>& nums, int target) {
        vector<bool> visited;
        for(unsigned int i=0;i<nums.size();i++){
            visited.push_back(false);
        }
        vector<int> current;
        result=0;
        isFirst=true;
        DFS(nums,current,visited,target);
        return result;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-4);
    Solution object;
    cout<<object.threeSumClosest(nums,5)<<endl;
    return 0;
}
