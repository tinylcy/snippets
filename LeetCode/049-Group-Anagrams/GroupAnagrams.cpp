/* Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
   1. For the return value, each inner list's elements must follow the lexicographic order.
   2. All inputs will be in lower-case. */


/*思想：用了最low的方法，自己设置一个哈希函数：对于每个字符串str，其哈希值就是str所有字符按照字典序排好后的字符串。
  然后遍历strs，按照哈希值将strs中的元素存到一个map内，然后依次排序map中的值，map中的值组成的vector就是
  所求结果。AC 128ms */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    string hash(string str){
        vector<char> value;
        for(unsigned int index=0;index<str.size();index++){
            value.push_back(str[index]);
        }
        sort(value.begin(),value.end());
        string ret="";
        for(unsigned int index=0;index<value.size();index++){
            ret+=value[index];
        }
        return ret;
    }

    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        map<string,vector<string> > dictionary;
        for(unsigned int i=0;i<strs.size();i++){
            string hashValue=hash(strs[i]);
            if(dictionary.count(hashValue)==0){
                vector<string> tmp;
                tmp.push_back(strs[i]);
                dictionary.insert(make_pair(hashValue,tmp));
            }else{
                dictionary[hashValue].push_back(strs[i]);
            }
        }
        map<string,vector<string> >::iterator iter;
        vector<vector<string> > result;
        for(iter=dictionary.begin();iter!=dictionary.end();iter++){
            sort(iter->second.begin(),iter->second.end());
            result.push_back(iter->second);
        }
        return result;
    }
};

int main()
{
    vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");
    Solution object;
    vector<vector<string> > result=object.groupAnagrams(strs);
    for(unsigned int i=0;i<result.size();i++){
        for(unsigned int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
