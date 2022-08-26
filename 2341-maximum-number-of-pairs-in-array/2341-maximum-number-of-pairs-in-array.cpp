class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        
        if(nums.size()==1){
            return {0,1};
        }
        int pair=0;
        vector<int> ans(2,0);
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(mp[nums[i]]==2){
                pair++;
                mp.erase(nums[i]);
            }
        }
        ans[0]=pair;
        if(mp.size()>0){
            ans[1]=mp.size();
        }
        return ans;
        
    }
};