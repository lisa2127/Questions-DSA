class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int target=nums[0];
        for(int i=0;i<nums.size();i++){
            ans+=abs(nums[i]-target);
        }
        return ans;
    }
};