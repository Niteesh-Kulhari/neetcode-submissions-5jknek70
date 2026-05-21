class Solution {
public:
// UP, DOWN, Left, Right
    int x[4] = {0, 0, -1, 1};
    int y[4] = {-1, 1, 0, 0};

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i){
        if(i == word.size()){
            return true;
        }

        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[i] || board[r][c] == '#'){
            return false;
        }

        board[r][c] = '#';

        bool res = dfs(board, word, r + x[0], c + y[0], i+1) || dfs(board, word, r + x[1], c + y[1], i+1) || dfs(board, word, r + x[2], c + y[2], i+1) || dfs(board, word, r + x[3], c + y[3], i+1);

        board[r][c] = word[i];
        return res;

    }



    bool exist(vector<vector<char>>& board, string word) {
        int R = board.size();
        int C = board[0].size();

        for(int r=0; r<R; r++){
            for(int c=0; c<C; c++){
                if(dfs(board, word, r, c, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};
