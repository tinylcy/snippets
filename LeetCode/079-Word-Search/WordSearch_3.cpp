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

/*思想：DFS，是已经遍历过的序列，current_x和current_y标记当前坐标，visited用来标记点是否被访问过，AC*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<bool> > visited;
    bool isExist;

    void initVisited(vector<vector<bool> > &visited,int width,int height){
        vector<bool> tmp;
        for(int i=0;i<height;i++){
            tmp.clear();
            for(int j=0;j<width;j++){
                tmp.push_back(false);
            }
            visited.push_back(tmp);
        }
    }

    void searchWord(vector<vector<char> >& board,vector<char> current,int current_x,int current_y,int curLen,string word){
        if(current.size()==word.size()){
            isExist=true;
            return;
        }
        int width=board[0].size();
        int height=board.size();
        if(current_x<0||current_x>=height||current_y<0||current_y>=width){ //首先要看是否越界
            return;
        }
        if(visited[current_x][current_y]==true){ //是否已经访问过
            return;
        }
        if(board[current_x][current_y]!=word[curLen]){ //是否是待匹配的字符
            return;
        }
        current.push_back(board[current_x][current_y]);
        visited[current_x][current_y]=true;
        searchWord(board,current,current_x-1,current_y,curLen+1,word); //向上
        if(isExist){
            return;
        }
        searchWord(board,current,current_x+1,current_y,curLen+1,word); //向下
        if(isExist){
            return;
        }
        searchWord(board,current,current_x,current_y-1,curLen+1,word); //向左
        if(isExist){
            return;
        }
        searchWord(board,current,current_x,current_y+1,curLen+1,word); //向右
        if(isExist){
            return;
        }
        visited[current_x][current_y]=false;
        current.pop_back();
        return;
    }
    bool exist(vector<vector<char> >& board, string word) {
        if(board.size()==0){
            return false;
        }
        int width=board[0].size();
        int height=board.size();
        initVisited(visited,width,height);
        for(unsigned int i=0;i<board.size();i++){
            for(unsigned int j=0;j<board[i].size();j++){
                if(board[i][j]==word[0]){
                    vector<char> current;
                    current.clear();
                    isExist=false;
                    searchWord(board,current,i,j,0,word);
                    if(isExist){
                        return true;
                    }
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
