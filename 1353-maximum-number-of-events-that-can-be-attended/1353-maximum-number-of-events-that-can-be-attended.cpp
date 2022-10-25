class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int,vector<int>,greater<int>> pq;
        sort(events.begin(),events.end());
        int start=events[0][0];
        int end=INT_MIN;
        for(int i=0;i<events.size();i++){
            end=max(end,events[i][1]);
        }
        int i=0,ans=0;
        for(int day=start;day<=end;day++){
            while(i<events.size() && events[i][0]==day){
                pq.push(events[i][1]);
                i++;
            }
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};