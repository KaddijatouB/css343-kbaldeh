//
// Created by Kaddijatou Baldeh on 7/20/22.
// 79. Word Search
// [DFS]

//

class Solution {
public:
    bool dfs(int i,int j, int n,int m,vector<vector<char>>& board, string& word){
        if(!word.size()) return true;
        if(i<0 || j<0 || i>=n || j>=m||board[i][j]!=word[0]) return false;
        char ch=board[i][j];
        board[i][j]='*';
        string s=word.substr(1);
        bool x=dfs(i-1,j,n,m,board,s)||dfs(i+1,j,n,m,board,s)||dfs(i,j-1,n,m,board,s)||dfs(i,j+1,n,m,board,s);
        board[i][j]=ch;
        return x;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(unsigned int i=0;i<n;i++)
            for(unsigned int j=0;j<m;j++)
                if(dfs(i,j,n,m,board,word))
                    return true;

        return false;
    }
};