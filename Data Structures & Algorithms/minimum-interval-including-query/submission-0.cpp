class Solution {
public:
    struct cmp{
        bool operator()(const pair<int, int>& a, const pair<int, int>& b){
            if(a.first == b.first){
                return a.second > b.second;
            }
            return a.first > b.first;
        } 
    };

    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = queries.size();
        vector<int> ans(n, -1);

        sort(intervals.begin(), intervals.end());
        vector<pair<int, int>> sortedQueries;
        for(int i=0; i<n; i++){
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

        int i=0;

        for(auto[q, index]: sortedQueries){
            while(i < intervals.size() && intervals[i][0] <= q){
                int start = intervals[i][0];
                int end = intervals[i][1];

                int len = end - start + 1;

                pq.push({len, end});
                i++;
            }

            while(!pq.empty() && pq.top().second < q){
                pq.pop();
            }

            if(!pq.empty()){
                ans[index] = pq.top().first;
            }


        }

        return ans;




    }
};
