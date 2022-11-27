class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2);
        unordered_map<int,int> lose;
        for(int i=0;i<matches.size();i++){
            lose[matches[i][1]]++;
        }
        for(auto it=lose.begin();it!=lose.end();it++){
            if(it->second==1){
                ans[1].push_back(it->first);
            }
        }
        for(int i=0;i<matches.size();i++){
            if(lose[matches[i][0]]==0){
                ans[0].push_back(matches[i][0]);
                lose[matches[i][0]]=1;
            }
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};