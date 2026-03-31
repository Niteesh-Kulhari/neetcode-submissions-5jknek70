class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int n = s.size();
        unordered_map<char, int> mp;
        int maxF = 0;
        int res = 0;

        for(int r=0; r<n; r++){
            mp[s[r]]++;
            maxF = max(maxF, mp[s[r]]);

            while((r-l+1) - maxF > k){
                mp[s[l]]--;
                l++;
            }

            res = max(res, r-l+1);
            
        }

        return res;
    }
};
