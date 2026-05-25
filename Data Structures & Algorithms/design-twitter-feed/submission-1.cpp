class Twitter {
private:
    int time;
    unordered_map<int, unordered_set<int>>follower;
    unordered_map<int, vector<pair<int, int>>>post;
public:
    Twitter() {
        this->time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        post[userId].push_back({time, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        priority_queue<pair<int, int>> max;

        if(post.count(userId)){
            for(auto[time, postId]: post[userId]){
                max.push({time, postId});
            }
        }

        if(follower.count(userId)){
            for(auto user: follower[userId]){
                for(auto[time, postId]: post[user]){
                    max.push({time, postId});
                }
            }
        }

        int count = 0;
        while(!max.empty() && count < 10){
            auto[time, postId] = max.top();
            max.pop();
            ans.push_back(postId);
            count++;
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            follower[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if(follower[followerId].count(followeeId)){
            follower[followerId].erase(followeeId);
        }
    }
};
