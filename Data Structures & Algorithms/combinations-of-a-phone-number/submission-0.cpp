class Solution {
private:
    string phonedigits;
    vector<string> ans;
    unordered_map<char, string> mp = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    void solve(string path, int index){
        if(path.length() == phonedigits.length()){
            ans.push_back(path);
            return;
        }

        for(char ch: mp[phonedigits[index]]){
            path += ch;
            solve(path, index+1);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};

        phonedigits = digits;
        solve("", 0);
        return ans;
    }
};
