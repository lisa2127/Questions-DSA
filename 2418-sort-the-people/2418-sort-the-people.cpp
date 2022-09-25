class Solution {
public:

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        //Approach 1
        /*vector<string> ans;
        unordered_map<int,string> mp;
        for(int i=0;i<heights.size();i++){
            mp[heights[i]]=names[i];
        }
        sort(heights.begin(),heights.end());
        for(int i=heights.size()-1;i>=0;i--){
            ans.push_back(mp[heights[i]]);
        }
        return ans;*/
        
        //Approach -2
        
        priority_queue<pair<int,string>> pq;
        for(int i=0;i<names.size();i++){
            pq.push({heights[i],names[i]});
        }
        vector<string> ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};