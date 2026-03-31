class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0;
        int res = 0;
        int n = s.size();

        for(int r=0; r<n; r++){
            if(mp.find(s[r]) != mp.end()){
                l = max(mp[s[r]] + 1, l);
                mp.erase(s[r]);
            }
            res = max(res, r - l + 1);
            mp[s[r]] = r;
        }

        return res;


    }
};
