class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);

        for(int i=1; i<n; i++){
            auto& elem = res.back();
            if(elem[1] < intervals[i][0]){
                res.push_back(intervals[i]);
            }else{
                elem[1] = max(elem[1], intervals[i][1]);
            }
        }

        return res;
    }
};
