class Twitter {
public:
    int time;
    // priority-queue<pair<int,int>,vector<pair<int,int>>pq;
    unordered_map<int,unordered_set<int>>followMap;
    unordered_map<int,vector<pair<int,int>>>tweets;
    Twitter() {
        time = 0;
    }
    bool compare(pair<int,int>p1,pair<int,int>p2)
    {
        return p1.first < p2.first;
    }
    
    void postTweet(int userId, int tweetId) {
        time++;
        tweets[userId].push_back({time,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>>pq;

        for(auto tweet:tweets[userId])
        {
            pq.push(tweet);
        }
        for(auto followee:followMap[userId])
        {
            if(followee == userId) continue;
            for(auto tweet:tweets[followee])
            {
                pq.push(tweet);
            }
        }

        vector<int>result;
        int cnt = 0;
        while(!pq.empty() && cnt <10)
        {
            result.push_back(pq.top().second);
            pq.pop();
            cnt++;
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */