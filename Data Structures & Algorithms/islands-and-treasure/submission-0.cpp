class Solution {
private:
    // UP, DOWN, LEFT, RIGHT
    int delRow[4] = {-1, 1, 0, 0};
    int delCol[4] = {0, 0, -1, 1};
    queue<pair<int, int>> q;

    void bfs(vector<vector<int>>& grid){
        while(!q.empty()){
            auto[row, col] = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                int nR = row + delRow[i];
                int nC = col + delCol[i];

                if(nR >= 0 && nR < grid.size() && nC >= 0 && nC < grid[0].size() && grid[nR][nC] == 2147483647){
                    grid[nR][nC] = grid[row][col] + 1;
                    q.push({nR, nC});
                }
            }
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();


        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        bfs(grid);
    }
};
