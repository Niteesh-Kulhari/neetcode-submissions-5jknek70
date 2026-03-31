class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0;
        int r = n-1;
        int ans = 0;

        while(l < r){
            int h = min(heights[l], heights[r]);
            int w = r - l;
            int area = h * w;
            ans = max(area, ans);

            if(heights[l] < heights[r]){
                l++;
            }else if(heights[r] < heights[l]){
                r--;
            }else{
                l++;
                r--;
            }
        }

        return ans;
    }
};
