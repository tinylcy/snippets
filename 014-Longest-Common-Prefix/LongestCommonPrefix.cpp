/*
 * Write a function to find the longest common prefix string amongst an array of strings. 
 */

#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class Solution {
public:

    string commonPredfix(string a,string b){
        string common="";
        unsigned int index=0;
        while(index<a.size()&&index<b.size()){
            if(a[index]==b[index]){
                common+=a[index];
            }else{
                break;
            }
            index++;
        }
        return common;
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }
        if(strs.size()==1){
            return strs[0];
        }
        string result=strs[0];
        for(unsigned int index=1;index<strs.size();index++){
            result=commonPredfix(result,strs[index]);
        }
        return result;
    }
};

int main()
{
    vector<string> strs;
    strs.push_back("abcdefr");
    strs.push_back("abcdefg");
    strs.push_back("abcefr");
    strs.push_back("abcdefr");
    strs.push_back("abcee");
    Solution object;
    cout<<object.longestCommonPrefix(strs);
    return 0;
}
