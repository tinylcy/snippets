/* Given a string S, find the longest palindromic substring in S. You may assume that the
maximum length of S is 1000, and there exists one unique longest palindromic substring. */

/*
 * 思想：遍历s的每个字符，从字符中心向两边扩展。需要考虑两种情况：
 * 1.所求得的最长回文字串的长度为偶数；2.所求得的最长回文字串的长度为奇数。
 * 把两种情况都计算一遍。AC。
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int length=s.size();
        int before=0,after=0;
        int startPos=0,maxLen=1;
        /* 如果所求得的最长回文字串长度为奇数 */
        for(int i=0;i<length;i++){
            before=i-1;
            after=i+1;
            while(before>=0&&after<length&&s[before]==s[after]){
                if(after-before+1>maxLen){
                    maxLen=after-before+1;
                    startPos=before;
                }
                before--;
                after++;
            }
        }
        /* 如果所求得的最长回文字串长度为偶数 */
        for(int i=0;i<length;i++){
            before=i;
            after=i+1;
            while(before>=0&&after<length&&s[before]==s[after]){
                if(after-before+1>maxLen){
                    maxLen=after-before+1;
                    startPos=before;
                }
                before--;
                after++;
            }
        }
        return s.substr(startPos,maxLen);
    }
};

int main()
{
    Solution object;
    cout<<object.longestPalindrome("tattarrattat")<<endl;
    return 0;
}
