//
// Created by Kaddijatou Baldeh on 7/20/22.
//[BFS]
//
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        // create pair queue
        queue<pair<int,int>>list;
        //keep track of explored grid node
        bool visited = false;
        //loop through the  grid
        for (int i = 0; i < grid.size() && !visited; i++) {
            for (int j = 0; j < grid[0].size() && !visited; j++) {
                if (grid[i][j]){
                    search(grid, j, i, list);
                    visited = true;
                }
            }
        }
        int count = 0;
        vector<int> paths{0, 1, 0, -1, 0};
        while (!list.empty()) {
            int size = list.size();
            while (size--) {
                // extract first and second element in list
                int first = list.front().first;
                int second = list.front().second;
                //then remove from the list
                list.pop();
                //loop through to trace paths
                for (int i = 0; i < 4; ++i) {
                    int top = first + paths[i];
                    int bottom = second + paths[i + 1];
                    if (top < 0 || bottom < 0 || top >= grid[0].size() || bottom >= grid.size() || grid[bottom][top] == 2) {
                        continue;
                    }
                    if (grid[bottom][top] == 1){
                        return count;
                    }
                    grid[bottom][top] = 2;
                    //add to the end of the queue, after its current last element.
                    list.emplace(top, bottom);
                }
            }
            ++count;
        }
        //otherwise, return negative 1
        return -1;
    }
    //helper function
    void search(vector<vector<int>>& A, int x, int y, queue<pair<int, int>>& q) {
        // terminate search if negative values or values greater than size
        if (x < 0 || y < 0 || x >= A[0].size() || y >= A.size() || A[y][x] != 1){
            return;
        }
        A[y][x] = 2;
        //add to the end of the queue, after its current last element.
        q.emplace(x, y);
        //recursively call search
        search(A, x - 1, y, q);
        search(A, x, y - 1, q);
        search(A, x + 1, y, q);
        search(A, x, y + 1, q);
    }
};

