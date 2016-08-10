/*
 * Given a digit string, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */

 /* 思想：DFS */

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    map<char,vector<char> > dict;
    vector<string> result;

    void createDict(){
        dict.clear();
        dict['2'].push_back('a');
        dict['2'].push_back('b');
        dict['2'].push_back('c');
        dict['3'].push_back('d');
        dict['3'].push_back('e');
        dict['3'].push_back('f');
        dict['4'].push_back('g');
        dict['4'].push_back('h');
        dict['4'].push_back('i');
        dict['5'].push_back('j');
        dict['5'].push_back('k');
        dict['5'].push_back('l');
        dict['6'].push_back('m');
        dict['6'].push_back('n');
        dict['6'].push_back('o');
        dict['7'].push_back('p');
        dict['7'].push_back('q');
        dict['7'].push_back('r');
        dict['7'].push_back('s');
        dict['8'].push_back('t');
        dict['8'].push_back('u');
        dict['8'].push_back('v');
        dict['9'].push_back('w');
        dict['9'].push_back('x');
        dict['9'].push_back('y');
        dict['9'].push_back('z');
    }

    void DFS(string digits,string current){
        if(current.size()==digits.size()){
            result.push_back(current);
            return;
        }
        int curLength=current.size();
        for(unsigned int i=0;i<dict[digits[curLength]].size();i++){
            DFS(digits,current+dict[digits[curLength]][i]);
        }
        return;
    }

    vector<string> letterCombinations(string digits) {
        result.clear();
        if(digits.size()==0){ //digits为空，直接返回。
            return result;
        }
        createDict();
        string current="";
        DFS(digits,current);
        return result;
    }
};

int main()
{
    Solution object;
    vector<string> result=object.letterCombinations("23");
    for(unsigned int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}
