class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> mp;
        int ans=-1;
        int freq=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto i:mp){
            if(i.first%2==0){
                if(i.second>freq){
                    ans=i.first;
                    freq=i.second;
                }
            }
        }
        return ans;
    }
};