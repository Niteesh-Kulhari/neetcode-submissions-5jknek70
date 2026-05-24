class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for(int num: stones){
            pq.push(num);
        }

        while(pq.size() > 1){
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();

            if(stone1 == stone2){
                continue;
            }else{
                int res = abs(stone1 - stone2);
                pq.push(res);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};
