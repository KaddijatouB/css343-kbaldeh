// 79. Word Search
// [search]

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word){
        //loop through the rows and cols
        for (int i = 0; i < board.size() ; i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]){
                    if(check(board, word, i, j, 0))
                        return true;
                }
            }
        }
        //otherwise, return false
        return false;
    }
    //checker function
    bool check(vector<vector<char>>& board, string word, int x, int y, int index){
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] != word[index])
            return false;

        if(index == word.size()-1){
            return true;
        }

        board[x][y] = '#';

        bool ret1 = check(board, word, x + 1, y, index + 1);
        bool ret2 = check(board, word, x - 1, y, index + 1);
        bool ret3 = check(board, word, x, y + 1, index + 1);
        bool ret4 = check(board, word, x, y - 1, index + 1);

        if(ret1 || ret2 || ret3 || ret4){
            return true;
        }
        board[x][y] = word[index];
        return false;
    }
};