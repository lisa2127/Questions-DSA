class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map<string,long long> creatorView;
        unordered_map<string,pair<int,string>> creatorsID;
        int n=creators.size();
        long long mxViews = 0;
        for(int i=0;i<n;i++){
            creatorView[creators[i]]+=views[i];
            if(creatorsID.count(creators[i])){
                if(creatorsID[creators[i]].first==views[i]){
                    creatorsID[creators[i]].second=min(creatorsID[creators[i]].second,ids[i]);
                }
                else if(creatorsID[creators[i]].first<views[i]){
                    creatorsID[creators[i]]={views[i],ids[i]};
                }
            }
            else{
                creatorsID[creators[i]]={views[i],ids[i]};
            }
            mxViews = max(mxViews, creatorView[creators[i]]);
        }
        vector<vector < string>> res;
            for (auto p: creatorView)
            {
                if (p.second == mxViews)
                {
                    res.push_back({ p.first,
                        creatorsID[p.first].second });
                }
            }
            return res;
        }
};