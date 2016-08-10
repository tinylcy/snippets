/* Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

Follow up:

Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution? */

/*
 *思想：最直接的办法，遍历整个矩阵，找到值为0的坐标，把坐标存储到vector，
 *然后遍历为0的点的坐标，把相应的行和列设置为0
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void clearRowAndColumn(vector<vector<int> >& matrix,vector<int> &point){
        int width=matrix[0].size();
        int height=matrix.size();
        int row=point[0];
        int column=point[1];
        for(int i=0;i<width;i++){
            matrix[row][i]=0;
        }
        for(int j=0;j<height;j++){
            matrix[j][column]=0;
        }
    }

    void setZeroes(vector<vector<int> >& matrix) {
        int width=matrix[0].size();
        int height=matrix.size();
        vector<vector<int> > points;
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(matrix[i][j]==0){
                    vector<int> point;
                    point.push_back(i);
                    point.push_back(j);
                    points.push_back(point);
                }
            }
        }
        for(unsigned int i=0;i<points.size();i++){
            clearRowAndColumn(matrix,points[i]);
        }
    }
};

int main()
{
    vector<vector<int> > matrix;
    vector<int> row1;
    vector<int> row2;
    vector<int> row3;
    vector<int> row4;

    row1.push_back(1);
    row1.push_back(1);
    row1.push_back(0);
    row1.push_back(3);

    row2.push_back(7);
    row2.push_back(2);
    row2.push_back(1);
    row2.push_back(0);

    row3.push_back(2);
    row3.push_back(0);
    row3.push_back(2);
    row3.push_back(0);

    row4.push_back(5);
    row4.push_back(2);
    row4.push_back(6);
    row4.push_back(5);

    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    matrix.push_back(row4);

    Solution object;
    object.setZeroes(matrix);

    return 0;
}
