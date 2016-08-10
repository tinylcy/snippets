/* Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time. */

/* 思想：动态规划：递推方程为dp[i][j]=grid[i][j]+min(dp[i][j-1],dp[i-1][j]) */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void initDP(vector<vector<int> > &dp,vector<vector<int> >& grid){
        int width=grid[0].size();
        int height=grid.size();
        for(int i=0;i<height;i++){ //初始化整个dp都为0
            vector<int> row;
            row.clear();
            for(int j=0;j<width;j++){
                row.push_back(0);
            }
            dp.push_back(row);
        }
        dp[0][0]=grid[0][0];
        for(int i=1;i<height;i++){ //初始化dp的第一列，累加
            dp[i][0]=grid[i][0]+dp[i-1][0];
        }
        for(int j=1;j<width;j++){  //初始化dp的第一行，累加
            dp[0][j]=grid[0][j]+dp[0][j-1];
        }
    }

    int minPathSum(vector<vector<int> >& grid) {
        vector<vector<int> > dp;
        int width=grid[0].size();
        int height=grid.size();
        initDP(dp,grid);
        for(int i=1;i<height;i++){
            for(int j=1;j<width;j++){
                int left=grid[i][j]+dp[i][j-1]; //从左边到达
                int up=grid[i][j]+dp[i-1][j]; //从上面到达
                dp[i][j]=(left<=up?left:up);
            }
        }
        return dp[height-1][width-1];
    }
};

int main()
{
    vector<vector<int> > grid;
    vector<int> row1;
    vector<int> row2;
    vector<int> row3;
    row1.push_back(1);
    row1.push_back(4);
    row1.push_back(3);
    row1.push_back(2);
    row2.push_back(2);
    row2.push_back(5);
    row2.push_back(1);
    row2.push_back(7);
    row3.push_back(3);
    row3.push_back(2);
    row3.push_back(5);
    row3.push_back(2);
    grid.push_back(row1);
    grid.push_back(row2);
    grid.push_back(row3);
    Solution object;
    cout<<object.minPathSum(grid)<<endl;
    return 0;
}
