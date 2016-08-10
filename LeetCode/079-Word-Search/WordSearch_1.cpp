/* Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells
are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =
[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.  */

/* 思想：DFS，但是TLE */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<bool> > visited;
    bool isExist;

    bool compare(vector<char> &current,string word){
        if(current.size()!=word.size()){
            return false;
        }
        for(unsigned int index=0;index<word.size();index++){
            if(current[index]!=word[index]){
                return false;
            }
        }
        return true;
    }

    void searchWord(vector<vector<char> >& board,vector<char> current,int current_x,int current_y,int curLen,string word){
        if(compare(current,word)){
            isExist=true;
            return;
        }
        int width=board[0].size();
        int height=board.size();
        if(current_x-1>=0&&current_y<width){ //往上
            if(visited[current_x-1][current_y]==false&&board[current_x-1][current_y]==word[curLen]){
                //cout<<current_x-1<<" "<<current_y<<" "<<board[current_x-1][current_y]<<endl;
                current.push_back(board[current_x-1][current_y]);
                visited[current_x-1][current_y]=true;
                searchWord(board,current,current_x-1,current_y,curLen+1,word);
                visited[current_x-1][current_y]=false;
                current.pop_back();
            }
        }

        if(current_x+1<height&&current_y<width){ //往下
            if(visited[current_x+1][current_y]==false&&board[current_x+1][current_y]==word[curLen]){
                //cout<<current_x+1<<" "<<current_y<<" "<<board[current_x+1][current_y]<<endl;
                current.push_back(board[current_x+1][current_y]);
                visited[current_x+1][current_y]=true;
                searchWord(board,current,current_x+1,current_y,curLen+1,word);
                visited[current_x+1][current_y]=false;
                current.pop_back();
            }
        }

        if(current_x<height&&current_y-1>=0){ //往左
            if(visited[current_x][current_y-1]==false&&board[current_x][current_y-1]==word[curLen]){
                //cout<<current_x<<" "<<current_y-1<<" "<<board[current_x][current_y-1]<<endl;
                current.push_back(board[current_x][current_y-1]);
                visited[current_x][current_y-1]=true;
                searchWord(board,current,current_x,current_y-1,curLen+1,word);
                visited[current_x][current_y-1]=false;
                current.pop_back();
            }
        }

        if(current_x<height&&current_y+1<width){ //往右
            if(visited[current_x][current_y+1]==false&&board[current_x][current_y+1]==word[curLen]){
                //cout<<current_x<<" "<<current_y+1<<" "<<board[current_x][current_y+1]<<endl;
                current.push_back(board[current_x][current_y+1]);
                visited[current_x][current_y+1]=true;
                searchWord(board,current,current_x,current_y+1,curLen+1,word);
                visited[current_x][current_y+1]=false;
                current.pop_back();
            }
        }
        return;
    }

    bool exist(vector<vector<char> >& board, string word) {
        if(board.size()==0){
            return false;
        }
        int width=board[0].size();
        int height=board.size();
        vector<bool> tmp;
        for(int i=0;i<height;i++){
            tmp.clear();
            for(int j=0;j<width;j++){
                tmp.push_back(false);
            }
            visited.push_back(tmp);
        }
        for(unsigned int i=0;i<board.size();i++){
            for(unsigned int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    vector<char> current;
                    current.clear();
                    current.push_back(board[i][j]);
                    visited[i][j]=true;
                    isExist=false;
                    searchWord(board,current,i,j,1,word);
                    if(isExist){
                        return true;
                    }
                    visited[i][j]=false;
                }
            }
        }
        return false;
    }
};
int main()
{
    Solution object;
    vector<vector<char> > board;
    vector<char> row1;
    row1.push_back('A');
    row1.push_back('B');
    row1.push_back('C');
    row1.push_back('E');
    vector<char> row2;
    row2.push_back('S');
    row2.push_back('F');
    row2.push_back('C');
    row2.push_back('S');
    vector<char> row3;
    row3.push_back('A');
    row3.push_back('D');
    row3.push_back('E');
    row3.push_back('E');
    board.push_back(row1);
    board.push_back(row2);
    board.push_back(row3);
    cout<<object.exist(board,"ESECCFDASA")<<endl;
    return 0;
}
