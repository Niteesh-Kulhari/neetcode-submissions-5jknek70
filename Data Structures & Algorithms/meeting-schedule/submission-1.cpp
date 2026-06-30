/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),
            [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        int i=0;
        int j=1;
        int n = intervals.size();

        while(j < n){
            int ce = intervals[i].end;
            int ns = intervals[j].start;

            if(ce > ns){
                return false;
            }

            i++;
            j++;
        }

        return true;
    }
};
