class Twitter {
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int,unordered_set<int>> follows;
    int count = 0;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
     tweets[userId].emplace_back(pair(count++, tweetId));
    }
    
    vector<int> getNewsFeed(int userId) {
        if(follows[userId].count(userId) == 0)
            follow(userId,userId);

        int tweetsFound = 0;
        static auto compare = [](auto& a,auto&b){return a.first < b.first;};
        priority_queue<pair<int, int>, vector<pair<int, int>>,decltype(compare)> q(compare);


        for(auto&& followed : follows[userId])
        {
            for(int i = 0; i < 10 && i < tweets[followed].size(); ++i)
                q.push(tweets[followed][tweets[followed].size() - 1 - i]);
        }
        vector<int> ans;
        for(int i = 0; i < 10 && !q.empty(); ++i)
        {
            ans.emplace_back(q.top().second);
            q.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
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