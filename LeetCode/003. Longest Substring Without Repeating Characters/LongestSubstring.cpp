/*Given a string, find the length of the longest substring without repeating characters. 
 *For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
 *which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int visited[10000];
        int maxLength=1;
        int sLength=s.length();
        if(sLength==0)
            return 0;
        memset(visited,-1,10000);
        for(int i=0;i<sLength;++i){
            visited[(int)s[i]]=1;
            for(int j=i+1;j<sLength;++j){
                if(visited[(int)s[j]]==-1){
                    visited[(int)s[j]]=1;
                    if(j-i+1>maxLength){
                        maxLength=j-i+1;
                    }
                }else{
                    break;
                }
            }
            memset(visited,-1,10000);
        }
        return maxLength;
    }
};

int main()
{
    Solution object;
    cout<<object.lengthOfLongestSubstring("b")<<endl;
    return 0;
}
