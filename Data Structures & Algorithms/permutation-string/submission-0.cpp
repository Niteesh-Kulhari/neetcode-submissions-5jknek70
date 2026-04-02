#include <cstring>
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }

        int freq1[26] = {0};
        int freq2[26] = {0};

        for(int i=0; i<s1.length(); i++){
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        int windowLength = s1.length();

        if(memcmp(freq1, freq2, sizeof(freq1)) == 0) return true;

        for(int i=windowLength; i<s2.length(); i++){
            freq2[s2[i] - 'a']++;
            freq2[s2[i - windowLength] - 'a']--;

            if(memcmp(freq1, freq2, sizeof(freq1)) == 0) return true;
        }

        return false;
    }
};
