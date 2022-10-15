class Twitter {
public:
    int history=0;
    unordered_map<int,set<int>> flist;
    unordered_map<int,vector<pair<int,int>>> mp;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
       mp[userId].push_back(make_pair(history,tweetId));
        history++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<pair<int,int>> pq;
        for(auto i:mp[userId]){
            pq.push(i);
        }
        for(auto j:flist[userId]){
            for(auto k:mp[j]){
                pq.push(k);
            }
        }
        int size=pq.size();
        int n=min(10,size);
        for(int i=0;i<n;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        flist[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        flist[followerId].erase(followeeId);
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