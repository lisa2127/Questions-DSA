class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& v) {
        unordered_map<int,unordered_set<string>>m;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++)m[i].insert(v[i][j]);
        }
        vector<int>ans;
        for(int i=0;i<v.size();i++){
            int mx=0;
            for(int j=0;j<v.size();j++){
                if(i==j)continue;
                int cnt=0;
                for(int k=0;k<v[i].size();k++){
                    if(m[j].count(v[i][k]))cnt++;
                }
                if(cnt==v[i].size()){
                    mx=cnt;
                    break;
                }
            }
            if(mx==0)ans.push_back(i);
        }
        return ans;
    }
};