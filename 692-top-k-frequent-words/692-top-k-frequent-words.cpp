class Solution {
public:
    struct MyComp {
        bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first != b.first) {
                return a.first > b.first;
            }
            else {
                return a.second < b.second;
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        map<string,int> mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,MyComp> pq;
        for(auto i: mp){
            pq.push(make_pair(i.second,i.first));
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.insert(ans.begin(),pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};