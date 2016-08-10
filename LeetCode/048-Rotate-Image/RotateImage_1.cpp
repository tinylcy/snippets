/*
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Follow up:
 * Could you do this in-place?
 */

 /*使用了额外的空间，先把整个矩阵转置，再给每一行逆置*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverse(int *num,int low,int high){
        while(low<high){
            int tmp=num[low];
            num[low]=num[high];
            num[high]=tmp;
            ++low;
            --high;
        }
    }

    void rotate(vector<vector<int> >& matrix) {
        int tmp[matrix.size()][matrix.size()];
        for(unsigned int i=0;i<matrix.size();i++){
            for(unsigned int j=0;j<matrix[i].size();j++){
                tmp[j][i]=matrix[i][j];
            }
        }
        for(unsigned int i=0;i<matrix.size();i++){
            reverse(tmp[i],0,matrix.size()-1);
        }
        for(unsigned int i=0;i<matrix.size();i++){
            for(unsigned int j=0;j<matrix.size();j++){
                matrix[i][j]=tmp[i][j];
            }
        }
    }
};

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    vector<int> v2;
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);
    vector<int> v3;
    v3.push_back(9);
    v3.push_back(10);
    v3.push_back(11);
    v3.push_back(12);
    vector<int> v4;
    v4.push_back(13);
    v4.push_back(14);
    v4.push_back(15);
    v4.push_back(16);
    vector<vector<int> > matrix;
    matrix.push_back(v1);
    matrix.push_back(v2);
    matrix.push_back(v3);
    matrix.push_back(v4);
    Solution object;
    object.rotate(matrix);
    return 0;
}
