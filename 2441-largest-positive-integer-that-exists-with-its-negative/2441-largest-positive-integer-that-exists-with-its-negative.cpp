class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        sort(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=0;i--){
            if(mp.find(-nums[i])!=mp.end()){
                return nums[i];
            }
        }
        return -1;
    }
};