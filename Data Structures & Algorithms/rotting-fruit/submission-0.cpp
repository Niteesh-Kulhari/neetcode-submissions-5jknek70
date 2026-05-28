class Solution {
private:
    queue<pair<int, int>> q;

    // UP, DOWN, LEFT, RIGHT
    int delRow[4] = {-1, 1, 0, 0};
    int delCol[4] = {0, 0, -1, 1};

    int bfs(vector<vector<int>>& grid){
        int ans = 0;

        while(!q.empty()){
            int size = q.size();
            bool flag = false;

            for(int i=0; i<size; i++){
                auto[row, col] = q.front();
                q.pop();

                for(int i=0; i<4; i++){
                    int nR = row + delRow[i];
                    int nC = col + delCol[i];

                    if(nR >= 0 && nR < grid.size() && nC >= 0 && nC < grid[0].size() && grid[nR][nC] == 1){
                        q.push({nR, nC});
                        grid[nR][nC] = 2;
                        flag = true;
                    }
                }
                
            }

            if (flag) ans++;
        }

        return ans;
    }


public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();

        for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }


        int ans =  bfs(grid);

        for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return ans;
    }
};
