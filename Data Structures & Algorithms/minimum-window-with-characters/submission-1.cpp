class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        unordered_map<char, int> mp2;

        for(char ch: t){
            mp[ch]++;
        }

        int count = mp.size();
        int l = 0;
        int curr = 0;

        int minLen = INT_MAX;   // track minimum window length
        int minL = 0;           // track minimum window start

        for(int r=0; r<s.size(); r++){
            mp2[s[r]]++;

            if(mp.count(s[r]) && mp2[s[r]] == mp[s[r]]){
                curr++;
            }

            while(curr == count){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    minL = l;
                }

                mp2[s[l]]--;

                if(mp.count(s[l]) && mp2[s[l]] < mp[s[l]]){
                    curr--;
                }

                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minL, minLen);
    }
};
