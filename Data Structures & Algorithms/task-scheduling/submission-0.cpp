class Solution {

struct Compare{
    bool operator()(pair<int, char>& a, pair<int, char>& b){
        return a.first < b.first;
    }
};

public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>, vector<pair<int, char>>, Compare> pq;

        unordered_map<char, int> mp;
        for(char task: tasks){
            mp[task]++;
        }

        for(auto [ch, freq]: mp){
            pq.push({freq, ch});
        }

        int time = 0;
        while(!pq.empty()){
            vector<pair<int, char>> temp;
            int cycle = n+1;

            while(cycle > 0 && !pq.empty()){
                auto [freq, task] = pq.top();
                pq.pop();
                time++;
                freq--;
                cycle--;
                cout << cycle << endl;

                if(freq > 0){
                    temp.push_back({freq, task});
                }
            }

            for(auto[freq, task]: temp){
                pq.push({freq, task});
            }

            if (pq.empty()) break;

            time += cycle; // idle time

        }

        return time;
    }
};
