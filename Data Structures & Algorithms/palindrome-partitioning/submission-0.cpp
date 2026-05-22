class Solution {
public:
    void solve(vector<vector<string>>& ans, vector<string>& path, int i, string s){
        if(i == s.size()){
            ans.push_back(path);
            return;
        }

        // Try every substring
        for(int j=i; j<s.length(); j++){
            if(isPalindrome(s, i, j)){
                path.push_back(s.substr(i, j-i+1));
                solve(ans, path, j+1, s);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end){
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;

        solve(ans, path, 0, s);

        return ans;
    }
};
