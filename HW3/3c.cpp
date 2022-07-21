//
// Created by Kaddijatou Baldeh on 7/20/22.
//[BFS]
//

class Solution {
public:
    /*
    In this problem first we get all the cells of island1 and pushed
     them into a new queue and marking them visited.
     Now from these cells we have to just find the first element in
     the grid which is 1 using bfs and if we found then the answer would be the level of the bfs
    */
    int shortestBridge(vector<vector<int>>& grid) {
        // connect two island
        int size = grid.size();
        int ans = 0;
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};
        // for the all element of 1 island
        queue<pair<int,int>>req;
        int count = 0;
        vector<vector<bool>>visited(size, vector<bool>(size, false));
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(grid[i][j] == 1 && count == 0){
                    // to get the one component of island
                    queue<pair<int,int>>q;
                    count++;
                    q.push({i,j});
                    visited[i][j] = true;
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        req.push({x,y});
                        q.pop();
                        for(int k = 0;k<4;k++){
                            int nx = x+dx[k];
                            int ny = y+dy[k];
                            if(nx >=0 && nx < size && ny >= 0 && ny < size && grid[nx][ny] == 1 && visited[nx][ny] == false){
                                visited[nx][ny] = true;
                                q.push({nx,ny});
                            }
                        }
                    }
                }
            }
        }
        // now the cells of the 1's island have been pushed to the queue
        while(!req.empty()){
            int t = req.size();
            while(t--){
                int x = req.front().first;
                int y = req.front().second;
                req.pop();
                for(int i = 0;i<4;i++){
                    int nx = x+dx[i];
                    int ny = y+dy[i];
                    if(nx >=0 && nx < size && ny >= 0 && ny < size && visited[nx][ny] == false){
                        if(grid[nx][ny] == 1){
                            return ans;
                        }
                        else{
                            req.push({nx,ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
            }

            ans++;
        }
        return ans;
    }
};