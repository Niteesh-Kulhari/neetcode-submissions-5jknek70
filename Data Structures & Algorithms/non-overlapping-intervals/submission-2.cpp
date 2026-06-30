class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();

        int count = 0;
        int i= 0;
        int j = 1;

        while(j < n){
            int cs = intervals[i][0];
            int ce = intervals[i][1];
            int ns = intervals[j][0];
            int ne = intervals[j][1];

            // If the intervals are not overlapping
            if(ce <= ns){
                i = j;
                j++;
            }else if(ne >= ce){
                count++;
                j++;
            }else if (ce > ne){
                count++;
                i=j;
                j++;
            }
        }
        return count;
    }
};
