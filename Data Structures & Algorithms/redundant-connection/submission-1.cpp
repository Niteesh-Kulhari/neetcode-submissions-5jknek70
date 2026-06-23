class Solution {
private:
    bool dfs(int u, int v, vector<vector<int>>& adj, vector<int>& vis){
        vis[u] = 1;
        
        if(u == v){
            return true;
        }

        for(auto edge: adj[u]){
            if(vis[edge]) continue;

            if(dfs(edge, v, adj, vis)) return true;
        }

        return false;

    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<vector<int>> adj(n+1);

        for(auto e: edges){
            int u = e[0];
            int v = e[1];
            vector<int> vis(n+1, 0);

            if(!adj[u].empty() && !adj[v].empty() && dfs(u, v, adj, vis)){
                return e;
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
            
        }

        return {};
    }
};
