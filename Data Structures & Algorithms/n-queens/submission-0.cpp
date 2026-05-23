class Solution {
private:
vector<vector<string>> ans;
    bool isValid(vector<string>& board, int r, int c, int n){
        // Check the COL if it has any other queen
        for(int i=0; i<n; i++){
            if(board[i][c] == 'Q'){
                return false;
            }
        }

        // Check upper left Diagonal if it has a queen
        for(int i=r, j=c; i>=0 && j <n; i--, j--){
            if(board[i][j] == 'Q')return false;
        }

        // Check upper right diagonal if it has a queen
        for(int i=r, j=c; i>=0 && j<n; i--, j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }

    void backTrack(vector<string>& board, int row, int n){
        if(row == n){
            ans.push_back(board);
            return;
        }

        for(int i=0; i<n; i++){
            if(isValid(board, row, i, n)){
                board[row][i] = 'Q';
                backTrack(board, row+1, n);
                board[row][i] = '.';
            }
        }
    }


public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backTrack(board, 0, n);
        return ans;
    }
};
