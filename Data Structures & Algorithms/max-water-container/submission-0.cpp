class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int h = min(heights[i], heights[j]);
                int area = h * (j-i);

                ans = max(ans, area);
            }
        }
        return ans;
    }
};
