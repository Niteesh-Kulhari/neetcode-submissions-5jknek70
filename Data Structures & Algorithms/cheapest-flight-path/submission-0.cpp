class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> distance(n, INT_MAX);
        vector<vector<pair<int, int>>> adj(n);

        for(auto flight: flights){
            int u = flight[0];
            int v = flight[1];
            int cost = flight[2];

            adj[u].push_back({v, cost});
        }

        queue<pair<int, pair<int, int>>> q;
        // stops, node, dis
        q.push({0, {src, 0}});

        while(!q.empty()){
            auto e = q.front();
            q.pop();
            int stops = e.first;
            auto [node, dis] = e.second;

            for(auto [ngbr, d]: adj[node]){
                if(d+dis < distance[ngbr] && stops <= k){
                    distance[ngbr] = d + dis;
                    q.push({stops+1, {ngbr, d+dis}});
                }
            }
        }

        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};
