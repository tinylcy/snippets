/*
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases.
 * If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
 * You are responsible to gather all the input requirements up front.
 *
 * Requirements for atoi:
 *
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found.
 * Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible,
 * and interprets them as a numerical value.
 *
 * The string can contain additional characters after those that form the integral number,
 * which are ignored and have no effect on the behavior of this function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid integral number,
 * or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned.
 * If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int abs(int x){
        return x>0 ? x : -x;
    }

    int myAtoi(string str) {
        if(str.size()==0){
            return 0;
        }
        string numbers="0123456789";
        vector<int> num;
        long long answer=0;
        unsigned int startPos=str.find_first_of(numbers,0);
        unsigned int endPos=str.find_first_not_of(numbers,startPos);
        if(startPos==-1){ //针对如"abc"的情况
            return 0;
        }
        if(endPos==-1){
            endPos=str.size();
        }
        for(unsigned int i=startPos;i<endPos;i++){
            num.push_back(str[i]-'0');
        }
        for(unsigned int i=0;i<num.size();i++){
            answer=answer*10+num[i];
        }
        int isPositive=1;
        if(startPos>0){
            if(str[startPos-1]=='+'){
                isPositive=1;
            }else if(str[startPos-1]=='-'){
                isPositive=-1;
            }else if(str[startPos-1]!=' '){
                return 0;
            }
        }
        if(isPositive==1&&num.size()>10){ //"9223372036854775809"
            return 2147483647;
        }else if(isPositive==-1&&num.size()>10){  //"-9223372036854775809"
            return -2147483648;
        }
        for(int i=startPos-2;i>=0;i--){  //“   - 23”返回0
            if(str[i]!=' '){
                return 0;
            }
        }
        if(answer*isPositive>(long)2147483647){
            return 2147483647;
        }
        if(answer*isPositive<(long)-2147483648){
            return -2147483648;
        }
        return isPositive*answer;
    }
};

int main()
{
    Solution object;
    cout<<object.myAtoi("-9223372036854775809")<<endl;
    return 0;
}
