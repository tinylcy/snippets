/* A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach
the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Note: m and n will be at most 100. */

/*
 *思想：动态规划，递推方程：dp[i][j]=dp[i][j-1]+dp[i-1][j]，
 *初始化dp的时候将第一行和第一列都设置为1（dp[0][0]除外，设为0）。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void initDP(vector<vector<int> > &dp,int m,int n){
        for(int i=0;i<m;i++){
            vector<int> row;
            row.clear();
            for(int j=0;j<n;j++){
                row.push_back(0);
            }
            dp.push_back(row);
        }
        for(int i=1;i<m;i++) dp[i][0]=1;
        for(int j=1;j<n;j++) dp[0][j]=1;
    }

    int uniquePaths(int m, int n) {
        if(m==1||n==1){
            return 1;
        }
        vector<vector<int> > dp;
        initDP(dp,m,n);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i][j-1]+dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int main()
{
    Solution object;
    cout<<object.uniquePaths(36,7)<<endl;
    return 0;
}
