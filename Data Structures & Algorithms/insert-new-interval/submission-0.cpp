class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int i= 0;

        // Loop through all the intervals that can be pushed in the res and which are smaller than the newInterval
        while(i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++;
        }

        // THe intervals which overlap
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        res.push_back(newInterval);

        while(i < n){
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};
