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

 /* 思想：通过交换数字实现，但还是TLE */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isFirst;

    void reverse(vector<int> &current,int low,int high){
        while(low<high){
            int tmp=current[low];
            current[low]=current[high];
            current[high]=tmp;
            low++;
            high--;
        }
    }

    string vectorToString(vector<int> &current){
        string ret="";
        for(unsigned int i=0;i<current.size();i++){
            ret+=current[i]+'0';
        }
        return ret;
    }


    vector<int> nextPermutation(vector<int> &current){
        if(isFirst){
            reverse(current,current.size()-2,current.size()-1);
            isFirst=false;
            return current;
        }
        int left=0,right=0;
        for(int i=current.size()-1;i>=1;i--){
            if(current[i-1]<current[i]){
                left=i-1;
                break;
            }
        }
        for(int i=current.size()-1;i>=0;i--){
            if(current[i]>current[left]){
                right=i;
                break;
            }
        }
        int tmp=current[left];
        current[left]=current[right];
        current[right]=tmp;
        reverse(current,left+1,current.size()-1);
        return current;
    }

    string getPermutation(int n, int k) {
        vector<int> current;
        isFirst=true;
        for(int i=1;i<=n;i++){
            current.push_back(i);
        }
        if(k==1){
            return vectorToString(current);
        }
        for(int i=2;i<=k;i++){
            current=nextPermutation(current);
        }
        return vectorToString(current);
    }
};

int main()
{
    Solution object;
    cout<<object.getPermutation(9,219601);
    return 0;
}
