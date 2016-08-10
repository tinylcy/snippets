/* Given a set of distinct integers, nums, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
] */

/*思想：DFS*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > result;

    void DFS(vector<int> &nums,vector<int> &current,vector<bool> &visited,unsigned int targetLen){
        if(current.size()==targetLen){
            result.push_back(current);
            return;
        }
        for(unsigned int i=0;i<nums.size();i++){
            if(visited[i]==true){
                continue;
            }
            bool flag=false;
            for(unsigned int j=0;j<i;j++){ //去重
                if(nums[j]==nums[i]&&visited[j]==false){
                    flag=true;
                    break;
                }
            }
            if(flag){
                continue;
            }
            flag=false;
            for(unsigned int j=0;j<current.size();j++){ //递增排序
                if(current[j]>nums[i]){
                    flag=true;
                    break;
                }
            }
            if(flag){
                continue;
            }
            current.push_back(nums[i]);
            visited[i]=true;
            DFS(nums,current,visited,targetLen);
            visited[i]=false;
            current.pop_back();
        }
        return;
    }

    void initVisited(vector<bool> &visited,int size){
        visited.clear();
        for(int i=0;i<size;i++){
            visited.push_back(false);
        }
    }

    vector<vector<int> > subsets(vector<int>& nums) {
        vector<bool> visited;
        vector<int> current;
        result.clear();
        if(nums.size()==0){
            return result;
        }
        sort(nums.begin(),nums.end());
        for(unsigned int i=0;i<=nums.size();i++){
            initVisited(visited,nums.size());
            current.clear();
            DFS(nums,current,visited,i);
        }
        return result;
    }
};

int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    Solution object;
    vector<vector<int> > result=object.subsets(nums);
    for(unsigned int i=0;i<result.size();i++){
        for(unsigned int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
