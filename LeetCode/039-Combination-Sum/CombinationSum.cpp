/*
 * Given a set of candidate numbers (C) and a target number (T),
 * find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * 1.All numbers (including target) will be positive integers.
 * 2.Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * 3.The solution set must not contain duplicate combinations.
 *
 * For example, given candidate set 2,3,6,7 and target 7,
 * A solution set is:
 * [7]
 * [2, 2, 3]
 */
 
 /*思想：我用了深度优先搜索然后再排序去重的办法，效率不高*/

#include <iostream>
#include <vector>

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

    bool isEqual(vector<int> &a,vector<int> &b){
        if(a.size()!=b.size()){
            return false;
        }
        for(unsigned int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }

    void quickSort(vector<int> &nums,int low,int high){
        if(low>=high){
            return;
        }
        int first=low;
        int last=high;
        int key=nums[first];
        while(first<last){
            while(first<last&&nums[last]>=key){
                --last;
            }
            nums[first]=nums[last];
            while(first<last&&nums[first]<=key){
                ++first;
            }
            nums[last]=nums[first];
        }
        nums[first]=key;
        quickSort(nums,low,first-1);
        quickSort(nums,first+1,high);
    }

    vector<vector<int> > removeDuplicate(vector<vector<int> > &result){
        vector<vector<int> > ret;
        if(result.size()==1){
            return result;
        }
        ret.push_back(result[0]);
        for(unsigned int i=1;i<result.size();i++){
            bool hasEqual=false;
            for(unsigned int j=0;j<ret.size();j++){
                if(isEqual(result[i],ret[j])){
                    hasEqual=true;
                    break;
                }
            }
            if(!hasEqual){
                ret.push_back(result[i]);
            }
        }
        return ret;
    }

    void DFS(vector<int> &nums,vector<int> &current,int target){
        if(currentSum(current)>target){
            return;
        }
        if(currentSum(current)==target){
            result.push_back(current);
            return;
        }
        for(unsigned int i=0;i<nums.size();i++){
            current.push_back(nums[i]);
            DFS(nums,current,target);
            current.pop_back();
        }
        return;
    }


    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        result.clear();
        vector<int> current;
        DFS(candidates,current,target);
        if(result.size()==0){
            return result;
        }
        for(unsigned int i=0;i<result.size();i++){
            quickSort(result[i],0,result[i].size()-1);
        }
        vector<vector<int> > answer=removeDuplicate(result);
        return answer;
    }
};

int main()
{
    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(6);
    candidates.push_back(7);
    Solution object;
    vector<vector<int> > result=object.combinationSum(candidates,1);
    for(unsigned int i=0;i<result.size();i++){
        for(unsigned int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
