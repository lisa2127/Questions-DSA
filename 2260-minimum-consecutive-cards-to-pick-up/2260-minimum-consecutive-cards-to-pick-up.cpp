class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        /*int ans=INT_MAX;
        for(int i=0;i<cards.size();i++){
            for(int j=i+1;j<cards.size();j++){
                if(cards[i]==cards[j]){
                    int temp=j-i+1;
                    ans=min(ans,temp);
                }
            }
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;*/  //TLE
        //Failed at 75 th test case:
       /* int ans=INT_MAX;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<cards.size();i++){
            mp[cards[i]].push_back(i);
        }
        vector<vector<int>> a;
        for(auto i: mp){
            vector<int> v;
            for(auto j:i.second){
                v.push_back(j);
            }
            if(v.size()>1){
            a.push_back(v);
        }
        }

        for(int i=0;i<a.size();i++){
            int temp=abs(a[i][0]-a[i][1])+1;
            ans=min(ans,temp);
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;*/
        int ans=INT_MAX;
        unordered_map<int,int> mp;
        for(int i=0;i<cards.size();i++){
            if(mp.find(cards[i])!=mp.end()){
                ans=min(ans,i-mp[cards[i]]+1);
            }
            mp[cards[i]]=i;
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};