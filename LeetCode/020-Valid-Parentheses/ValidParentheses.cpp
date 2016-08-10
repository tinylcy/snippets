/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 */

/* 
 * 今天看论文看得郁闷，用个粗鲁点的变量名 :)
 * 思想：利用stack来实现，需要注意的是如果当前字符是右括号且stack为空，返回false即可 
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2==1){
            return false;
        }
        stack<int> fuck;
        while(!fuck.empty()){
            fuck.pop();
        }
        for(unsigned int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                fuck.push(s[i]);
            }else{
                if(fuck.empty()){
                    return false;
                }
                char top=fuck.top();
                if(s[i]==')'){
                    if(top=='('){
                        fuck.pop();
                    }else{
                        return false;
                    }
                }
                if(s[i]==']'){
                    if(top=='['){
                        fuck.pop();
                    }else{
                        return false;
                    }
                }
                if(s[i]=='}'){
                    if(top=='{'){
                        fuck.pop();
                    }else{
                        return false;
                    }
                }
            }
        }
        if(fuck.empty()){
            return true;
        }else{
            return false;
        }
    }
};

int main()
{
    string s=")}{({))[{{[}";
    Solution object;
    cout<<object.isValid(s)<<endl;
    return 0;
}
