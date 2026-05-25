class MedianFinder {
private:
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        max.push(num);

        if(!min.empty() && max.top() > min.top()){
            int elem = max.top();
            max.pop();
            min.push(elem);
        }

        // We will need to balance left and right side queues in order to calculate mean in O(1) time

        //Check left side Max queue is greater than 1 from right side
        if(max.size() > min.size() + 1){
            int elem = max.top();
            max.pop();
            min.push(elem);
        }

        //Check right side Min queue is greater than +1 from left side
        if(min.size() > max.size() + 1){
            int elem = min.top();
            min.pop();
            max.push(elem);
        }
    }
    
    double findMedian() {
        int size = max.size() + min.size();
        if(size % 2 == 0){
            double res = (double)(max.top() + min.top()) / 2;
            return res;
        }

        return max.size() > min.size() ? max.top() : min.top();
        
    }
};
