class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        // UP, DOWN, LEFT, RIGHT
        int delRow[4] = {-1, 1, 0, 0};
        int delCol[4] = {0, 0, -1, 1};

        int ans = INT_MAX;
        while(!pq.empty()){
            auto e = pq.top();
            pq.pop();
            int t = e.first;
            auto [r, c] = e.second;
            if(r == row-1 && c == col-1){
                return t;
            }
            
            for(int i=0; i<4; i++){
                int nR = r + delRow[i];
                int nC = c + delCol[i];

                if(nR >= 0 && nC >= 0 && nR < row && nC < col && !vis[nR][nC]){
                    pq.push({max(t, grid[nR][nC]), {nR, nC}});
                    vis[nR][nC] = 1;
                }
            }


        }

        return ans;
    }
};
