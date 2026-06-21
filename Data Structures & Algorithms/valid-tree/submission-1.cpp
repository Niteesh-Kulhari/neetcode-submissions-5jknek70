class Solution {
private:
    bool dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        
        for(auto e: adj[node]){
            if(!vis[e]){
                if(dfs(e, node, vis, adj)){
                    return true;
                }
            }else if(vis[e] && e != parent){
                return true;
            }
        }

        return false;

    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> vis(n, 0);

        for(auto e: edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

       if(dfs(0, -1, vis, adj)){
        return false;
       }

       for(int i=0; i<n; i++){
        if(!vis[i]) return false;
       }

       
        return true;
    }
};
