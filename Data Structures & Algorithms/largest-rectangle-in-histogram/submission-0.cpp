class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int n = heights.size();
        int area = 0;

        for(int i=0; i<n; i++){
            
            int start = i;

            while(!st.empty() && st.top().second > heights[i]){
                auto[index, h] = st.top();
                st.pop();
                area = max(area, (h * (i - index)));
                start = index;
            }

            st.push({start, heights[i]});
        }

        while(!st.empty()){
            auto [index, h] = st.top();
            area = max(area, h * (n - index));
            st.pop();
        }

        return area;
    }
};

