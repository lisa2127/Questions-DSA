class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> ans;
        map<int,vector<int>> mp;
        for(int i=0;i<items1.size();i++){
            mp[items1[i][0]].push_back(items1[i][1]);
        }
        for(int i=0;i<items2.size();i++){
            mp[items2[i][0]].push_back(items2[i][1]);
        }
        for(auto i:mp){
            vector<int> temp;
            temp.push_back(i.first);
            int sum=0;
            for(auto j:i.second){
                sum+=j;
            }
            temp.push_back(sum);
            ans.push_back(temp);
        }
        return ans;
    }
};