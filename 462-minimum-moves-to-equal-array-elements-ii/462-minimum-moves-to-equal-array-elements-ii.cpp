class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
        int temp=nums[nums.size()/2];
        for(int i=0;i<nums.size();i++){
            ans+=abs(nums[i]-temp);
        }
        return ans;
    }
};