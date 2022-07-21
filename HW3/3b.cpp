// 200. Number of Islands
// [BFS]

class Solution {
public:
    int numIslands(vector < vector < char >> & grid) {
        //initialize count to zero
        int count = 0;
        //loop through rows and cols
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                //call BFS if grit equal 1
                if (grid[i][j] == '1') {
                    BFS(grid, i, j);
                    //increment count
                    count++;
                }
            }
        }
        //return count
        return count;
    }
    // sub-function for BFS
    vector<pair<int,int>> paths{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void BFS(vector < vector < char >> & grid, int i, int j) {
        int size = grid.size();
        int sz = grid[0].size();
        //create queue of pairs
        queue<pair<int, int>> list;
        list.push({i,j});
        //loop through list
        while (!list.empty()) {
            auto first = list.front();
            list.pop();
            for (auto dir: paths) {
                int x = first.first + dir.first;
                int y = first.second + dir.second;
                // if the cell is valid and is a land cell ,then push it in the queue
                if (path(x, y, size, sz) && grid[x][y] == '1') {
                    grid[x][y] = '0';
                    list.push({x, y});

                }
            }
        }
    }
    // checker to check the cell path
    int path(int i, int j, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m){
            return 0;
        }
        return 1;
    }
};