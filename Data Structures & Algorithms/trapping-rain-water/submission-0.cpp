class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax(n, 0);
        vector<int> rightMax(n, 0);
        int ans = 0;

        int left_max = 0;
        for(int i=0; i<n; i++){
            leftMax[i] = max(height[i], left_max);
            left_max = max(left_max, height[i]);
        }

        int right_max = 0;
        for(int i=n-1; i>=0; i--){
            rightMax[i] = max(height[i], right_max);
            right_max = max(right_max, height[i]);
        }

        for(int i=0; i<n; i++){
            int minHeight = min(leftMax[i], rightMax[i]);
            int water = minHeight - height[i];
            ans += water;
        }

        return ans;
    }
};
