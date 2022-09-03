class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum<abs(target) || (sum+target)%2!=0){
            return 0;
        }
        int mainsum=(sum+target)/2;
        int n=nums.size();
        int dp[n+1][mainsum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=mainsum;j++){
                if(i==0){
                    dp[i][j]=0;
                }
                if(j==0){
                    dp[i][j]=1;
                }
                if(i>0 && j>=0){
                    if(nums[i-1]<=j){
                        dp[i][j]=dp[i-1][j] + dp[i-1][j-nums[i-1]];
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
        }
        return dp[n][mainsum];
    }
};