/*
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Follow up:
 * Could you do this in-place?
 */

/*先把矩阵上下对折，然后再转置，不开辟多余空间*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void swapVector(vector<int> &num1,vector<int> &num2,int n){
        for(int i=0;i<n;i++){
            int tmp=num1[i];
            num1[i]=num2[i];
            num2[i]=tmp;
        }
    }

    void rotate(vector<vector<int> >& matrix) {
        int n=matrix.size();
        int i=0;
        int j=n-1;
        while(i<j){
            swapVector(matrix[i],matrix[j],n);
            i++;
            j--;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                int tmp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=tmp;
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
