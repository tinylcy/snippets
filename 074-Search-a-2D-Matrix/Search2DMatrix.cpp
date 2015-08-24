/* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

 For example,

 Consider the following matrix:

 [
   [1,   3,  5,  7],
   [10, 11, 16, 20],
   [23, 30, 34, 50]
 ]

 Given target = 3, return true. */

 /*思想：从右下角沿着对角线往左上找，如果是方阵那正好，否则剩余的行或者列再单独找*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }
        int row=matrix.size()-1;
        int column=matrix[0].size()-1;
        int m=row,n=column;
        if(target<matrix[0][0]||target>matrix[m][n]){
            return false;
        }
        while(m>=0&&n>=0){
            if(matrix[m][n]==target){
                return true;
            }
            if(matrix[m][n]>target){
                m--;
                n--;
            }else if(matrix[m][n]<target){
                for(int i=n+1;i<=column;i++){
                    if(matrix[m][i]==target){
                        return true;
                    }
                }
                for(int j=m+1;j<=row;j++){
                    if(matrix[j][n]==target){
                        return true;
                    }
                }
                m--; //要是还没有找到，继续减1
                n--;
            }
        }
        while(m>=0){
            for(int i=0;i<=column;i++){
                if(matrix[m][i]==target){
                    return true;
                }
            }
            m--;
        }
        while(n>=0){
            for(int i=0;i<=row;i++){
                if(matrix[i][n]==target){
                    return true;
                }
            }
            n--;
        }
        return false;
    }
};

int main()
{
    vector<vector<int> >matrix;
    vector<int> row1;
    row1.push_back(1);
    row1.push_back(3);
    row1.push_back(5);
    row1.push_back(7);
    vector<int> row2;
    row2.push_back(10);
    row2.push_back(11);
    row2.push_back(16);
    row2.push_back(20);
    vector<int> row3;
    row3.push_back(23);
    row3.push_back(30);
    row3.push_back(34);
    row3.push_back(50);
    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    Solution object;
    cout<<object.searchMatrix(matrix,23)<<endl;
    return 0;
}
