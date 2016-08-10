/* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

/*思想：DFS*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > result;

    void DFS(vector<int> &nums,vector<int> &current,vector<bool> &visited,int k){
        if(current.size()==(unsigned int)k){
            result.push_back(current);
            return;
        }
        for(unsigned int i=0;i<nums.size();i++){
            if(visited[i]==true){
                continue;
            }
            bool flag=false;
            for(unsigned int j=0;j<current.size();j++){
                if(current[j]>nums[i]){
                    flag=true;
                }
            }
            if(flag){
                continue;
            }
            current.push_back(nums[i]);
            visited[i]=true;
            DFS(nums,current,visited,k);
            visited[i]=false;
            current.pop_back();
        }
        return;
    }

    vector<vector<int> > combine(int n, int k) {
        result.clear();
        if(n==0||n<k){
            return result;
        }
        vector<int> nums;
        vector<bool> visited;
        for(int i=1;i<=n;i++){
            nums.push_back(i);
            visited.push_back(false);
        }
        vector<int> current;
        DFS(nums,current,visited,k);
        return result;
    }
};

int main()
{
    vector<vector<int> > result;
    Solution object;
    result=object.combine(10,3);
    for(unsigned int i=0;i<result.size();i++){
        for(unsigned int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
