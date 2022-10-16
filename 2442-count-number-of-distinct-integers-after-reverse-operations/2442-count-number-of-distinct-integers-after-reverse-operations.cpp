class Solution {
public:
    int reverse(int n){
        int ans=0;
        while(n>0){
            int r=n%10;
            ans=ans*10+r;
            n=n/10;
        }
        return ans;
    }
    int countDistinctIntegers(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(int i=0;i<nums.size();i++){
            int temp=reverse(nums[i]);
            if(mp.find(temp)==mp.end()){
                mp[temp]++;
            }
        }
        return mp.size();
    }
};