class Solution {
private:
    // queue<pair<int, int>> q;
    //UP, DOWN, LEFT, RIGHT
    int delRow[4] = {-1, 1, 0, 0};
    int delCol[4] = {0, 0, -1, 1};

    void dfs(int r, int c, vector<vector<bool>>& flag, vector<vector<char>>& board){
        int ROW = board.size();
        int COL = board[0].size();

        flag[r][c] = true;

        for(int i=0; i<4; i++){
            int nR = r + delRow[i];
            int nC = c + delCol[i];

            if(nR >= 0 && nR < ROW && nC >= 0 && nC < COL && board[nR][nC] == 'O' && !flag[nR][nC]){
                dfs(nR, nC, flag, board);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int ROW = board.size();
        int COL = board[0].size();

        vector<vector<bool>> flag(ROW, vector<bool>(COL, false));

        // for(int i=0; i<COL; i++){
        //     if(board[0][i] == 'O') q.push({0, i});
        //     if(board[ROW-1][i] == 'O') q.push({ROW-1, i});
        // }

        // for(int i=0; i<ROW; i++){
        //     if(board[i][0] == 'O') q.push({i, 0});
        //     if(board[i][COL-1] == 'O') q.push({i, COL-1});
        // }

        // Top and Bottom boundary columns
        for(int i=0; i<COL; i++){
            if(board[0][i] == 'O'){
                dfs(0, i, flag, board);
            }

            if(board[ROW-1][i] == 'O'){
                dfs(ROW-1, i, flag, board);
            }
        }

        //Left and Right boundary elements
        for(int i=0; i<ROW; i++){
            if(board[i][0] == 'O'){
                dfs(i, 0, flag, board);
            }

            if(board[i][COL-1] == 'O'){
                dfs(i, COL-1, flag, board);
            }
        }

        for(int i=0; i<ROW; i++){
            for(int j=0; j<COL; j++){
                if(board[i][j] == 'O' && !flag[i][j]){
                    board[i][j] = 'X';
                }
            }
        }

    }
};
