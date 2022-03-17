    int getFood(vector<vector<char>>& grid) {
        queue<pair<int, int>> bfsQueue;
        map<pair<int,int>, bool> visited;
        int dirX[4] = {0 , 1, -1, 0};
        int dirY[4] = {1, 0, 0,-1};
        
        int startRow = 0, startCol = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '*'){
                    startRow = i;
                    startCol = j;
                    break;
                }
            }
        }
        
        bfsQueue.push({startRow, startCol});
        int steps = 0;
        
        while(!bfsQueue.empty()){
            int qSize = bfsQueue.size();
            for(int i = 0; i < qSize; i++){
                int r = bfsQueue.front().first;
                int c = bfsQueue.front().second;
                
                if(grid[r][c] == '#'){
                    return steps;
                }
                bfsQueue.pop();
                
                for(int i = 0; i <4; i++){
                    int newRow = r + dirX[i];
                    int newCol = c + dirY[i];
                    
                    if(newRow >= 0 && newRow < grid.size() && newCol >= 0 && newCol < grid[0].size()){
                        if(grid[newRow][newCol] != '*' && grid[newRow][newCol] != 'X' && !visited[{newRow, newCol}]){
                            visited[{newRow,newCol}] = true;
                            bfsQueue.push({newRow, newCol});
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }