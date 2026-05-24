class Solution {
struct Compare{
    bool operator()(pair<int, vector<int>>& a,
                    pair<int, vector<int>>& b){
                    return a.first < b.first;
    }
};
private:
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, Compare> pq;


public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<vector<int>> ans;
        for(auto nums: points){
            int x1 = nums[0];
            int y1 = nums[1];

            float dist = (x1*x1) + (y1*y1);
            pq.push({dist, nums});
            if(pq.size() > k) pq.pop();
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
