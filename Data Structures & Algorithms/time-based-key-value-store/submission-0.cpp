class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";
        
        auto &arr = mp[key];
        int left = 0;
        int right = arr.size()-1;

        string res = "";

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(arr[mid].first <= timestamp){
                left = mid + 1;
                res = arr[mid].second;
            }else{
                right = mid -1;
            }
        }

        return res;
    }
};
