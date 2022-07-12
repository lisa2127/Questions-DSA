class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int sub=target-nums[i];
            if(mp.find(sub)!=mp.end()){
                ans.push_back(mp[sub]);
                ans.push_back(i);
            }
            mp[nums[i]]=i;
        }
        return ans;
    }
};