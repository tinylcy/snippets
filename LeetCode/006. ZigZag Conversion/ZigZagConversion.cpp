/*
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
* (you may want to display this pattern in a fixed font for better legibility)
*
*                                      P   A   H   N
*                                      A P L S I I G
*                                      Y   I   R
*
* And then read line by line: "PAHNAPLSIIGYIR"
*
* Write the code that will take a string and make this conversion given a number of rows:
*
* string convert(string text, int nRows);
*
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/


/*
 * 我的思路是做如下转化，用一个二维数组存储
 *
 *  P   A   H   N      P   A   H   N
 *  A P L S I I G =>    A P L S I I G
 *  Y   I   R            Y   I   R
 *
 * 这样，只需要转化出这样的序列就可以解决问题（假设numRows=3）：
 * (0,0)，(1,1)，(2,2),(1,3),(0,4),(1,5),(2,6),(1,7),(0,8)...
 */

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Solution{
public:
    string convert(string s, int numRows){
        if(numRows==1){
            return s;
        }
        int i,j,flag,length;
        length=s.length();
        char buf[numRows][length];
        string answer="";
        for(int i=0; i<numRows; i++){
            memset(buf[i],' ',length);
        }
        j=0;
        flag=1;
        for(i=0; i<length; i++){
            buf[j][i]=s[i];
            if(j==0){
                flag=1;
            }
            if(j==numRows-1){
                flag=-1;
            }
            j=j+flag;
        }
        for(int i=0; i<numRows; i++){
            for(int j=0; j<length; j++){
                if(buf[i][j]!=' '){
                    answer+=buf[i][j];
                }
            }
        }
        return answer;
    }
};

int main(){
    Solution object;
    cout<<object.convert("PAYPALISHIRING", 3)<<endl;
    return 0;
}
