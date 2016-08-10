/*
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 */

/*思想：DFS，用visited数组标记是否已经被访问过，注意去掉重复的序列*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    vector<string> result;

    bool judge(vector<char> &current,char &ch){
        if(ch=='('){
            return true;
        }
        int countLeft=0;
        int countRight=0;
        for(unsigned int i=0;i<current.size();i++){
            if(current[i]=='('){
                countLeft++;
            }else{
                countRight++;
            }
        }
        if(countLeft>countRight){
            return true;
        }else{
            return false;
        }
    }

    string toString(vector<char> &current){
        string ret="";
        for(unsigned int i=0;i<current.size();i++){
            ret+=current[i];
        }
        return ret;
    }

    void DFS(vector<char> &seq,vector<char> &current,vector<bool> &visited,int n){
        if((int)current.size()==2*n){
            string tmp=toString(current);
            result.push_back(tmp);
            return;
        }
        for(unsigned int i=0;i<seq.size();i++){
            if(visited[i]==true){
                continue;
            }
            if(!judge(current,seq[i])){
                continue;
            }
            /*去掉重复的序列*/
            bool flag=false;
            for(unsigned int j=0;j<i;j++){
                if(seq[j]==seq[i]&&visited[j]==false){
                    flag=true;
                    break;
                }
            }
            if(flag){
                continue;
            }
            current.push_back(seq[i]);
            visited[i]=true;
            DFS(seq,current,visited,n);
            visited[i]=false;
            current.pop_back();
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<char> seq;
        for(int i=0;i<2*n;i++){
            if(i<n){
                seq.push_back('(');
            }else{
                seq.push_back(')');
            }
        }
        vector<bool> visited;
        for(int i=0;i<2*n;i++){
            visited.push_back(false);
        }
        vector<char> current;
        result.clear();
        DFS(seq,current,visited,n);
        return result;
    }
};

int main()
{
    Solution object;
    vector<string> result=object.generateParenthesis(4);
    for(unsigned int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}
