/* Given a string S, find the longest palindromic substring in S. You may assume that the
maximum length of S is 1000, and there exists one unique longest palindromic substring. */

/*
 * 思想：动态规划，如果dp[i][j]=1，说明s(i)到s(j)是回文串(包括i,j)，否则不是回文串。
 * 而回文串的字串依旧是回文串，这里设定递推方程是用来判断“是”还是“不是”回文串。
 * 递推方程：
 *         if(i==j) => dp[i][j]=1
 *         if(s[i]=s[j]) => dp[i][j]=dp[i+1][j-1]
 *         if(s[i]!=s[j]) => dp[i][j]=0
 *
 * 然而 TLE.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s,int left,int right){
        if(right<=left){
            return true;
        }
        if(s[left]!=s[right]){
            return false;
        }
        return isPalindrome(s,left+1,right-1);
    }

    string longestPalindrome(string s) {
        int length=s.size();
        int startPos=0,maxLen=-1;
        string result="";
        for(int i=0;i<length;i++){
            for(int j=i;j<length;j++){
                if(isPalindrome(s,i,j)){
                    if((j-i)>maxLen){
                        maxLen=j-i;
                        startPos=i;
                        result=s.substr(startPos,maxLen);
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution object;
    cout<<object.longestPalindrome("tattarrattat")<<endl;
    return 0;
}
