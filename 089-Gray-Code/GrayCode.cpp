/*
 * The gray code is a binary numeral system where two successive values differ in only one bit.
 *
 * Given a non-negative integer n representing the total number of bits in the code,
 * print the sequence of gray code. A gray code sequence must begin with 0.
 *
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 *
 *       00 - 0
 *       01 - 1
 *       11 - 3
 *       10 - 2
 *
 * Note:
 * For a given n, a gray code sequence is not uniquely defined.
 *
 * For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
 *
 * For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 */

 /*思想：DFS，从每一位都为0开始，从最后一位开始(题意要求)修改，每次改动一位，如果改动后的结果是合理的(通过isExist判断)，就
  *继续搜索下去，否则不改动。
  */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> result;

    int getValue(vector<int> &current){
        int sum=0;
        for(unsigned int i=0;i<current.size();i++){
            if(current[i]==1){
                sum+=pow(2,current.size()-1-i);
            }
        }
        return sum;
    }

    void DFS(vector<int> current,vector<bool> &isExist,int n){
        if(result.size()==pow(2,n)){
            return;
        }
        if(isExist[getValue(current)]==false){
            result.push_back(getValue(current));
            isExist[getValue(current)]=true;
        }
        for(int i=n-1;i>=0;i--){ // 由题意，它要[0,1,3,2]不要[0,2,3,1]，所以从最后一位开始修改
            if(current[i]==0){ // 如果某一位是0
                current[i]=1;
                if(isExist[getValue(current)]==true){ // 把这一位改成1后，如果之前存在过，就改回0
                    current[i]=0;
                }else{
                    DFS(current,isExist,n); // 如果改成1后是一个新值，继续搜索下去
                    current[i]=0;
                }
            }else{ // 某一位是1时
                current[i]=0;
                if(isExist[getValue(current)]==true){
                    current[i]=1;
                }else{
                    DFS(current,isExist,n);
                    current[i]=1;
                }
            }
        }
        return;
    }

    vector<int> grayCode(int n) {
        vector<bool> isExist;
        for(int i=0;i<pow(2,n);i++){
            isExist.push_back(false);
        }
        vector<int> current;
        current.clear();
        result.clear();
        for(int i=0;i<n;i++){
            current.push_back(0);
        }
        DFS(current,isExist,n);
        return result;
    }
};

int main()
{
    Solution object;
    vector<int> result=object.grayCode(2);
    for(unsigned int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
