class Solution {
private:
    bool dfs(string from, vector<string>& path){
        path.push_back(from);

        if(path.size() == numTickets+1){
            res = path;
            return true;
        }

        for(int i=0; i<adj[from].size(); i++){
            string to = adj[from][i];
            adj[from].erase(adj[from].begin()+i);
            if(dfs(to, path)) return true;
            adj[from].insert(adj[from].begin()+i, to);
        }
        path.pop_back();
        return false;
    }
public:
    unordered_map<string, vector<string>> adj;
    vector<string> res;
    int numTickets = 0;

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        numTickets = tickets.size();
        
        for(auto it: tickets){
            string from = it[0];
            string to = it[1];

            adj[from].push_back(to);
        }

        for(auto& e: adj){
            sort(e.second.begin(), e.second.end());
        }

        vector<string> path;

        dfs("JFK", path);

        return res;
    }
};
