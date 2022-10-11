class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //TLE
        /*int n=nums.size();
        if(n==0){
            return 0;
        }
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            if(dp[i]==3){
                return true;
            }
        }
        return false;*/
        
        int c1=INT_MAX;
        int c2=INT_MAX;
        for(auto i: nums){
            if(i<=c1){
                c1=i;
            }
            else if(i<=c2){
                c2=i;
            }
            else{
                return true;
            }
        }
        return false;
    }
};