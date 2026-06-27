class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        vector<int> adj[26];
        vector<bool> present(26, false);

        for(auto word: words){
            for(char ch: word){
                present[ch - 'a'] = true;
            }
        }

        for(int i=0; i<n-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];

            int len = min(s1.length(), s2.length());
            bool found = false;

            for(int j=0; j<len; j++){
                if(s1[j] != s2[j]){
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    found = true;
                    break;
                }
            }

            if(!found && s1.length() > s2.length()){
                return "";
            }
        }

        vector<int> topo;
        queue<int> q;
        vector<int> inDegree(26, 0);

        for(int i=0; i<26; i++){
            for(auto edge: adj[i]){
                inDegree[edge]++;
            }
        }

        int totalChars = 0;
        for(int i=0; i<26; i++){
            if(present[i]){
                totalChars++;
                if(inDegree[i] == 0) q.push({i});
            }
        }

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                inDegree[it]--;

                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }

        string ans = "";
        for(int num: topo){
            ans += char(num + 'a');
        }

        if(ans.size() != totalChars){
            return "";
        }

        return ans;

    }
};
