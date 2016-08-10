/* Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

The total number of unique paths is 2.

Note: m and n will be at most 100. */

/* 思想：动态规划，递推方程为dp[i][j]=dp[i][j-1]+dp[i-1][j],要注意的是dp数组第一行和第一列的初始化 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void initDP(vector<vector<int> > &dp,vector<vector<int> >& obstacleGrid){
        int width=obstacleGrid[0].size();
        int height=obstacleGrid.size();
        bool hasObstacle=false; //初始化第一列，碰到一个1，剩余的都为0，即不可达
        for(int i=1;i<height;i++){
            if(obstacleGrid[i][0]==1){
                hasObstacle=true;
            }
            if(hasObstacle){
                dp[i][0]=0;
            }else{
                dp[i][0]=1;
            }
        }
        hasObstacle=false;
        for(int j=1;j<width;j++){ //初始化第一行，碰到一个1，剩余的都为0，即不可达
            if(obstacleGrid[0][j]==1){
                hasObstacle=true;
            }
            if(hasObstacle){
                dp[0][j]=0;
            }else{
                dp[0][j]=1;
            }
        }
    }

    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        vector<vector<int> > dp;
        int width=obstacleGrid[0].size();
        int height=obstacleGrid.size();
        if(width==1||height==1){         //只有一行或者只有一列
            for(int i=0;i<height;i++){
                for(int j=0;j<width;j++){
                    if(obstacleGrid[i][j]==1){
                        return 0;
                    }
                }
            }
            return 1;
        }
        if(obstacleGrid[0][1]==1&&obstacleGrid[1][0]==1){ //起点右边和下面都是障碍，直接返回0
            return 0;
        }
        for(int i=0;i<height;i++){ //初始化dp
            vector<int> row;
            row.clear();
            for(int j=0;j<width;j++){
                row.push_back(0);
            }
            dp.push_back(row);
        }
        initDP(dp,obstacleGrid); //初始化dp的第一行和第一列
        for(int i=1;i<height;i++){
            for(int j=1;j<width;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                }else{
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
                }
            }
        }
        return dp[height-1][width-1];
    }
};

int main()
{
    vector<vector<int> > obstacleGrid;
    vector<int> row1;
    vector<int> row2;
    vector<int> row3;
    vector<int> row4;

    row1.push_back(0);
    row1.push_back(0);
    row1.push_back(0);
    row1.push_back(1);
    row1.push_back(0);

    row2.push_back(0);
    row2.push_back(0);
    row2.push_back(1);
    row2.push_back(0);
    row2.push_back(0);

    row3.push_back(0);
    row3.push_back(0);
    row3.push_back(0);
    row3.push_back(0);
    row3.push_back(0);

    row4.push_back(0);
    row4.push_back(1);
    row4.push_back(0);
    row4.push_back(0);
    row4.push_back(0);

    obstacleGrid.push_back(row1);
    obstacleGrid.push_back(row2);
    obstacleGrid.push_back(row3);
    obstacleGrid.push_back(row4);
    Solution object;
    cout<<object.uniquePathsWithObstacles(obstacleGrid)<<endl;
    return 0;
}
