class Solution {
private:
    // UP, DOWN, LEFT, RIGHT
    int delRow[4] = {-1, 1, 0, 0};
    int delCol[4] = {0, 0, -1, 1};

    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& oc, vector<vector<int>>& heights){
        while(!q.empty()){
            auto[row, col] = q.front();
            q.pop();
            oc[row][col] = true;

            for(int i=0; i<4; i++){
                int nR = row + delRow[i];
                int nC = col + delCol[i];

                if(nR >= 0 && nR < heights.size() && nC >= 0 && nC < heights[0].size() && heights[nR][nC] >= heights[row][col] && !oc[nR][nC]){
                    q.push({nR, nC});
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROW = heights.size();
        int COL = heights[0].size();
        vector<vector<int>> ans;

        vector<vector<bool>> PC(ROW, vector<bool>(COL, false));
        vector<vector<bool>> AT(ROW, vector<bool>(COL, false));
        
        queue<pair<int, int>> pq;
        queue<pair<int, int>> at;

        for(int i=0; i<COL; i++){
            pq.push({0, i});         // top row
            at.push({ROW-1, i});     // bottom row
        }

        for(int i=0; i<ROW; i++){
            pq.push({i, 0});         // left column
            at.push({i, COL-1});     // right column
        }

        // Do the BFS and mark all the cells where we can reach from the given end
        bfs(pq, PC, heights);
        bfs(at, AT, heights);

        for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++){
                if(PC[i][j] && AT[i][j]){
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};
