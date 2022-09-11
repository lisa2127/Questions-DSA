class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int mod=1e9+7;
        vector<pair<int,int>> engineer(n);
        for(int i=0;i<n;i++){
            engineer[i]={efficiency[i],speed[i]};
        }
        sort(engineer.rbegin(),engineer.rend()); //sorting and reversing
        priority_queue<int,vector<int> ,greater<int>> pq;
        long sumspeed=0;
        long ans=0;
        for(auto &[e,s]:engineer){
            pq.push(s);
            sumspeed+=s;
            if(pq.size()>k){
                sumspeed-=pq.top();
                pq.pop();
            }
            ans=max(ans,sumspeed*e);
        }
        return ans%mod;
    }
};