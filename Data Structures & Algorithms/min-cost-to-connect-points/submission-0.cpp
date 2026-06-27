class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int>vis(n, 0);
        int ans = 0;
        // 0th node to start traversal -> {dis, node}
        pq.push({0, 0});

        while(!pq.empty()){
            auto[dis, node] = pq.top();
            pq.pop();
            if(vis[node]) continue;

            vis[node] = 1;
            ans += dis;

            for(int next=0; next<n; next++){
                if(!vis[next]){
                    int dist = abs(points[node][0] - points[next][0]) + abs(points[node][1] - points[next][1]);
                    pq.push({dist, next});
                }
            }
        }

        return ans;

    }
};
