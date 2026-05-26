class Solution {
private:
    // UP, DOWN, LEFT, RIGHT
    int delRow[4] = {-1, 1, 0, 0};
    int delCol[4] = {0, 0, -1, 1};

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int& res, int r, int c){
        int ROW = grid.size();
        int COL = grid[0].size();

        vis[r][c] = 1;
        res++;
        queue<pair<int, int>> q;
        q.push({r,c});

        while(!q.empty()){
            auto[row, col] = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int nR = row + delRow[i];
                int nC = col + delCol[i];

                if(nR >= 0 && nR < ROW && nC >= 0 && nC < COL && grid[nR][nC] == 1 && vis[nR][nC] == 0){
                    q.push({nR, nC});
                    vis[nR][nC] = 1;
                    res++;
                }
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();
        int ans = 0;

        vector<vector<int>> vis(ROW, vector<int>(COL, 0));

        for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    int res = 0;
                    bfs(grid, vis, res, i, j);
                    ans = max(ans, res);
                } 
            }
        }

        return ans;
    }
};
