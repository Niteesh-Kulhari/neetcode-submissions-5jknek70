class Solution {
private:
    // Up, Down, LEft, Right
    int delRow[4] = {-1, 1, 0, 0};
    int delCol[4] = {0, 0, -1, 1};

    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int r, int c){
        vis[r][c] = 1;
        int ROW = grid.size();
        int COL = grid[0].size();

        for(int i=0; i<4; i++){
            int nR = r + delRow[i];
            int nC = c + delCol[i];

            if(nR >= 0 && nR < ROW && nC >= 0 && nC < COL && grid[nR][nC] == '1' && vis[nR][nC] == 0){
                dfs(grid, vis, nR, nC);
            }
        }
    }

    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int r, int c){
        int ROW = grid.size();
        int COL = grid[0].size();

        queue<pair<int, int>> q;
        q.push({r, c});
        vis[r][c] = 1;

        while(!q.empty()){
            auto[row, col] = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int nR = row + delRow[i];
                int nC = col + delCol[i];

                if(nR >= 0 && nR < ROW && nC >= 0 && nC < COL && grid[nR][nC] == '1' && vis[nR][nC] == 0){
                    q.push({nR, nC});
                    vis[nR][nC] = 1; 
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ROW = grid.size();
        int COL = grid[0].size();

        vector<vector<int>> vis(ROW, vector<int>(COL, 0));
        int count = 0;

        for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    count++;
                    dfs(grid, vis, i, j);
                }
            }
        }

        return count;
    }
};
