class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        
        vector<int> ans;
        for(auto &q:queries){
            vector<pair<string,int>> p;
            for(int i=0;i<nums.size();i++){
               p.push_back({(nums[i].substr(nums[i].size()-q[1])),i}); 
            }
            sort(p.begin(),p.end());
            ans.push_back(p[q[0]-1].second);
        }
        return ans;
    }
};