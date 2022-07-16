class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> mp;
        

        for(int x:nums){
            mp[x]++;
        }
        int ans=0;
        for(auto i:mp){
            ans=max(ans,i.second);
        }
        int res=INT_MAX;
        for(auto i:mp){
            if(ans==i.second){
                int l=0;
                int r=nums.size()-1;
                while(l<r+1){if(nums[l]==i.first)break;l++;}
                
                 while(l<r){if(nums[r]==i.first)break;r--; }
                res=min(res,r-l+1);
            }
        }
        return res;
        
    
    }
};
 
                
