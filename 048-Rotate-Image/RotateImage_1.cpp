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
