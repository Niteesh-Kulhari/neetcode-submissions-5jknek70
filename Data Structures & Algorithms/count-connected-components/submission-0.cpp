class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;

        for(auto e: adj[node]){
            if(!vis[e]){
                dfs(e, vis, adj);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);

        for(auto e: edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                count++;
                dfs(i, vis, adj);
            }
        }

        return count;
    }
};
