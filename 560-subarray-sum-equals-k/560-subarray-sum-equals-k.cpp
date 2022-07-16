class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int curr_sum=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            if(curr_sum==k){
                count++;
            }
            if(mp.find(curr_sum-k)!=mp.end()){
                count+=mp[curr_sum-k];
            }
            mp[curr_sum]++;
        }
        return count;
    }
};