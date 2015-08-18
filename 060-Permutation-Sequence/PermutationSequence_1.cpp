/*
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 *
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 *
 *  1.  "123"
 *  2.  "132"
 *  3.  "213"
 *  4.  "231"
 *  5.  "312"
 *  6.  "321"
 *
 * Given n and k, return the kth permutation sequence.
 *
 * Note: Given n will be between 1 and 9 inclusive.
 */

 /* 思想：用了DFS，但是TLE */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int count;
    string result;

    void DFS(vector<int> &nums,vector<int> &current,vector<bool> &visited,int n,int k){
        if(current.size()==(unsigned int)n){
            count++;
            if(count==k){
                for(unsigned int i=0;i<current.size();i++){
                    result+=current[i]+'0';
                }
                return;
            }
        }
        for(unsigned int i=0;i<nums.size();i++){
            if(visited[i]==true){
                continue;
            }
            current.push_back(nums[i]);
            visited[i]=true;
            DFS(nums,current,visited,n,k);
            visited[i]=false;
            current.pop_back();
        }
        return;
    }

    string getPermutation(int n, int k) {
        vector<int> nums;
        vector<bool> visited;
        for(int i=0;i<n;i++){
            nums.push_back(i+1);
            visited.push_back(false);
        }
        vector<int> current;
        count=0;
        result="";
        DFS(nums,current,visited,n,k);
        return result;
    }
};

int main()
{
    Solution object;
    cout<<object.getPermutation(9,5);
    return 0;
}
