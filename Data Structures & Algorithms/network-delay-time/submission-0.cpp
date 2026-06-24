class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        vector<int> dis(n+1, INT_MAX);
        pq.push({0, k});
        dis[k] = 0;
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto e: times){
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
        }

        while(!pq.empty()){
            auto e = pq.top();
            int d = e.first;
            int edge = e.second;
            pq.pop();

            for(auto it: adj[edge]){
                int node = it.first;
                int wt = it.second;

                if(wt+d < dis[node]){
                    pq.push({wt+d, node});
                    dis[node] = wt+d;
                }
            }
        }


         int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dis[i] == INT_MAX) return -1;
            ans = max(ans, dis[i]);
        }

        return ans;
    }
};
