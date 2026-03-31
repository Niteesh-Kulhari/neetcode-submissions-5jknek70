class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int top = 0;
        int bottom = ROWS - 1;

        while(top <= bottom){
            int row = top + (bottom - top)/2;

            if(target > matrix[row][COLS-1]){
                top = row + 1;
            }else if(target < matrix[row][0]){
                bottom = row - 1;
            }else{
                break;
            }
        }

        if(!(top <= bottom)) return false;

        int row = (top + bottom) / 2;
        int left = 0;
        int right = COLS-1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(target == matrix[row][mid]) return true;

            if(target > matrix[row][mid]){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }

        return false;
    }
};
