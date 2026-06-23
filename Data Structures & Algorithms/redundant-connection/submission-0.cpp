class DSU{
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1, 0);

        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUparent(int node){
        if(node == parent[node]){
            return node;
        }

        return parent[node] = findUparent(parent[node]);
    }

    bool unionByRank(int u, int v){
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);

        if(ulp_u == ulp_v) return false;

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++; 
        }

        return true;
    }

};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU* dsu = new DSU(edges.size());

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];

            if(!dsu->unionByRank(u, v)){
                return edge;
            }
        }

        return {};
    }
};
