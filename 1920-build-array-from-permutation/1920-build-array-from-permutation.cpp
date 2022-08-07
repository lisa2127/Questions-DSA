class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int element=nums[nums[i]];
            ans.push_back(element);
        }
        return ans;
    }
};