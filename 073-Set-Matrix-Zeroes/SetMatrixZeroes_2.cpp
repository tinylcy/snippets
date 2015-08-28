/* Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.
Follow up:

Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution? */

/*
 *思想：用matrix的第一行和第一列存储行列是否需要清零的信息，需要提前判断第一行和第一列的信息，
 *如果第一行全不为0，那么到最后第一行改怎么样就怎么样，否则最后把第一行全部设为0；第一列同理。
 *总结：我用第一行和第一列来存储matrix剩余部分是否需要清零的信息。最后单独处理第一行和第一列。
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        bool firstRow=false,firstColumn=false;
        int width=matrix[0].size();
        int height=matrix.size();
        for(int i=0;i<width;i++){ //检查第一行内是否有0
            if(matrix[0][i]==0){
                firstRow=true;
                break;
            }
        }
        for(int i=0;i<height;i++){ //检查第一列内是否有0
            if(matrix[i][0]==0){
                firstColumn=true;
                break;
            }
        }
        for(int i=1;i<height;i++){  //遍历数组，如果matric[i][j]=0,那么把matrix[i][0]和matrix[0][j]设为0
            for(int j=1;j<width;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<height;i++){ //处理行，从第二行还是处理
            if(matrix[i][0]==0){
                for(int j=1;j<width;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=1;i<width;i++){ //处理列，从第二列开始处理
            if(matrix[0][i]==0){
                for(int j=0;j<height;j++){
                    matrix[j][i]=0;
                }
            }
        }
        if(firstRow){ //处理第一行
            for(int i=0;i<width;i++){
                matrix[0][i]=0;
            }
        }
        if(firstColumn){ //处理第一列
            for(int i=0;i<height;i++){
                matrix[i][0]=0;
            }
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
    vector<int> row5;

    row1.push_back(0);
    row1.push_back(0);
    row1.push_back(0);
    row1.push_back(5);

    row2.push_back(4);
    row2.push_back(3);
    row2.push_back(1);
    row2.push_back(4);

    row3.push_back(0);
    row3.push_back(1);
    row3.push_back(1);
    row3.push_back(4);

    row4.push_back(1);
    row4.push_back(2);
    row4.push_back(1);
    row4.push_back(3);

    row5.push_back(0);
    row5.push_back(0);
    row5.push_back(1);
    row5.push_back(1);

    matrix.push_back(row1);
    matrix.push_back(row2);
    matrix.push_back(row3);
    matrix.push_back(row4);
    matrix.push_back(row5);

    Solution object;
    object.setZeroes(matrix);
    for(unsigned int i=0;i<matrix.size();i++){
        for(unsigned int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
