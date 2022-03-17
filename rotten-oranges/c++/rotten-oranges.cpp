    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = -1;
        queue<pair<int, int>> bfsQueue;
        int dirX[4] = {0,1,-1,0};
        int dirY[4] = {1,0,0,-1};
        
        int freshOranges  = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 2){
                    bfsQueue.push({i, j});
                }else if(grid[i][j] == 1){
                    freshOranges++;
                }
            }
        }
        
        bfsQueue.push({-1, -1});
        
        while(!bfsQueue.empty()){
            int r = bfsQueue.front().first;
            int c = bfsQueue.front().second;
            bfsQueue.pop();
            if(r == -1){
                minutes++;
                if(!bfsQueue.empty())
                bfsQueue.push({-1, -1});
            }
            for(int i = 0; i < 4; i++){
                int nr = r + dirX[i];
                int nc = c + dirY[i];
                    
                if(nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()){
                    if(grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        bfsQueue.push({nr, nc});
                        freshOranges--;
                    }
                }
            }
        }
        
        return freshOranges == 0 ? minutes : -1;
    }